"""Minimal Autodesk FLI/FLC decoder (enough for the Lazarus intro files).

Supported chunks: COLOR_256 (4), COLOR_64 (11), DELTA_FLC (7), DELTA_FLI (12),
BLACK (13), BYTE_RUN (15), FLI_COPY (16).  Yields (pixels, palette) per frame
where pixels is a bytearray of width*height palette indices and palette is a
list of 256 (r,g,b) tuples.

Note: several Lazarus files have the `depth` header field zeroed (so `file`
does not recognise them) - they are ordinary 8-bit FLCs otherwise.
"""
import struct


def frames(data):
    size, magic, nframes, w, h, depth, flags, speed = struct.unpack_from("<IHHHHHHI", data, 0)
    if magic not in (0xAF11, 0xAF12):
        raise ValueError("not a FLI/FLC file")
    off = 128
    if magic == 0xAF12:
        f1 = struct.unpack_from("<I", data, 80)[0]
        if f1:
            off = f1
    pix = bytearray(w * h)
    pal = [(0, 0, 0)] * 256
    for _ in range(nframes):
        fsize, ftype = struct.unpack_from("<IH", data, off)
        if ftype == 0xF100:          # prefix chunk, skip
            off += fsize
            fsize, ftype = struct.unpack_from("<IH", data, off)
        nchunks = struct.unpack_from("<H", data, off + 6)[0]
        p = off + 16
        for _c in range(nchunks):
            csize, ctype = struct.unpack_from("<IH", data, p)
            body = p + 6
            if ctype in (4, 11):
                pal = _color(data, body, pal, ctype == 11)
            elif ctype == 15:
                _brun(data, body, pix, w, h)
            elif ctype == 7:
                _delta_flc(data, body, pix, w)
            elif ctype == 12:
                _delta_fli(data, body, pix, w)
            elif ctype == 13:
                pix[:] = bytes(w * h)
            elif ctype == 16:
                pix[:] = data[body:body + w * h]
            p += csize
        off += fsize
        yield bytes(pix), list(pal), (w, h), speed


def _color(d, p, pal, six_bit):
    pal = list(pal)
    npk = struct.unpack_from("<H", d, p)[0]
    p += 2
    idx = 0
    for _ in range(npk):
        idx += d[p]
        cnt = d[p + 1] or 256
        p += 2
        for _k in range(cnt):
            r, g, b = d[p], d[p + 1], d[p + 2]
            if six_bit:
                r, g, b = (r * 255) // 63, (g * 255) // 63, (b * 255) // 63
            pal[idx & 255] = (r, g, b)
            idx += 1
            p += 3
    return pal


def _brun(d, p, pix, w, h):
    for y in range(h):
        p += 1                       # obsolete packet count
        x = 0
        row = y * w
        while x < w:
            c = struct.unpack_from("<b", d, p)[0]
            p += 1
            if c > 0:
                pix[row + x:row + x + c] = bytes([d[p]]) * c
                p += 1
                x += c
            else:
                c = -c
                pix[row + x:row + x + c] = d[p:p + c]
                p += c
                x += c


def _delta_fli(d, p, pix, w):
    y, nlines = struct.unpack_from("<HH", d, p)
    p += 4
    for _ in range(nlines):
        npk = d[p]
        p += 1
        x = 0
        for _k in range(npk):
            x += d[p]
            c = struct.unpack_from("<b", d, p + 1)[0]
            p += 2
            row = y * w
            if c > 0:
                pix[row + x:row + x + c] = d[p:p + c]
                p += c
                x += c
            else:
                c = -c
                pix[row + x:row + x + c] = bytes([d[p]]) * c
                p += 1
                x += c
        y += 1


def _delta_flc(d, p, pix, w):
    nlines = struct.unpack_from("<H", d, p)[0]
    p += 2
    y = 0
    for _ in range(nlines):
        last = None
        while True:
            word = struct.unpack_from("<H", d, p)[0]
            p += 2
            if word & 0xC000 == 0xC000:
                y += 0x10000 - word      # skip lines
            elif word & 0xC000 == 0x8000:
                last = word & 0xFF
            else:
                npk = word
                break
        row = y * w
        x = 0
        for _k in range(npk):
            x += d[p]
            c = struct.unpack_from("<b", d, p + 1)[0]
            p += 2
            if c > 0:
                n = c * 2
                pix[row + x:row + x + n] = d[p:p + n]
                p += n
                x += n
            else:
                c = -c
                pix[row + x:row + x + 2 * c] = d[p:p + 2] * c
                p += 2
                x += 2 * c
        if last is not None:
            pix[row + w - 1] = last
        y += 1
