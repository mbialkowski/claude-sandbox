
/* ======== __break @ 00010000 ======== */

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* ======== __break @ 00010001 ======== */

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


/* ======== FUN_0001000c @ 0001000c ======== */

void FUN_0001000c(undefined4 param_1,uint unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  int *unaff_EDI;
  int unaff_FS_OFFSET;
  
  for (uVar2 = unaff_EDX >> 4; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    *unaff_EDI = *unaff_EDI + *(int *)(uVar1 * 4);
    unaff_EDI[1] = unaff_EDI[1] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX + unaff_ECX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX + unaff_ECX;
    unaff_EDI[2] = unaff_EDI[2] + *(int *)(uVar1 * 4);
    unaff_EDI[3] = unaff_EDI[3] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[4] = unaff_EDI[4] + *(int *)(uVar1 * 4);
    unaff_EDI[5] = unaff_EDI[5] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[6] = unaff_EDI[6] + *(int *)(uVar1 * 4);
    unaff_EDI[7] = unaff_EDI[7] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[8] = unaff_EDI[8] + *(int *)(uVar1 * 4);
    unaff_EDI[9] = unaff_EDI[9] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[10] = unaff_EDI[10] + *(int *)(uVar1 * 4);
    unaff_EDI[0xb] = unaff_EDI[0xb] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0xc] = unaff_EDI[0xc] + *(int *)(uVar1 * 4);
    unaff_EDI[0xd] = unaff_EDI[0xd] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0xe] = unaff_EDI[0xe] + *(int *)(uVar1 * 4);
    unaff_EDI[0xf] = unaff_EDI[0xf] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x10] = unaff_EDI[0x10] + *(int *)(uVar1 * 4);
    unaff_EDI[0x11] = unaff_EDI[0x11] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x12] = unaff_EDI[0x12] + *(int *)(uVar1 * 4);
    unaff_EDI[0x13] = unaff_EDI[0x13] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x14] = unaff_EDI[0x14] + *(int *)(uVar1 * 4);
    unaff_EDI[0x15] = unaff_EDI[0x15] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x16] = unaff_EDI[0x16] + *(int *)(uVar1 * 4);
    unaff_EDI[0x17] = unaff_EDI[0x17] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x18] = unaff_EDI[0x18] + *(int *)(uVar1 * 4);
    unaff_EDI[0x19] = unaff_EDI[0x19] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1a] = unaff_EDI[0x1a] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1b] = unaff_EDI[0x1b] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1c] = unaff_EDI[0x1c] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1d] = unaff_EDI[0x1d] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1e] = unaff_EDI[0x1e] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1f] = unaff_EDI[0x1f] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    unaff_EDI = unaff_EDI + 0x20;
  }
  for (unaff_EDX = unaff_EDX & 0xf; unaff_EDX != 0; unaff_EDX = unaff_EDX - 1) {
    uVar2 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    *unaff_EDI = *unaff_EDI + *(int *)(uVar2 * 4);
    unaff_EDI[1] = unaff_EDI[1] + *(int *)(unaff_FS_OFFSET + uVar2 * 4);
    unaff_EDI = unaff_EDI + 2;
  }
  return;
}


/* ======== FUN_00010010 @ 00010010 ======== */

void FUN_00010010(undefined4 param_1,uint unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  uint uVar1;
  uint uVar2;
  int unaff_ESI;
  int *unaff_EDI;
  int unaff_FS_OFFSET;
  
  for (uVar2 = unaff_EDX >> 4; uVar2 != 0; uVar2 = uVar2 - 1) {
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    *unaff_EDI = *unaff_EDI + *(int *)(uVar1 * 4);
    unaff_EDI[1] = unaff_EDI[1] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX + unaff_ECX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX + unaff_ECX;
    unaff_EDI[2] = unaff_EDI[2] + *(int *)(uVar1 * 4);
    unaff_EDI[3] = unaff_EDI[3] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[4] = unaff_EDI[4] + *(int *)(uVar1 * 4);
    unaff_EDI[5] = unaff_EDI[5] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[6] = unaff_EDI[6] + *(int *)(uVar1 * 4);
    unaff_EDI[7] = unaff_EDI[7] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[8] = unaff_EDI[8] + *(int *)(uVar1 * 4);
    unaff_EDI[9] = unaff_EDI[9] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[10] = unaff_EDI[10] + *(int *)(uVar1 * 4);
    unaff_EDI[0xb] = unaff_EDI[0xb] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0xc] = unaff_EDI[0xc] + *(int *)(uVar1 * 4);
    unaff_EDI[0xd] = unaff_EDI[0xd] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0xe] = unaff_EDI[0xe] + *(int *)(uVar1 * 4);
    unaff_EDI[0xf] = unaff_EDI[0xf] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x10] = unaff_EDI[0x10] + *(int *)(uVar1 * 4);
    unaff_EDI[0x11] = unaff_EDI[0x11] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x12] = unaff_EDI[0x12] + *(int *)(uVar1 * 4);
    unaff_EDI[0x13] = unaff_EDI[0x13] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x14] = unaff_EDI[0x14] + *(int *)(uVar1 * 4);
    unaff_EDI[0x15] = unaff_EDI[0x15] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x16] = unaff_EDI[0x16] + *(int *)(uVar1 * 4);
    unaff_EDI[0x17] = unaff_EDI[0x17] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x18] = unaff_EDI[0x18] + *(int *)(uVar1 * 4);
    unaff_EDI[0x19] = unaff_EDI[0x19] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1a] = unaff_EDI[0x1a] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1b] = unaff_EDI[0x1b] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1c] = unaff_EDI[0x1c] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1d] = unaff_EDI[0x1d] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    uVar1 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    unaff_EDI[0x1e] = unaff_EDI[0x1e] + *(int *)(uVar1 * 4);
    unaff_EDI[0x1f] = unaff_EDI[0x1f] + *(int *)(unaff_FS_OFFSET + uVar1 * 4);
    unaff_EDI = unaff_EDI + 0x20;
  }
  for (unaff_EDX = unaff_EDX & 0xf; unaff_EDX != 0; unaff_EDX = unaff_EDX - 1) {
    uVar2 = (uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb));
    unaff_EBX = unaff_EBX + unaff_ECX;
    *unaff_EDI = *unaff_EDI + *(int *)(uVar2 * 4);
    unaff_EDI[1] = unaff_EDI[1] + *(int *)(unaff_FS_OFFSET + uVar2 * 4);
    unaff_EDI = unaff_EDI + 2;
  }
  return;
}


/* ======== FUN_00010272 @ 00010272 ======== */

void FUN_00010272(undefined4 param_1,uint unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int *unaff_EDI;
  
  for (uVar1 = unaff_EDX >> 4; uVar1 != 0; uVar1 = uVar1 - 1) {
    *unaff_EDI = *unaff_EDI + *(int *)((uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb)) * 4);
    iVar2 = unaff_EBX + unaff_ECX + unaff_ECX;
    unaff_EDI[1] = unaff_EDI[1] +
                   *(int *)((uint)*(byte *)(unaff_ESI + (unaff_EBX + unaff_ECX >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[2] = unaff_EDI[2] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[3] = unaff_EDI[3] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[4] = unaff_EDI[4] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[5] = unaff_EDI[5] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[6] = unaff_EDI[6] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[7] = unaff_EDI[7] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[8] = unaff_EDI[8] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[9] = unaff_EDI[9] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[10] = unaff_EDI[10] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[0xb] = unaff_EDI[0xb] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[0xc] = unaff_EDI[0xc] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    iVar2 = iVar3 + unaff_ECX;
    unaff_EDI[0xd] = unaff_EDI[0xd] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    iVar3 = iVar2 + unaff_ECX;
    unaff_EDI[0xe] = unaff_EDI[0xe] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar2 >> 0xb)) * 4);
    unaff_EBX = iVar3 + unaff_ECX;
    unaff_EDI[0xf] = unaff_EDI[0xf] + *(int *)((uint)*(byte *)(unaff_ESI + (iVar3 >> 0xb)) * 4);
    unaff_EDI = unaff_EDI + 0x10;
  }
  for (unaff_EDX = unaff_EDX & 0xf; unaff_EDX != 0; unaff_EDX = unaff_EDX - 1) {
    *unaff_EDI = *unaff_EDI + *(int *)((uint)*(byte *)(unaff_ESI + (unaff_EBX >> 0xb)) * 4);
    unaff_EDI = unaff_EDI + 1;
    unaff_EBX = unaff_EBX + unaff_ECX;
  }
  return;
}


/* ======== FUN_00010417 @ 00010417 ======== */

undefined FUN_00010417(void)

{
  out(0x20,0x20);
  return 0x20;
}


/* ======== FUN_00010460 @ 00010460 ======== */

void FUN_00010460(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(3);
  DAT_000523a7 = 0;
  return;
}


/* ======== FUN_00010471 @ 00010471 ======== */

void FUN_00010471(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x13);
  DAT_000523a7 = 1;
  return;
}


/* ======== SetMode640x480x16 @ 00010484 ======== */

void SetMode640x480x16(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x12);
  DAT_000523a7 = 2;
  return;
}


/* ======== SetModeX320x240 @ 00010497 ======== */

undefined8 SetModeX320x240(void)

{
  code *pcVar1;
  undefined2 *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x13);
  DAT_000523a7 = 3;
  out(0x3c4,0x604);
  out(0x3c4,0x100);
  out(0x3c2,DAT_00051a7c);
  out(0x3c4,0x300);
  out(0x3d4,0x11);
  bVar3 = in(0x3d5);
  out(0x3d5,bVar3 & 0x7f);
  iVar4 = 10;
  puVar2 = &DAT_00051a7e;
  do {
    out(0x3d4,*puVar2);
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar4 != 0);
  out(0x3c4,0xf02);
  puVar5 = &DAT_000a0000;
  for (iVar4 = 0x4000; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  out(0x3d4,0x13);
  out(0x3d5,0x28);
  return 0x3d500000028;
}


/* ======== DrawPlatformTile @ 000105ab ======== */

void DrawPlatformTile(uint param_1,int unaff_EDX,int unaff_EBX)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar5 = g_backBuffer +
           *(int *)(&DAT_00051b24 + (unaff_EDX * 0x13 + 6) * 4) + (param_1 & 0x7f) * 4;
  pcVar4 = (char *)(DAT_00051b16 + unaff_EBX * 0x130);
  iVar3 = 0x13;
  pcVar6 = pcVar5;
  do {
    iVar2 = 4;
    do {
      pcVar7 = pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 != '\0') {
        *pcVar7 = cVar1;
      }
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar7 + 1;
    } while (iVar2 != 0);
    pcVar6 = pcVar7 + 0x4d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar6 = pcVar5 + 0x4b00;
  iVar3 = 0x13;
  do {
    iVar2 = 4;
    do {
      pcVar7 = pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 != '\0') {
        *pcVar7 = cVar1;
      }
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar7 + 1;
    } while (iVar2 != 0);
    pcVar6 = pcVar7 + 0x4d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar6 = pcVar5 + 0x9600;
  iVar3 = 0x13;
  do {
    iVar2 = 4;
    do {
      pcVar7 = pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 != '\0') {
        *pcVar7 = cVar1;
      }
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar7 + 1;
    } while (iVar2 != 0);
    pcVar6 = pcVar7 + 0x4d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pcVar5 = pcVar5 + 0xe100;
  iVar3 = 0x13;
  do {
    iVar2 = 4;
    do {
      pcVar6 = pcVar5;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 != '\0') {
        *pcVar6 = cVar1;
      }
      iVar2 = iVar2 + -1;
      pcVar5 = pcVar6 + 1;
    } while (iVar2 != 0);
    pcVar5 = pcVar6 + 0x4d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* ======== DrawBackgroundTile @ 000106fe ======== */

void DrawBackgroundTile(uint param_1,int unaff_EDX,int unaff_EBX)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)
           (g_backBuffer +
           *(int *)(&DAT_00051b24 + (unaff_EDX * 0x26 + 6) * 4) + (param_1 & 0x7f) * 8);
  puVar2 = (undefined4 *)(DAT_00051b1a + unaff_EBX * 0x4c0);
  iVar1 = 0x26;
  puVar4 = puVar3;
  do {
    *puVar4 = *puVar2;
    puVar4[1] = puVar2[1];
    puVar2 = puVar2 + 2;
    puVar4 = puVar4 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar4 = puVar3 + 0x12c0;
  iVar1 = 0x26;
  do {
    *puVar4 = *puVar2;
    puVar4[1] = puVar2[1];
    puVar2 = puVar2 + 2;
    puVar4 = puVar4 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar4 = puVar3 + 0x2580;
  iVar1 = 0x26;
  do {
    *puVar4 = *puVar2;
    puVar4[1] = puVar2[1];
    puVar2 = puVar2 + 2;
    puVar4 = puVar4 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar3 = puVar3 + 0x3840;
  iVar1 = 0x26;
  do {
    *puVar3 = *puVar2;
    puVar3[1] = puVar2[1];
    puVar2 = puVar2 + 2;
    puVar3 = puVar3 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


/* ======== DrawHudPanel @ 000107b0 ======== */

void DrawHudPanel(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = g_roomBuffer;
  puVar5 = (undefined4 *)(g_roomBuffer + 0x3d);
  iVar3 = 0xf0;
  puVar4 = DAT_00051b1e;
  do {
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar2 = 3; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined *)puVar5 = *(undefined *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar5 = (undefined4 *)((int)puVar5 + 0x3d);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar5 = (undefined4 *)(puVar1 + 0x4b3d);
  iVar3 = 0xf0;
  do {
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar2 = 3; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined *)puVar5 = *(undefined *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar5 = (undefined4 *)((int)puVar5 + 0x3d);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar5 = (undefined4 *)(puVar1 + 0x963d);
  iVar3 = 0xf0;
  do {
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar2 = 3; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined *)puVar5 = *(undefined *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar5 = (undefined4 *)((int)puVar5 + 0x3d);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar5 = (undefined4 *)(puVar1 + 0xe13d);
  iVar3 = 0xf0;
  do {
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar2 = 3; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined *)puVar5 = *(undefined *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar5 = (undefined4 *)((int)puVar5 + 0x3d);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* ======== ClearVRAM @ 000108bb ======== */

void ClearVRAM(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  out(0x3c4,0xf02);
  puVar2 = &DAT_000a0000;
  for (iVar1 = 0x12c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


/* ======== FUN_000108d5 @ 000108d5 ======== */

undefined6 FUN_000108d5(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  out(0x3c4,0x102);
  puVar2 = (undefined4 *)g_backBuffer;
  puVar3 = (undefined4 *)((int)&DAT_000a0000 + param_1);
  for (iVar1 = 0x12c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  out(0x3c4,0x202);
  puVar3 = (undefined4 *)((int)&DAT_000a0000 + param_1);
  for (iVar1 = 0x12c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  out(0x3c4,0x402);
  puVar3 = (undefined4 *)((int)&DAT_000a0000 + param_1);
  for (iVar1 = 0x12c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  out(0x3c4,0x802);
  puVar3 = (undefined4 *)((int)&DAT_000a0000 + param_1);
  for (iVar1 = 0x12c0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return 0x3c400000802;
}


/* ======== FUN_00010a22 @ 00010a22 ======== */

void FUN_00010a22(undefined *param_1,undefined2 *unaff_EDX)

{
  undefined *puVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  puVar6 = param_1 + 1;
  iVar5 = 0x12c0;
  puVar7 = param_1;
  do {
    uVar2 = *puVar7;
    puVar1 = puVar7 + 4;
    uVar3 = puVar7[8];
    uVar4 = puVar7[0xc];
    puVar7 = puVar7 + 0x10;
    *unaff_EDX = CONCAT11(*puVar1,uVar2);
    unaff_EDX[1] = CONCAT11(uVar4,uVar3);
    unaff_EDX = unaff_EDX + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar7 = param_1 + 2;
  iVar5 = 0x12c0;
  do {
    uVar2 = *puVar6;
    puVar1 = puVar6 + 4;
    uVar3 = puVar6[8];
    uVar4 = puVar6[0xc];
    puVar6 = puVar6 + 0x10;
    *unaff_EDX = CONCAT11(*puVar1,uVar2);
    unaff_EDX[1] = CONCAT11(uVar4,uVar3);
    unaff_EDX = unaff_EDX + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1 = param_1 + 3;
  iVar5 = 0x12c0;
  do {
    uVar2 = *puVar7;
    puVar6 = puVar7 + 4;
    uVar3 = puVar7[8];
    uVar4 = puVar7[0xc];
    puVar7 = puVar7 + 0x10;
    *unaff_EDX = CONCAT11(*puVar6,uVar2);
    unaff_EDX[1] = CONCAT11(uVar4,uVar3);
    unaff_EDX = unaff_EDX + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 0x12c0;
  do {
    uVar2 = *param_1;
    puVar7 = param_1 + 4;
    uVar3 = param_1[8];
    uVar4 = param_1[0xc];
    param_1 = param_1 + 0x10;
    *unaff_EDX = CONCAT11(*puVar7,uVar2);
    unaff_EDX[1] = CONCAT11(uVar4,uVar3);
    unaff_EDX = unaff_EDX + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


/* ======== FUN_00010ba3 @ 00010ba3 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010ba3(uint param_1,int unaff_EDX,ushort *unaff_EBX)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar5;
  
  _DAT_00051b12 = g_backBuffer;
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0;
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  do {
    pcVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      uVar2 = uVar4 & 0xff;
      pcVar9 = pcVar8;
      do {
        cVar5 = *(char *)puVar6;
        puVar6 = (ushort *)((int)puVar6 + 1);
        if (cVar5 != '\0') {
          *pcVar9 = cVar5;
        }
        pcVar9 = pcVar9 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      pcVar8 = pcVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar3 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar2 >> 8) + -1;
    uVar3 = CONCAT11(cVar5,(char)uVar2);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00010be8 @ 00010be8 ======== */

void FUN_00010be8(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      pcVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *pcVar6 = cVar5;
        }
        pcVar6 = pcVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (char *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010c15 @ 00010c15 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010c15(uint param_1,int unaff_EDX,ushort *unaff_EBX)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar5;
  
  _DAT_00051b12 = g_backBuffer;
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4);
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  do {
    pcVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      uVar2 = uVar4 & 0xff;
      pcVar9 = pcVar8;
      do {
        cVar5 = *(char *)puVar6;
        puVar6 = (ushort *)((int)puVar6 + 1);
        if (cVar5 != '\0') {
          *pcVar9 = cVar5;
        }
        pcVar9 = pcVar9 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      pcVar8 = pcVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar3 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar2 >> 8) + -1;
    uVar3 = CONCAT11(cVar5,(char)uVar2);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00010c54 @ 00010c54 ======== */

void FUN_00010c54(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      pcVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *pcVar6 = cVar5;
        }
        pcVar6 = pcVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (char *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010c81 @ 00010c81 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010c81(uint param_1,int unaff_EDX,ushort *unaff_EBX,int unaff_ECX)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  byte bVar6;
  ushort uVar5;
  ushort *puVar8;
  undefined *puVar9;
  char *pcVar10;
  char *pcVar11;
  char cVar7;
  
  uVar4 = CONCAT11(4,(byte)param_1 & 3);
  puVar9 = g_backBuffer +
           (param_1 >> 2) + *(int *)(&DAT_00051b24 + (unaff_EDX + unaff_ECX) * 4) + 0x1e0;
  puVar8 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  bVar6 = (byte)(uVar1 >> 8);
  bVar2 = (byte)unaff_ECX;
  if (bVar6 != bVar2) {
    _DAT_000523ab = (uint)(ushort)((uVar1 & 0xff) * (ushort)bVar2);
    do {
      puVar8 = (ushort *)((int)puVar8 + _DAT_000523ab);
      pcVar10 = puVar9 + *(int *)(&DAT_00051ac6 + (uVar4 & 0xff) * 4);
      uVar5 = CONCAT11(bVar6 - bVar2,(char)uVar1);
      do {
        uVar3 = uVar5 & 0xff;
        pcVar11 = pcVar10;
        do {
          cVar7 = *(char *)puVar8;
          puVar8 = (ushort *)((int)puVar8 + 1);
          if (cVar7 != '\0') {
            *pcVar11 = cVar7;
          }
          pcVar11 = pcVar11 + 1;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
        pcVar10 = pcVar10 + 0x50;
        cVar7 = (char)(uVar5 >> 8) + -1;
        uVar5 = CONCAT11(cVar7,(char)uVar5);
      } while (cVar7 != '\0');
      cVar7 = (char)uVar4 + '\x01';
      if (cVar7 == '\x04') {
        puVar9 = (undefined *)CONCAT22((short)((uint)puVar9 >> 0x10),(short)puVar9 + 1);
      }
      uVar3 = CONCAT11((char)(uVar4 >> 8),cVar7) & 0xffffff03;
      cVar7 = (char)(uVar3 >> 8) + -1;
      uVar4 = CONCAT11(cVar7,(char)uVar3);
    } while (cVar7 != '\0');
  }
  return;
}


/* ======== FUN_00010cbe @ 00010cbe ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010cbe(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar6;
  char *pcVar7;
  char cVar5;
  
  cVar3 = (char)((uint)unaff_EDX >> 8);
  bVar2 = (byte)unaff_EDX;
  do {
    unaff_ESI = unaff_ESI + _DAT_000523ab;
    pcVar6 = (char *)(unaff_EDI + *(int *)(&DAT_00051ac6 + (uint)bVar2 * 4));
    uVar4 = unaff_EBX;
    do {
      uVar1 = uVar4 & 0xff;
      pcVar7 = pcVar6;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *pcVar7 = cVar5;
        }
        pcVar7 = pcVar7 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      pcVar6 = pcVar6 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = (uint)CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    if ((byte)(bVar2 + 1) == 4) {
      unaff_EDI = CONCAT22((short)((uint)unaff_EDI >> 0x10),(short)unaff_EDI + 1);
    }
    bVar2 = bVar2 + 1 & 3;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  return;
}


/* ======== FUN_00010cd3 @ 00010cd3 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010cd3(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      pcVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *pcVar6 = cVar5;
        }
        pcVar6 = pcVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_ESI = unaff_ESI + _DAT_000523ab;
    unaff_EDI = (char *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010d00 @ 00010d00 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010d00(uint param_1,int unaff_EDX,ushort *unaff_EBX,char unaff_CL)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar5;
  
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0;
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  _DAT_000523ab = (uint)(ushort)((ushort)(byte)((char)(uVar1 >> 8) - unaff_CL) * (uVar1 & 0xff));
  if (unaff_CL != '\0') {
    do {
      pcVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
      uVar4 = CONCAT11(unaff_CL,(char)uVar1);
      do {
        uVar2 = uVar4 & 0xff;
        pcVar9 = pcVar8;
        do {
          cVar5 = *(char *)puVar6;
          puVar6 = (ushort *)((int)puVar6 + 1);
          if (cVar5 != '\0') {
            *pcVar9 = cVar5;
          }
          pcVar9 = pcVar9 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
        pcVar8 = pcVar8 + 0x50;
        cVar5 = (char)(uVar4 >> 8) + -1;
        uVar4 = CONCAT11(cVar5,(char)uVar4);
      } while (cVar5 != '\0');
      puVar6 = (ushort *)((int)puVar6 + _DAT_000523ab);
      cVar5 = (char)uVar3 + '\x01';
      if (cVar5 == '\x04') {
        puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
      }
      uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
      cVar5 = (char)(uVar2 >> 8) + -1;
      uVar3 = CONCAT11(cVar5,(char)uVar2);
    } while (cVar5 != '\0');
  }
  return;
}


/* ======== FUN_00010d4c @ 00010d4c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010d4c(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      pcVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *pcVar6 = cVar5;
        }
        pcVar6 = pcVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    unaff_ESI = unaff_ESI + _DAT_000523ab;
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (char *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010d7f @ 00010d7f ======== */

void FUN_00010d7f(int param_1,int unaff_EDX,ushort *unaff_EBX,int unaff_ECX)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar5;
  
  DAT_000523b7 = 0;
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0;
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  DAT_000523af = unaff_ECX;
  do {
    pcVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      DAT_000523b3 = DAT_000523b7;
      uVar2 = uVar4 & 0xff;
      pcVar9 = pcVar8;
      do {
        if ((DAT_000523af < DAT_000523b3) && (*(char *)puVar6 != '\0')) {
          *pcVar9 = *(char *)puVar6;
        }
        puVar6 = (ushort *)((int)puVar6 + 1);
        DAT_000523b3 = DAT_000523b3 + 4;
        pcVar9 = pcVar9 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      pcVar8 = pcVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    DAT_000523b7 = DAT_000523b7 + 1;
    cVar5 = (char)uVar3 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar2 >> 8) + -1;
    uVar3 = CONCAT11(cVar5,(char)uVar2);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00010e1b @ 00010e1b ======== */

void FUN_00010e1b(uint param_1,int unaff_EDX,ushort *unaff_EBX,int unaff_ECX)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar5;
  
  DAT_000523b7 = 0;
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0;
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  DAT_000523af = unaff_ECX;
  do {
    pcVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      DAT_000523b3 = DAT_000523b7;
      uVar2 = uVar4 & 0xff;
      pcVar9 = pcVar8;
      do {
        if ((DAT_000523b3 <= DAT_000523af) && (*(char *)puVar6 != '\0')) {
          *pcVar9 = *(char *)puVar6;
        }
        DAT_000523b3 = DAT_000523b3 + 4;
        puVar6 = (ushort *)((int)puVar6 + 1);
        pcVar9 = pcVar9 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      pcVar8 = pcVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar3 + '\x01';
    DAT_000523b7 = DAT_000523b7 + 1;
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar2 >> 8) + -1;
    uVar3 = CONCAT11(cVar5,(char)uVar2);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00010ef5 @ 00010ef5 ======== */

void FUN_00010ef5(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  char *pcVar6;
  char *unaff_EDI;
  char *pcVar7;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      pcVar6 = unaff_ESI;
      pcVar7 = unaff_EDI;
      do {
        cVar5 = *pcVar6;
        pcVar6 = pcVar6 + -1;
        if (cVar5 != '\0') {
          *pcVar7 = cVar5;
        }
        pcVar7 = pcVar7 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_ESI = unaff_ESI + (unaff_EBX & 0xff);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (char *)(unaff_retaddr + *(int *)(&DAT_00051ad6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010f26 @ 00010f26 ======== */

void FUN_00010f26(uint param_1,int unaff_EDX,ushort *unaff_EBX,undefined unaff_CL)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  char cVar5;
  
  uVar3 = CONCAT11(4,(byte)param_1 & 3);
  puVar7 = g_backBuffer + (param_1 >> 2) + *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0;
  puVar6 = unaff_EBX + 1;
  uVar1 = *unaff_EBX;
  DAT_00051b23 = unaff_CL;
  do {
    puVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      uVar2 = uVar4 & 0xff;
      puVar9 = puVar8;
      do {
        cVar5 = *(char *)puVar6;
        puVar6 = (ushort *)((int)puVar6 + 1);
        if (cVar5 != '\0') {
          *puVar9 = DAT_00051b23;
        }
        puVar9 = puVar9 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      puVar8 = puVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar3 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar2 = CONCAT11((char)(uVar3 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar2 >> 8) + -1;
    uVar3 = CONCAT11(cVar5,(char)uVar2);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00010f65 @ 00010f65 ======== */

void FUN_00010f65(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  undefined *unaff_EDI;
  undefined *puVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      puVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          *puVar6 = DAT_00051b23;
        }
        puVar6 = puVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (undefined *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00010f97 @ 00010f97 ======== */

void FUN_00010f97(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(&DAT_000a01e0 + param_1);
  puVar2 = (undefined4 *)(g_backBuffer + param_1 + 0x1e0);
  out(0x3c4,0x102);
  iVar1 = 0x13;
  puVar3 = puVar2;
  puVar4 = puVar5;
  do {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 0x14;
    puVar4 = puVar4 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar4 = puVar2 + 0x12c0;
  out(0x3c4,0x202);
  iVar1 = 0x13;
  puVar3 = puVar5;
  do {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 0x14;
    puVar3 = puVar3 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar4 = puVar2 + 0x2580;
  out(0x3c4,0x402);
  iVar1 = 0x13;
  puVar3 = puVar5;
  do {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 0x14;
    puVar3 = puVar3 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar2 = puVar2 + 0x3840;
  out(0x3c4,0x802);
  iVar1 = 0x13;
  do {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 0x14;
    puVar5 = puVar5 + 0x14;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


/* ======== FUN_00011049 @ 00011049 ======== */

void FUN_00011049(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)g_roomBuffer;
  puVar3 = (undefined4 *)g_backBuffer;
  for (iVar1 = 0x4b00; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


/* ======== FUN_0001105d @ 0001105d ======== */

void FUN_0001105d(uint param_1,int unaff_EDX)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(&DAT_00051b24 + unaff_EDX * 0x4c) + (param_1 & 0x7f) * 4 + 0x1e0;
  puVar3 = (undefined4 *)(g_backBuffer + iVar2);
  puVar1 = (undefined4 *)(g_roomBuffer + iVar2);
  iVar2 = 0x13;
  do {
    *puVar3 = *puVar1;
    puVar3[0x12c0] = puVar1[0x12c0];
    puVar3[0x2580] = puVar1[0x2580];
    puVar3[0x3840] = puVar1[0x3840];
    puVar1 = puVar1 + 0x14;
    puVar3 = puVar3 + 0x14;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* ======== FUN_000110c2 @ 000110c2 ======== */

uint FUN_000110c2(uint param_1,int unaff_EDX,char unaff_BL,undefined unaff_CL)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  char cVar6;
  
  uVar3 = 0x400;
  param_1 = param_1 >> 2;
  puVar9 = (undefined4 *)
           ((int)&DAT_000a0000 + *(int *)(&DAT_00051b24 + (unaff_EDX + 6) * 4) + param_1);
  puVar7 = g_backBuffer + *(int *)(&DAT_00051b24 + (unaff_EDX + 6) * 4) + param_1;
  uVar4 = (uint)CONCAT11(unaff_CL,(byte)(unaff_BL + 3U) >> 2);
  do {
    param_1 = CONCAT31(CONCAT21((short)(param_1 >> 0x10),'\x01' << (sbyte)uVar3),2);
    out(0x3c4,(short)param_1);
    puVar8 = (undefined4 *)(puVar7 + *(int *)(&DAT_00051ac6 + (uVar3 & 0xff) * 4));
    uVar1 = uVar4 & 0xff;
    uVar5 = uVar4;
    puVar10 = puVar9;
    do {
      for (uVar2 = uVar5 & 0xff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar10 = puVar10 + (0x14 - uVar1);
      puVar8 = puVar8 + (0x14 - uVar1);
      cVar6 = (char)(uVar5 >> 8) + -1;
      uVar5 = (uint)CONCAT11(cVar6,(char)uVar5);
    } while (cVar6 != '\0');
    cVar6 = (sbyte)uVar3 + 1;
    if (cVar6 == '\x04') {
      puVar7 = puVar7 + 1;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    uVar3 = CONCAT31((int3)(uVar3 >> 8),cVar6) & 0xffffff03;
    cVar6 = (char)(uVar3 >> 8) + -1;
    uVar3 = (uint)CONCAT11(cVar6,(char)uVar3);
  } while (cVar6 != '\0');
  return param_1;
}


/* ======== FUN_00011145 @ 00011145 ======== */

void FUN_00011145(uint param_1,int unaff_EDX,undefined unaff_BL,undefined unaff_CL)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  char cVar4;
  
  uVar2 = CONCAT11(4,(byte)param_1 & 3);
  iVar8 = *(int *)(&DAT_00051b24 + unaff_EDX * 4) + 0x1e0 + (param_1 >> 2);
  puVar9 = g_backBuffer + iVar8;
  puVar5 = g_roomBuffer + iVar8;
  do {
    iVar8 = (uVar2 & 0xff) * 4;
    puVar6 = puVar5 + *(int *)(&DAT_00051ac6 + iVar8);
    puVar10 = puVar9 + *(int *)(&DAT_00051ac6 + iVar8);
    uVar3 = CONCAT11(unaff_CL,unaff_BL);
    do {
      puVar7 = puVar6;
      puVar11 = puVar10;
      for (uVar1 = uVar3 & 0xff; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar11 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar11 = puVar11 + 1;
      }
      puVar10 = puVar10 + 0x50;
      puVar6 = puVar6 + 0x50;
      cVar4 = (char)(uVar3 >> 8) + -1;
      uVar3 = CONCAT11(cVar4,(char)uVar3);
    } while (cVar4 != '\0');
    cVar4 = (char)uVar2 + '\x01';
    if (cVar4 == '\x04') {
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    uVar1 = CONCAT11((char)(uVar2 >> 8),cVar4) & 0xffffff03;
    cVar4 = (char)(uVar1 >> 8) + -1;
    uVar2 = CONCAT11(cVar4,(char)uVar1);
  } while (cVar4 != '\0');
  return;
}


/* ======== FUN_00011186 @ 00011186 ======== */

void FUN_00011186(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  undefined *unaff_ESI;
  undefined *puVar7;
  undefined *unaff_EDI;
  undefined *puVar8;
  int unaff_retaddr;
  
  cVar5 = (char)((uint)unaff_EDX >> 8);
  bVar4 = (byte)unaff_EDX;
  while( true ) {
    do {
      puVar7 = unaff_ESI;
      puVar8 = unaff_EDI;
      for (uVar2 = unaff_EBX & 0xff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      unaff_EDI = unaff_EDI + 0x50;
      unaff_ESI = unaff_ESI + 0x50;
      cVar6 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar6,(char)unaff_EBX);
    } while (cVar6 != '\0');
    bVar3 = bVar4 + 1;
    if (bVar3 == 4) {
      unaff_retaddr = unaff_retaddr + 1;
      param_5 = param_5 + 1;
    }
    bVar4 = bVar3 & 3;
    cVar5 = cVar5 + -1;
    if (cVar5 == '\0') break;
    iVar1 = (bVar3 & 0xffffff03) * 4;
    unaff_ESI = (undefined *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + iVar1));
    unaff_EDI = (undefined *)(param_5 + *(int *)(&DAT_00051ac6 + iVar1));
    unaff_EBX = param_6;
  }
  return;
}


/* ======== FUN_000111ae @ 000111ae ======== */

void FUN_000111ae(void)

{
  byte bVar1;
  
  do {
    bVar1 = in(0x3da);
  } while ((bVar1 & 8) == 0);
  do {
    bVar1 = in(0x3da);
  } while ((bVar1 & 8) != 0);
  return;
}


/* ======== FUN_000111bd @ 000111bd ======== */

void FUN_000111bd(byte param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  char *pcVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  char cVar5;
  
  uVar2 = CONCAT11(4,(byte)DAT_0005238f & 3);
  puVar7 = PTR_DAT_00051b02 +
           (DAT_0005238f >> 2) + *(int *)(&DAT_00051b24 + DAT_00052393 * 4) + 0x1e0;
  pcVar6 = (char *)(DAT_000522a8 + 2 + DAT_000522a4 * (param_1 - 0x20));
  uVar1 = *(ushort *)(pcVar6 + -2);
  do {
    puVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar2 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      uVar3 = uVar4 & 0xff;
      puVar9 = puVar8;
      do {
        cVar5 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        if (cVar5 != '\0') {
          if (cVar5 == '\x01') {
            *puVar9 = DAT_000522ac;
          }
          else {
            *puVar9 = DAT_000522ad;
          }
        }
        puVar9 = puVar9 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      puVar8 = puVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar2 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar3 = CONCAT11((char)(uVar2 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar3 >> 8) + -1;
    uVar2 = CONCAT11(cVar5,(char)uVar3);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_00011217 @ 00011217 ======== */

void FUN_00011217(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  undefined *unaff_EDI;
  undefined *puVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      puVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 != '\0') {
          if (cVar5 == '\x01') {
            *puVar6 = DAT_000522ac;
          }
          else {
            *puVar6 = DAT_000522ad;
          }
        }
        puVar6 = puVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (undefined *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00011256 @ 00011256 ======== */

void FUN_00011256(byte param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  char *pcVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  char cVar5;
  
  uVar2 = CONCAT11(4,(byte)DAT_0005238f & 3);
  puVar7 = PTR_DAT_00051b02 +
           (DAT_0005238f >> 2) + *(int *)(&DAT_00051b24 + DAT_00052393 * 4) + 0x1e0;
  pcVar6 = (char *)(DAT_000522a8 + 2 + DAT_000522a4 * (param_1 - 0x20));
  uVar1 = *(ushort *)(pcVar6 + -2);
  do {
    puVar8 = puVar7 + *(int *)(&DAT_00051ac6 + (uVar2 & 0xff) * 4);
    uVar4 = uVar1;
    do {
      uVar3 = uVar4 & 0xff;
      puVar9 = puVar8;
      do {
        cVar5 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        if (cVar5 == '\0') {
          *puVar9 = DAT_000522ae;
        }
        else if (cVar5 == '\x01') {
          *puVar9 = DAT_000522ac;
        }
        else {
          *puVar9 = DAT_000522ad;
        }
        puVar9 = puVar9 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      puVar8 = puVar8 + 0x50;
      cVar5 = (char)(uVar4 >> 8) + -1;
      uVar4 = CONCAT11(cVar5,(char)uVar4);
    } while (cVar5 != '\0');
    cVar5 = (char)uVar2 + '\x01';
    if (cVar5 == '\x04') {
      puVar7 = (undefined *)CONCAT22((short)((uint)puVar7 >> 0x10),(short)puVar7 + 1);
    }
    uVar3 = CONCAT11((char)(uVar2 >> 8),cVar5) & 0xffffff03;
    cVar5 = (char)(uVar3 >> 8) + -1;
    uVar2 = CONCAT11(cVar5,(char)uVar3);
  } while (cVar5 != '\0');
  return;
}


/* ======== FUN_000112b0 @ 000112b0 ======== */

void FUN_000112b0(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 param_4,
                 uint param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char *unaff_ESI;
  undefined *unaff_EDI;
  undefined *puVar6;
  int unaff_retaddr;
  
  cVar4 = (char)((uint)unaff_EDX >> 8);
  bVar3 = (byte)unaff_EDX;
  while( true ) {
    do {
      uVar1 = unaff_EBX & 0xff;
      puVar6 = unaff_EDI;
      do {
        cVar5 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
        if (cVar5 == '\0') {
          *puVar6 = DAT_000522ae;
        }
        else if (cVar5 == '\x01') {
          *puVar6 = DAT_000522ac;
        }
        else {
          *puVar6 = DAT_000522ad;
        }
        puVar6 = puVar6 + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      unaff_EDI = unaff_EDI + 0x50;
      cVar5 = (char)(unaff_EBX >> 8) + -1;
      unaff_EBX = (uint)CONCAT11(cVar5,(char)unaff_EBX);
    } while (cVar5 != '\0');
    bVar2 = bVar3 + 1;
    if (bVar2 == 4) {
      unaff_retaddr = CONCAT22((short)((uint)unaff_retaddr >> 0x10),(short)unaff_retaddr + 1);
    }
    bVar3 = bVar2 & 3;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') break;
    unaff_EDI = (undefined *)(unaff_retaddr + *(int *)(&DAT_00051ac6 + (bVar2 & 0xffffff03) * 4));
    unaff_EBX = param_5;
  }
  return;
}


/* ======== FUN_00011300 @ 00011300 ======== */

undefined8 FUN_00011300(uint param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,param_1 >> 1 & 0x1ffff | param_1 & 0xc0000);
}


/* ======== FUN_0001133c @ 0001133c ======== */

void FUN_0001133c(undefined param_1,undefined unaff_DL)

{
  DAT_000661d0 = param_1;
  FUN_00033e1b(DAT_000661bc + 0x103,param_1);
  FUN_00033e1b(DAT_000661bc + 0x105,unaff_DL);
  return;
}


/* ======== FUN_0001138c @ 0001138c ======== */

void FUN_0001138c(undefined param_1,undefined2 unaff_DX)

{
  DAT_000661d0 = param_1;
  FUN_00033e1b(DAT_000661bc + 0x103,param_1);
  FUN_00033e25(DAT_000661bc + 0x104,unaff_DX);
  return;
}


/* ======== FUN_000113dc @ 000113dc ======== */

undefined8 FUN_000113dc(undefined param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  DAT_000661d0 = param_1;
  FUN_00033e1b(DAT_000661bc + 0x103,param_1);
  uVar1 = FUN_00033e30(DAT_000661bc + 0x105);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_0001142c @ 0001142c ======== */

undefined8 FUN_0001142c(undefined param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  DAT_000661d0 = param_1;
  FUN_00033e1b(DAT_000661bc + 0x103,param_1);
  uVar1 = FUN_00033e38(DAT_000661bc + 0x104);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_0001147c @ 0001147c ======== */

void FUN_0001147c(void)

{
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  FUN_00033e30(DAT_000661bc + 0x107);
  return;
}


/* ======== FUN_00011508 @ 00011508 ======== */

undefined8 FUN_00011508(uint param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  FUN_0001138c(0x43,param_1 & 0xffff);
  FUN_0001133c(0x44,param_1 >> 0x10 & 0xff);
  uVar1 = FUN_00033e30(DAT_000661bc + 0x107);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00011560 @ 00011560 ======== */

void FUN_00011560(uint param_1,undefined unaff_DL)

{
  FUN_0001138c(0x43,param_1 & 0xffff);
  FUN_0001133c(0x44,param_1 >> 0x10 & 0xff);
  FUN_00033e1b(DAT_000661bc + 0x107,unaff_DL);
  return;
}


/* ======== FUN_000115b4 @ 000115b4 ======== */

undefined * FUN_000115b4(undefined *param_1,undefined *unaff_EDX,int unaff_EBX)

{
  undefined *puVar1;
  undefined *local_1c;
  
  puVar1 = param_1;
  if (unaff_EBX != 0) {
    DAT_000661d0 = 0x44;
    FUN_00033e1b(DAT_000661bc + 0x103,0x44);
    FUN_00033e1b(DAT_000661bc + 0x105,(uint)param_1 >> 0x10 & 0xff);
    DAT_000661d0 = 0x43;
    puVar1 = (undefined *)FUN_00033e1b(DAT_000661bc + 0x103,0x43);
    local_1c = param_1;
    while (unaff_EBX = unaff_EBX + -1, unaff_EBX != -1) {
      FUN_00033e25(DAT_000661bc + 0x104,local_1c);
      FUN_00033e1b(DAT_000661bc + 0x107,*unaff_EDX);
      local_1c = local_1c + 1;
      puVar1 = unaff_EDX;
      unaff_EDX = unaff_EDX + 1;
    }
  }
  return puVar1;
}


/* ======== FUN_00011678 @ 00011678 ======== */

void FUN_00011678(uint param_1,int unaff_EDX,uint unaff_EBX)

{
  uint local_24;
  uint local_20;
  uint local_1c;
  
  local_20 = 0x10000 - (param_1 & 0xffff);
  local_1c = param_1;
  if (unaff_EBX < local_20) {
    local_20 = unaff_EBX;
  }
  do {
    FUN_000115b4(local_1c,unaff_EDX,local_20);
    local_1c = local_1c + local_20;
    unaff_EDX = unaff_EDX + local_20;
    unaff_EBX = unaff_EBX - local_20;
    local_24 = unaff_EBX;
    if (0xffff < unaff_EBX) {
      local_24 = 0x10000;
    }
    local_20 = local_24;
  } while (local_24 != 0);
  return;
}


/* ======== FUN_000116f8 @ 000116f8 ======== */

undefined8 FUN_000116f8(int param_1,undefined4 unaff_EDX)

{
  undefined uVar1;
  undefined4 local_24;
  undefined4 *local_20;
  int local_1c;
  
  local_20 = &local_24;
  local_1c = param_1;
  uVar1 = FUN_00011508(param_1);
  *(undefined *)local_20 = uVar1;
  uVar1 = FUN_00011508(local_1c + 1);
  *(undefined *)((int)local_20 + 1) = uVar1;
  uVar1 = FUN_00011508(local_1c + 2);
  *(undefined *)((int)local_20 + 2) = uVar1;
  uVar1 = FUN_00011508(local_1c + 3);
  *(undefined *)((int)local_20 + 3) = uVar1;
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00011768 @ 00011768 ======== */

void FUN_00011768(undefined4 param_1)

{
  FUN_00011678(param_1,&stack0xffffffe8,4);
  return;
}


/* ======== FUN_00011794 @ 00011794 ======== */

void FUN_00011794(void)

{
  DAT_000661c1 = DAT_000661c1 & 0xfd;
  FUN_00033e1b(DAT_000661bc,DAT_000661c1);
  return;
}


/* ======== FUN_000117c4 @ 000117c4 ======== */

void FUN_000117c4(void)

{
  DAT_000661c1 = DAT_000661c1 | 2;
  FUN_00033e1b(DAT_000661bc,DAT_000661c1);
  return;
}


/* ======== FUN_000117f4 @ 000117f4 ======== */

void FUN_000117f4(void)

{
  DAT_000661c1 = DAT_000661c1 | 1;
  FUN_00033e1b(DAT_000661bc,DAT_000661c1);
  return;
}


/* ======== FUN_00011824 @ 00011824 ======== */

void FUN_00011824(void)

{
  DAT_000661c1 = DAT_000661c1 & 0xfb;
  FUN_00033e1b(DAT_000661bc,DAT_000661c1);
  return;
}


/* ======== FUN_00011854 @ 00011854 ======== */

void FUN_00011854(int param_1)

{
  int iVar1;
  int local_20;
  int local_1c;
  
  local_1c = param_1;
  if (param_1 < 0xe) {
    local_1c = 0xe;
  }
  if (0x20 < local_1c) {
    local_1c = 0x20;
  }
  DAT_000661be = (char)local_1c;
  DAT_000661bf = 0;
  DAT_000661c0 = 0;
  FUN_00011768(0,0);
  iVar1 = FUN_0001133c(0x4c,0);
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    FUN_0001147c(iVar1);
    iVar1 = local_20;
  }
  iVar1 = FUN_0001133c(0x4c,1);
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    FUN_0001147c(iVar1);
    iVar1 = local_20;
  }
  iVar1 = FUN_00033e1b(DAT_000661bc + 0x100,3);
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    FUN_0001147c(iVar1);
    iVar1 = local_20;
  }
  FUN_00033e1b(DAT_000661bc + 0x100,0);
  FUN_0001133c(0x41,0);
  FUN_0001133c(0x45,0);
  FUN_0001133c(0x49,0);
  FUN_0001133c(0xe,(char)local_1c - 1U | 0xc0);
  FUN_00033e30(DAT_000661bc + 6);
  FUN_000113dc(0x41);
  FUN_000113dc(0x49);
  FUN_000113dc(0x8f);
  for (local_20 = 0; local_20 < local_1c; local_20 = local_20 + 1) {
    FUN_00033e1b(DAT_000661bc + 0x102,local_20);
    FUN_0001133c(0,3);
    FUN_0001133c(0xd,3);
    FUN_0001147c();
    FUN_0001138c(1,0x400);
    FUN_0001138c(2,0);
    FUN_0001138c(3,0);
    FUN_0001138c(4,0);
    FUN_0001138c(5,0);
    FUN_0001133c(6,1);
    FUN_0001133c(7,0x10);
    FUN_0001133c(8,0xe0);
    FUN_0001138c(9,0);
    FUN_0001138c(10,0);
    FUN_0001138c(0xb,0);
  }
  FUN_00033e30(DAT_000661bc + 6);
  FUN_000113dc(0x41);
  FUN_000113dc(0x49);
  FUN_000113dc(0x8f);
  FUN_0001133c(0x4c,7);
  return;
}


/* ======== FUN_00011ac4 @ 00011ac4 ======== */

undefined8 FUN_00011ac4(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined uVar1;
  undefined uVar2;
  char cVar3;
  char cVar4;
  undefined4 local_2c;
  
  FUN_0001133c(0x4c,0);
  FUN_0001147c();
  FUN_0001147c();
  FUN_0001133c(0x4c,1);
  FUN_0001147c();
  FUN_0001147c();
  uVar1 = FUN_00011508(0);
  uVar2 = FUN_00011508(1);
  FUN_00011560(0,0xaa);
  cVar3 = FUN_00011508(0);
  FUN_00011560(1,0x55);
  cVar4 = FUN_00011508(1);
  FUN_00011560(0,uVar1);
  FUN_00011560(1,uVar2);
  if ((cVar3 == -0x56) && (cVar4 == 'U')) {
    local_2c = 1;
  }
  else {
    local_2c = 0;
  }
  return CONCAT44(unaff_EDX,local_2c);
}


/* ======== FUN_00011b9c @ 00011b9c ======== */

undefined8 FUN_00011b9c(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_20;
  
  iVar1 = FUN_00033e41(s_ULTRASND_00059544);
  if (iVar1 == 0) {
    local_20 = 0;
  }
  else {
    iVar1 = FUN_00033ef6();
    if (iVar1 == 5) {
      local_20 = FUN_00011ac4();
    }
    else {
      local_20 = 0;
    }
  }
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00011c18 @ 00011c18 ======== */

void FUN_00011c18(int param_1,int unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  byte bVar1;
  byte local_28;
  byte local_24;
  
  bVar1 = DAT_000661c1;
  if ((unaff_EBX == unaff_ECX) && (unaff_EBX != 0)) {
    local_28 = (&DAT_000523c4)[unaff_EBX] | 0x40;
  }
  else {
    local_28 = (&DAT_000523c4)[unaff_EBX] | (&DAT_000523c4)[unaff_ECX] << 3;
  }
  if ((param_1 == unaff_EDX) && (param_1 != 0)) {
    local_24 = (&DAT_000523bc)[param_1] | 0x40;
  }
  else {
    local_24 = (&DAT_000523bc)[param_1] | (&DAT_000523bc)[unaff_EDX] << 3;
  }
  FUN_00033e1b(DAT_000661bc + 0xf,5);
  FUN_00033e1b(DAT_000661bc,bVar1);
  FUN_00033e1b(DAT_000661bc + 0xb,0);
  FUN_00033e1b(DAT_000661bc + 0xf,0);
  FUN_00033e1b(DAT_000661bc,bVar1);
  FUN_00033e1b(DAT_000661bc + 0xb,local_24 | 0x80);
  FUN_00033e1b(DAT_000661bc,bVar1 | 0x40);
  FUN_00033e1b(DAT_000661bc + 0xb,local_28);
  FUN_00033e1b(DAT_000661bc,bVar1);
  FUN_00033e1b(DAT_000661bc + 0xb,local_24);
  FUN_00033e1b(DAT_000661bc,bVar1 | 0x40);
  FUN_00033e1b(DAT_000661bc + 0xb,local_28);
  FUN_00033e1b(DAT_000661bc + 0x102,0);
  FUN_00033e1b(DAT_000661bc,bVar1 | 9);
  FUN_00033e1b(DAT_000661bc + 0x102,0);
  DAT_000661c1 = bVar1 | 9;
  return;
}


/* ======== FUN_00011de4 @ 00011de4 ======== */

undefined8 FUN_00011de4(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined uVar1;
  char cVar2;
  uint local_28;
  
  uVar1 = FUN_00011508(param_1);
  FUN_00011560(param_1,0xaa);
  cVar2 = FUN_00011508(param_1);
  FUN_00011560(param_1,uVar1);
  local_28 = (uint)(cVar2 == -0x56);
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_00011e50 @ 00011e50 ======== */

undefined8 FUN_00011e50(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_1c;
  
  iVar1 = FUN_00011de4(0);
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    iVar1 = FUN_00011de4(0x40000);
    if (iVar1 == 0) {
      local_1c = 0x100;
    }
    else {
      iVar1 = FUN_00011de4(0x80000);
      if (iVar1 == 0) {
        local_1c = 0x200;
      }
      else {
        iVar1 = FUN_00011de4(0xc0000);
        if (iVar1 == 0) {
          local_1c = 0x300;
        }
        else {
          local_1c = 0x400;
        }
      }
    }
  }
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00011ec8 @ 00011ec8 ======== */

undefined4 FUN_00011ec8(int param_1,int unaff_EDX)

{
  int iVar1;
  undefined4 local_20;
  
  if (((param_1 == 0) || (unaff_EDX == 0)) ||
     (iVar1 = FUN_000116f8(param_1), iVar1 + param_1 != unaff_EDX)) {
    local_20 = 0;
  }
  else {
    local_20 = 1;
  }
  return local_20;
}


/* ======== FUN_00011f1c @ 00011f1c ======== */

int FUN_00011f1c(int param_1,int unaff_EDX)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_000116f8(param_1);
  uVar2 = FUN_000116f8(unaff_EDX,uVar1);
  FUN_00011768(param_1,(int)((ulonglong)uVar2 >> 0x20) + (int)uVar2);
  uVar1 = FUN_000116f8(unaff_EDX + 4);
  FUN_00011768(param_1 + 4,uVar1);
  return param_1;
}


/* ======== FUN_00011f74 @ 00011f74 ======== */

void FUN_00011f74(int param_1,uint unaff_EDX)

{
  uint uVar1;
  int iVar2;
  uint local_24;
  uint local_20;
  
  local_24 = 0;
  local_20 = DAT_000661cc;
  if (param_1 != 0) {
    FUN_00011768(unaff_EDX,param_1 + 0x1fU & 0xffffffe0);
    for (; (local_20 != 0 && (local_20 <= unaff_EDX)); local_20 = FUN_000116f8(local_20 + 4)) {
      local_24 = local_20;
    }
    uVar1 = unaff_EDX;
    if (local_24 != 0) {
      FUN_00011768(local_24 + 4,unaff_EDX);
      uVar1 = DAT_000661cc;
    }
    DAT_000661cc = uVar1;
    FUN_00011768(unaff_EDX + 4,local_20);
    iVar2 = FUN_00011ec8(local_24,unaff_EDX);
    if (iVar2 != 0) {
      unaff_EDX = FUN_00011f1c(local_24,unaff_EDX);
    }
    iVar2 = FUN_00011ec8(unaff_EDX,local_20);
    if (iVar2 != 0) {
      FUN_00011f1c(unaff_EDX,local_20);
    }
  }
  return;
}


/* ======== FUN_00012044 @ 00012044 ======== */

/* WARNING: Removing unreachable block (ram,0x000120e6) */

undefined8 FUN_00012044(int param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_38;
  int local_34;
  int local_20;
  
  local_34 = DAT_000661cc;
  if (param_1 == 0) {
    local_38 = 0;
  }
  else {
    uVar1 = param_1 + 0x1fU & 0xffffffe0;
    local_20 = local_34;
    do {
      local_34 = local_20;
      if (local_34 == 0) {
        local_38 = 0;
        goto LAB_00012123;
      }
      local_20 = FUN_000116f8(local_34 + 4);
      uVar2 = FUN_000116f8(local_34);
    } while (uVar2 < uVar1);
    iVar3 = local_34 + uVar1;
    if (7 < uVar2 - uVar1) {
      FUN_00011768(iVar3,uVar2 - uVar1);
      FUN_00011768(iVar3 + 4,local_20);
      local_20 = iVar3;
    }
    DAT_000661cc = local_20;
    FUN_00011768(local_34,uVar1);
    local_38 = local_34;
  }
LAB_00012123:
  return CONCAT44(unaff_EDX,local_38);
}


/* ======== FUN_00012130 @ 00012130 ======== */

undefined8 FUN_00012130(uint param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_2c;
  uint local_28;
  
  if (param_1 < 0x40001) {
    uVar1 = param_1 + 0x1f & 0xffffffe0;
    local_28 = FUN_00012044(uVar1);
    uVar2 = (local_28 + uVar1) - 1 >> 0x12;
    if ((local_28 != 0) && (local_28 >> 0x12 != uVar2)) {
      iVar3 = local_28 + uVar1 + uVar2 * -0x40000;
      FUN_00011f74(iVar3,uVar2 << 0x12);
      uVar2 = FUN_00012130(uVar1);
      FUN_00011f74(uVar1 - iVar3,local_28);
      local_28 = uVar2;
    }
    local_2c = local_28;
  }
  else {
    local_2c = 0;
  }
  return CONCAT44(unaff_EDX,local_2c);
}


/* ======== FUN_000121e0 @ 000121e0 ======== */

void FUN_000121e0(void)

{
  uint uVar1;
  
  DAT_000661cc = 0x20;
  uVar1 = FUN_00011e50();
  FUN_00011768(DAT_000661cc,(uVar1 & 0xffff) * 0x400 + -0x20);
  FUN_00011768(DAT_000661cc + 4,0);
  return;
}


/* ======== FUN_0001222c @ 0001222c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001222c(undefined4 param_1)

{
  FUN_000117f4();
  FUN_00011824();
  FUN_000117c4();
  FUN_00011854(param_1);
  FUN_00011c18(DAT_000661c2,DAT_000661c4,_DAT_000661c6,DAT_000661c8);
  return;
}


/* ======== FUN_00012364 @ 00012364 ======== */

undefined8 FUN_00012364(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = DAT_000661d4;
  DAT_000661d4 = param_1;
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00012398 @ 00012398 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012398(undefined4 param_1)

{
  undefined2 extraout_var;
  undefined2 in_CS;
  undefined6 uVar1;
  
  DAT_000661c1 = 0xb;
  DAT_000661d4 = 0;
  DAT_000661d8 = 0;
  FUN_000117f4();
  FUN_00011824();
  FUN_000117c4();
  FUN_00011854(param_1);
  FUN_00011c18(DAT_000661c2,DAT_000661c4,_DAT_000661c6,DAT_000661c8);
  FUN_000121e0();
  uVar1 = FUN_00015bf0(DAT_000661c6,DAT_000661c6,&LAB_0001227c,CONCAT22(extraout_var,in_CS));
  DAT_000661e0 = (undefined2)((uint6)uVar1 >> 0x20);
  DAT_000661dc = (undefined4)uVar1;
  FUN_00015ab0(DAT_000661c6,1);
  return;
}


/* ======== FUN_00012448 @ 00012448 ======== */

void FUN_00012448(void)

{
  FUN_00015ab0(DAT_000661c6,0);
  FUN_00015bf0(DAT_000661c6,DAT_000661c6,DAT_000661dc,DAT_000661e0);
  FUN_000117c4();
  FUN_000117f4();
  FUN_00011824();
  FUN_00011854(0xe);
  return;
}


/* ======== FUN_000124a4 @ 000124a4 ======== */

void FUN_000124a4(undefined param_1)

{
  FUN_00033e1b(DAT_000661bc + 0x102,param_1);
  return;
}


/* ======== FUN_000124d4 @ 000124d4 ======== */

void FUN_000124d4(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((int)&DAT_000523b7 + (uint)DAT_000661be * 2 + 1);
  FUN_0001138c(1,(((uint)(uVar1 >> 1) + param_1 * 0x200) / (uint)uVar1) * 2 & 0xffff);
  return;
}


/* ======== FUN_00012528 @ 00012528 ======== */

byte FUN_00012528(uint param_1,uint unaff_EDX,uint unaff_EBX,byte unaff_CL)

{
  byte bVar1;
  uint local_30;
  uint local_2c;
  uint local_28;
  byte local_10;
  
  local_2c = unaff_EDX;
  local_30 = unaff_EBX;
  local_10 = unaff_CL;
  if (unaff_EBX < unaff_EDX) {
    local_10 = unaff_CL | 0x40;
    local_2c = unaff_EBX;
    local_30 = unaff_EDX;
  }
  local_28 = param_1;
  if ((local_10 & 4) != 0) {
    local_28 = FUN_00011300(param_1);
    local_2c = FUN_00011300(local_2c);
    local_30 = FUN_00011300(local_30);
  }
  bVar1 = FUN_000113dc(0x8d);
  FUN_0001133c(0xd,bVar1 & 0xfb);
  FUN_0001147c();
  FUN_0001133c(0xd,bVar1 & 0xfb);
  FUN_0001138c(0xb,(local_28 & 0x7f) << 9);
  FUN_0001138c(10,local_28 >> 7 & 0x1fff);
  FUN_0001138c(2,local_2c >> 7 & 0x1fff);
  FUN_0001138c(3,(local_2c & 0x7f) << 9);
  FUN_0001138c(4,local_30 >> 7 & 0x1fff);
  FUN_0001138c(5,(local_30 & 0x7f) << 9);
  return local_10;
}


/* ======== FUN_00012668 @ 00012668 ======== */

void FUN_00012668(byte param_1)

{
  FUN_0001133c(0,param_1 & 0xfc);
  FUN_0001147c();
  FUN_0001133c(0,param_1 & 0xfc);
  return;
}


/* ======== FUN_000126a0 @ 000126a0 ======== */

void FUN_000126a0(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined unaff_CL)

{
  undefined uVar1;
  
  uVar1 = FUN_00012528(param_1,unaff_EDX,unaff_EBX,unaff_CL);
  FUN_00012668(uVar1);
  return;
}


/* ======== FUN_000126dc @ 000126dc ======== */

void FUN_000126dc(void)

{
  byte bVar1;
  
  bVar1 = FUN_000113dc(0x8d);
  FUN_0001133c(0xd,bVar1 & 0xfb);
  FUN_0001147c();
  FUN_0001133c(0xd,bVar1 & 0xfb);
  bVar1 = FUN_000113dc(0x80);
  bVar1 = bVar1 & 0xdf | 3;
  FUN_0001133c(0,bVar1);
  FUN_0001147c();
  FUN_0001133c(0,bVar1);
  return;
}


/* ======== FUN_00012754 @ 00012754 ======== */

void FUN_00012754(uint param_1)

{
  FUN_0001138c(9,(param_1 & 0xfff) << 4);
  return;
}


/* ======== FUN_00012780 @ 00012780 ======== */

undefined8 FUN_00012780(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  
  uVar1 = FUN_0001142c(0x89);
  return CONCAT44(unaff_EDX,(int)(uVar1 & 0xffff) >> 4);
}


/* ======== FUN_000127ac @ 000127ac ======== */

void FUN_000127ac(void)

{
  byte bVar1;
  
  bVar1 = FUN_000113dc(0x8d);
  FUN_0001133c(0xd,bVar1 | 3);
  FUN_0001147c();
  FUN_0001133c(0xd,bVar1 | 3);
  return;
}


/* ======== FUN_000127f4 @ 000127f4 ======== */

void FUN_000127f4(ushort param_1,ushort unaff_DX,undefined unaff_BL,byte unaff_CL)

{
  ushort uVar1;
  byte bVar2;
  byte local_10;
  
  if (param_1 != unaff_DX) {
    local_10 = unaff_CL & 0x78;
    uVar1 = param_1;
    if (unaff_DX < param_1) {
      local_10 = local_10 | 0x40;
      uVar1 = unaff_DX;
      unaff_DX = param_1;
    }
    if (uVar1 < 0x40) {
      uVar1 = 0x40;
    }
    if (0xfc0 < unaff_DX) {
      unaff_DX = 0xfc0;
    }
    FUN_0001133c(6,unaff_BL);
    FUN_0001133c(7,(int)(uint)uVar1 >> 4 & 0xff);
    FUN_0001133c(8,(int)(uint)unaff_DX >> 4 & 0xff);
    FUN_00012754(param_1);
    bVar2 = FUN_000113dc(0x8d);
    if ((bVar2 & 4) != 0) {
      local_10 = local_10 | 4;
    }
    FUN_0001133c(0xd,local_10);
    FUN_0001147c();
    FUN_0001133c(0xd,local_10);
  }
  return;
}


/* ======== FUN_000128d8 @ 000128d8 ======== */

void FUN_000128d8(uint param_1,undefined unaff_DL,undefined unaff_BL)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_000127ac();
  iVar1 = (param_1 & 0xffff) * 2;
  uVar2 = FUN_00012780(iVar1,*(undefined2 *)(&DAT_00052420 + iVar1),unaff_DL,unaff_BL);
  FUN_000127f4(uVar2);
  return;
}


/* ======== FUN_0001291c @ 0001291c ======== */

void FUN_0001291c(char param_1,char unaff_DL)

{
  undefined local_20;
  
  if (param_1 == '\x01') {
    DAT_000661bf = DAT_000661bf | 4;
    DAT_000661c0 = DAT_000661c0 | 1;
    local_20 = 0x46;
  }
  else {
    DAT_000661bf = DAT_000661bf | 8;
    DAT_000661c0 = DAT_000661c0 | 2;
    local_20 = 0x47;
  }
  FUN_0001133c(local_20,-unaff_DL);
  FUN_0001133c(0x45,DAT_000661bf);
  FUN_00033e1b(DAT_000661bc + 8,4);
  FUN_00033e1b(DAT_000661bc + 9,DAT_000661c0);
  return;
}


/* ======== FUN_000129b4 @ 000129b4 ======== */

void FUN_000129b4(int param_1)

{
  if (param_1 == 1) {
    DAT_000661bf = DAT_000661bf & 0xfb;
    DAT_000661c0 = DAT_000661c0 & 0xfe;
  }
  else {
    DAT_000661bf = DAT_000661bf & 0xf7;
    DAT_000661c0 = DAT_000661c0 & 0xfd;
  }
  FUN_0001133c(0x45,DAT_000661bf);
  FUN_00033e1b(DAT_000661bc + 8,4);
  FUN_00033e1b(DAT_000661bc + 9,DAT_000661c0 | 0x80);
  return;
}


/* ======== FUN_00012a30 @ 00012a30 ======== */

void FUN_00012a30(byte param_1)

{
  uint local_20;
  
  DAT_00066964 = '\0';
  DAT_00066965 = 0;
  local_20 = (uint)(0x7a12 / (ulonglong)(longlong)(int)(uint)param_1);
  while (0xff < (ushort)local_20) {
    DAT_00066964 = DAT_00066964 + '\x01';
    local_20 = (uint)((ushort)local_20 >> 1);
  }
  FUN_0001291c(1,local_20 & 0xff);
  return;
}


/* ======== FUN_00012a94 @ 00012a94 ======== */

void FUN_00012a94(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uStack_54;
  uint uStack_50;
  uint uStack_48;
  int local_44;
  int local_3c;
  int local_34;
  int local_30;
  byte local_1c;
  
  uVar2 = 0;
  if (DAT_00066965 < DAT_00066964) {
    DAT_00066965 = DAT_00066965 + 1;
  }
  else {
    DAT_00066965 = '\0';
    (*(code *)PTR_FUN_00052ad4)();
    if (DAT_00066966 != DAT_00052ad0) {
      FUN_00012a30(DAT_00052ad0);
      DAT_00066966 = DAT_00052ad0;
    }
    for (local_1c = 0; local_1c < DAT_000669dc; local_1c = local_1c + 1) {
      FUN_000124a4(local_1c);
      if ((&DAT_000665e4)[(uint)local_1c * 0x1c] != '\0') {
        uVar3 = FUN_00012780();
        if (uVar2 <= uVar3) {
          uVar2 = uVar3;
        }
        FUN_000128d8(0,0x3f,0);
      }
    }
    for (local_1c = 0; local_1c < DAT_000669dc; local_1c = local_1c + 1) {
      FUN_000124a4(local_1c);
      iVar4 = (uint)local_1c * 0x1c;
      if ((&DAT_000665e4)[iVar4] == '\0') {
        FUN_000124d4(*(undefined4 *)(&DAT_000665fa + iVar4));
        FUN_000128d8((uint)(byte)(&DAT_000665fe)[iVar4] * 6,0x3f,0);
      }
      else {
        (&DAT_000665e4)[iVar4] = '\0';
        iVar1 = *(int *)(&DAT_000661e4 + *(short *)(&DAT_000665e8 + iVar4) * 4);
        local_34 = *(int *)(&DAT_000665ea + iVar4);
        local_30 = *(int *)(&DAT_000665f2 + iVar4);
        local_3c = *(int *)(&DAT_000665f6 + iVar4);
        local_44 = *(int *)(&DAT_000665ee + iVar4);
        if (((&DAT_000665e6)[iVar4] & 1) != 0) {
          local_34 = local_34 << 1;
          local_30 = local_30 << 1;
          local_3c = local_3c << 1;
          local_44 = local_44 << 1;
        }
        FUN_000126dc();
        FUN_000124d4(*(undefined4 *)(&DAT_000665fa + iVar4));
        FUN_000128d8((uint)(byte)(&DAT_000665fe)[iVar4] * 6,0x3f,0);
        if (((&DAT_000665e6)[iVar4] & 0x10) == 0) {
          if (((&DAT_000665e6)[iVar4] & 1) == 0) {
            uStack_54 = 0;
          }
          else {
            uStack_54 = 4;
          }
          FUN_000126a0(iVar1 + local_34,iVar1 + local_34,iVar1 + local_44 + 2,uStack_54);
        }
        else {
          if (((&DAT_000665e6)[iVar4] & 1) == 0) {
            uStack_48 = 0;
          }
          else {
            uStack_48 = 4;
          }
          if (((&DAT_000665e6)[iVar4] & 0x20) == 0) {
            uStack_50 = 0;
          }
          else {
            uStack_50 = 0x10;
          }
          FUN_000126a0(iVar1 + local_34,iVar1 + local_30,iVar1 + local_3c,uStack_48 | 8 | uStack_50)
          ;
        }
      }
    }
  }
  return;
}


/* ======== FUN_00012cf4 @ 00012cf4 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00012cf4(undefined4 param_1,uint unaff_EDX,int unaff_EBX,int unaff_ECX,ushort param_5)

{
  undefined uVar1;
  int extraout_EDX;
  int iVar2;
  int extraout_EDX_00;
  int local_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  local_34 = param_5 | 2;
  FUN_000152b8(param_1,param_5,local_34);
  for (local_20 = 0; (local_20 < 0x80 && (*(int *)(&DAT_000661e4 + local_20 * 4) != 0));
      local_20 = local_20 + 1) {
  }
  if (local_20 == 0x80) {
    _DAT_00067358 = PTR_s_Wyczerpane_uchwyty_sampli_00052b10;
    local_24 = -1;
  }
  else {
    if ((param_5 & 1) != 0) {
      unaff_EDX = unaff_EDX << 1;
      unaff_EBX = unaff_EBX << 1;
      unaff_ECX = unaff_ECX << 1;
    }
    if ((param_5 & 1) == 0) {
      local_28 = FUN_00012044(unaff_EDX + 8);
    }
    else {
      local_28 = FUN_00012130(unaff_EDX + 8);
    }
    *(undefined4 *)(&DAT_000661e4 + local_20 * 4) = local_28;
    if (*(int *)(&DAT_000661e4 + local_20 * 4) == 0) {
      _DAT_00067358 = PTR_s_Instrument_za_duzy_00052b14;
      local_24 = -1;
    }
    else {
      iVar2 = local_20 * 4;
      *(uint *)(&DAT_000663e4 + iVar2) = unaff_EDX + 8;
      local_2c = *(int *)(&DAT_000661e4 + local_20 * 4);
      for (local_30 = unaff_EDX; 0 < (int)local_30; local_30 = local_30 - local_34) {
        if ((int)local_30 < 0x401) {
          local_34 = local_30;
        }
        else {
          local_34 = 0x400;
        }
        FUN_00015310(&DAT_00065dbc,local_34);
        FUN_00011678(local_2c,&DAT_00065dbc);
        local_2c = local_2c + local_34;
        iVar2 = extraout_EDX;
      }
      if (((param_5 & 0x10) == 0) || ((param_5 & 0x20) != 0)) {
        for (local_3c = 0; local_3c < 8; local_3c = local_3c + 1) {
          FUN_00011560(*(int *)(&DAT_000661e4 + local_20 * 4) + unaff_EDX + local_3c,0);
        }
      }
      else {
        for (local_3c = 0; local_3c < 8; local_3c = local_3c + 1) {
          uVar1 = FUN_00011508(*(int *)(&DAT_000661e4 + local_20 * 4) + unaff_EBX + local_3c,iVar2,
                               local_34);
          FUN_00011560(*(int *)(&DAT_000661e4 + local_20 * 4) + unaff_ECX + local_3c,uVar1);
          iVar2 = extraout_EDX_00;
        }
      }
      local_24 = local_20;
    }
  }
  return local_24;
}


/* ======== FUN_00012ef8 @ 00012ef8 ======== */

void FUN_00012ef8(short param_1)

{
  FUN_00011f74(*(undefined4 *)(&DAT_000663e4 + param_1 * 4),
               *(undefined4 *)(&DAT_000661e4 + param_1 * 4));
  *(undefined4 *)(&DAT_000661e4 + param_1 * 4) = 0;
  return;
}


/* ======== FUN_00012f4c @ 00012f4c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00012f4c(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint local_28;
  
  if ((DAT_000669da & 2) == 0) {
    DAT_000669da = DAT_000669da | 2;
  }
  if ((DAT_000669da & 1) == 0) {
    DAT_000669da = DAT_000669da | 1;
  }
  iVar1 = FUN_00011b9c();
  if (iVar1 != 0) {
    FUN_00012398(0x20);
    FUN_00012364(FUN_00012a94);
    FUN_00033e1b(DAT_000661bc + 0x102,0);
    FUN_0001133c(0xc,4);
    FUN_00033e1b(DAT_000661bc + 0x102,3);
    FUN_0001133c(0xc,4);
    FUN_00033e1b(DAT_000661bc + 0x102,1);
    FUN_0001133c(0xc,0xc);
    FUN_00033e1b(DAT_000661bc + 0x102,2);
    FUN_0001133c(0xc,0xc);
  }
  else {
    _DAT_00067358 = s_Couldn_t_detect_gus__please_chec_00059561;
  }
  local_28 = (uint)(iVar1 != 0);
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_00013050 @ 00013050 ======== */

void FUN_00013050(void)

{
  FUN_00012448();
  return;
}


/* ======== FUN_0001306c @ 0001306c ======== */

void FUN_0001306c(void)

{
  undefined local_20;
  uint local_1c;
  
  for (local_1c = 0; (int)local_1c < (int)(uint)DAT_000669dc; local_1c = local_1c + 1) {
    *(undefined2 *)(&DAT_000665e6 + local_1c * 0x1c) = 0;
    *(undefined2 *)(&DAT_000665e8 + local_1c * 0x1c) = 0;
    (&DAT_000665e4)[local_1c * 0x1c] = 0;
    (&DAT_000665e5)[local_1c * 0x1c] = 0;
    *(undefined4 *)(&DAT_000665fa + local_1c * 0x1c) = 10000;
    (&DAT_000665fe)[local_1c * 0x1c] = 0;
    if ((local_1c & 1) == 0) {
      local_20 = 0xff;
    }
    else {
      local_20 = 0;
    }
    (&DAT_000665ff)[local_1c * 0x1c] = local_20;
  }
  FUN_0001222c(DAT_000669dc);
  FUN_00011794();
  DAT_00066966 = 0x7d;
  FUN_00012a30(0x7d);
  return;
}


/* ======== FUN_00013134 @ 00013134 ======== */

void FUN_00013134(void)

{
  FUN_000129b4(1);
  FUN_000117c4();
  return;
}


/* ======== FUN_00013158 @ 00013158 ======== */

undefined8 FUN_00013158(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint local_1c;
  
  iVar1 = FUN_00033e41(s_ULTRASND_0005958f);
  local_1c = (uint)(iVar1 != 0);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00013194 @ 00013194 ======== */

void FUN_00013194(byte param_1,undefined unaff_DL)

{
  (&DAT_000665fe)[(uint)param_1 * 0x1c] = unaff_DL;
  return;
}


/* ======== FUN_000131c0 @ 000131c0 ======== */

void FUN_000131c0(byte param_1,undefined4 unaff_EDX)

{
  *(undefined4 *)(&DAT_000665fa + (uint)param_1 * 0x1c) = unaff_EDX;
  return;
}


/* ======== FUN_000131ec @ 000131ec ======== */

void FUN_000131ec(byte param_1,undefined unaff_DL)

{
  (&DAT_000665ff)[(uint)param_1 * 0x1c] = unaff_DL;
  return;
}


/* ======== FUN_00013218 @ 00013218 ======== */

void FUN_00013218(byte param_1,undefined2 unaff_DX,uint unaff_EBX,uint unaff_ECX,undefined4 param_5,
                 uint param_6,ushort param_7)

{
  if (unaff_EBX < unaff_ECX) {
    if (((param_7 & 0x10) != 0) && (unaff_ECX < param_6)) {
      param_6 = unaff_ECX;
    }
    *(ushort *)(&DAT_000665e6 + (uint)param_1 * 0x1c) = param_7;
    *(undefined2 *)(&DAT_000665e8 + (uint)param_1 * 0x1c) = unaff_DX;
    *(uint *)(&DAT_000665ea + (uint)param_1 * 0x1c) = unaff_EBX;
    *(uint *)(&DAT_000665ee + (uint)param_1 * 0x1c) = unaff_ECX;
    *(undefined4 *)(&DAT_000665f2 + (uint)param_1 * 0x1c) = param_5;
    *(uint *)(&DAT_000665f6 + (uint)param_1 * 0x1c) = param_6;
    (&DAT_000665e4)[(uint)param_1 * 0x1c] = 1;
  }
  return;
}


/* ======== FUN_000132c8 @ 000132c8 ======== */

void FUN_000132c8(void)

{
  return;
}


/* ======== FUN_000132e0 @ 000132e0 ======== */

longlong FUN_000132e0(undefined4 param_1,uint unaff_EDX)

{
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_00013310 @ 00013310 ======== */

undefined8 FUN_00013310(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_00013330 @ 00013330 ======== */

undefined4 FUN_00013330(void)

{
  return 1;
}


/* ======== FUN_00013358 @ 00013358 ======== */

void FUN_00013358(void)

{
  return;
}


/* ======== FUN_00013370 @ 00013370 ======== */

undefined8 FUN_00013370(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_00013390 @ 00013390 ======== */

void FUN_00013390(void)

{
  return;
}


/* ======== FUN_000133a8 @ 000133a8 ======== */

void FUN_000133a8(void)

{
  return;
}


/* ======== FUN_000133c0 @ 000133c0 ======== */

void FUN_000133c0(void)

{
  return;
}


/* ======== FUN_000133d8 @ 000133d8 ======== */

void FUN_000133d8(void)

{
  return;
}


/* ======== FUN_000133f0 @ 000133f0 ======== */

void FUN_000133f0(void)

{
  return;
}


/* ======== FUN_0001340c @ 0001340c ======== */

void FUN_0001340c(void)

{
  return;
}


/* ======== FUN_00013428 @ 00013428 ======== */

void FUN_00013428(void)

{
  return;
}


/* ======== FUN_00013444 @ 00013444 ======== */

void FUN_00013444(void)

{
  return;
}


/* ======== FUN_00013464 @ 00013464 ======== */

longlong FUN_00013464(undefined4 param_1,uint unaff_EDX)

{
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_00013490 @ 00013490 ======== */

void FUN_00013490(void)

{
  uint uVar1;
  
  FUN_00033e1b(DAT_0006696c + 4,0xe);
  uVar1 = FUN_00033e30(DAT_0006696c + 5);
  FUN_00033e1b(DAT_0006696c + 5,uVar1 | 2);
  return;
}


/* ======== FUN_000134dc @ 000134dc ======== */

void FUN_000134dc(void)

{
  uint uVar1;
  
  FUN_00033e1b(DAT_0006696c + 4,0xe);
  uVar1 = FUN_00033e30(DAT_0006696c + 5);
  FUN_00033e1b(DAT_0006696c + 5,uVar1 & 0xfd);
  return;
}


/* ======== FUN_0001352c @ 0001352c ======== */

undefined8 FUN_0001352c(undefined4 param_1,undefined4 unaff_EDX)

{
  short sVar1;
  uint uVar2;
  undefined4 local_20;
  
  sVar1 = 0x7fff;
  do {
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      local_20 = 0;
      goto LAB_00013570;
    }
    uVar2 = FUN_00033e30(DAT_0006696c + 0xc);
  } while ((uVar2 & 0x80) != 0);
  local_20 = 1;
LAB_00013570:
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_0001357c @ 0001357c ======== */

undefined8 FUN_0001357c(undefined4 param_1,undefined4 unaff_EDX)

{
  short sVar1;
  uint uVar2;
  undefined4 local_20;
  
  sVar1 = 0x7fff;
  do {
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      local_20 = 0;
      goto LAB_000135c0;
    }
    uVar2 = FUN_00033e30(DAT_0006696c + 0xe);
  } while ((uVar2 & 0x80) == 0);
  local_20 = 1;
LAB_000135c0:
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_000135cc @ 000135cc ======== */

undefined8 FUN_000135cc(undefined param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint local_20;
  
  iVar1 = FUN_0001352c();
  if (iVar1 != 0) {
    FUN_00033e1b(DAT_0006696c + 0xc,param_1);
  }
  local_20 = (uint)(iVar1 != 0);
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00013614 @ 00013614 ======== */

undefined8 FUN_00013614(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_1c;
  
  iVar1 = FUN_0001357c();
  if (iVar1 == 0) {
    local_1c = 0xffff;
  }
  else {
    local_1c = FUN_00033e30(DAT_0006696c + 10);
  }
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00013650 @ 00013650 ======== */

void FUN_00013650(void)

{
  FUN_000135cc(0xd1);
  return;
}


/* ======== FUN_00013670 @ 00013670 ======== */

void FUN_00013670(void)

{
  FUN_000135cc(0xd3);
  return;
}


/* ======== FUN_00013690 @ 00013690 ======== */

void FUN_00013690(void)

{
  int local_1c;
  
  FUN_00033e1b(DAT_0006696c + 6,1);
  for (local_1c = 0; local_1c < 8; local_1c = local_1c + 1) {
    FUN_00033e30(DAT_0006696c + 6);
  }
  FUN_00033e1b(DAT_0006696c + 6,0);
  return;
}


/* ======== FUN_000136f0 @ 000136f0 ======== */

undefined8 FUN_000136f0(undefined4 param_1,undefined4 unaff_EDX)

{
  short sVar1;
  uint local_1c;
  
  FUN_00013690();
  sVar1 = FUN_00013614();
  local_1c = (uint)(sVar1 == 0xaa);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00013734 @ 00013734 ======== */

undefined8 FUN_00013734(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint local_24;
  
  iVar1 = FUN_000135cc(0xe1);
  if (iVar1 == 0) {
    local_24 = 0xffff;
  }
  else {
    iVar1 = FUN_00013614();
    local_24 = FUN_00013614();
    local_24 = local_24 | iVar1 << 8;
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00013784 @ 00013784 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00013784(undefined4 param_1,undefined4 unaff_EDX)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_24;
  byte *local_20;
  
  DAT_0006696c = -1;
  DAT_00066980 = 0xff;
  DAT_00066981 = -1;
  DAT_00066982 = 0xff;
  local_20 = (byte *)FUN_00033e41(s_BLASTER_00059608);
  if (local_20 == (byte *)0x0) {
    local_24 = 0;
  }
  else {
    while( true ) {
      do {
        do {
          pbVar1 = local_20 + 1;
          bVar2 = *local_20;
          local_20 = pbVar1;
        } while (bVar2 == 0x20);
      } while (bVar2 == 9);
      if (bVar2 == 0) break;
      if (bVar2 < 0x49) {
        if (bVar2 < 0x44) {
          if (bVar2 != 0x41) goto LAB_00013870;
LAB_000137ff:
          DAT_0006696c = FUN_0003435c(pbVar1,&DAT_00066968,0x10);
        }
        else if (bVar2 < 0x45) {
LAB_00013838:
          DAT_00066981 = FUN_0003435c(pbVar1,&DAT_00066968,10);
        }
        else {
          if (bVar2 != 0x48) goto LAB_00013870;
LAB_00013854:
          DAT_00066982 = FUN_0003435c(pbVar1,&DAT_00066968,10);
        }
      }
      else if (bVar2 < 0x4a) {
LAB_0001381c:
        DAT_00066980 = FUN_0003435c(pbVar1,&DAT_00066968,10);
      }
      else {
        if (bVar2 < 100) {
          if (bVar2 == 0x61) goto LAB_000137ff;
        }
        else {
          if (bVar2 < 0x65) goto LAB_00013838;
          if (0x67 < bVar2) {
            if (bVar2 < 0x69) goto LAB_00013854;
            if (bVar2 == 0x69) goto LAB_0001381c;
          }
        }
LAB_00013870:
        FUN_0003435c(pbVar1,&DAT_00066968,0x10);
      }
      local_20 = DAT_00066968;
    }
    if (((DAT_0006696c == -1) || (DAT_00066980 == 0xff)) || (DAT_00066981 == -1)) {
      local_24 = 0;
    }
    else {
      if (DAT_00066980 < 8) {
        _DAT_0006697c = DAT_00066980 + 8;
      }
      else {
        _DAT_0006697c = DAT_00066980 + 0x68;
      }
      iVar3 = FUN_000136f0();
      if (iVar3 == 0) {
        local_24 = 0;
      }
      else {
        DAT_0006697e = FUN_00013734();
        if (DAT_0006697e == -1) {
          local_24 = 0;
        }
        else {
          local_24 = 1;
        }
      }
    }
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00013a34 @ 00013a34 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00013a34(undefined4 param_1,undefined4 unaff_EDX)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 in_CS;
  undefined8 uVar5;
  undefined6 uVar6;
  char local_24;
  undefined4 local_20;
  uint local_1c;
  
  uVar5 = FUN_00013784();
  uVar6 = CONCAT24(DAT_00066988,DAT_00066984);
  uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if ((int)uVar5 == 0) {
    _DAT_00067358 = s_Nie_wykryto_karty_dzwiekowej__sp_00059610;
    local_20 = 0;
    uVar6 = CONCAT24(DAT_00066988,DAT_00066984);
  }
  else if ((DAT_0006697e < 0x400) || (DAT_00066982 != -1)) {
    if ((DAT_0006697e < 0x400) && ((DAT_000669da & 2) != 0)) {
      DAT_000669da = DAT_000669da & 0xfd;
    }
    if ((DAT_0006697e < 0x300) && ((DAT_000669da & 1) != 0)) {
      DAT_000669da = DAT_000669da & 0xfe;
    }
    if ((DAT_000669da & 2) == 0) {
      local_24 = DAT_00066981;
    }
    else {
      local_24 = DAT_00066982;
    }
    DAT_00066983 = local_24;
    uVar2 = (uint)DAT_0006697e;
    if (uVar2 < 0x400) {
      local_1c = (uint)DAT_00052acc;
      if ((DAT_000669da & 1) != 0) {
        local_1c = local_1c << 1;
      }
      DAT_00066978 = -(char)(1000000 / (ulonglong)local_1c);
      if (DAT_0006697e < 0x201) {
        if (0xd2 < DAT_00066978) {
          DAT_00066978 = 0xd2;
        }
      }
      else if (0xe9 < DAT_00066978) {
        DAT_00066978 = 0xe9;
      }
      lVar1 = 1000000 / (longlong)(int)(0x100 - (uint)DAT_00066978);
      uVar2 = (uint)lVar1;
      uVar4 = (undefined4)(1000000 % (longlong)(int)(0x100 - (uint)DAT_00066978));
      DAT_00052acc = (ushort)lVar1;
      if ((DAT_000669da & 1) != 0) {
        DAT_00052acc = DAT_00052acc >> 1;
      }
    }
    iVar3 = FUN_0001a91c(uVar2,uVar4);
    uVar6 = CONCAT24(DAT_00066988,DAT_00066984);
    if (iVar3 == 0) {
      local_20 = 0;
    }
    else {
      DAT_00066970 = FUN_00014f80(DAT_00052ace);
      if (DAT_00066970 == 0) {
        FUN_0001aa78();
        uVar6 = CONCAT24(DAT_00066988,DAT_00066984);
        _DAT_00067358 = s_Nie_moge_zaalokowac_bufora_mikso_0005969b;
        local_20 = 0;
      }
      else {
        DAT_00066974 = FUN_00014f40(DAT_00066970);
        uVar6 = FUN_00015bf0(DAT_00066980,DAT_00066980,&LAB_000139b4,in_CS);
        local_20 = 1;
      }
    }
  }
  else {
    _DAT_00067358 = s_Dla_SB_16_wymagany_jest_podanie_w_00059653;
    local_20 = 0;
  }
  DAT_00066988 = (undefined2)((uint6)uVar6 >> 0x20);
  DAT_00066984 = (undefined4)uVar6;
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00013c38 @ 00013c38 ======== */

void FUN_00013c38(void)

{
  FUN_00015bf0(DAT_00066980,DAT_00066980,DAT_00066984,DAT_00066988);
  FUN_00014fe0(DAT_00066970);
  FUN_0001aa78();
  return;
}


/* ======== FUN_00013c7c @ 00013c7c ======== */

void FUN_00013c7c(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  
  sVar2 = FUN_000151ec(DAT_00066983);
  uVar1 = DAT_0006698a;
  DAT_0006698c = DAT_00052ace - sVar2 & 0xfffc;
  if (DAT_0006698c != DAT_0006698a) {
    if (DAT_0006698a < DAT_0006698c) {
      sVar2 = DAT_0006698c - DAT_0006698a;
      sVar3 = FUN_0001a798((uint)DAT_0006698a + DAT_00066974,sVar2);
      DAT_0006698a = DAT_0006698a + sVar3;
      FUN_00014f64(DAT_00066970,uVar1,sVar2);
      if (DAT_00052ace <= DAT_0006698a) {
        DAT_0006698a = 0;
      }
    }
    else {
      sVar2 = DAT_00052ace - DAT_0006698a;
      FUN_0001a798((uint)DAT_0006698a + DAT_00066974,sVar2);
      FUN_00014f64(DAT_00066970,DAT_0006698a,sVar2);
      DAT_0006698a = FUN_0001a798(DAT_00066974,DAT_0006698c);
      FUN_00014f64(DAT_00066970,0,DAT_0006698c);
    }
  }
  return;
}


/* ======== FUN_00013d9c @ 00013d9c ======== */

void FUN_00013d9c(void)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
  FUN_0001a81c();
  FUN_00015ab0(DAT_00066980,1);
  if ((0x2ff < DAT_0006697e) && (DAT_0006697e < 0x400)) {
    if ((DAT_000669da & 1) == 0) {
      FUN_000134dc();
    }
    else {
      FUN_00013490();
    }
  }
  FUN_0001a7d8(DAT_00066974,DAT_00052ace);
  FUN_00014f64(DAT_00066970,0,DAT_00052ace);
  iVar1 = FUN_00015008(DAT_00066983,DAT_00066970,DAT_00052ace,3);
  if (iVar1 != 0) {
    if (DAT_0006697e < 0x400) {
      FUN_00013650();
      FUN_000135cc(0x40);
      FUN_000135cc(DAT_00066978);
      if (DAT_0006697e < 0x200) {
        FUN_000135cc(0x14);
        FUN_000135cc(0xff);
        FUN_000135cc(0xfe);
      }
      else if (DAT_0006697e == 0x200) {
        FUN_000135cc(0x48);
        FUN_000135cc(0xff);
        FUN_000135cc(0xfe);
        FUN_000135cc(0x1c);
      }
      else {
        FUN_000135cc(0x48);
        FUN_000135cc(0xff);
        FUN_000135cc(0xfe);
        FUN_000135cc(0x90);
      }
    }
    else {
      FUN_000135cc(0x41);
      FUN_000135cc((int)(uint)DAT_00052acc >> 8);
      FUN_000135cc((undefined)DAT_00052acc);
      if ((DAT_000669da & 2) == 0) {
        FUN_000135cc(0xc6);
        if ((DAT_000669da & 1) == 0) {
          local_20 = 0;
        }
        else {
          local_20 = 0x20;
        }
        FUN_000135cc(local_20);
      }
      else {
        FUN_000135cc(0xb6);
        if ((DAT_000669da & 1) == 0) {
          local_1c = 0x10;
        }
        else {
          local_1c = 0x30;
        }
        FUN_000135cc(local_1c);
      }
      FUN_000135cc(0xff);
      FUN_000135cc(0xef);
    }
  }
  return;
}


/* ======== FUN_00013fa8 @ 00013fa8 ======== */

void FUN_00013fa8(void)

{
  FUN_0001a904();
  FUN_00013670();
  FUN_00013690();
  FUN_00013690();
  FUN_000151b0(DAT_00066983);
  FUN_00015ab0(DAT_00066980,0);
  return;
}


/* ======== FUN_00013ff0 @ 00013ff0 ======== */

undefined8 FUN_00013ff0(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_24;
  int local_20;
  undefined local_1c [4];
  
  FUN_00016670(DAT_00067204,0x438,0);
  iVar1 = fread(local_1c,4,1,DAT_00067204);
  if (iVar1 == 0) {
    local_24 = 0;
  }
  else {
    for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
      iVar1 = FUN_0003459d(local_1c,&DAT_0005292c + local_20 * 10,4);
      if (iVar1 == 0) {
        local_24 = 1;
        goto LAB_00014077;
      }
    }
    local_24 = 0;
  }
LAB_00014077:
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00014084 @ 00014084 ======== */

undefined8 FUN_00014084(undefined4 param_1,undefined4 unaff_EDX)

{
  uint local_1c;
  
  DAT_00066994 = 0;
  DAT_00066990 = FUN_00015d48(1,0x43c);
  local_1c = (uint)(DAT_00066990 != 0);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_000140d4 @ 000140d4 ======== */

void FUN_000140d4(void)

{
  if (DAT_00066990 != 0) {
    free(DAT_00066990);
  }
  if (DAT_00066994 != 0) {
    free(DAT_00066994);
  }
  return;
}


/* ======== FUN_00014110 @ 00014110 ======== */

void FUN_00014110(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort local_30;
  byte local_28;
  
  bVar3 = *param_1 & 0x10 | (byte)((int)(uint)param_1[2] >> 4);
  local_30 = (*param_1 & 0xf) * 0x100 + (ushort)param_1[1];
  bVar1 = param_1[2];
  bVar2 = param_1[3];
  local_28 = '\0';
  if (local_30 != 0) {
    local_28 = 0;
    while ((local_28 < 0x3c && (local_30 < *(ushort *)(&DAT_0005299a + (uint)local_28 * 2)))) {
      local_28 = local_28 + 1;
    }
    local_28 = local_28 + 1;
    if (local_28 == '=') {
      local_28 = '\0';
    }
  }
  if (bVar3 != 0) {
    FUN_00019674(bVar3 - 1);
  }
  if (local_28 != '\0') {
    FUN_000196a0(local_28 + '\x17');
  }
  FUN_000196cc(bVar1 & 0xf,bVar2);
  return;
}


/* ======== FUN_000141f4 @ 000141f4 ======== */

undefined8 FUN_000141f4(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 uVar2;
  int local_20;
  int local_1c;
  
  iVar1 = FUN_000195b8();
  local_1c = param_1;
  for (local_20 = 0; local_20 < 0x40; local_20 = local_20 + 1) {
    FUN_00014110(local_1c);
    FUN_00019768();
    local_1c = local_1c + (uint)DAT_00067208 * 4;
    iVar1 = local_20;
  }
  uVar2 = FUN_0001985c(iVar1);
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_00014254 @ 00014254 ======== */

undefined8 FUN_00014254(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_28;
  int local_24;
  uint local_20;
  int local_1c;
  
  local_1c = 0;
  iVar2 = FUN_00015e34();
  if (iVar2 == 0) {
    local_28 = 0;
  }
  else {
    iVar2 = FUN_00015f2c();
    if (iVar2 == 0) {
      local_28 = 0;
    }
    else {
      DAT_00066994 = FUN_00015d48((uint)DAT_00067208 << 6,4);
      if (DAT_00066994 == 0) {
        local_28 = 0;
      }
      else {
        for (local_24 = 0; local_24 < (int)(uint)DAT_0006720d; local_24 = local_24 + 1) {
          for (local_20 = 0; local_20 < (uint)DAT_00067208 * 0x40; local_20 = local_20 + 1) {
            uVar1 = FUN_00016b5c(DAT_00067204);
            *(undefined *)(local_20 * 4 + DAT_00066994) = uVar1;
            uVar1 = FUN_00016b5c(DAT_00067204);
            *(undefined *)(local_20 * 4 + DAT_00066994 + 1) = uVar1;
            uVar1 = FUN_00016b5c(DAT_00067204);
            *(undefined *)(local_20 * 4 + DAT_00066994 + 2) = uVar1;
            uVar1 = FUN_00016b5c(DAT_00067204);
            *(undefined *)(local_20 * 4 + DAT_00066994 + 3) = uVar1;
          }
          for (local_20 = 0; (int)local_20 < (int)(uint)DAT_00067208; local_20 = local_20 + 1) {
            iVar2 = FUN_000141f4(DAT_00066994 + local_20 * 4);
            piVar3 = (int *)(local_1c * 4 + DAT_0006734e);
            *piVar3 = iVar2;
            if (*piVar3 == 0) {
              local_28 = 0;
              goto LAB_000143e8;
            }
            local_1c = local_1c + 1;
          }
        }
        local_28 = 1;
      }
    }
  }
LAB_000143e8:
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_000143f4 @ 000143f4 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000143f4(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined2 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_EDX;
  undefined4 local_30;
  int local_2c;
  int local_28;
  undefined *local_24;
  int local_1c;
  
  iVar5 = DAT_00067204;
  FUN_00016d2c(DAT_00066990,0x14,DAT_00067204);
  uVar6 = extraout_EDX;
  for (local_2c = 0; iVar2 = DAT_00067204, local_2c < 0x1f; local_2c = local_2c + 1) {
    iVar5 = DAT_00066990 + 0x14 + local_2c * 0x1e;
    FUN_00016d2c(iVar5,0x16);
    uVar6 = FUN_00016b84(DAT_00067204);
    *(short *)(iVar5 + 0x16) = (short)uVar6;
    uVar3 = FUN_00016b5c(DAT_00067204,uVar6,iVar2);
    *(undefined *)(iVar5 + 0x18) = uVar3;
    uVar3 = FUN_00016b5c(DAT_00067204);
    *(undefined *)(iVar5 + 0x19) = uVar3;
    uVar4 = FUN_00016b84(DAT_00067204);
    *(undefined2 *)(iVar5 + 0x1a) = uVar4;
    uVar6 = FUN_00016b84(DAT_00067204);
    *(short *)(iVar5 + 0x1c) = (short)uVar6;
    iVar5 = iVar2;
  }
  uVar3 = FUN_00016b5c(DAT_00067204,uVar6,iVar5);
  *(undefined *)(DAT_00066990 + 0x3b6) = uVar3;
  uVar3 = FUN_00016b5c(DAT_00067204);
  *(undefined *)(DAT_00066990 + 0x3b7) = uVar3;
  FUN_00016dd8(DAT_00066990 + 0x3b8,0x80,DAT_00067204);
  FUN_00016dd8(DAT_00066990 + 0x438,4,DAT_00067204);
  if ((*(byte *)(DAT_00067204 + 0xc) & 0x10) == 0) {
    for (local_28 = 0; local_28 < 10; local_28 = local_28 + 1) {
      iVar5 = FUN_0003459d(DAT_00066990 + 0x438,&DAT_0005292c + local_28 * 10,4);
      if (iVar5 == 0) break;
    }
    if (local_28 == 10) {
      _DAT_00067358 = PTR_s_Nieznay_typ_modulu_00052b08;
      local_30 = 0;
    }
    else {
      DAT_00067213 = 6;
      DAT_00067214 = 0x7d;
      DAT_00067208 = (&DAT_00052931)[local_28 * 10];
      _DAT_0006733a = FUN_0003463d(*(undefined4 *)((int)&PTR_s_Protracker_00052932 + local_28 * 10))
      ;
      _DAT_00067336 = FUN_0001606c(DAT_00066990,0x14);
      _DAT_00067209 = (ushort)*(byte *)(DAT_00066990 + 0x3b6);
      FUN_00034682(&DAT_00067215,DAT_00066990 + 0x3b8,0x80);
      DAT_0006720d = 0;
      for (local_2c = 0; local_2c < 0x80; local_2c = local_2c + 1) {
        if (DAT_0006720d < (byte)(&DAT_00067215)[local_2c]) {
          DAT_0006720d = (ushort)(byte)(&DAT_00067215)[local_2c];
        }
      }
      DAT_0006720d = DAT_0006720d + 1;
      DAT_0006720f = DAT_0006720d * DAT_00067208;
      DAT_00067211 = 0x1f;
      iVar5 = FUN_00015f74();
      if (iVar5 == 0) {
        local_30 = 0;
      }
      else {
        local_1c = DAT_00066990 + 0x14;
        local_24 = DAT_00067342;
        for (local_2c = 0; local_2c < (int)(uint)DAT_00067211; local_2c = local_2c + 1) {
          *local_24 = 1;
          iVar5 = FUN_00015fbc(local_24);
          if (iVar5 == 0) {
            local_30 = 0;
            goto LAB_000147c6;
          }
          puVar1 = *(undefined2 **)(local_24 + 0xd5);
          uVar6 = FUN_0001606c(local_1c,0x16);
          *(undefined4 *)(local_24 + 0xd1) = uVar6;
          *puVar1 = *(undefined2 *)(&DAT_00052ad8 + (uint)(*(byte *)(local_1c + 0x18) & 0xf) * 2);
          *(undefined *)((int)puVar1 + 3) = *(undefined *)(local_1c + 0x19);
          *(uint *)((int)puVar1 + 9) = (uint)*(ushort *)(local_1c + 0x1a) * 2;
          *(uint *)((int)puVar1 + 0xd) =
               *(int *)((int)puVar1 + 9) + (uint)*(ushort *)(local_1c + 0x1c) * 2;
          *(uint *)((int)puVar1 + 5) = (uint)*(ushort *)(local_1c + 0x16) * 2;
          *(undefined4 *)((int)puVar1 + 0x13) = 0;
          *(undefined2 *)((int)puVar1 + 0x11) = 2;
          if (1 < *(ushort *)(local_1c + 0x1c)) {
            *(byte *)((int)puVar1 + 0x11) = *(byte *)((int)puVar1 + 0x11) | 0x10;
          }
          if (*(uint *)((int)puVar1 + 5) < *(uint *)((int)puVar1 + 0xd)) {
            *(undefined4 *)((int)puVar1 + 0xd) = *(undefined4 *)((int)puVar1 + 5);
          }
          local_1c = local_1c + 0x1e;
          local_24 = local_24 + 0xd9;
        }
        iVar5 = FUN_00014254();
        if (iVar5 == 0) {
          local_30 = 0;
        }
        else {
          local_30 = 1;
        }
      }
    }
  }
  else {
    _DAT_00067358 = PTR_s_Blad_ladowania_naglowka_00052b04;
    local_30 = 0;
  }
LAB_000147c6:
  return CONCAT44(unaff_EDX,local_30);
}


/* ======== FUN_000147d0 @ 000147d0 ======== */

undefined8 FUN_000147d0(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_20;
  undefined local_1c [4];
  
  iVar1 = fread(local_1c,4,1,DAT_00067204);
  if (iVar1 == 0) {
    local_20 = 0;
  }
  else {
    iVar1 = FUN_0003459d(local_1c,&DAT_00059738,4);
    if (iVar1 == 0) {
      local_20 = 1;
    }
    else {
      local_20 = 0;
    }
  }
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00014834 @ 00014834 ======== */

undefined8 FUN_00014834(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_00014854 @ 00014854 ======== */

void FUN_00014854(void)

{
  return;
}


/* ======== FUN_0001486c @ 0001486c ======== */

undefined8 FUN_0001486c(undefined4 param_1,undefined4 unaff_EDX)

{
  ushort uVar1;
  int local_24;
  
  uVar1 = FUN_00016bc8(DAT_00067204);
  if (uVar1 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = malloc(uVar1 + 1);
    fread(local_24,uVar1,1,DAT_00067204);
    *(undefined *)((uint)uVar1 + local_24) = 0;
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_000148d8 @ 000148d8 ======== */

undefined8 FUN_000148d8(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00016bc8(DAT_00067204);
  uVar2 = malloc(uVar1);
  fread(uVar2,uVar1,1,DAT_00067204);
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_00014928 @ 00014928 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00014928(undefined4 param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  undefined uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined4 local_24;
  int local_20;
  int local_1c;
  
  FUN_00016670(DAT_00067204,4,0);
  DAT_00067208 = FUN_00016b5c(DAT_00067204);
  _DAT_00067209 = FUN_00016bc8(DAT_00067204);
  _DAT_0006720b = FUN_00016bc8(DAT_00067204);
  DAT_0006720d = FUN_00016bc8(DAT_00067204);
  DAT_0006720f = FUN_00016bc8(DAT_00067204);
  DAT_00067211 = FUN_00016bc8(DAT_00067204);
  DAT_00067213 = FUN_00016b5c(DAT_00067204);
  DAT_00067214 = FUN_00016b5c(DAT_00067204);
  FUN_00016dd8(&DAT_00067215,0x100,DAT_00067204);
  iVar9 = DAT_00067204;
  FUN_00016dd8(&DAT_00067315,0x20,DAT_00067204);
  DAT_00067335 = FUN_00016b5c(DAT_00067204);
  if ((*(byte *)(DAT_00067204 + 0xc) & 0x10) == 0) {
    _DAT_00067336 = FUN_0001486c();
    _DAT_0006733a = FUN_0001486c();
    _DAT_0006733e = FUN_0001486c();
    iVar5 = FUN_00015f74();
    if (iVar5 == 0) {
      local_24 = 0;
    }
    else {
      iVar5 = FUN_00015f2c();
      if (iVar5 == 0) {
        local_24 = 0;
      }
      else {
        iVar5 = FUN_00015e34();
        if (iVar5 == 0) {
          local_24 = 0;
        }
        else {
          for (local_20 = 0; local_20 < (int)(uint)DAT_00067211; local_20 = local_20 + 1) {
            pbVar6 = (byte *)(DAT_00067342 + local_20 * 0xd9);
            bVar1 = FUN_00016b5c(DAT_00067204,local_20 * 0xd9,iVar9);
            *pbVar6 = bVar1;
            iVar9 = DAT_00067204;
            FUN_00016dd8(pbVar6 + 1,0x60);
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0x61] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0x62] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[99] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[100] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            uVar4 = (ushort)bVar1;
            pbVar6[0x65] = bVar1;
            for (local_1c = 0; local_1c < 0xc; local_1c = local_1c + 1) {
              uVar3 = FUN_00016c34(DAT_00067204);
              *(undefined2 *)(pbVar6 + local_1c * 4 + 0x66) = uVar3;
              uVar4 = FUN_00016c34(DAT_00067204);
              *(ushort *)(pbVar6 + local_1c * 4 + 0x68) = uVar4;
            }
            bVar1 = FUN_00016b5c(DAT_00067204,uVar4,iVar9);
            pbVar6[0x96] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0x97] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0x98] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0x99] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            uVar4 = (ushort)bVar1;
            pbVar6[0x9a] = bVar1;
            for (local_1c = 0; local_1c < 0xc; local_1c = local_1c + 1) {
              uVar3 = FUN_00016c34(DAT_00067204);
              *(undefined2 *)(pbVar6 + local_1c * 4 + 0x9b) = uVar3;
              uVar4 = FUN_00016c34(DAT_00067204);
              *(ushort *)(pbVar6 + local_1c * 4 + 0x9d) = uVar4;
            }
            bVar1 = FUN_00016b5c(DAT_00067204,uVar4,iVar9);
            pbVar6[0xcb] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0xcc] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0xcd] = bVar1;
            bVar1 = FUN_00016b5c(DAT_00067204);
            pbVar6[0xce] = bVar1;
            uVar3 = FUN_00016bc8(DAT_00067204);
            *(undefined2 *)(pbVar6 + 0xcf) = uVar3;
            uVar7 = FUN_0001486c();
            *(undefined4 *)(pbVar6 + 0xd1) = uVar7;
            iVar5 = FUN_00015fbc(pbVar6);
            if (iVar5 == 0) {
              local_24 = 0;
              goto LAB_00014e20;
            }
            for (local_1c = 0; local_1c < (int)(uint)*pbVar6; local_1c = local_1c + 1) {
              puVar8 = (undefined2 *)(*(int *)(pbVar6 + 0xd5) + local_1c * 0x1d);
              uVar3 = FUN_00016bc8(DAT_00067204);
              *puVar8 = uVar3;
              uVar2 = FUN_00016b34(DAT_00067204);
              *(undefined *)(puVar8 + 1) = uVar2;
              uVar2 = FUN_00016b5c(DAT_00067204,uVar2,iVar9);
              *(undefined *)((int)puVar8 + 3) = uVar2;
              uVar2 = FUN_00016b5c(DAT_00067204);
              *(undefined *)(puVar8 + 2) = uVar2;
              uVar7 = FUN_00016c9c(DAT_00067204);
              *(undefined4 *)((int)puVar8 + 5) = uVar7;
              uVar7 = FUN_00016c9c(DAT_00067204);
              *(undefined4 *)((int)puVar8 + 9) = uVar7;
              uVar7 = FUN_00016c9c(DAT_00067204);
              *(undefined4 *)((int)puVar8 + 0xd) = uVar7;
              uVar3 = FUN_00016bc8(DAT_00067204);
              *(undefined2 *)((int)puVar8 + 0x11) = uVar3;
              *(undefined4 *)((int)puVar8 + 0x13) = 0;
              uVar7 = FUN_0001486c();
              *(undefined4 *)((int)puVar8 + 0x17) = uVar7;
            }
          }
          FUN_00016f48(DAT_0006734a,DAT_0006720d,DAT_00067204);
          FUN_00016f48(DAT_00067346,(uint)DAT_0006720d * (uint)DAT_00067208,DAT_00067204);
          for (local_20 = 0; local_20 < (int)(uint)DAT_0006720f; local_20 = local_20 + 1) {
            uVar7 = FUN_000148d8();
            *(undefined4 *)(local_20 * 4 + DAT_0006734e) = uVar7;
          }
          local_24 = 1;
        }
      }
    }
  }
  else {
    _DAT_00067358 = PTR_s_Blad_ladowania_naglowka_00052b04;
    local_24 = 0;
  }
LAB_00014e20:
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00014e30 @ 00014e30 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00014e30(uint *param_1,uint unaff_EDX)

{
  uint local_24;
  undefined4 local_20;
  
  DAT_00066998 = 0x100;
  _DAT_0006699c = (int)((unaff_EDX & 0xffff) * 2 + 0xf) >> 4;
  FUN_0003478a(0x31,&DAT_00066998,&DAT_00066998);
  if (DAT_000669b0 == 0) {
    *(undefined2 *)(param_1 + 1) = DAT_000669a4;
    local_24 = (DAT_00066998 & 0xffff) * 0x10;
    if (local_24 >> 0x10 != ((unaff_EDX & 0xffff) + local_24) - 1 >> 0x10) {
      local_24 = local_24 + (unaff_EDX & 0xffff);
    }
    *param_1 = local_24;
    local_20 = 1;
  }
  else {
    local_20 = 0;
  }
  return local_20;
}


/* ======== FUN_00014ed8 @ 00014ed8 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014ed8(int param_1)

{
  _DAT_000669b4 = 0x101;
  _DAT_000669c0 = (uint)*(ushort *)(param_1 + 4);
  FUN_0003478a(0x31,&DAT_000669b4,&DAT_000669b4);
  return;
}


/* ======== FUN_00014f1c @ 00014f1c ======== */

undefined8 FUN_00014f1c(undefined4 *param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,*param_1);
}


/* ======== FUN_00014f40 @ 00014f40 ======== */

undefined8 FUN_00014f40(undefined4 *param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,*param_1);
}


/* ======== FUN_00014f64 @ 00014f64 ======== */

void FUN_00014f64(void)

{
  return;
}


/* ======== FUN_00014f80 @ 00014f80 ======== */

undefined8 FUN_00014f80(undefined2 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_24;
  
  local_24 = malloc(6);
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    iVar1 = FUN_00014e30(local_24,param_1);
    if (iVar1 == 0) {
      free(local_24);
      local_24 = 0;
    }
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00014fe0 @ 00014fe0 ======== */

void FUN_00014fe0(undefined4 param_1)

{
  FUN_00014ed8(param_1);
  free(param_1);
  return;
}


/* ======== FUN_00015008 @ 00015008 ======== */

undefined4 FUN_00015008(int param_1,undefined4 unaff_EDX,uint unaff_EBX,uint unaff_ECX)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  byte in_AF;
  bool bVar7;
  bool bVar8;
  byte in_TF;
  byte in_IF;
  bool bVar9;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 local_40;
  uint local_38;
  short local_2c;
  byte local_20;
  
  iVar4 = param_1 * 0x10;
  local_38 = FUN_00014f1c(unaff_EDX);
  uVar2 = local_38 >> 0x10;
  local_2c = (short)((unaff_EBX & 0xffff) + local_38 + -1 >> 0x10);
  if ((short)(local_38 >> 0x10) == local_2c) {
    uVar3 = unaff_EBX;
    if (3 < param_1) {
      local_38 = local_38 >> 1;
      uVar3 = (int)(unaff_EBX & 0xffff) >> 1;
    }
    bVar5 = unaff_ECX < 3;
    bVar9 = SBORROW4(unaff_ECX,3);
    uVar1 = unaff_ECX - 3;
    bVar8 = (int)uVar1 < 0;
    bVar7 = uVar1 == 0;
    bVar6 = (POPCOUNT(uVar1 & 0xff) & 1U) == 0;
    if (bVar5 || bVar7) {
      switch((&switchD_000150e8::switchdataD_000150c8)[unaff_ECX]) {
      case (undefined *)0x15096:
        local_20 = (&DAT_00052a5b)[iVar4];
        break;
      case (undefined *)0x150a1:
        local_20 = (&DAT_00052a5a)[iVar4];
        break;
      case (undefined *)0x150ac:
        bVar5 = false;
        bVar9 = false;
        local_20 = (&DAT_00052a5b)[iVar4] | 0x10;
        bVar8 = (char)local_20 < '\0';
        bVar7 = local_20 == 0;
        bVar6 = (POPCOUNT(local_20) & 1U) == 0;
        break;
      case (undefined *)0x150b9:
        bVar5 = false;
        bVar9 = false;
        local_20 = (&DAT_00052a5a)[iVar4] | 0x10;
        bVar8 = (char)local_20 < '\0';
        bVar7 = local_20 == 0;
        bVar6 = (POPCOUNT(local_20) & 1U) == 0;
      }
    }
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a54 + iVar4),(&DAT_00052a4c)[iVar4],unaff_EBX,unaff_ECX,
                 (uint)(in_NT & 1) * 0x4000 | (uint)bVar9 * 0x800 | (uint)(in_IF & 1) * 0x200 |
                 (uint)(in_TF & 1) * 0x100 | (uint)bVar8 * 0x80 | (uint)bVar7 * 0x40 |
                 (uint)(in_AF & 1) * 0x10 | (uint)bVar6 * 4 | (uint)bVar5 |
                 (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
                 (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a56 + iVar4),local_20);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a58 + iVar4),0);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a50 + iVar4),local_38 & 0xff);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a50 + iVar4),(int)(local_38 & 0xffff) >> 8);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a4e + iVar4),uVar2);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a58 + iVar4),0);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a52 + iVar4),uVar3 - 1 & 0xff);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a52 + iVar4),(int)(uVar3 - 1 & 0xffff) >> 8);
    FUN_00033e1b(*(undefined2 *)(&DAT_00052a54 + iVar4),(&DAT_00052a4d)[iVar4]);
    local_40 = 1;
  }
  else {
    local_40 = 0;
  }
  return local_40;
}


/* ======== FUN_000151b0 @ 000151b0 ======== */

void FUN_000151b0(int param_1)

{
  FUN_00033e1b(*(undefined2 *)(&DAT_00052a54 + param_1 * 0x10),(&DAT_00052a4c)[param_1 * 0x10]);
  return;
}


/* ======== FUN_000151ec @ 000151ec ======== */

undefined8 FUN_000151ec(int param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  short local_28;
  uint local_24;
  
  uVar6 = param_1 * 0x10;
  puVar3 = &DAT_00052a4c + uVar6;
  uVar1 = *(undefined2 *)(&DAT_00052a52 + uVar6);
  FUN_00033e1b(*(undefined2 *)(&DAT_00052a58 + uVar6),0xff,unaff_EBX,unaff_ECX,
               (uint)(in_NT & 1) * 0x4000 | (uint)SCARRY4(uVar6,0x52a4c) * 0x800 |
               (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
               (uint)((int)puVar3 < 0) * 0x80 | (uint)(puVar3 == (undefined *)0x0) * 0x40 |
               (uint)(in_AF & 1) * 0x10 | (uint)((POPCOUNT((uint)puVar3 & 0xff) & 1U) == 0) * 4 |
               (uint)(0xfffad5b3 < uVar6) | (uint)(in_ID & 1) * 0x200000 |
               (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
               (uint)(in_AC & 1) * 0x40000);
  do {
    do {
      uVar2 = FUN_00033e30(uVar1);
      iVar4 = FUN_00033e30(uVar1);
      local_24 = FUN_00033e30(uVar1);
      iVar5 = FUN_00033e30(uVar1);
      local_24 = local_24 | iVar5 << 8;
      local_28 = (uVar2 | (ushort)(iVar4 << 8)) - (short)local_24;
    } while (0x40 < local_28);
  } while (local_28 < -0x40);
  if (3 < param_1) {
    local_24 = local_24 << 1;
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_000152a0 @ 000152a0 ======== */

void FUN_000152a0(void)

{
  return;
}


/* ======== FUN_000152b8 @ 000152b8 ======== */

void FUN_000152b8(undefined4 param_1,undefined2 unaff_DX,undefined2 unaff_BX)

{
  DAT_000669e4 = 0;
  DAT_000669e0 = param_1;
  DAT_000669e6 = unaff_DX;
  DAT_000669e8 = unaff_BX;
  return;
}


/* ======== FUN_000152f8 @ 000152f8 ======== */

void FUN_000152f8(void)

{
  return;
}


/* ======== FUN_00015310 @ 00015310 ======== */

void FUN_00015310(undefined2 *param_1,uint unaff_EDX)

{
  short *local_38;
  byte *local_34;
  uint local_30;
  undefined2 *local_2c;
  undefined2 *local_28;
  int local_24;
  
  local_2c = param_1;
  local_28 = param_1;
  if ((DAT_000669e8 & 1) != 0) {
    unaff_EDX = unaff_EDX >> 1;
  }
  for (; unaff_EDX != 0; unaff_EDX = unaff_EDX - (local_30 & 0xffff)) {
    local_30 = unaff_EDX;
    if (0x3ff < unaff_EDX) {
      local_30 = 0x400;
    }
    if ((DAT_000669e6 & 1) == 0) {
      fread(&DAT_000669ea,1,local_30 & 0xffff,DAT_000669e0);
      local_34 = &DAT_000669ea + (local_30 & 0xffff);
      local_38 = (short *)(&DAT_000669ea + (local_30 & 0xffff) * 2);
      for (local_24 = 0; local_24 < (int)(local_30 & 0xffff); local_24 = local_24 + 1) {
        local_34 = local_34 + -1;
        local_38 = local_38 + -1;
        *local_38 = (ushort)*local_34 << 8;
      }
    }
    else {
      fread(&DAT_000669ea,2,local_30 & 0xffff,DAT_000669e0);
      if ((DAT_000669e6 & 8) != 0) {
        FUN_000347a7(&DAT_000669ea,&DAT_000669ea,(local_30 & 0xffff) * 2);
      }
    }
    if ((DAT_000669e6 & 4) != 0) {
      for (local_24 = 0; local_24 < (int)(local_30 & 0xffff); local_24 = local_24 + 1) {
        *(short *)(&DAT_000669ea + local_24 * 2) =
             *(short *)(&DAT_000669ea + local_24 * 2) + DAT_000669e4;
        DAT_000669e4 = *(short *)(&DAT_000669ea + local_24 * 2);
      }
    }
    if (((DAT_000669e8 ^ DAT_000669e6) & 2) != 0) {
      for (local_24 = 0; local_24 < (int)(local_30 & 0xffff); local_24 = local_24 + 1) {
        (&DAT_000669eb)[local_24 * 2] = (&DAT_000669eb)[local_24 * 2] ^ 0x80;
      }
    }
    if ((DAT_000669e8 & 1) == 0) {
      for (local_24 = 0; local_24 < (int)(local_30 & 0xffff); local_24 = local_24 + 1) {
        *(char *)local_2c = (char)((ushort)*(undefined2 *)(&DAT_000669ea + local_24 * 2) >> 8);
        local_2c = (undefined2 *)((int)local_2c + 1);
      }
    }
    else {
      for (local_24 = 0; local_24 < (int)(local_30 & 0xffff); local_24 = local_24 + 1) {
        *local_28 = *(undefined2 *)(&DAT_000669ea + local_24 * 2);
        local_28 = local_28 + 1;
      }
    }
  }
  return;
}


/* ======== FUN_0001556c @ 0001556c ======== */

void FUN_0001556c(int *param_1)

{
  if (DAT_000669d0 == (int *)0x0) {
    DAT_000669d0 = param_1;
    *param_1 = 0;
  }
  else {
    *param_1 = (int)DAT_000669d0;
    DAT_000669d0 = param_1;
  }
  return;
}


/* ======== FUN_000155b4 @ 000155b4 ======== */

undefined4
FUN_000155b4(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX,
            undefined2 param_5)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(DAT_000669d4 + 0x10))(param_1,unaff_EDX,unaff_EBX,unaff_ECX,param_5);
  FUN_000152f8();
  return uVar1;
}


/* ======== FUN_000155fc @ 000155fc ======== */

void FUN_000155fc(short param_1)

{
  (**(code **)(DAT_000669d4 + 0x14))((int)param_1);
  return;
}


/* ======== FUN_00015624 @ 00015624 ======== */

undefined8 FUN_00015624(undefined4 param_1,undefined4 unaff_EDX)

{
  short sVar1;
  int iVar2;
  undefined4 local_20;
  
  sVar1 = DAT_000669d8;
  if (DAT_000669d8 == 0) {
    sVar1 = 1;
    DAT_000669d4 = DAT_000669d0;
    while ((DAT_000669d4 != (undefined4 *)0x0 && (iVar2 = (*(code *)DAT_000669d4[3])(), iVar2 == 0))
          ) {
      DAT_000669d4 = (undefined4 *)*DAT_000669d4;
      sVar1 = sVar1 + 1;
    }
    if (DAT_000669d4 == (undefined4 *)0x0) {
      local_20 = 0;
      goto LAB_000156ed;
    }
  }
  DAT_000669d8 = sVar1;
  DAT_000669d4 = DAT_000669d0;
  for (sVar1 = 1; (DAT_000669d4 != (undefined4 *)0x0 && (sVar1 != DAT_000669d8)); sVar1 = sVar1 + 1)
  {
    DAT_000669d4 = (undefined4 *)*DAT_000669d4;
  }
  if (DAT_000669d4 == (undefined4 *)0x0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(code *)DAT_000669d4[6])();
  }
LAB_000156ed:
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_000156f8 @ 000156f8 ======== */

void FUN_000156f8(void)

{
  (**(code **)(DAT_000669d4 + 0x1c))();
  return;
}


/* ======== FUN_00015718 @ 00015718 ======== */

void FUN_00015718(void)

{
  if (DAT_000671ec == 0) {
    (**(code **)(DAT_000669d4 + 0x20))();
    DAT_000671ec = 1;
  }
  return;
}


/* ======== FUN_00015748 @ 00015748 ======== */

void FUN_00015748(void)

{
  if (DAT_000671ec != 0) {
    DAT_000671ec = 0;
    (**(code **)(DAT_000669d4 + 0x24))();
  }
  return;
}


/* ======== FUN_00015778 @ 00015778 ======== */

void FUN_00015778(undefined param_1)

{
  DAT_00052ad0 = param_1;
  return;
}


/* ======== FUN_00015798 @ 00015798 ======== */

void FUN_00015798(undefined *param_1)

{
  PTR_FUN_00052ad4 = param_1;
  return;
}


/* ======== FUN_000157b8 @ 000157b8 ======== */

void FUN_000157b8(void)

{
  if (DAT_000671ec != 0) {
    (**(code **)(DAT_000669d4 + 0x28))();
  }
  return;
}


/* ======== FUN_000157e0 @ 000157e0 ======== */

void FUN_000157e0(undefined param_1,undefined unaff_DL)

{
  (**(code **)(DAT_000669d4 + 0x2c))(param_1,unaff_DL);
  return;
}


/* ======== FUN_0001580c @ 0001580c ======== */

void FUN_0001580c(undefined param_1,undefined4 unaff_EDX)

{
  (**(code **)(DAT_000669d4 + 0x30))(param_1,unaff_EDX);
  return;
}


/* ======== FUN_00015838 @ 00015838 ======== */

void FUN_00015838(undefined param_1,undefined unaff_DL)

{
  (**(code **)(DAT_000669d4 + 0x34))(param_1,unaff_DL);
  return;
}


/* ======== FUN_00015864 @ 00015864 ======== */

void FUN_00015864(undefined param_1,short unaff_DX,undefined4 unaff_EBX,undefined4 unaff_ECX,
                 undefined4 param_5,undefined4 param_6,undefined2 param_7)

{
  (**(code **)(DAT_000669d4 + 0x38))
            (param_1,(int)unaff_DX,unaff_EBX,unaff_ECX,param_5,param_6,param_7);
  return;
}


/* ======== FUN_000158b0 @ 000158b0 ======== */

void FUN_000158b0(void)

{
  FUN_00018cf4();
  FUN_00015778(DAT_00067edc);
  return;
}


/* ======== PlayModule @ 000158d8 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlayModule(int param_1)

{
  int iVar1;
  
  if ((DAT_00067200 != param_1) || (DAT_000b1594 == 0)) {
    if (DAT_000671f8 != 0) {
      StopModule();
    }
    DAT_000671f8 = 0;
    DAT_00052acc = 0xac44;
    DAT_00052ace = 20000;
    _DAT_000669da = 3;
    DAT_000669d8 = 0;
    FUN_00015cc4(&DAT_00052a14);
    FUN_00015cc4(&DAT_00052a30);
    FUN_0001556c(&DAT_00052860);
    FUN_0001556c(&DAT_000528a0);
    FUN_0001556c(&DAT_00052820);
    FUN_00015798(FUN_000158b0);
    DAT_00067eec = 1;
    iVar1 = FUN_00015624();
    if ((iVar1 != 0) &&
       (DAT_000671fc = (undefined *)FUN_00016608(param_1), DAT_000671fc != (undefined *)0x0)) {
      FUN_00019230(DAT_000671fc);
      DAT_000669dc = *DAT_000671fc;
      FUN_00015718();
      DAT_000b1594 = 1;
      DAT_000671f8 = 1;
      DAT_00067200 = param_1;
    }
  }
  return;
}


/* ======== StopModule @ 000159f8 ======== */

void StopModule(void)

{
  if (DAT_000671f8 != 0) {
    DAT_000b1594 = 0;
    FUN_00015748();
    FUN_000164e4(DAT_000671fc);
    FUN_000156f8();
    DAT_000671f8 = 0;
  }
  return;
}


/* ======== FUN_00015ab0 @ 00015ab0 ======== */

bool FUN_00015ab0(byte param_1,char unaff_DL)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined4 local_28;
  undefined4 local_20;
  
  if (param_1 < 8) {
    local_20 = 0x21;
    local_28 = 0x20;
  }
  else {
    local_20 = 0xa1;
    local_28 = 0xa0;
  }
  bVar1 = '\x01' << (param_1 & 7);
  bVar2 = FUN_00033e30(local_20);
  if (unaff_DL == '\0') {
    uVar3 = FUN_00033e30(local_20);
    FUN_00033e1b(local_20,bVar1 | uVar3);
  }
  else {
    uVar4 = FUN_00033e30(local_20,~(uint)bVar1);
    FUN_00033e1b(local_20,(uint)((ulonglong)uVar4 >> 0x20) & (uint)uVar4);
    FUN_00033e1b(local_28,param_1 & 7 | 0x60);
    if (7 < param_1) {
      FUN_00015ab0(2,1);
    }
  }
  return (bVar2 & bVar1) == 0;
}


/* ======== FUN_00015bb0 @ 00015bb0 ======== */

void FUN_00015bb0(byte param_1)

{
  FUN_00033e1b(0x20,0x20);
  if (7 < param_1) {
    FUN_00033e1b(0xa0,0x20);
  }
  return;
}


/* ======== FUN_00015bf0 @ 00015bf0 ======== */

undefined8 FUN_00015bf0(byte param_1,undefined4 param_2,undefined4 unaff_EBX,undefined2 unaff_CX)

{
  undefined6 uVar1;
  undefined2 uStack_2a;
  int local_1c;
  
  if (param_1 < 8) {
    local_1c = param_1 + 8;
  }
  else {
    local_1c = param_1 + 0x68;
  }
  uVar1 = FUN_000347e5(local_1c);
  FUN_00034817(local_1c,local_1c,unaff_EBX,unaff_CX);
  return CONCAT26(uStack_2a,uVar1);
}


/* ======== FUN_00015cc4 @ 00015cc4 ======== */

void FUN_00015cc4(int *param_1)

{
  if (DAT_00067354 == (int *)0x0) {
    DAT_00067354 = param_1;
    *param_1 = 0;
  }
  else {
    *param_1 = (int)DAT_00067354;
    DAT_00067354 = param_1;
  }
  return;
}


/* ======== FUN_00015d0c @ 00015d0c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00015d0c(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = malloc(param_1);
  if (iVar1 == 0) {
    _DAT_00067358 = s_Blad_przy_alokacji_struktury_00059754;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_00015d48 @ 00015d48 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00015d48(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_00034844(param_1,unaff_EDX);
  if (iVar1 == 0) {
    _DAT_00067358 = s_Blad_przy_alokacji_struktury_00059771;
  }
  return iVar1;
}


/* ======== FUN_00015e34 @ 00015e34 ======== */

undefined8 FUN_00015e34(undefined4 param_1,undefined4 unaff_EDX)

{
  short sVar1;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  sVar1 = 0;
  DAT_00067346 = FUN_00015d48((uint)DAT_0006720d * (uint)DAT_00067208,2);
  if (DAT_00067346 == 0) {
    local_28 = 0;
  }
  else {
    DAT_0006734a = FUN_00015d48(DAT_0006720d,2);
    if (DAT_0006734a == 0) {
      local_28 = 0;
    }
    else {
      for (local_20 = 0; local_20 < (int)(uint)DAT_0006720d; local_20 = local_20 + 1) {
        *(undefined2 *)(local_20 * 2 + DAT_0006734a) = 0x40;
        for (local_24 = 0; local_24 < (int)(uint)DAT_00067208; local_24 = local_24 + 1) {
          *(short *)(((uint)DAT_00067208 * local_20 + local_24) * 2 + DAT_00067346) = sVar1;
          sVar1 = sVar1 + 1;
        }
      }
      local_28 = 1;
    }
  }
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_00015f2c @ 00015f2c ======== */

undefined8 FUN_00015f2c(undefined4 param_1,undefined4 unaff_EDX)

{
  uint local_1c;
  
  DAT_0006734e = FUN_00015d48(DAT_0006720f,4);
  local_1c = (uint)(DAT_0006734e != 0);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00015f74 @ 00015f74 ======== */

undefined8 FUN_00015f74(undefined4 param_1,undefined4 unaff_EDX)

{
  uint local_20;
  
  DAT_00067342 = FUN_00015d48(DAT_00067211,0xd9);
  local_20 = (uint)(DAT_00067342 != 0);
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00015fbc @ 00015fbc ======== */

undefined8 FUN_00015fbc(byte *param_1,undefined4 unaff_EDX)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  
  uVar2 = (ushort)*param_1;
  if (uVar2 != 0) {
    uVar3 = FUN_00015d48(uVar2,0x1d);
    *(undefined4 *)(param_1 + 0xd5) = uVar3;
    if (*(int *)(param_1 + 0xd5) == 0) {
      local_28 = 0;
      goto LAB_0001605f;
    }
    for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
      *(undefined *)(*(int *)(param_1 + 0xd5) + (uint)uVar1 * 0x1d + 4) = 0x80;
      *(undefined2 *)(*(int *)(param_1 + 0xd5) + (uint)uVar1 * 0x1d + 0x1b) = 0xffff;
    }
  }
  local_28 = 1;
LAB_0001605f:
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_0001606c @ 0001606c ======== */

int FUN_0001606c(int param_1,ushort unaff_DX)

{
  ushort uVar1;
  undefined local_28;
  int local_24;
  
  local_24 = 0;
  while ((unaff_DX != 0 && (*(byte *)((uint)unaff_DX + param_1 + -1) < 0x21))) {
    unaff_DX = unaff_DX - 1;
  }
  if ((unaff_DX != 0) && (local_24 = malloc(unaff_DX + 1), local_24 != 0)) {
    for (uVar1 = 0; uVar1 < unaff_DX; uVar1 = uVar1 + 1) {
      if (*(byte *)((uint)uVar1 + param_1) < 0x20) {
        local_28 = 0x20;
      }
      else {
        local_28 = *(undefined *)((uint)uVar1 + param_1);
      }
      *(undefined *)((uint)uVar1 + local_24) = local_28;
    }
    *(undefined *)((uint)uVar1 + local_24) = 0;
  }
  return local_24;
}


/* ======== FUN_00016144 @ 00016144 ======== */

undefined8 FUN_00016144(undefined4 param_1,undefined4 unaff_EDX)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 local_2c;
  
  uVar1 = 0;
  do {
    if (DAT_00067211 <= uVar1) {
      local_2c = 1;
LAB_00016232:
      return CONCAT44(unaff_EDX,local_2c);
    }
    pbVar5 = (byte *)(DAT_00067342 + (uint)uVar1 * 0xd9);
    for (uVar2 = 0; uVar2 < *pbVar5; uVar2 = uVar2 + 1) {
      iVar4 = *(int *)(pbVar5 + 0xd5) + (uint)uVar2 * 0x1d;
      if (*(int *)(iVar4 + 5) != 0) {
        if (*(int *)(iVar4 + 0x13) != 0) {
          FUN_00016670(DAT_00067204,*(undefined4 *)(iVar4 + 0x13),0);
        }
        uVar3 = FUN_000155b4(DAT_00067204,*(undefined4 *)(iVar4 + 5),*(undefined4 *)(iVar4 + 9),
                             *(undefined4 *)(iVar4 + 0xd),*(undefined2 *)(iVar4 + 0x11));
        *(undefined2 *)(iVar4 + 0x1b) = uVar3;
        if (*(short *)(iVar4 + 0x1b) < 0) {
          local_2c = 0;
          goto LAB_00016232;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while( true );
}


/* ======== FUN_0001623c @ 0001623c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001623c(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  
  local_20 = 0;
  for (local_1c = DAT_00067354; local_1c != (undefined4 *)0x0; local_1c = (undefined4 *)*local_1c) {
    FUN_00016670(DAT_00067204,0);
    iVar1 = (*(code *)local_1c[4])();
    if (iVar1 != 0) break;
  }
  if (local_1c == (undefined4 *)0x0) {
    _DAT_00067358 = s_Nieznany_format_modulu_0005978e;
    local_24 = 0;
  }
  else {
    iVar1 = FUN_00019918();
    if (iVar1 == 0) {
      local_24 = 0;
    }
    else {
      iVar1 = (*(code *)local_1c[3])();
      if (iVar1 != 0) {
        FUN_00016670(DAT_00067204,0,0);
        local_20 = (*(code *)local_1c[5])();
      }
      (*(code *)local_1c[6])();
      FUN_00019970();
      local_24 = local_20;
    }
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_000162e8 @ 000162e8 ======== */

void FUN_000162e8(byte *param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0xd5) != 0) {
    for (uVar1 = 0; uVar1 < *param_1; uVar1 = uVar1 + 1) {
      if (-1 < *(short *)(*(int *)(param_1 + 0xd5) + (uint)uVar1 * 0x1d + 0x1b)) {
        FUN_000155fc((int)*(short *)(*(int *)(param_1 + 0xd5) + (uint)uVar1 * 0x1d + 0x1b));
      }
    }
    free(*(undefined4 *)(param_1 + 0xd5));
  }
  if (*(int *)(param_1 + 0xd1) != 0) {
    free(*(undefined4 *)(param_1 + 0xd1));
  }
  return;
}


/* ======== FUN_00016388 @ 00016388 ======== */

void FUN_00016388(int param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0x132) != 0) {
    free(*(undefined4 *)(param_1 + 0x132));
  }
  if (*(int *)(param_1 + 0x13e) != 0) {
    free(*(undefined4 *)(param_1 + 0x13e));
  }
  if (*(int *)(param_1 + 0x142) != 0) {
    free(*(undefined4 *)(param_1 + 0x142));
  }
  if (*(int *)(param_1 + 0x146) != 0) {
    for (uVar1 = 0; uVar1 < *(ushort *)(param_1 + 7); uVar1 = uVar1 + 1) {
      if (*(int *)(*(int *)(param_1 + 0x146) + (uint)uVar1 * 4) != 0) {
        free(*(undefined4 *)(*(int *)(param_1 + 0x146) + (uint)uVar1 * 4));
      }
    }
    free(*(undefined4 *)(param_1 + 0x146));
  }
  if (*(int *)(param_1 + 0x13a) != 0) {
    for (uVar1 = 0; uVar1 < *(ushort *)(param_1 + 9); uVar1 = uVar1 + 1) {
      FUN_000162e8(*(int *)(param_1 + 0x13a) + (uint)uVar1 * 0xd9);
    }
    free(*(undefined4 *)(param_1 + 0x13a));
  }
  if (*(int *)(param_1 + 0x12e) != 0) {
    free(*(undefined4 *)(param_1 + 0x12e));
  }
  if (*(int *)(param_1 + 0x136) != 0) {
    free(*(undefined4 *)(param_1 + 0x136));
  }
  return;
}


/* ======== FUN_000164e4 @ 000164e4 ======== */

void FUN_000164e4(int param_1)

{
  if (param_1 != 0) {
    FUN_00016388(param_1);
    free(param_1);
  }
  return;
}


/* ======== FUN_00016514 @ 00016514 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016514(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined local_2c;
  int local_28;
  int local_24;
  
  _DAT_00067358 = 0;
  DAT_00067204 = param_1;
  iVar1 = memset(&DAT_00067208,0,0x14a);
  for (local_24 = 0; local_24 < 0x20; local_24 = local_24 + 1) {
    if ((local_24 + 1U & 2) == 0) {
      local_2c = 0;
    }
    else {
      local_2c = 0xff;
    }
    (&DAT_00067315)[local_24] = local_2c;
    iVar1 = local_24;
  }
  iVar1 = FUN_0001623c(iVar1);
  if (iVar1 == 0) {
    FUN_00016388(&DAT_00067208);
    local_28 = 0;
  }
  else {
    iVar1 = FUN_00016144();
    if (iVar1 == 0) {
      FUN_00016388(&DAT_00067208);
      local_28 = 0;
    }
    else {
      local_28 = FUN_00015d48(1,0x14a);
      if (local_28 == 0) {
        FUN_00016388(&DAT_00067208);
        local_28 = 0;
      }
      else {
        FUN_00034682(local_28,&DAT_00067208,0x14a);
      }
    }
  }
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_00016608 @ 00016608 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00016608(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 local_28;
  
  iVar1 = fopen(param_1,&DAT_000597a5);
  if (iVar1 == 0) {
    _DAT_00067358 = s_Blad_otwarcia_pliku_000597a8;
    local_28 = 0;
  }
  else {
    local_28 = FUN_00016514(iVar1);
    fclose(iVar1);
  }
  return CONCAT44(unaff_EDX,local_28);
}


/* ======== FUN_00016670 @ 00016670 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00016670(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  undefined4 uVar1;
  int local_24;
  
  local_24 = unaff_EDX;
  if (unaff_EBX == 0) {
    local_24 = unaff_EDX + _DAT_0006735c;
  }
  uVar1 = FUN_00034c7f(param_1,local_24,unaff_EBX);
  return uVar1;
}


/* ======== FUN_0001670c @ 0001670c ======== */

void FUN_0001670c(undefined param_1,undefined4 unaff_EDX)

{
  FUN_00034dbd(param_1,unaff_EDX);
  return;
}


/* ======== FUN_00016734 @ 00016734 ======== */

void FUN_00016734(undefined param_1,undefined4 unaff_EDX)

{
  FUN_00034dbd(param_1,unaff_EDX);
  return;
}


/* ======== FUN_0001675c @ 0001675c ======== */

void FUN_0001675c(uint param_1,undefined4 unaff_EDX)

{
  FUN_00016734((int)(param_1 & 0xffff) >> 8,unaff_EDX);
  FUN_00016734(param_1 & 0xff,unaff_EDX);
  return;
}


/* ======== FUN_00016798 @ 00016798 ======== */

void FUN_00016798(uint param_1,undefined4 unaff_EDX)

{
  FUN_00016734(param_1 & 0xff,unaff_EDX);
  FUN_00016734((int)(param_1 & 0xffff) >> 8,unaff_EDX);
  return;
}


/* ======== FUN_000167d4 @ 000167d4 ======== */

void FUN_000167d4(undefined2 param_1,undefined4 unaff_EDX)

{
  FUN_0001675c(param_1,unaff_EDX);
  return;
}


/* ======== FUN_000167fc @ 000167fc ======== */

void FUN_000167fc(undefined2 param_1,undefined4 unaff_EDX)

{
  FUN_00016798(param_1,unaff_EDX);
  return;
}


/* ======== FUN_00016824 @ 00016824 ======== */

void FUN_00016824(uint param_1,undefined4 unaff_EDX)

{
  FUN_0001675c(param_1 >> 0x10,unaff_EDX);
  FUN_0001675c(param_1 & 0xffff,unaff_EDX);
  return;
}


/* ======== FUN_0001685c @ 0001685c ======== */

void FUN_0001685c(uint param_1,undefined4 unaff_EDX)

{
  FUN_00016798(param_1 & 0xffff,unaff_EDX);
  FUN_00016798(param_1 >> 0x10,unaff_EDX);
  return;
}


/* ======== FUN_00016894 @ 00016894 ======== */

void FUN_00016894(undefined4 param_1,undefined4 unaff_EDX)

{
  FUN_00016824(param_1,unaff_EDX);
  return;
}


/* ======== FUN_000168b8 @ 000168b8 ======== */

void FUN_000168b8(undefined4 param_1,undefined4 unaff_EDX)

{
  FUN_0001685c(param_1,unaff_EDX);
  return;
}


/* ======== FUN_00016b34 @ 00016b34 ======== */

undefined8 FUN_00016b34(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00034e61(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016b5c @ 00016b5c ======== */

undefined8 FUN_00016b5c(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00034e61(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016b84 @ 00016b84 ======== */

undefined8 FUN_00016b84(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00016b5c(param_1);
  uVar2 = FUN_00016b5c(param_1);
  return CONCAT44(unaff_EDX,
                  CONCAT22((short)((uint)uVar1 >> 0x10),(ushort)(byte)uVar1) << 8 |
                  CONCAT22((short)((uint)uVar2 >> 0x10),(ushort)(byte)uVar2));
}


/* ======== FUN_00016bc8 @ 00016bc8 ======== */

undefined8 FUN_00016bc8(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00016b5c(param_1);
  uVar2 = FUN_00016b5c(param_1);
  return CONCAT44(unaff_EDX,
                  CONCAT22((short)((uint)uVar1 >> 0x10),(ushort)(byte)uVar1) |
                  CONCAT22((short)((uint)uVar2 >> 0x10),(ushort)(byte)uVar2) << 8);
}


/* ======== FUN_00016c0c @ 00016c0c ======== */

undefined8 FUN_00016c0c(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00016b84(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016c34 @ 00016c34 ======== */

undefined8 FUN_00016c34(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00016bc8(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016c5c @ 00016c5c ======== */

undefined8 FUN_00016c5c(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00016b84(param_1);
  uVar2 = FUN_00016b84(param_1);
  return CONCAT44(unaff_EDX,iVar1 << 0x10 | uVar2 & 0xffff);
}


/* ======== FUN_00016c9c @ 00016c9c ======== */

undefined8 FUN_00016c9c(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_00016bc8(param_1);
  iVar2 = FUN_00016bc8(param_1);
  return CONCAT44(unaff_EDX,uVar1 & 0xffff | iVar2 << 0x10);
}


/* ======== FUN_00016cdc @ 00016cdc ======== */

undefined8 FUN_00016cdc(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00016c5c(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016d04 @ 00016d04 ======== */

undefined8 FUN_00016d04(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00016c9c(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00016d2c @ 00016d2c ======== */

bool FUN_00016d2c(undefined4 param_1,undefined4 unaff_EDX,int unaff_EBX)

{
  fread(param_1,1,unaff_EDX,unaff_EBX);
  return (*(byte *)(unaff_EBX + 0xc) & 0x10) == 0;
}


/* ======== FUN_00016dd8 @ 00016dd8 ======== */

bool FUN_00016dd8(undefined *param_1,int unaff_EDX,int unaff_EBX)

{
  undefined uVar1;
  undefined *local_1c;
  
  local_1c = param_1;
  for (; 0 < unaff_EDX; unaff_EDX = unaff_EDX + -1) {
    uVar1 = FUN_00016b5c(unaff_EBX);
    *local_1c = uVar1;
    local_1c = local_1c + 1;
  }
  return (*(byte *)(unaff_EBX + 0xc) & 0x10) == 0;
}


/* ======== FUN_00016f48 @ 00016f48 ======== */

bool FUN_00016f48(undefined2 *param_1,int unaff_EDX,int unaff_EBX)

{
  undefined2 uVar1;
  undefined2 *local_1c;
  
  local_1c = param_1;
  for (; 0 < unaff_EDX; unaff_EDX = unaff_EDX + -1) {
    uVar1 = FUN_00016bc8(unaff_EBX);
    *local_1c = uVar1;
    local_1c = local_1c + 1;
  }
  return (*(byte *)(unaff_EBX + 0xc) & 0x10) == 0;
}


/* ======== FUN_00017120 @ 00017120 ======== */

int FUN_00017120(short param_1,short unaff_DX,short unaff_BX,int unaff_ECX,short param_5)

{
  int local_2c;
  short local_24;
  
  local_2c = unaff_ECX;
  if (unaff_DX != unaff_BX) {
    local_24 = param_5 - (short)unaff_ECX;
    local_2c = ((int)local_24 * (int)(short)(param_1 - unaff_DX)) /
               (int)(short)(unaff_BX - unaff_DX) + (int)(short)unaff_ECX;
  }
  return local_2c;
}


/* ======== FUN_0001718c @ 0001718c ======== */

int FUN_0001718c(byte param_1,ushort unaff_DX)

{
  return ((uint)param_1 * -0x40 - unaff_DX / 2) + 0x1e40;
}


/* ======== FUN_000171d0 @ 000171d0 ======== */

int FUN_000171d0(byte param_1,uint unaff_EDX)

{
  short sVar1;
  int iVar2;
  
  iVar2 = ((int)(unaff_EDX & 0xffff) >> 4) + (uint)(param_1 % 0xc) * 8;
  sVar1 = FUN_00017120((short)((int)(unaff_EDX & 0xffff) >> 4),0,0xf,
                       (int)*(short *)(&DAT_00053158 + iVar2 * 2),
                       (int)*(short *)(&DAT_0005315a + iVar2 * 2));
  return (int)sVar1 >> param_1 / 0xc;
}


/* ======== FUN_0001727c @ 0001727c ======== */

int FUN_0001727c(byte param_1,ushort unaff_DX)

{
  int local_28;
  
  if (unaff_DX == 0) {
    local_28 = 0x1092;
  }
  else {
    local_28 = ((int)((uint)*(ushort *)(&DAT_00052b1e + (uint)(param_1 % 0xc) * 2) * 0x20ab) >>
               param_1 / 0xc) / (int)(uint)unaff_DX;
  }
  return local_28;
}


/* ======== FUN_00017300 @ 00017300 ======== */

undefined4 FUN_00017300(undefined param_1,undefined2 unaff_DX)

{
  undefined4 local_24;
  undefined4 local_20;
  
  if ((*(byte *)(DAT_00067360 + 0x12d) & 1) == 0) {
    local_24 = FUN_0001727c(param_1,unaff_DX);
  }
  else {
    if ((*(byte *)(DAT_00067360 + 0x12d) & 2) == 0) {
      local_20 = FUN_000171d0(param_1,unaff_DX);
    }
    else {
      local_20 = FUN_0001718c(param_1,unaff_DX);
    }
    local_24 = local_20;
  }
  return local_24;
}


/* ======== FUN_00017374 @ 00017374 ======== */

/* WARNING: Removing unreachable block (ram,0x00017556) */

void FUN_00017374(byte param_1)

{
  byte bVar1;
  
  bVar1 = param_1 & 0xf;
  switch((int)(uint)param_1 >> 4) {
  case 0:
    break;
  case 1:
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) + (ushort)bVar1 * -4;
    }
    break;
  case 2:
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) + (ushort)bVar1 * 4;
    }
    break;
  case 3:
    *(byte *)(DAT_00067ef4 + 0x51) = bVar1;
    break;
  case 4:
    *(byte *)(DAT_00067ef4 + 0x52) = *(byte *)(DAT_00067ef4 + 0x52) & 0xf0;
    *(byte *)(DAT_00067ef4 + 0x52) = *(byte *)(DAT_00067ef4 + 0x52) | bVar1;
    break;
  case 5:
    break;
  case 6:
    if (DAT_00067368 == 0) {
      if (bVar1 == 0) {
        DAT_00067364 = DAT_00067ede + -1;
      }
      else {
        if (DAT_00067366 == 0) {
          DAT_00067366 = (ushort)bVar1;
        }
        else {
          DAT_00067366 = DAT_00067366 - 1;
        }
        if (DAT_00067366 != 0) {
          DAT_00067ede = DAT_00067364;
        }
      }
    }
    break;
  case 7:
    *(byte *)(DAT_00067ef4 + 0x52) = *(byte *)(DAT_00067ef4 + 0x52) & 0xf;
    *(byte *)(DAT_00067ef4 + 0x52) = *(byte *)(DAT_00067ef4 + 0x52) | bVar1 << 4;
    break;
  case 8:
    if (DAT_00067ee8 != 0) {
      *(byte *)(DAT_00067ef4 + 0x31) = bVar1 << 4;
      *(byte *)(DAT_00067360 + (uint)DAT_00067ee4 + 0x10d) = bVar1 << 4;
    }
    break;
  case 9:
    if (bVar1 != 0) {
      if (*(char *)(DAT_00067ef4 + 0x40) == '\0') {
        *(undefined *)(DAT_00067ef4 + 0x29) = 1;
        *(byte *)(DAT_00067ef4 + 0x40) = bVar1;
      }
      *(char *)(DAT_00067ef4 + 0x40) = *(char *)(DAT_00067ef4 + 0x40) + -1;
    }
    break;
  case 10:
    if ((DAT_00067368 == 0) &&
       (*(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) + bVar1,
       0x40 < *(byte *)(DAT_00067ef4 + 0x43))) {
      *(undefined *)(DAT_00067ef4 + 0x43) = 0x40;
    }
    break;
  case 0xb:
    if (DAT_00067368 == 0) {
      *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) - bVar1;
    }
    break;
  case 0xc:
    if (bVar1 <= DAT_00067368) {
      *(undefined *)(DAT_00067ef4 + 0x43) = 0;
    }
    break;
  case 0xd:
    if (DAT_00067368 == bVar1) {
      *(undefined *)(DAT_00067ef4 + 0x29) = 1;
    }
    else {
      *(undefined *)(DAT_00067ef4 + 0x29) = 0;
    }
    break;
  case 0xe:
    if ((DAT_00067368 == 0) && (DAT_0006736d == '\0')) {
      DAT_0006736c = bVar1 + 1;
    }
    break;
  case 0xf:
  }
  return;
}


/* ======== FUN_00017630 @ 00017630 ======== */

/* WARNING: Removing unreachable block (ram,0x00017684) */
/* WARNING: Removing unreachable block (ram,0x000176fd) */
/* WARNING: Removing unreachable block (ram,0x000176bb) */

void FUN_00017630(void)

{
  byte bVar1;
  byte bVar2;
  ushort local_20;
  
  bVar1 = (byte)((int)(uint)*(byte *)(DAT_00067ef4 + 0x53) >> 2) & 0x1f;
  bVar2 = *(byte *)(DAT_00067ef4 + 0x52) & 3;
  if (bVar2 == 0) {
    local_20 = (ushort)(byte)(&DAT_00052b38)[bVar1];
  }
  else if (bVar2 < 2) {
    local_20 = (ushort)(byte)(bVar1 << 3);
  }
  else if (bVar2 == 2) {
    local_20 = 0xff;
  }
  *(ushort *)(DAT_00067ef4 + 0x34) =
       *(short *)(DAT_00067ef4 + 0x44) +
       ((ushort)(local_20 * *(byte *)(DAT_00067ef4 + 0x55)) >> 7) * 4;
  if (DAT_00067368 != 0) {
    *(char *)(DAT_00067ef4 + 0x53) = *(char *)(DAT_00067ef4 + 0x53) + *(char *)(DAT_00067ef4 + 0x54)
    ;
  }
  return;
}


/* ======== FUN_00017734 @ 00017734 ======== */

/* WARNING: Removing unreachable block (ram,0x00017814) */
/* WARNING: Removing unreachable block (ram,0x0001778a) */
/* WARNING: Removing unreachable block (ram,0x00017834) */
/* WARNING: Removing unreachable block (ram,0x000177c1) */

void FUN_00017734(void)

{
  byte bVar1;
  uint uVar2;
  ushort local_20;
  
  bVar1 = (byte)((int)(uint)*(byte *)(DAT_00067ef4 + 0x56) >> 2) & 0x1f;
  uVar2 = (int)(uint)*(byte *)(DAT_00067ef4 + 0x52) >> 4 & 3;
  if (uVar2 == 0) {
    local_20 = (ushort)(byte)(&DAT_00052b38)[bVar1];
  }
  else if (uVar2 < 2) {
    local_20 = (ushort)(byte)(bVar1 << 3);
  }
  else if (uVar2 == 2) {
    local_20 = 0xff;
  }
  local_20._0_1_ = (char)((ushort)(local_20 * *(byte *)(DAT_00067ef4 + 0x58)) >> 6);
  *(char *)(DAT_00067ef4 + 0x33) = *(char *)(DAT_00067ef4 + 0x43) + (char)local_20;
  if (0x40 < *(byte *)(DAT_00067ef4 + 0x33)) {
    *(undefined *)(DAT_00067ef4 + 0x33) = 0x40;
  }
  if (DAT_00067368 != 0) {
    *(char *)(DAT_00067ef4 + 0x56) = *(char *)(DAT_00067ef4 + 0x56) + *(char *)(DAT_00067ef4 + 0x57)
    ;
  }
  return;
}


/* ======== FUN_00017860 @ 00017860 ======== */

/* WARNING: Removing unreachable block (ram,0x000178ab) */

void FUN_00017860(byte param_1)

{
  if (DAT_00067368 != 0) {
    *(char *)(DAT_00067ef4 + 0x43) =
         *(char *)(DAT_00067ef4 + 0x43) + (char)((int)(uint)param_1 >> 4);
    *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) - (param_1 & 0xf);
    if (0x40 < *(byte *)(DAT_00067ef4 + 0x43)) {
      *(undefined *)(DAT_00067ef4 + 0x43) = 0x40;
    }
  }
  return;
}


/* ======== FUN_000178d4 @ 000178d4 ======== */

/* WARNING: Removing unreachable block (ram,0x0001798d) */

void FUN_000178d4(char param_1)

{
  byte bVar1;
  char cVar2;
  
  if (param_1 != '\0') {
    *(char *)(DAT_00067ef4 + 0x4e) = param_1;
  }
  bVar1 = *(byte *)(DAT_00067ef4 + 0x4e) & 0xf;
  cVar2 = (char)((int)(uint)*(byte *)(DAT_00067ef4 + 0x4e) >> 4);
  if (cVar2 == '\0') {
    *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) - bVar1;
  }
  else if (bVar1 == 0) {
    *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) + cVar2;
  }
  else if (cVar2 == '\x0f') {
    if (DAT_00067368 == 0) {
      *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) - bVar1;
    }
  }
  else if ((bVar1 == 0xf) && (DAT_00067368 == 0)) {
    *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) + cVar2;
  }
  if (0x40 < *(byte *)(DAT_00067ef4 + 0x43)) {
    *(undefined *)(DAT_00067ef4 + 0x43) = 0x40;
  }
  return;
}


/* ======== FUN_000179b4 @ 000179b4 ======== */

/* WARNING: Removing unreachable block (ram,0x00017a2d) */

void FUN_000179b4(char param_1)

{
  char cVar1;
  
  if (param_1 != '\0') {
    *(char *)(DAT_00067ef4 + 0x4e) = param_1;
  }
  if (DAT_00067368 != 0) {
    cVar1 = (char)((int)(uint)*(byte *)(DAT_00067ef4 + 0x4e) >> 4);
    if (cVar1 == '\0') {
      *(char *)(DAT_00067ef4 + 0x43) =
           *(char *)(DAT_00067ef4 + 0x43) - (*(byte *)(DAT_00067ef4 + 0x4e) & 0xf);
    }
    else {
      *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) + cVar1;
    }
    if (0x40 < *(byte *)(DAT_00067ef4 + 0x43)) {
      *(undefined *)(DAT_00067ef4 + 0x43) = 0x40;
    }
  }
  return;
}


/* ======== FUN_00017a58 @ 00017a58 ======== */

/* WARNING: Removing unreachable block (ram,0x00017ac2) */

void FUN_00017a58(byte param_1)

{
  char cVar1;
  
  if (param_1 != 0) {
    DAT_00067ef0 = param_1;
  }
  if (DAT_00067368 != 0) {
    cVar1 = (char)((int)(uint)DAT_00067ef0 >> 4);
    if (cVar1 == '\0') {
      cVar1 = -(DAT_00067ef0 & 0xf);
    }
    DAT_00052b1d = DAT_00052b1d + cVar1;
    if (0x40 < DAT_00052b1d) {
      DAT_00052b1d = 0x40;
    }
  }
  return;
}


/* ======== FUN_00017ae8 @ 00017ae8 ======== */

void FUN_00017ae8(byte param_1)

{
  int local_28;
  byte local_24;
  byte local_1c;
  
  if (param_1 == 0) {
    local_1c = *(byte *)(DAT_00067ef4 + 0x32);
  }
  else {
    *(byte *)(DAT_00067ef4 + 0x32) = param_1;
    local_1c = param_1;
  }
  if (DAT_00067368 != 0) {
    local_24 = local_1c & 0xf;
    if ((char)((int)(uint)local_1c >> 4) != '\0') {
      local_24 = 0;
    }
    local_28 = ((uint)*(byte *)(DAT_00067ef4 + 0x31) - (uint)local_24) + ((int)(uint)local_1c >> 4);
    if ((short)local_28 < 0) {
      local_28 = 0;
    }
    if (0xff < (short)local_28) {
      local_28 = 0xff;
    }
    *(undefined *)(DAT_00067ef4 + 0x31) = (undefined)local_28;
  }
  return;
}


/* ======== FUN_00017b94 @ 00017b94 ======== */

void FUN_00017b94(byte param_1)

{
  char cVar1;
  byte local_1c;
  
  if (param_1 == 0) {
    local_1c = *(byte *)(DAT_00067ef4 + 0x48);
  }
  else {
    *(ushort *)(DAT_00067ef4 + 0x48) = (ushort)param_1;
    local_1c = param_1;
  }
  cVar1 = (char)((int)(uint)local_1c >> 4);
  if (cVar1 == '\x0f') {
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) =
           *(short *)(DAT_00067ef4 + 0x44) + (ushort)(local_1c & 0xf) * 4;
    }
  }
  else if (cVar1 == '\x0e') {
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) + (ushort)(local_1c & 0xf);
    }
  }
  else if (DAT_00067368 != 0) {
    *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) + (ushort)local_1c * 4;
  }
  return;
}


/* ======== FUN_00017c48 @ 00017c48 ======== */

void FUN_00017c48(byte param_1)

{
  char cVar1;
  byte local_1c;
  
  if (param_1 == 0) {
    local_1c = *(byte *)(DAT_00067ef4 + 0x48);
  }
  else {
    *(ushort *)(DAT_00067ef4 + 0x48) = (ushort)param_1;
    local_1c = param_1;
  }
  cVar1 = (char)((int)(uint)local_1c >> 4);
  if (cVar1 == '\x0f') {
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) =
           *(short *)(DAT_00067ef4 + 0x44) + (ushort)(local_1c & 0xf) * -4;
    }
  }
  else if (cVar1 == '\x0e') {
    if (DAT_00067368 == 0) {
      *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) - (ushort)(local_1c & 0xf);
    }
  }
  else if (DAT_00067368 != 0) {
    *(short *)(DAT_00067ef4 + 0x44) = *(short *)(DAT_00067ef4 + 0x44) + (ushort)local_1c * -4;
  }
  return;
}


/* ======== FUN_00017cfc @ 00017cfc ======== */

void FUN_00017cfc(byte param_1)

{
  undefined uVar1;
  byte bVar2;
  byte local_1c;
  
  if (param_1 == 0) {
    local_1c = *(byte *)(DAT_00067ef4 + 0x4d);
  }
  else {
    *(byte *)(DAT_00067ef4 + 0x4d) = param_1;
    local_1c = param_1;
  }
  if (DAT_00067368 != 0) {
    bVar2 = (char)((int)(uint)local_1c >> 4) + 1;
    *(byte *)(DAT_00067ef4 + 0x4c) =
         *(byte *)(DAT_00067ef4 + 0x4c) % (byte)(bVar2 + (local_1c & 0xf) + 1);
    if (*(byte *)(DAT_00067ef4 + 0x4c) < bVar2) {
      uVar1 = *(undefined *)(DAT_00067ef4 + 0x43);
    }
    else {
      uVar1 = 0;
    }
    *(undefined *)(DAT_00067ef4 + 0x33) = uVar1;
    *(char *)(DAT_00067ef4 + 0x4c) = *(char *)(DAT_00067ef4 + 0x4c) + '\x01';
  }
  return;
}


/* ======== FUN_00017da8 @ 00017da8 ======== */

/* WARNING: Removing unreachable block (ram,0x00017f63) */

void FUN_00017da8(byte param_1)

{
  byte bVar1;
  char cVar2;
  
  cVar2 = (char)((int)(uint)param_1 >> 4);
  if ((param_1 & 0xf) != 0) {
    *(char *)(DAT_00067ef4 + 0x50) = cVar2;
    *(byte *)(DAT_00067ef4 + 0x4f) = param_1 & 0xf;
  }
  if (cVar2 != '\0') {
    *(char *)(DAT_00067ef4 + 0x50) = cVar2;
  }
  if (*(char *)(DAT_00067ef4 + 0x4f) != '\0') {
    if (*(char *)(DAT_00067ef4 + 0x40) == '\0') {
      *(undefined *)(DAT_00067ef4 + 0x29) = 1;
      *(undefined *)(DAT_00067ef4 + 0x40) = *(undefined *)(DAT_00067ef4 + 0x4f);
      if (DAT_00067368 != 0) {
        bVar1 = *(byte *)(DAT_00067ef4 + 0x50);
        if (bVar1 < 7) {
          if (bVar1 != 0) {
            if (bVar1 < 6) {
              *(char *)(DAT_00067ef4 + 0x43) =
                   *(char *)(DAT_00067ef4 + 0x43) -
                   ('\x01' << (*(char *)(DAT_00067ef4 + 0x50) - 1U & 0x1f));
            }
            else {
              *(char *)(DAT_00067ef4 + 0x43) =
                   (char)(((uint)*(byte *)(DAT_00067ef4 + 0x43) * 2) / 3);
            }
          }
        }
        else if (bVar1 < 8) {
          *(char *)(DAT_00067ef4 + 0x43) = (char)((int)(uint)*(byte *)(DAT_00067ef4 + 0x43) >> 1);
        }
        else if (bVar1 < 0xe) {
          if (8 < bVar1) {
            *(char *)(DAT_00067ef4 + 0x43) =
                 *(char *)(DAT_00067ef4 + 0x43) +
                 ('\x01' << (*(char *)(DAT_00067ef4 + 0x50) - 9U & 0x1f));
          }
        }
        else if (bVar1 < 0xf) {
          *(char *)(DAT_00067ef4 + 0x43) = (char)(((uint)*(byte *)(DAT_00067ef4 + 0x43) * 3) / 2);
        }
        else if (bVar1 == 0xf) {
          *(char *)(DAT_00067ef4 + 0x43) = *(char *)(DAT_00067ef4 + 0x43) * '\x02';
        }
        if (0x40 < *(byte *)(DAT_00067ef4 + 0x43)) {
          *(undefined *)(DAT_00067ef4 + 0x43) = 0x40;
        }
      }
    }
    *(char *)(DAT_00067ef4 + 0x40) = *(char *)(DAT_00067ef4 + 0x40) + -1;
  }
  return;
}


/* ======== FUN_00017f94 @ 00017f94 ======== */

void FUN_00017f94(byte param_1)

{
  if (((DAT_00067368 == 0) && (DAT_0006736d == '\0')) && (param_1 != 0)) {
    DAT_00067ee2 = (ushort)param_1;
    DAT_00067368 = 0;
  }
  return;
}


/* ======== FUN_00017fdc @ 00017fdc ======== */

void FUN_00017fdc(undefined param_1)

{
  undefined uVar1;
  
  if ((DAT_00067368 != 0) || (uVar1 = param_1, DAT_0006736d != '\0')) {
    uVar1 = DAT_00067edc;
  }
  DAT_00067edc = uVar1;
  return;
}


/* ======== thunk_FUN_0001800a @ 00018000 ======== */

void thunk_FUN_0001800a(void)

{
  return;
}


/* ======== FUN_0001800a @ 0001800a ======== */

void FUN_0001800a(void)

{
  return;
}


/* ======== FUN_00018014 @ 00018014 ======== */

void FUN_00018014(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_00067368 != 0) {
    iVar1 = (uint)*(ushort *)(DAT_00067ef4 + 0x34) - (uint)*(ushort *)(DAT_00067ef4 + 0x46);
    if ((iVar1 == 0) ||
       (uVar2 = FUN_00034fc5(iVar1,*(undefined2 *)(DAT_00067ef4 + 0x4a)),
       (int)uVar2 < (int)((ulonglong)uVar2 >> 0x20))) {
      *(undefined2 *)(DAT_00067ef4 + 0x34) = *(undefined2 *)(DAT_00067ef4 + 0x46);
    }
    else if (iVar1 < 1) {
      *(short *)(DAT_00067ef4 + 0x34) =
           *(short *)(DAT_00067ef4 + 0x34) + *(short *)(DAT_00067ef4 + 0x4a);
    }
    else {
      *(short *)(DAT_00067ef4 + 0x34) =
           *(short *)(DAT_00067ef4 + 0x34) - *(short *)(DAT_00067ef4 + 0x4a);
    }
    *(undefined2 *)(DAT_00067ef4 + 0x44) = *(undefined2 *)(DAT_00067ef4 + 0x34);
    return;
  }
  *(undefined2 *)(DAT_00067ef4 + 0x44) = *(undefined2 *)(DAT_00067ef4 + 0x34);
  return;
}


/* ======== FUN_000180d4 @ 000180d4 ======== */

void FUN_000180d4(byte param_1)

{
  undefined2 uVar1;
  uint uVar2;
  char local_20;
  
  local_20 = *(char *)(DAT_00067ef4 + 0x37);
  if (param_1 != 0) {
    uVar2 = (uint)DAT_00067368 % 3;
    if (uVar2 != 0) {
      if (uVar2 < 2) {
        local_20 = local_20 + (char)((int)(uint)param_1 >> 4);
      }
      else if (uVar2 == 2) {
        local_20 = local_20 + (param_1 & 0xf);
      }
    }
    uVar1 = FUN_00017300(local_20 + *(char *)(DAT_00067ef4 + 0x36),
                         *(undefined2 *)(DAT_00067ef4 + 0x41));
    *(undefined2 *)(DAT_00067ef4 + 0x34) = uVar1;
    *(undefined2 *)(DAT_00067ef4 + 0x38) = 1;
  }
  return;
}


/* ======== FUN_00018188 @ 00018188 ======== */

void FUN_00018188(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  byte *pbVar4;
  undefined2 *puVar5;
  
  if (DAT_00067ef4[0xf] != (byte *)0x0) {
    FUN_00019480(DAT_00067ef4[0xf]);
    while (bVar1 = FUN_000194cc(), bVar1 != 0) {
      if (bVar1 == 0) {
LAB_000183f2:
        FUN_00019514(bVar1);
      }
      else if (bVar1 < 2) {
        cVar2 = FUN_000194cc();
        if (cVar2 == '`') {
          *(undefined *)(DAT_00067ef4 + 10) = 0;
          if ((*DAT_00067ef4 != (byte *)0x0) && (((*DAT_00067ef4)[0x61] & 1) == 0)) {
            *(undefined *)((int)DAT_00067ef4 + 0x43) = 0;
          }
        }
        else {
          *(char *)((int)DAT_00067ef4 + 0x37) = cVar2;
          uVar3 = FUN_00017300(cVar2 + *(char *)((int)DAT_00067ef4 + 0x36),
                               *(undefined2 *)((int)DAT_00067ef4 + 0x41));
          *(undefined2 *)((int)DAT_00067ef4 + 0x46) = uVar3;
          *(undefined2 *)(DAT_00067ef4 + 0x11) = uVar3;
          *(undefined *)((int)DAT_00067ef4 + 0x29) = 1;
          *(undefined4 *)((int)DAT_00067ef4 + 0x2d) = 0;
          if ((*(byte *)((int)DAT_00067ef4 + 0x52) & 0x80) == 0) {
            *(undefined *)((int)DAT_00067ef4 + 0x56) = 0;
          }
          if ((*(byte *)((int)DAT_00067ef4 + 0x52) & 8) == 0) {
            *(undefined *)((int)DAT_00067ef4 + 0x53) = 0;
          }
        }
      }
      else {
        if (bVar1 != 2) goto LAB_000183f2;
        bVar1 = FUN_000194cc();
        if ((ushort)bVar1 < *(ushort *)(DAT_00067360 + 9)) {
          *(byte *)((int)DAT_00067ef4 + 0x2a) = bVar1;
          pbVar4 = (byte *)(*(int *)(DAT_00067360 + 0x13a) + (uint)bVar1 * 0xd9);
          *DAT_00067ef4 = pbVar4;
          if (pbVar4[*(byte *)((int)DAT_00067ef4 + 0x37) + 1] < *pbVar4) {
            puVar5 = (undefined2 *)
                     (*(int *)(pbVar4 + 0xd5) +
                     (uint)pbVar4[*(byte *)((int)DAT_00067ef4 + 0x37) + 1] * 0x1d);
            DAT_00067ef4[1] = (byte *)puVar5;
            *(undefined *)((int)DAT_00067ef4 + 0x31) =
                 *(undefined *)(DAT_00067360 + (uint)DAT_00067ee4 + 0x10d);
            *(byte *)((int)DAT_00067ef4 + 0x36) = *(byte *)(puVar5 + 1);
            *(undefined2 *)((int)DAT_00067ef4 + 0x2b) = *(undefined2 *)((int)puVar5 + 0x1b);
            *(byte *)((int)DAT_00067ef4 + 0x43) = *(byte *)((int)puVar5 + 3);
            *(byte *)((int)DAT_00067ef4 + 0x33) = *(byte *)((int)puVar5 + 3);
            *(undefined2 *)((int)DAT_00067ef4 + 0x41) = *puVar5;
            *(undefined *)(DAT_00067ef4 + 0x10) = 0;
            *(undefined *)(DAT_00067ef4 + 0x13) = 0;
            uVar3 = FUN_00017300(*(char *)((int)DAT_00067ef4 + 0x37) +
                                 *(char *)((int)DAT_00067ef4 + 0x36),
                                 *(undefined2 *)((int)DAT_00067ef4 + 0x41));
            *(undefined2 *)((int)DAT_00067ef4 + 0x46) = uVar3;
            *(undefined2 *)(DAT_00067ef4 + 0x11) = uVar3;
          }
        }
      }
    }
  }
  return;
}


/* ======== FUN_00018430 @ 00018430 ======== */

void FUN_00018430(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined uVar4;
  byte local_1c;
  
  if (*(int *)(DAT_00067ef4 + 0x3c) != 0) {
    FUN_00019480(*(undefined4 *)(DAT_00067ef4 + 0x3c));
    *(undefined2 *)(DAT_00067ef4 + 0x38) = 0;
    *(undefined2 *)(DAT_00067ef4 + 0x3a) = 0;
    bVar2 = DAT_00067edc;
    while (DAT_00067edc = bVar2, cVar1 = FUN_000194cc(), cVar1 != '\0') {
      switch(cVar1) {
      case '\x01':
      case '\x02':
        FUN_00019514(cVar1);
        bVar2 = DAT_00067edc;
        break;
      case '\x03':
        uVar4 = FUN_000194cc();
        FUN_000180d4(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x04':
        bVar2 = FUN_000194cc();
        if (bVar2 != 0) {
          *(ushort *)(DAT_00067ef4 + 0x48) = (ushort)bVar2 << 2;
        }
        bVar2 = DAT_00067edc;
        if (DAT_00067368 != 0) {
          *(short *)(DAT_00067ef4 + 0x44) =
               *(short *)(DAT_00067ef4 + 0x44) - *(short *)(DAT_00067ef4 + 0x48);
          bVar2 = DAT_00067edc;
        }
        break;
      case '\x05':
        bVar2 = FUN_000194cc();
        if (bVar2 != 0) {
          *(ushort *)(DAT_00067ef4 + 0x48) = (ushort)bVar2 << 2;
        }
        bVar2 = DAT_00067edc;
        if (DAT_00067368 != 0) {
          *(short *)(DAT_00067ef4 + 0x44) =
               *(short *)(DAT_00067ef4 + 0x44) + *(short *)(DAT_00067ef4 + 0x48);
          bVar2 = DAT_00067edc;
        }
        break;
      case '\x06':
        bVar2 = FUN_000194cc();
        *(undefined *)(DAT_00067ef4 + 0x29) = 0;
        if (bVar2 != 0) {
          *(ushort *)(DAT_00067ef4 + 0x4a) = (ushort)bVar2;
          *(short *)(DAT_00067ef4 + 0x4a) = *(short *)(DAT_00067ef4 + 0x4a) << 2;
        }
        FUN_00018014();
        *(undefined2 *)(DAT_00067ef4 + 0x38) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\a':
        bVar2 = FUN_000194cc();
        if ((bVar2 & 0xf) != 0) {
          *(byte *)(DAT_00067ef4 + 0x55) = bVar2 & 0xf;
        }
        if ((bVar2 & 0xf0) != 0) {
          *(char *)(DAT_00067ef4 + 0x54) = (char)((int)(uint)(bVar2 & 0xf0) >> 2);
        }
        FUN_00017630();
        *(undefined2 *)(DAT_00067ef4 + 0x38) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\b':
        uVar4 = FUN_000194cc();
        *(undefined *)(DAT_00067ef4 + 0x29) = 0;
        FUN_00018014();
        FUN_00017860(uVar4);
        *(undefined2 *)(DAT_00067ef4 + 0x38) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\t':
        uVar4 = FUN_000194cc();
        FUN_00017630();
        FUN_00017860(uVar4);
        *(undefined2 *)(DAT_00067ef4 + 0x38) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\n':
        bVar2 = FUN_000194cc();
        if ((bVar2 & 0xf) != 0) {
          *(byte *)(DAT_00067ef4 + 0x58) = bVar2 & 0xf;
        }
        if ((bVar2 & 0xf0) != 0) {
          *(char *)(DAT_00067ef4 + 0x57) = (char)((int)(uint)(bVar2 & 0xf0) >> 2);
        }
        FUN_00017734();
        *(undefined2 *)(DAT_00067ef4 + 0x3a) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\v':
        uVar4 = FUN_000194cc();
        bVar2 = DAT_00067edc;
        if (DAT_00067ee8 != 0) {
          *(undefined *)(DAT_00067ef4 + 0x31) = uVar4;
          *(undefined *)(DAT_00067360 + (uint)DAT_00067ee4 + 0x10d) = uVar4;
          bVar2 = DAT_00067edc;
        }
        break;
      case '\f':
        bVar2 = FUN_000194cc();
        if (bVar2 != 0) {
          *(ushort *)(DAT_00067ef4 + 0x59) = (ushort)bVar2 << 8;
        }
        *(uint *)(DAT_00067ef4 + 0x2d) = (uint)*(ushort *)(DAT_00067ef4 + 0x59);
        bVar2 = DAT_00067edc;
        if (*(uint *)(*(int *)(DAT_00067ef4 + 4) + 5) < *(uint *)(DAT_00067ef4 + 0x2d)) {
          *(undefined4 *)(DAT_00067ef4 + 0x2d) = *(undefined4 *)(*(int *)(DAT_00067ef4 + 4) + 5);
          bVar2 = DAT_00067edc;
        }
        break;
      case '\r':
        uVar4 = FUN_000194cc();
        FUN_00017860(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x0e':
        bVar3 = FUN_000194cc();
        bVar2 = DAT_00067edc;
        if (DAT_0006736d == '\0') {
          DAT_0006736a = 0;
          DAT_00067ee0 = bVar3 - 1;
          DAT_00067370 = 3;
        }
        break;
      case '\x0f':
        local_1c = FUN_000194cc();
        bVar2 = DAT_00067edc;
        if (DAT_00067368 == 0) {
          if (0x40 < local_1c) {
            local_1c = 0x40;
          }
          *(byte *)(DAT_00067ef4 + 0x43) = local_1c;
          bVar2 = DAT_00067edc;
        }
        break;
      case '\x10':
        bVar3 = FUN_000194cc();
        bVar2 = DAT_00067edc;
        if (DAT_0006736d == '\0') {
          DAT_0006736a = (ushort)(bVar3 & 0xf) + (short)((int)(uint)(bVar3 & 0xf0) >> 4) * 10;
          if (0x40 < DAT_0006736a) {
            DAT_0006736a = 0x40;
          }
          DAT_00067370 = 3;
        }
        break;
      case '\x11':
        uVar4 = FUN_000194cc();
        FUN_00017374(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x12':
        bVar3 = FUN_000194cc();
        bVar2 = DAT_00067edc;
        if ((((DAT_00067368 == 0) && (DAT_0006736d == '\0')) &&
            ((DAT_00052b18 == 0 || (bVar2 = bVar3, bVar3 < 0x20)))) &&
           (bVar2 = DAT_00067edc, bVar3 != 0)) {
          DAT_00067ee2 = (ushort)bVar3;
          DAT_00067368 = 0;
        }
        break;
      case '\x13':
        uVar4 = FUN_000194cc();
        FUN_00017f94(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x14':
        uVar4 = FUN_000194cc();
        FUN_000178d4(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x15':
        uVar4 = FUN_000194cc();
        FUN_00017b94(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x16':
        uVar4 = FUN_000194cc();
        FUN_00017c48(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x17':
        uVar4 = FUN_000194cc();
        FUN_00017cfc(uVar4);
        *(undefined2 *)(DAT_00067ef4 + 0x3a) = 1;
        bVar2 = DAT_00067edc;
        break;
      case '\x18':
        uVar4 = FUN_000194cc();
        FUN_00017da8(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x19':
        uVar4 = FUN_000194cc();
        FUN_00017fdc(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x1a':
        uVar4 = FUN_000194cc();
        FUN_000179b4(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x1b':
        DAT_00052b1d = FUN_000194cc();
        bVar2 = DAT_00067edc;
        break;
      case '\x1c':
        uVar4 = FUN_000194cc();
        FUN_00017a58(uVar4);
        bVar2 = DAT_00067edc;
        break;
      case '\x1d':
        uVar4 = FUN_000194cc();
        FUN_00017ae8(uVar4);
        bVar2 = DAT_00067edc;
        break;
      default:
        FUN_00019514(cVar1);
        bVar2 = DAT_00067edc;
      }
    }
    if (*(short *)(DAT_00067ef4 + 0x38) == 0) {
      *(undefined2 *)(DAT_00067ef4 + 0x34) = *(undefined2 *)(DAT_00067ef4 + 0x44);
    }
    if (*(short *)(DAT_00067ef4 + 0x3a) == 0) {
      *(undefined *)(DAT_00067ef4 + 0x33) = *(undefined *)(DAT_00067ef4 + 0x43);
    }
  }
  return;
}


/* ======== FUN_00018a10 @ 00018a10 ======== */

undefined4 FUN_00018a10(short param_1,short *unaff_EDX,short *unaff_EBX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00017120((int)param_1,(int)*unaff_EDX,(int)*unaff_EBX,(int)unaff_EDX[1],
                       (int)unaff_EBX[1]);
  return uVar1;
}


/* ======== FUN_00018aac @ 00018aac ======== */

void FUN_00018aac(undefined *param_1,undefined param_2,undefined param_3,undefined param_4,
                 undefined param_5,undefined param_6,undefined4 param_7)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[4] = param_6;
  *(undefined4 *)(param_1 + 0xb) = param_7;
  *(undefined2 *)(param_1 + 5) = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  *(undefined2 *)(param_1 + 9) = 1;
  return;
}


/* ======== FUN_00018b1c @ 00018b1c ======== */

undefined4 FUN_00018b1c(byte *param_1,undefined4 unaff_EDX,char unaff_BL)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte local_24;
  byte local_20;
  
  if ((*param_1 & 1) != 0) {
    local_20 = param_1[7];
    bVar1 = param_1[9];
    uVar2 = *(ushort *)(param_1 + 5);
    unaff_EDX = FUN_00018a10((int)(short)uVar2,*(int *)(param_1 + 0xb) + (uint)local_20 * 4,
                             *(int *)(param_1 + 0xb) + (uint)bVar1 * 4);
    local_24 = bVar1;
    if ((((((*param_1 & 2) == 0) || (unaff_BL == '\0')) || (local_20 != param_1[2])) ||
        (uVar3 = uVar2, (uint)uVar2 != (int)*(short *)(*(int *)(param_1 + 0xb) + (uint)local_20 * 4)
        )) && (uVar3 = uVar2 + 1,
              (int)*(short *)(*(int *)(param_1 + 0xb) + (uint)bVar1 * 4) <= (int)(uint)uVar3)) {
      local_24 = bVar1 + 1;
      local_20 = bVar1;
      if ((*param_1 & 4) == 0) {
        if (param_1[1] <= local_24) {
          local_24 = bVar1;
          uVar3 = uVar2;
        }
      }
      else if (param_1[4] < local_24) {
        local_20 = param_1[3];
        local_24 = local_20 + 1;
        uVar3 = *(ushort *)(*(int *)(param_1 + 0xb) + (uint)local_20 * 4);
      }
    }
    *(ushort *)(param_1 + 7) = (ushort)local_20;
    *(ushort *)(param_1 + 9) = (ushort)local_24;
    *(ushort *)(param_1 + 5) = uVar3;
  }
  return unaff_EDX;
}


/* ======== FUN_00018c84 @ 00018c84 ======== */

undefined8 FUN_00018c84(int param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,
                  (int)((uint)*(ushort *)(&DAT_00052b58 + ((0x1e00 - param_1) % 0x300) * 2) << 2) >>
                  (7U - (char)((0x1e00 - param_1) / 0x300) & 0x1f));
}


/* ======== FUN_00018cf4 @ 00018cf4 ======== */

void FUN_00018cf4(void)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int local_2c;
  uint local_24;
  
  if (DAT_00067378 == 0) {
    if ((DAT_00067374 == 0) &&
       (iVar4 = FUN_00019338(), sVar2 = DAT_00067ede, sVar3 = DAT_0006736a, iVar4 == 0)) {
      DAT_00067368 = DAT_00067368 + 1;
      if (DAT_00067ee2 <= DAT_00067368) {
        DAT_00067ede = DAT_00067ede + 1;
        DAT_00067368 = 0;
        if (DAT_0006736c != '\0') {
          DAT_0006736d = DAT_0006736c;
          DAT_0006736c = '\0';
        }
        if ((DAT_0006736d != '\0') && (DAT_0006736d = DAT_0006736d + -1, DAT_0006736d != '\0')) {
          DAT_00067ede = sVar2;
        }
        if (DAT_00067ede == DAT_0006736e) {
          DAT_00067370 = 3;
        }
        if (DAT_00067370 != 0) {
          DAT_00067ede = DAT_0006736a;
          DAT_00067ee0 = DAT_00067ee0 + DAT_00067370 + -2;
          DAT_00067370 = 0;
          DAT_0006736a = 0;
          if ((int)(uint)*(ushort *)(DAT_00067360 + 1) <= (int)DAT_00067ee0) {
            if (DAT_00067eec == 0) {
              DAT_00067368 = 0;
              DAT_0006736a = 0;
              DAT_00067370 = 0;
              DAT_00067ede = sVar3;
              return;
            }
            DAT_00067ee0 = *(short *)(DAT_00067360 + 3);
          }
          if (DAT_00067ee0 < 0) {
            DAT_00067ee0 = *(short *)(DAT_00067360 + 1) + -1;
          }
        }
        if (DAT_0006736d == '\0') {
          for (local_24 = 0; (int)local_24 < (int)(uint)*DAT_00067360; local_24 = local_24 + 1) {
            uVar5 = (uint)*(ushort *)
                           (*(int *)(DAT_00067360 + 0x13e) +
                           ((uint)DAT_00067360[DAT_00067ee0 + 0xd] * (uint)*DAT_00067360 + local_24)
                           * 2);
            DAT_0006736e = *(short *)(*(int *)(DAT_00067360 + 0x142) +
                                     (uint)DAT_00067360[DAT_00067ee0 + 0xd] * 2);
            DAT_00067ee4 = (undefined2)local_24;
            DAT_00067ef4 = (int *)(&DAT_0006737c + local_24 * 0x5b);
            if (uVar5 < *(ushort *)(DAT_00067360 + 7)) {
              local_2c = FUN_00019550(*(undefined4 *)(*(int *)(DAT_00067360 + 0x146) + uVar5 * 4),
                                      DAT_00067ede);
            }
            else {
              local_2c = 0;
            }
            DAT_00067ef4[0xf] = local_2c;
            FUN_00018188();
          }
        }
      }
      for (local_24 = 0; (int)local_24 < (int)(uint)*DAT_00067360; local_24 = local_24 + 1) {
        DAT_00067ee4 = (undefined2)local_24;
        DAT_00067ef4 = (int *)(&DAT_0006737c + local_24 * 0x5b);
        FUN_00018430();
      }
      for (local_24 = 0; (int)local_24 < (int)(uint)*DAT_00067360; local_24 = local_24 + 1) {
        iVar6 = local_24 * 0x5b;
        DAT_00067ef4 = (int *)(&DAT_0006737c + iVar6);
        iVar4 = *DAT_00067ef4;
        iVar1 = *(int *)(&DAT_00067380 + iVar6);
        if ((iVar4 != 0) && (iVar1 != 0)) {
          if (*(ushort *)(&DAT_000673b0 + iVar6) < 0x28) {
            *(undefined2 *)(&DAT_000673b0 + iVar6) = 0x28;
          }
          if (8000 < *(ushort *)(DAT_00067ef4 + 0xd)) {
            *(undefined2 *)(DAT_00067ef4 + 0xd) = 8000;
          }
          if (*(char *)((int)DAT_00067ef4 + 0x29) != '\0') {
            FUN_00015864(local_24 & 0xff,(int)*(short *)((int)DAT_00067ef4 + 0x2b),
                         *(undefined4 *)((int)DAT_00067ef4 + 0x2d),*(undefined4 *)(iVar1 + 5),
                         *(undefined4 *)(iVar1 + 9),*(undefined4 *)(iVar1 + 0xd),
                         *(undefined2 *)(iVar1 + 0x11));
            *(undefined *)((int)DAT_00067ef4 + 0x29) = 0;
            *(undefined *)(DAT_00067ef4 + 10) = 1;
            *(undefined2 *)(DAT_00067ef4 + 2) = 0x8000;
            FUN_00018aac((undefined *)((int)DAT_00067ef4 + 10),*(undefined *)(iVar4 + 0x61),
                         *(undefined *)(iVar4 + 0x62),*(undefined *)(iVar4 + 99),
                         *(undefined *)(iVar4 + 100),*(undefined *)(iVar4 + 0x65),iVar4 + 0x66);
            FUN_00018aac((undefined *)((int)DAT_00067ef4 + 0x19),*(undefined *)(iVar4 + 0x96),
                         *(undefined *)(iVar4 + 0x97),*(undefined *)(iVar4 + 0x98),
                         *(undefined *)(iVar4 + 0x99),*(undefined *)(iVar4 + 0x9a),iVar4 + 0x9b);
          }
          sVar3 = FUN_00018b1c((undefined *)((int)DAT_00067ef4 + 10),0x100,
                               *(undefined *)(DAT_00067ef4 + 10));
          FUN_00018b1c((undefined *)((int)DAT_00067ef4 + 0x19),0x80,
                       *(undefined *)(DAT_00067ef4 + 10));
          FUN_000157e0(local_24 & 0xff,
                       (((uint)*(ushort *)(DAT_00067ef4 + 2) * (int)sVar3 *
                         (uint)*(byte *)((int)DAT_00067ef4 + 0x33) >> 0xe) * (uint)DAT_00052b1d *
                       (uint)DAT_00052b1c) / 0x320000 & 0xff);
          FUN_00015838(local_24 & 0xff,*(undefined *)((int)DAT_00067ef4 + 0x31));
          if ((DAT_00067360[0x12d] & 2) == 0) {
            FUN_0001580c(local_24 & 0xff,
                         (int)(0xda7a68 / (ulonglong)*(ushort *)(DAT_00067ef4 + 0xd)));
          }
          else {
            uVar7 = FUN_00018c84(*(undefined2 *)(DAT_00067ef4 + 0xd));
            FUN_0001580c(local_24 & 0xff,uVar7);
          }
          if (*(char *)(DAT_00067ef4 + 10) == '\0') {
            if (*(ushort *)(DAT_00067ef4 + 2) < *(ushort *)(iVar4 + 0xcf)) {
              *(undefined2 *)(DAT_00067ef4 + 2) = 0;
            }
            else {
              *(short *)(DAT_00067ef4 + 2) = *(short *)(DAT_00067ef4 + 2) - *(short *)(iVar4 + 0xcf)
              ;
            }
          }
        }
      }
    }
  }
  else {
    DAT_00067378 = DAT_00067378 + -1;
  }
  return;
}


/* ======== FUN_00019230 @ 00019230 ======== */

void FUN_00019230(byte *param_1)

{
  int local_20;
  
  DAT_00067364 = 0;
  DAT_00067366 = 0;
  DAT_00067ee0 = 0;
  DAT_00067368 = (ushort)param_1[0xb];
  DAT_0006736c = 0;
  DAT_0006736d = 0;
  DAT_00067edc = param_1[0xc];
  DAT_00067374 = 0;
  DAT_00067ede = 0;
  DAT_00067370 = 2;
  DAT_0006736a = 0;
  DAT_00067378 = 2;
  DAT_00052b1d = 0x40;
  DAT_00067360 = param_1;
  DAT_00067ee2 = DAT_00067368;
  for (local_20 = 0; local_20 < (int)(uint)*DAT_00067360; local_20 = local_20 + 1) {
    (&DAT_000673a5)[local_20 * 0x5b] = 0;
    (&DAT_000673bf)[local_20 * 0x5b] = 0;
    (&DAT_000673bc)[local_20 * 0x5b] = 0;
    (&DAT_000673ce)[local_20 * 0x5b] = 0;
    (&DAT_000673cd)[local_20 * 0x5b] = 0;
    *(undefined2 *)(&DAT_000673d5 + local_20 * 0x5b) = 0;
  }
  return;
}


/* ======== FUN_00019338 @ 00019338 ======== */

undefined8 FUN_00019338(undefined4 param_1,undefined4 unaff_EDX)

{
  uint local_1c;
  
  local_1c = (uint)((int)(uint)*(ushort *)(DAT_00067360 + 1) <= (int)DAT_00067ee0);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00019480 @ 00019480 ======== */

void FUN_00019480(byte *param_1)

{
  DAT_00067ef8 = param_1;
  DAT_00067f00 = param_1 + 1;
  DAT_00067efc = param_1 + (*param_1 & 0x1f);
  return;
}


/* ======== FUN_000194cc @ 000194cc ======== */

undefined8 FUN_000194cc(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined *puVar1;
  undefined local_20;
  
  puVar1 = DAT_00067f00;
  if (DAT_00067f00 < DAT_00067efc) {
    DAT_00067f00 = DAT_00067f00 + 1;
    local_20 = *puVar1;
    puVar1 = (undefined *)0x0;
  }
  else {
    local_20 = 0;
  }
  return CONCAT44(unaff_EDX,CONCAT31((int3)((uint)puVar1 >> 8),local_20));
}


/* ======== FUN_00019514 @ 00019514 ======== */

void FUN_00019514(byte param_1)

{
  short sVar1;
  
  sVar1 = *(short *)((int)&PTR___break_00053228 + (uint)param_1 * 2);
  while (sVar1 = sVar1 + -1, sVar1 != -1) {
    FUN_000194cc();
  }
  return;
}


/* ======== FUN_00019550 @ 00019550 ======== */

byte * FUN_00019550(byte *param_1,ushort unaff_DX)

{
  byte bVar1;
  byte bVar2;
  byte *local_1c;
  
  local_1c = param_1;
  while( true ) {
    bVar1 = *local_1c;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    bVar2 = (char)((int)(uint)bVar1 >> 5) + 1;
    if (unaff_DX < bVar2) break;
    unaff_DX = unaff_DX - bVar2;
    local_1c = local_1c + (bVar1 & 0x1f);
  }
  return local_1c;
}


/* ======== FUN_000195b8 @ 000195b8 ======== */

void FUN_000195b8(void)

{
  DAT_00067f0c = 0;
  DAT_00067f0a = 1;
  DAT_00067f0e = 0;
  *DAT_00067f04 = 0;
  return;
}


/* ======== FUN_000195f0 @ 000195f0 ======== */

void FUN_000195f0(undefined param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = DAT_00067f0a;
  DAT_00067f0a = DAT_00067f0a + 1;
  *(undefined *)((uint)uVar1 + DAT_00067f04) = param_1;
  if ((int)(DAT_00067f08 - 0x10) < (int)(uint)DAT_00067f0a) {
    iVar2 = FUN_00034fcc(DAT_00067f04,DAT_00067f08 + 0x80);
    if (iVar2 == 0) {
      DAT_00067f0a = DAT_00067f0a - 1;
    }
    else {
      DAT_00067f08 = DAT_00067f08 + 0x80;
      DAT_00067f04 = iVar2;
    }
  }
  return;
}


/* ======== FUN_00019674 @ 00019674 ======== */

void FUN_00019674(undefined param_1)

{
  FUN_000195f0(2);
  FUN_000195f0(param_1);
  return;
}


/* ======== FUN_000196a0 @ 000196a0 ======== */

void FUN_000196a0(undefined param_1)

{
  FUN_000195f0(1);
  FUN_000195f0(param_1);
  return;
}


/* ======== FUN_000196cc @ 000196cc ======== */

void FUN_000196cc(char param_1,char unaff_DL)

{
  if ((param_1 != '\0') || (unaff_DL != '\0')) {
    FUN_000195f0(param_1 + '\x03');
    FUN_000195f0(unaff_DL);
  }
  return;
}


/* ======== FUN_0001970c @ 0001970c ======== */

undefined4 FUN_0001970c(char *param_1,char *unaff_EDX,ushort unaff_BX)

{
  ushort uVar1;
  char *local_1c;
  
  uVar1 = 0;
  local_1c = param_1;
  while( true ) {
    if (unaff_BX <= uVar1) {
      return 1;
    }
    if (*local_1c != *unaff_EDX) break;
    uVar1 = uVar1 + 1;
    local_1c = local_1c + 1;
    unaff_EDX = unaff_EDX + 1;
  }
  return 0;
}


/* ======== FUN_00019768 @ 00019768 ======== */

void FUN_00019768(void)

{
  ushort uVar1;
  int iVar2;
  ushort local_20;
  undefined local_1c;
  
  local_20 = (short)((int)(uint)*(byte *)(DAT_00067f04 + (uint)DAT_00067f0e) >> 5) + 1;
  uVar1 = DAT_00067f0a - DAT_00067f0c;
  if (((local_20 < 8) && (uVar1 == (*(byte *)((uint)DAT_00067f0e + DAT_00067f04) & 0x1f))) &&
     (iVar2 = FUN_0001970c(DAT_00067f04 + DAT_00067f0e + 1,DAT_00067f04 + DAT_00067f0c + 1,uVar1 - 1
                          ), iVar2 != 0)) {
    *(char *)(DAT_00067f04 + (uint)DAT_00067f0e) =
         *(char *)(DAT_00067f04 + (uint)DAT_00067f0e) + ' ';
  }
  else {
    local_1c = (undefined)uVar1;
    *(undefined *)(DAT_00067f04 + (uint)DAT_00067f0c) = local_1c;
    DAT_00067f0e = DAT_00067f0c;
    DAT_00067f0c = DAT_00067f0a;
  }
  DAT_00067f0a = DAT_00067f0c + 1;
  return;
}


/* ======== FUN_0001985c @ 0001985c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001985c(undefined4 param_1,undefined4 unaff_EDX)

{
  int local_20;
  
  *(undefined *)(DAT_00067f04 + (uint)DAT_00067f0c) = 0;
  local_20 = malloc(DAT_00067f0a);
  if (local_20 == 0) {
    _DAT_00067358 = PTR_s_Blad_alokacji_struktury_00052af8;
    local_20 = 0;
  }
  else {
    FUN_00034682(local_20,DAT_00067f04,DAT_00067f0a);
  }
  return CONCAT44(unaff_EDX,local_20);
}


/* ======== FUN_00019918 @ 00019918 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00019918(undefined4 param_1,undefined4 unaff_EDX)

{
  uint local_1c;
  
  DAT_00067f08 = 0x80;
  DAT_00067f04 = malloc(0x80);
  if (DAT_00067f04 == 0) {
    _DAT_00067358 = PTR_s_Blad_alokacji_struktury_00052af8;
  }
  local_1c = (uint)(DAT_00067f04 != 0);
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00019970 @ 00019970 ======== */

void FUN_00019970(void)

{
  if (DAT_00067f04 != 0) {
    free(DAT_00067f04);
  }
  DAT_00067f04 = 0;
  return;
}


/* ======== FUN_000199b0 @ 000199b0 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000199b0(int param_1,undefined4 unaff_EDX)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *local_24;
  
  FUN_00016670(param_1,0,0);
  FUN_00016d2c(&DAT_00067f10,4,param_1);
  _DAT_00067f14 = FUN_00016c9c(param_1);
  FUN_00016d2c(&DAT_00067f18,4,param_1);
  FUN_00016d2c(&DAT_00067f1c,4,param_1);
  DAT_00067f20 = FUN_00016c9c(param_1);
  _DAT_00067f24 = FUN_00016bc8(param_1);
  DAT_00067f26 = FUN_00016bc8(param_1);
  _DAT_00067f28 = FUN_00016c9c(param_1);
  _DAT_00067f2c = FUN_00016c9c(param_1);
  DAT_00067f30 = FUN_00016bc8(param_1);
  _DAT_00067f32 = FUN_00016bc8(param_1);
  if (((((*(byte *)(param_1 + 0xc) & 0x10) == 0) &&
       (iVar2 = FUN_0003459d(&DAT_00067f10,&DAT_00059880,4), iVar2 == 0)) &&
      (iVar2 = FUN_0003459d(&DAT_00067f18,&DAT_00059885,4), iVar2 == 0)) &&
     (iVar2 = FUN_0003459d(&DAT_00067f1c,&DAT_0005988a,4), iVar2 == 0)) {
    FUN_00016670(param_1,DAT_00067f20 + -0x10,1);
    FUN_00016d2c(&DAT_00067f34,4,param_1);
    iVar2 = FUN_0003459d(&DAT_00067f34,&DAT_000598a4);
    if (iVar2 == 0) {
      if (DAT_00067f26 < 2) {
        local_24 = (undefined2 *)FUN_00034844(1,0x1d);
        if (local_24 == (undefined2 *)0x0) {
          _DAT_00067358 = s_Brak_pamieci_000598de;
          local_24 = (undefined2 *)0x0;
        }
        else {
          *local_24 = 0x2000;
          *(undefined *)((int)local_24 + 3) = 0x40;
          uVar3 = FUN_00016c9c(param_1);
          *(undefined4 *)((int)local_24 + 5) = uVar3;
          if (DAT_00067f30 == 2) {
            *(undefined2 *)((int)local_24 + 0x11) = 3;
            *(uint *)((int)local_24 + 5) = *(uint *)((int)local_24 + 5) >> 1;
          }
          uVar1 = FUN_000155b4(param_1,*(undefined4 *)((int)local_24 + 5),0,
                               *(undefined4 *)((int)local_24 + 5),
                               *(undefined2 *)((int)local_24 + 0x11));
          *(undefined2 *)((int)local_24 + 0x1b) = uVar1;
          if (*(short *)((int)local_24 + 0x1b) < 0) {
            free(local_24);
            local_24 = (undefined2 *)0x0;
          }
        }
      }
      else {
        _DAT_00067358 = s_Obslugiwana_sa_tylko_pliki_MONO_000598be;
        local_24 = (undefined2 *)0x0;
      }
    }
    else {
      _DAT_00067358 = s_To_nie_jest_plik_WAV_000598a9;
      local_24 = (undefined2 *)0x0;
    }
  }
  else {
    _DAT_00067358 = s_To_nie_jest_plik_WAV_0005988f;
    local_24 = (undefined2 *)0x0;
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_00019cb0 @ 00019cb0 ======== */

uint FUN_00019cb0(uint param_1,ushort unaff_DX)

{
  return (param_1 % (uint)unaff_DX << 0xb) / (uint)unaff_DX | param_1 / unaff_DX << 0xb;
}


/* ======== FUN_00019d04 @ 00019d04 ======== */

undefined8 FUN_00019d04(int param_1,undefined4 unaff_EDX)

{
  int local_1c;
  
  local_1c = param_1;
  if ((DAT_000669da & 2) != 0) {
    local_1c = param_1 << 1;
  }
  if ((DAT_000669da & 1) != 0) {
    local_1c = local_1c << 1;
  }
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00019d40 @ 00019d40 ======== */

undefined8 FUN_00019d40(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 local_1c;
  
  local_1c = param_1;
  if ((DAT_000669da & 2) != 0) {
    local_1c._0_2_ = (ushort)param_1;
    local_1c._2_2_ = (undefined2)((uint)param_1 >> 0x10);
    local_1c = CONCAT22(local_1c._2_2_,(ushort)local_1c >> 1);
  }
  if ((DAT_000669da & 1) != 0) {
    local_1c = CONCAT22(local_1c._2_2_,(ushort)local_1c >> 1);
  }
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_00019d7c @ 00019d7c ======== */

undefined4 FUN_00019d7c(int param_1,uint unaff_EDX)

{
  uint local_2c;
  int local_1c;
  
  local_1c = param_1;
  for (; unaff_EDX != 0; unaff_EDX = unaff_EDX - local_2c) {
    local_2c = unaff_EDX;
    if (8000 < unaff_EDX) {
      local_2c = 8000;
    }
    FUN_00015310(local_1c,local_2c);
    local_1c = local_1c + local_2c;
  }
  return 1;
}


/* ======== FUN_00019ddc @ 00019ddc ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00019ddc(undefined4 param_1,int unaff_EDX,int unaff_EBX,int unaff_ECX,ushort param_5)

{
  undefined4 uVar1;
  uint local_28;
  int local_24;
  int local_20;
  
  FUN_000152b8(param_1,param_5,param_5 & 0xfffe | 2);
  for (local_24 = 0; (local_24 < 0x80 && (*(int *)(&DAT_0007c120 + local_24 * 4) != 0));
      local_24 = local_24 + 1) {
  }
  if (local_24 == 0x80) {
    _DAT_00067358 = PTR_s_Wyczerpane_uchwyty_sampli_00052b10;
    local_20 = -1;
  }
  else {
    uVar1 = malloc(unaff_EDX + 0x10);
    *(undefined4 *)(&DAT_0007c120 + local_24 * 4) = uVar1;
    if (*(int *)(&DAT_0007c120 + local_24 * 4) == 0) {
      _DAT_00067358 = PTR_s_Instrument_za_duzy_00052b14;
      local_20 = -1;
    }
    else {
      FUN_00019d7c(*(undefined4 *)(&DAT_0007c120 + local_24 * 4),unaff_EDX);
      if ((param_5 & 0x10) == 0) {
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(undefined *)(*(int *)(&DAT_0007c120 + local_24 * 4) + local_28 + unaff_EDX) = 0;
        }
      }
      else if ((param_5 & 0x20) == 0) {
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(undefined *)(*(int *)(&DAT_0007c120 + local_24 * 4) + unaff_ECX + local_28) =
               *(undefined *)(local_28 + unaff_EBX + *(int *)(&DAT_0007c120 + local_24 * 4));
        }
      }
      else {
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(undefined *)(*(int *)(&DAT_0007c120 + local_24 * 4) + unaff_ECX + local_28) =
               *(undefined *)((unaff_ECX - local_28) + *(int *)(&DAT_0007c120 + local_24 * 4) + -1);
        }
      }
      local_20 = local_24;
    }
  }
  return local_20;
}


/* ======== FUN_00019f98 @ 00019f98 ======== */

void FUN_00019f98(short param_1)

{
  free(*(undefined4 *)(&DAT_0007c120 + param_1 * 4));
  *(undefined4 *)(&DAT_0007c120 + param_1 * 4) = 0;
  return;
}


/* ======== FUN_00019fe4 @ 00019fe4 ======== */

uint FUN_00019fe4(int param_1,int unaff_EDX,int unaff_EBX,ushort unaff_CX)

{
  uint local_24;
  uint local_20;
  int local_1c;
  
  local_20 = (unaff_EDX - param_1) / unaff_EBX;
  local_1c = param_1 + local_20 * unaff_EBX;
  if (unaff_EBX < 0) {
    for (; unaff_EDX <= local_1c; local_1c = local_1c + unaff_EBX) {
      local_20 = local_20 + 1;
    }
  }
  else {
    for (; local_1c <= unaff_EDX; local_1c = local_1c + unaff_EBX) {
      local_20 = local_20 + 1;
    }
  }
  if ((int)local_20 < (int)(uint)unaff_CX) {
    local_24 = local_20;
  }
  else {
    local_24 = (uint)unaff_CX;
  }
  return local_24;
}


/* ======== FUN_0001a070 @ 0001a070 ======== */

void FUN_0001a070(undefined4 param_1,short unaff_DX)

{
  ushort uVar1;
  int local_34;
  int local_30;
  int local_2c;
  
  while( true ) {
    if (unaff_DX == 0) {
      return;
    }
    if ((*(byte *)(DAT_0006bc78 + 2) & 0x80) == 0) {
      if ((*(byte *)(DAT_0006bc78 + 2) & 0x10) == 0) {
        if (DAT_0006bc80 < *(int *)(DAT_0006bc78 + 0x1c)) {
          *(undefined4 *)(DAT_0006bc78 + 0x1c) = 0;
          *(undefined *)(DAT_0006bc78 + 1) = 0;
          return;
        }
      }
      else if (DAT_0006bc88 < *(int *)(DAT_0006bc78 + 0x1c)) {
        if ((*(byte *)(DAT_0006bc78 + 2) & 0x20) == 0) {
          *(int *)(DAT_0006bc78 + 0x1c) =
               DAT_0006bc84 + (*(int *)(DAT_0006bc78 + 0x1c) - DAT_0006bc88);
        }
        else {
          *(byte *)(DAT_0006bc78 + 2) = *(byte *)(DAT_0006bc78 + 2) | 0x80;
          *(int *)(DAT_0006bc78 + 0x20) = -*(int *)(DAT_0006bc78 + 0x20);
          *(int *)(DAT_0006bc78 + 0x1c) = DAT_0006bc88 * 2 - *(int *)(DAT_0006bc78 + 0x1c);
        }
      }
    }
    else if ((*(byte *)(DAT_0006bc78 + 2) & 0x10) == 0) {
      if (*(int *)(DAT_0006bc78 + 0x1c) < 0) {
        *(undefined4 *)(DAT_0006bc78 + 0x1c) = 0;
        *(undefined *)(DAT_0006bc78 + 1) = 0;
        return;
      }
    }
    else if (*(int *)(DAT_0006bc78 + 0x1c) < DAT_0006bc84) {
      if ((*(byte *)(DAT_0006bc78 + 2) & 0x20) == 0) {
        *(int *)(DAT_0006bc78 + 0x1c) =
             DAT_0006bc88 - (DAT_0006bc84 - *(int *)(DAT_0006bc78 + 0x1c));
      }
      else {
        *(int *)(DAT_0006bc78 + 0x1c) = DAT_0006bc84 * 2 - *(int *)(DAT_0006bc78 + 0x1c);
        *(byte *)(DAT_0006bc78 + 2) = *(byte *)(DAT_0006bc78 + 2) & 0x7f;
        *(int *)(DAT_0006bc78 + 0x20) = -*(int *)(DAT_0006bc78 + 0x20);
      }
    }
    if (*(int *)(&DAT_0007c120 + *(short *)(DAT_0006bc78 + 4) * 4) == 0) break;
    if ((*(byte *)(DAT_0006bc78 + 2) & 0x80) == 0) {
      if ((*(byte *)(DAT_0006bc78 + 2) & 0x10) == 0) {
        local_34 = DAT_0006bc80;
      }
      else {
        local_34 = DAT_0006bc88;
      }
      local_30 = local_34;
    }
    else {
      if ((*(byte *)(DAT_0006bc78 + 2) & 0x10) == 0) {
        local_2c = 0;
      }
      else {
        local_2c = DAT_0006bc84;
      }
      local_30 = local_2c;
    }
    uVar1 = FUN_00019fe4(*(undefined4 *)(DAT_0006bc78 + 0x1c),local_30,
                         *(undefined4 *)(DAT_0006bc78 + 0x20),unaff_DX);
    if (uVar1 == 0) {
      *(undefined *)(DAT_0006bc78 + 1) = 0;
      return;
    }
    if (*(char *)(DAT_0006bc78 + 0x1a) != '\0') {
      if ((DAT_000669da & 1) == 0) {
        FUN_00010272(DAT_0006bc78,uVar1,*(undefined4 *)(DAT_0006bc78 + 0x1c),
                     *(undefined4 *)(DAT_0006bc78 + 0x20));
      }
      else {
        FUN_00010010(DAT_0006bc78,uVar1,*(undefined4 *)(DAT_0006bc78 + 0x1c),
                     *(undefined4 *)(DAT_0006bc78 + 0x20));
      }
    }
    *(int *)(DAT_0006bc78 + 0x1c) =
         *(int *)(DAT_0006bc78 + 0x1c) + (uint)uVar1 * *(int *)(DAT_0006bc78 + 0x20);
    unaff_DX = unaff_DX - uVar1;
  }
  *(undefined4 *)(DAT_0006bc78 + 0x1c) = 0;
  *(undefined *)(DAT_0006bc78 + 1) = 0;
  return;
}


/* ======== FUN_0001a360 @ 0001a360 ======== */

void FUN_0001a360(undefined2 *param_1,ushort unaff_DX)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint local_34;
  uint local_2c;
  int local_24;
  int local_20;
  
  if ((DAT_000669da & 1) == 0) {
    local_20 = (uint)unaff_DX * 4;
  }
  else {
    local_20 = (uint)unaff_DX * 8;
  }
  memset(&DAT_00067f38,0,local_20);
  for (local_24 = 0; local_24 < (int)(uint)DAT_000669dc; local_24 = local_24 + 1) {
    iVar2 = local_24 * 0x28;
    DAT_0006bc78 = &DAT_0006b778 + iVar2;
    if ((&DAT_0006b779)[iVar2] != '\0') {
      DAT_0006bc80 = *(int *)(&DAT_0006b782 + iVar2) * 0x800 + -1;
      DAT_0006bc84 = *(int *)(&DAT_0006b786 + iVar2) << 0xb;
      DAT_0006bc88 = *(int *)(&DAT_0006b78a + iVar2) * 0x800 + -1;
      DAT_0007c11a = *(undefined2 *)(&DAT_0006b79c + iVar2);
      DAT_0007c11c = *(undefined2 *)(&DAT_0006b79e + iVar2);
      FUN_0001a070(&DAT_00067f38,unaff_DX);
    }
  }
  if ((DAT_000669da & 2) == 0) {
    bVar1 = 0x18 - DAT_0006bc94;
    if ((DAT_000669da & 1) == 0) {
      local_34 = (uint)unaff_DX;
    }
    else {
      local_34 = (uint)unaff_DX * 2;
    }
    piVar3 = &DAT_00067f38;
    do {
      iVar2 = *piVar3 >> (bVar1 & 0x1f);
      if (iVar2 < 0x80) {
        if (iVar2 < -0x80) {
          iVar2 = -0x80;
        }
      }
      else {
        iVar2 = 0x7f;
      }
      *(char *)param_1 = (char)iVar2 + -0x80;
      piVar3 = piVar3 + 1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      local_34 = local_34 - 1;
    } while (local_34 != 0);
  }
  else {
    bVar1 = 0x10 - DAT_0006bc94;
    if ((DAT_000669da & 1) == 0) {
      local_2c = (uint)unaff_DX;
    }
    else {
      local_2c = (uint)unaff_DX * 2;
    }
    piVar3 = &DAT_00067f38;
    do {
      iVar2 = *piVar3 >> (bVar1 & 0x1f);
      if (iVar2 < 0x8000) {
        if (iVar2 < -0x8000) {
          iVar2 = -0x8000;
        }
      }
      else {
        iVar2 = 0x7fff;
      }
      *param_1 = (short)iVar2;
      piVar3 = piVar3 + 1;
      param_1 = param_1 + 1;
      local_2c = local_2c - 1;
    } while (local_2c != 0);
  }
  return;
}


/* ======== FUN_0001a518 @ 0001a518 ======== */

void FUN_0001a518(int param_1,ushort unaff_DX)

{
  ushort uVar1;
  uint uVar2;
  int local_1c;
  
  local_1c = param_1;
  for (; unaff_DX != 0; unaff_DX = unaff_DX - uVar1) {
    uVar1 = DAT_0006bc7c;
    if (unaff_DX < DAT_0006bc7c) {
      uVar1 = unaff_DX;
    }
    FUN_0001a360(local_1c,uVar1);
    uVar2 = FUN_00019d04(uVar1);
    local_1c = local_1c + (uVar2 & 0xffff);
  }
  return;
}


/* ======== FUN_0001a580 @ 0001a580 ======== */

void FUN_0001a580(int param_1,ushort unaff_DX)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_24;
  int local_1c;
  
  local_1c = param_1;
  for (; unaff_DX != 0; unaff_DX = unaff_DX - uVar1) {
    if (DAT_0007c320 == 0) {
      (*(code *)PTR_FUN_00052ad4)();
      DAT_0007c320 = (ushort)(((uint)DAT_00052acc * 0x7d) / ((uint)DAT_00052ad0 * 0x32));
      for (local_24 = 0; local_24 < (int)(uint)DAT_000669dc; local_24 = local_24 + 1) {
        if ((&DAT_0006b778)[local_24 * 0x28] != '\0') {
          *(int *)(&DAT_0006b794 + local_24 * 0x28) =
               *(int *)(&DAT_0006b77e + local_24 * 0x28) << 0xb;
          (&DAT_0006b779)[local_24 * 0x28] = 1;
          (&DAT_0006b778)[local_24 * 0x28] = 0;
        }
        if (*(int *)(&DAT_0006b78e + local_24 * 0x28) == 0) {
          (&DAT_0006b779)[local_24 * 0x28] = 0;
        }
        if ((&DAT_0006b779)[local_24 * 0x28] != '\0') {
          uVar2 = FUN_00019cb0(*(undefined4 *)(&DAT_0006b78e + local_24 * 0x28),DAT_00052acc);
          *(undefined4 *)(&DAT_0006b798 + local_24 * 0x28) = uVar2;
          if (((&DAT_0006b77a)[local_24 * 0x28] & 0x80) != 0) {
            *(int *)(&DAT_0006b798 + local_24 * 0x28) = -*(int *)(&DAT_0006b798 + local_24 * 0x28);
          }
          uVar3 = (uint)(byte)(&DAT_0006b792)[local_24 * 0x28];
          if ((DAT_000669da & 1) == 0) {
            *(undefined2 *)(&DAT_0006b79c + local_24 * 0x28) =
                 *(undefined2 *)(&DAT_0007c098 + uVar3 * 2);
          }
          else {
            *(undefined2 *)(&DAT_0006b79c + local_24 * 0x28) =
                 *(undefined2 *)
                  (&DAT_0007c098 +
                  ((int)((0xff - (uint)(byte)(&DAT_0006b793)[local_24 * 0x28]) * uVar3) / 0xff) * 2)
            ;
            *(undefined2 *)(&DAT_0006b79e + local_24 * 0x28) =
                 *(undefined2 *)
                  (&DAT_0007c098 + ((uVar3 * (byte)(&DAT_0006b793)[local_24 * 0x28]) / 0xff) * 2);
          }
        }
      }
    }
    uVar1 = unaff_DX;
    if (DAT_0007c320 < unaff_DX) {
      uVar1 = DAT_0007c320;
    }
    FUN_0001a518(local_1c,uVar1);
    DAT_0007c320 = DAT_0007c320 - uVar1;
    uVar3 = FUN_00019d04(uVar1);
    local_1c = local_1c + (uVar3 & 0xffff);
  }
  return;
}


/* ======== FUN_0001a798 @ 0001a798 ======== */

undefined4 FUN_0001a798(undefined4 param_1,undefined2 unaff_DX)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00019d40(unaff_DX);
  FUN_0001a580(param_1,uVar1);
  uVar2 = FUN_00019d04(uVar1);
  return uVar2;
}


/* ======== FUN_0001a7d8 @ 0001a7d8 ======== */

void FUN_0001a7d8(undefined4 param_1,undefined2 unaff_DX)

{
  if ((DAT_000669da & 2) == 0) {
    memset(param_1,0x80,unaff_DX);
  }
  else {
    memset(param_1,0,unaff_DX);
  }
  return;
}


/* ======== FUN_0001a81c @ 0001a81c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001a81c(void)

{
  int iVar1;
  int iVar2;
  uint local_24;
  int local_1c;
  
  DAT_0006bc8c = (int)(0x1000000 / (ulonglong)(longlong)(int)(uint)DAT_000669dc);
  for (local_1c = 0; local_1c < 0x41; local_1c = local_1c + 1) {
    iVar1 = DAT_0006bc8c * local_1c;
    iVar2 = iVar1 >> 0x1f;
    for (local_24 = 0xffffff80; (int)local_24 < 0x80; local_24 = local_24 + 1) {
      *(uint *)(&DAT_0006bc98 + (local_24 & 0xff) * 4 + local_1c * 0x400) =
           local_24 * ((int)((iVar1 + iVar2 * -0x40) - (uint)(iVar2 << 5 < 0)) >> 6);
    }
  }
  _DAT_0006bc94 = (int)(uint)DAT_000669dc >> 3;
  if ((DAT_000669da & 1) != 0) {
    _DAT_0006bc94 = _DAT_0006bc94 + 1;
  }
  DAT_0006bc7c = 0xe10;
  if ((DAT_000669da & 1) != 0) {
    DAT_0006bc7c = 0x708;
  }
  DAT_0007c320 = 0;
  return;
}


/* ======== FUN_0001a904 @ 0001a904 ======== */

void FUN_0001a904(void)

{
  return;
}


/* ======== FUN_0001a91c @ 0001a91c ======== */

undefined8 FUN_0001a91c(undefined4 param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined *puVar3;
  bool bVar4;
  undefined local_24;
  undefined4 local_20;
  uint local_1c;
  
  for (local_1c = 0; (int)local_1c < 0x20; local_1c = local_1c + 1) {
    *(undefined4 *)(&DAT_0006b794 + local_1c * 0x28) = 0;
    *(undefined2 *)(&DAT_0006b77a + local_1c * 0x28) = 0;
    *(undefined2 *)(&DAT_0006b77c + local_1c * 0x28) = 0;
    (&DAT_0006b778)[local_1c * 0x28] = 0;
    (&DAT_0006b779)[local_1c * 0x28] = 0;
    *(undefined4 *)(&DAT_0006b78e + local_1c * 0x28) = 10000;
    (&DAT_0006b792)[local_1c * 0x28] = 0;
    if ((local_1c & 1) == 0) {
      local_24 = 0xff;
    }
    else {
      local_24 = 0;
    }
    (&DAT_0006b793)[local_1c * 0x28] = local_24;
  }
  if ((DAT_000669da & 4) != 0) {
    DAT_000669da = DAT_000669da & 0xfb;
  }
  for (local_1c = 0; (int)local_1c < 0x41; local_1c = local_1c + 1) {
    *(undefined2 *)(&DAT_0007c098 + local_1c * 2) = 0;
  }
  local_1c = 0;
  do {
    bVar4 = local_1c < 0x41;
    if (0x40 < (int)local_1c) {
      local_20 = 1;
LAB_0001aa6e:
      return CONCAT44(unaff_EDX,local_20);
    }
    pcVar1 = (code *)swi(0x31);
    uVar2 = (*pcVar1)(10);
    if (bVar4) {
      uVar2 = 0;
    }
    *(undefined2 *)(&DAT_0007c098 + local_1c * 2) = uVar2;
    if (*(short *)(&DAT_0007c098 + local_1c * 2) == 0) {
      local_20 = 0;
      goto LAB_0001aa6e;
    }
    puVar3 = &DAT_0006bc98 + local_1c * 0x400;
    pcVar1 = (code *)swi(0x31);
    (*pcVar1)(CONCAT22((short)(local_1c * 2 >> 0x10),7),puVar3,
              *(undefined2 *)(&DAT_0007c098 + local_1c * 2),
              (uint)puVar3 >> 0x10 | (int)puVar3 * 0x10000);
    local_1c = local_1c + 1;
  } while( true );
}


/* ======== FUN_0001aa78 @ 0001aa78 ======== */

undefined8 FUN_0001aa78(int param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  int local_1c;
  
  for (local_1c = 0; local_1c < 0x41; local_1c = local_1c + 1) {
    if (*(short *)(&DAT_0007c098 + local_1c * 2) != 0) {
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(CONCAT22((short)((uint)(local_1c * 2) >> 0x10),1));
    }
    param_1 = local_1c;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0001aac8 @ 0001aac8 ======== */

void FUN_0001aac8(byte param_1,undefined unaff_DL)

{
  (&DAT_0006b792)[(uint)param_1 * 0x28] = unaff_DL;
  return;
}


/* ======== FUN_0001aaf4 @ 0001aaf4 ======== */

void FUN_0001aaf4(byte param_1,undefined4 unaff_EDX)

{
  *(undefined4 *)(&DAT_0006b78e + (uint)param_1 * 0x28) = unaff_EDX;
  return;
}


/* ======== FUN_0001ab20 @ 0001ab20 ======== */

void FUN_0001ab20(byte param_1,undefined unaff_DL)

{
  (&DAT_0006b793)[(uint)param_1 * 0x28] = unaff_DL;
  return;
}


/* ======== FUN_0001ab4c @ 0001ab4c ======== */

void FUN_0001ab4c(byte param_1,undefined2 unaff_DX,uint unaff_EBX,uint unaff_ECX,undefined4 param_5,
                 uint param_6,ushort param_7)

{
  if (unaff_EBX < unaff_ECX) {
    if (((param_7 & 0x10) != 0) && (unaff_ECX < param_6)) {
      param_6 = unaff_ECX;
    }
    *(ushort *)(&DAT_0006b77a + (uint)param_1 * 0x28) = param_7;
    *(undefined2 *)(&DAT_0006b77c + (uint)param_1 * 0x28) = unaff_DX;
    *(uint *)(&DAT_0006b77e + (uint)param_1 * 0x28) = unaff_EBX;
    *(uint *)(&DAT_0006b782 + (uint)param_1 * 0x28) = unaff_ECX;
    *(undefined4 *)(&DAT_0006b786 + (uint)param_1 * 0x28) = param_5;
    *(uint *)(&DAT_0006b78a + (uint)param_1 * 0x28) = param_6;
    (&DAT_0006b778)[(uint)param_1 * 0x28] = 1;
  }
  return;
}


/* ======== FUN_0001abfc @ 0001abfc ======== */

undefined8 FUN_0001abfc(byte param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,(uint)(byte)(&DAT_0006b779)[(uint)param_1 * 0x28]);
}


/* ======== FUN_0001ac50 @ 0001ac50 ======== */
/* role: item 0 use */

void FUN_0001ac50(void)

{
  return;
}


/* ======== FUN_0001ac68 @ 0001ac68 ======== */
/* role: item 1 use */

void FUN_0001ac68(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_256) /* "Zestaw pierszej pomocy." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ac98 @ 0001ac98 ======== */
/* role: item 4 use */

void FUN_0001ac98(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_259) /* "Bezpiecznik." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001acc8 @ 0001acc8 ======== */
/* role: item 5 use */

void FUN_0001acc8(void)

{
  g_fuel = 0x2f0000;
  Pocket_Remove(g_invSel);
  g_hudDirty._0_1_ = (byte)g_hudDirty | 4;
  return;
}


/* ======== FUN_0001acf8 @ 0001acf8 ======== */
/* role: item 2 use, item 6 use */

void FUN_0001acf8(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_257) /* "Czerwona karta magnetyczna." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ad28 @ 0001ad28 ======== */
/* role: item 7 use */

void FUN_0001ad28(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_276) /* "Nożyce do drutu." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ad58 @ 0001ad58 ======== */
/* role: item 8 use */

void FUN_0001ad58(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_260) /* "To chyba klucz do klatki." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ad88 @ 0001ad88 ======== */
/* role: item 9 use */

void FUN_0001ad88(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_261) /* "Puste wiaderko." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001adb8 @ 0001adb8 ======== */
/* role: item 10 use */

void FUN_0001adb8(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_262) /* "Wiaderko pełne wody." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ade8 @ 0001ade8 ======== */
/* role: item 11 use */

void FUN_0001ade8(void)

{
  Dlg_Begin();
  if ((g_roomCol == 1) && (g_roomRow == 5)) {
    Dlg_Say(MSG_160) /* "O rany! Ten chłamowaty gwizdek zamienił / się w jakiś klucz!" */;
    Pocket_Find(0xb);
    Pocket_Remove();
    Pocket_Add(0x17);
  }
  else {
    Dlg_Say(MSG_159) /* "Ten gwizdek nie działa! Zabiję grubasa!" */;
  }
  Dlg_End();
  return;
}


/* ======== FUN_0001ae54 @ 0001ae54 ======== */
/* role: item 12 use */

void FUN_0001ae54(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_263) /* "Gdzieś widziałem dziurę o takim kształcie..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001ae84 @ 0001ae84 ======== */
/* role: item 13 use */

void FUN_0001ae84(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_264) /* "Szara karta magnetyczna." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001aeb4 @ 0001aeb4 ======== */
/* role: item 14 use */

void FUN_0001aeb4(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_265) /* "Muszę znaleźć jakiś grób!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001aee4 @ 0001aee4 ======== */
/* role: item 15 use */

void FUN_0001aee4(void)

{
  ShowPicture(0x435);
  return;
}


/* ======== FUN_0001af04 @ 0001af04 ======== */
/* role: item 3 use, item 16 use */

void FUN_0001af04(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_258) /* "Fioletowa karta magnetyczna." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001af34 @ 0001af34 ======== */
/* role: item 17 use */

void FUN_0001af34(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_266) /* "Bilet na prom." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001af64 @ 0001af64 ======== */
/* role: item 18 use, item 19 use, item 20 use, item 21 use, item 22 use */

void FUN_0001af64(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_267) /* "Jeden z magicznych kluczy." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001af94 @ 0001af94 ======== */
/* role: item 23 use */

void FUN_0001af94(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_268) /* "Złoty klucz." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001afc4 @ 0001afc4 ======== */
/* role: item 24 use */

void FUN_0001afc4(void)

{
  Dlg_Begin();
  if (g_money == 0) {
    Dlg_Say(MSG_253) /* "Jestem kompletnie spłukany!" */;
  }
  else {
    Dlg_Print(MSG_252) /* "Mam w portfelu $" */;
    Text_DrawNumber(g_money);
    Text_Flip();
    WaitKeyFireEnterSpace();
    Text_Clear(0);
  }
  Dlg_End();
  return;
}


/* ======== FUN_0001b024 @ 0001b024 ======== */
/* role: item 25 use */

void FUN_0001b024(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_269) /* "Stara, cuchnąca skarpeta." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b054 @ 0001b054 ======== */
/* role: item 26 use */

void FUN_0001b054(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_270) /* "Dekoder bełkotu." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b084 @ 0001b084 ======== */
/* role: item 27 use */

void FUN_0001b084(void)

{
  ShowPicture(0x438);
  return;
}


/* ======== FUN_0001b0a4 @ 0001b0a4 ======== */
/* role: item 28 use */

void FUN_0001b0a4(void)

{
  if (DAT_00089314 == 0) {
    ShowPicture(0x439);
  }
  else if (DAT_00089314 == 1) {
    ShowPicture(0x43a);
  }
  else {
    ShowPicture(0x43a);
  }
  return;
}


/* ======== FUN_0001b0f8 @ 0001b0f8 ======== */
/* role: item 29 use */

void FUN_0001b0f8(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_271) /* "Pluszowy misiaczek." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b128 @ 0001b128 ======== */
/* role: item 30 use, item 31 use, item 32 use */

void FUN_0001b128(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_272) /* "Jeden z czarodziejskich kwiatów." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b158 @ 0001b158 ======== */
/* role: item 33 use */

void FUN_0001b158(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_273) /* "Nowy numer "Pani Domu"." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b188 @ 0001b188 ======== */
/* role: item 34 use */

void FUN_0001b188(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_274) /* "Sekator od czarownicy." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b1b8 @ 0001b1b8 ======== */
/* role: item 35 use */

void FUN_0001b1b8(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_275) /* "Klucz Czasu! Nareszcie!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b1e8 @ 0001b1e8 ======== */
/* role: item 36 use */

void FUN_0001b1e8(void)

{
  Dlg_Begin();
  if (*(int *)(&g_ammo + g_curWeapon * 4) == 0x2f0000) {
    Dlg_Say(MSG_278) /* "Magazynek jest pełny!" */;
    Dlg_End();
  }
  else {
    Ammo_AddThird();
    Sfx_Play(0x26,0,0);
    DAT_00089310 = DAT_00089310 + -1;
    if (DAT_00089310 == 0) {
      Pocket_Find(0x24);
      Pocket_Remove();
    }
    else {
      Dlg_Print(MSG_277) /* "Magazynków w zapasie: " */;
      FUN_0002cf7c(DAT_00089310);
      WaitKeyFireEnterSpace();
      Text_Clear(0);
    }
    Dlg_End();
  }
  return;
}


/* ======== FUN_0001b290 @ 0001b290 ======== */
/* role: item 37 use */

void FUN_0001b290(void)

{
  ShowPicture(DAT_0008947c);
  return;
}


/* ======== FUN_0001b2b0 @ 0001b2b0 ======== */

void FUN_0001b2b0(void)

{
  return;
}


/* ======== FUN_0001b2c8 @ 0001b2c8 ======== */
/* role: item 1 missing-item reply */

void FUN_0001b2c8(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_3) /* "Nie tego mi potrzeba, kmiotku!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b2f8 @ 0001b2f8 ======== */
/* role: item 2 missing-item reply */

void FUN_0001b2f8(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_8) /* "Potrzebuję czerwonej karty / żeby to uruchomić." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b328 @ 0001b328 ======== */
/* role: item 3 missing-item reply, item 16 missing-item reply */

void FUN_0001b328(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_1) /* "Wygląda na to, że przydałaby się / fioletowa karta!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b358 @ 0001b358 ======== */
/* role: item 4 missing-item reply */

void FUN_0001b358(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_5) /* "Co jest?! Nie działa!! / Chyba przepalił się bezpiecznik..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b388 @ 0001b388 ======== */
/* role: item 6 missing-item reply */

void FUN_0001b388(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_34) /* "Przydałaby się czerwona karta." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b3b8 @ 0001b3b8 ======== */
/* role: item 7 missing-item reply */

void FUN_0001b3b8(void)

{
  Dlg_Begin();
  Dlg_SayKeep(MSG_23) /* "Rozbrojenie bomby to pestka... / " */;
  Dlg_SayKeep(MSG_24) /* "Jeśli ma się obcęgi..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b3f8 @ 0001b3f8 ======== */
/* role: item 8 missing-item reply */

void FUN_0001b3f8(void)

{
  Dlg_Begin();
  Dlg_SayKeep(MSG_29) /* "Wygląda na dziurkę od klucza" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b428 @ 0001b428 ======== */
/* role: item 9 missing-item reply */

void FUN_0001b428(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_64) /* "Do diaska! Polałem sobie gacie! / Do niczego to i sam Olo nie naleje." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b454 @ 0001b454 ======== */
/* role: item 10 missing-item reply */

void FUN_0001b454(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_72) /* "Proszę! Pomóż mi, ugaś ten ogień" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b484 @ 0001b484 ======== */
/* role: item 12 missing-item reply */

void FUN_0001b484(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_76) /* "Wygląda na jakiś dziwny zamek..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b4b4 @ 0001b4b4 ======== */
/* role: item 13 missing-item reply */

void FUN_0001b4b4(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_77) /* "Potrzebuję szarej karty." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b4e4 @ 0001b4e4 ======== */
/* role: item 14 missing-item reply */

void FUN_0001b4e4(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_105) /* "Tu leży Jouler de Generat, / pirat i oprawca." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b514 @ 0001b514 ======== */
/* role: item 17 missing-item reply */

void FUN_0001b514(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_156) /* "Przewiozę cię, po okazaniu biletu. / I nie próbowałbym przefrunąć!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b544 @ 0001b544 ======== */
/* role: item 18 missing-item reply, item 19 missing-item reply, item 20 missing-item reply, item 21 missing-item reply, item 22 missing-item reply */

void FUN_0001b544(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_230) /* "To tutaj nie pasuje..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b574 @ 0001b574 ======== */
/* role: item 23 missing-item reply */

void FUN_0001b574(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_158) /* "Skąd mam wytrzasnąć taki klucz?" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b5a4 @ 0001b5a4 ======== */
/* role: item 25 missing-item reply */

void FUN_0001b5a4(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_140) /* "To mi nie zastąpi mojej skarpety!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b5d4 @ 0001b5d4 ======== */
/* role: item 26 missing-item reply */

void FUN_0001b5d4(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_161) /* "Dqwq wqeącew er hnduyqe erfdbg / judoioiu, ewiue uh x iuytwqu ju yterewr!" */;
  Dlg_Say(MSG_162) /* "Czy mógłbyś powtórzyć?" */;
  Dlg_Say(MSG_161) /* "Dqwq wqeącew er hnduyqe erfdbg / judoioiu, ewiue uh x iuytwqu ju yterewr!" */;
  Dlg_Say(MSG_163) /* "Chyba se nie pogadamy!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b630 @ 0001b630 ======== */
/* role: item 29 missing-item reply */

void FUN_0001b630(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_202) /* "Gdzie mój misio?!! / Nie zasnę bez niego!" */;
  Dlg_End();
  return;
}


/* ======== Script32_Merchant1 @ 0001b660 ======== */
/* role: script 32 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script32_Merchant1(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Print(MSG_37) /* "Drogi chłopcze! Jeśli masz kapuchę / druga taka okazja może się nie powtórzyć! /  / " */;
  g_menuOpt = 1;
  DAT_0008931c = 2;
  _DAT_00089320 = 3;
  _DAT_00089324 = 4;
  iVar1 = Dlg_Menu(/*options = MSG_37 + g_menuOpt[i]*/ 4);
  Text_Clear(0);
  if (iVar1 == 3) {
    DAT_000894a8 = 1;
    Dlg_Say(MSG_44) /* "To spadaj frajerzyno!" */;
    Dlg_End();
  }
  else if (g_money < 10) {
    Dlg_Say(MSG_43) /* "Nie stać cię na to! Żegnaj!" */;
    DAT_000894a8 = 1;
    Dlg_End();
  }
  else {
    if (iVar1 == 0) {
      DAT_000894a8 = 1;
      _DAT_00089338 = 1;
      Dlg_Say(MSG_53) /* "Oto hasło: Otchłań." */;
    }
    else if (iVar1 == 1) {
      DAT_000894a8 = 1;
      Pocket_Add(6);
    }
    else {
      Pocket_Add(7);
    }
    Dlg_Say(MSG_42) /* "Przyjemnie robić z tobą interesy, / ale muszę już lecieć!" */;
    Money_Spend(10);
    Dlg_End();
  }
  return;
}


/* ======== FUN_0001b794 @ 0001b794 ======== */
/* role: script 33 on_trigger */

void FUN_0001b794(void)

{
  Pocket_Give(6);
  return;
}


/* ======== FUN_0001b7b4 @ 0001b7b4 ======== */
/* role: item 33 missing-item reply */

void FUN_0001b7b4(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_86..MSG_87) /* "Przepraszam bardzo..." ... "Nie zawracaj mi głowy, / jestem zajęta." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b7e8 @ 0001b7e8 ======== */
/* role: script 34 on_trigger */

void FUN_0001b7e8(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_9) /* "Pomóż mi, proszę, póki jeszczę żyję! / Ściągnij mnie, a zdradzę ci pewną tajemnicę." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b814 @ 0001b814 ======== */
/* role: item 34 missing-item reply */

void FUN_0001b814(void)

{
  int iVar1;
  
  Dlg_Begin();
  iVar1 = Pocket_Find(0x22);
  if (iVar1 < 0) {
    Dlg_Say(MSG_254) /* "Po co mi jakiś kwiatek?!" */;
  }
  else {
    Dlg_Say(MSG_255) /* "Muszę użyć sekatora!" */;
  }
  Dlg_End();
  return;
}


/* ======== FUN_0001b864 @ 0001b864 ======== */
/* role: script 35 on_trigger */

void FUN_0001b864(void)

{
  Dlg_Begin();
  Dlg_Print(MSG_10) /* "Dziękuję przyjacielu! / Zapamiętaj: " */;
  Dlg_Say(&PTR_DAT_00053d88,DAT_00089348 + 2);
  Dlg_Say(MSG_22) /* "Oj! Chyba upadł na głowę..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001b8b4 @ 0001b8b4 ======== */
/* role: item 35 missing-item reply */

void FUN_0001b8b4(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_229) /* "To raczej nie jest Klucz Czasu..." */;
  Dlg_End();
  return;
}


/* ======== Script37_Merchant2 @ 0001b8e4 ======== */
/* role: script 37 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script37_Merchant2(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Print(MSG_45) /* "Witaj nieznajomy! Czyżbyś dał się zrobić w bambuko / mojemu ziomkowi z góry? Popraw sobie humor! /  " */;
  g_menuOpt = 9;
  DAT_0008931c = 10;
  _DAT_00089320 = 0xb;
  _DAT_00089324 = 0xc;
  iVar1 = Dlg_Menu(/*options = MSG_37 + g_menuOpt[i]*/ 4);
  Text_Clear(0);
  if (iVar1 == 3) {
    Dlg_Say(MSG_51) /* "Cóż, i tak mi się nie spodobałeś!" */;
    Dlg_End();
  }
  else if (g_money < 0xe) {
    Dlg_Say(MSG_43) /* "Nie stać cię na to! Żegnaj!" */;
    Dlg_End();
  }
  else {
    Dlg_Say(MSG_50) /* "Gratuluję trafnego wyboru, i znikam!" */;
    Money_Spend(0xe);
    if (iVar1 == 1) {
      Pocket_Add(7);
    }
    else {
      WaitKeyFireEnterSpace();
      Text_Clear(0);
      Dlg_Say(MSG_52) /* "Mam wrażenie że dałem dupy... / Chyba pozbędę się tego szajsu." */;
    }
    Dlg_End();
  }
  return;
}


/* ======== Script38_BombArmed @ 0001b9d8 ======== */
/* role: script 38 on_trigger */

void Script38_BombArmed(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_14..MSG_17) /* "No... Wreszcie ktoś tu zawitał..." ... "COOO?! MÓWŻE GŁOŚNIEJ ANEMIKU!" */;
  Bomb_StartSound();
  FadePalette(&g_palGame,&g_palAlarm,7);
  g_curPalette = &g_palAlarm;
  Dlg_SayRange(MSG_18..MSG_21) /* "No to masz babo placek! / PROSIŁEM, ŻEBYŚ TAK NIE RYCZAŁ!!! " ... "A, jeszcze jedno! Byłbym wdzięczny / gdybyś przy okazji roze" */;
  g_bombActive = 1;
  Dlg_End();
  return;
}


/* ======== Script39_BombDefuse @ 0001ba4c ======== */
/* role: script 39 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script39_BombDefuse(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Print(MSG_25) /* "Mamy 3 kabelki. Który by tu przeciąć? /  / " */;
  g_menuOpt = 0x11;
  DAT_0008931c = 0x12;
  _DAT_00089320 = 0x13;
  iVar1 = Dlg_Menu(/*options = MSG_9 + g_menuOpt[i]*/ 3);
  Text_Clear(0);
  if (iVar1 == DAT_00089348) {
    Bomb_StopSound();
    FadePalette(&g_palAlarm,&g_palGame,7);
    g_curPalette = &g_palGame;
    g_bombActive = 0;
    Pocket_Find(7);
    Pocket_Remove();
    Dlg_Say(MSG_35) /* "Nie wyjebało!" */;
    Dlg_End();
  }
  else {
    Dlg_Print(MSG_36) /* "Ooops!!! Pomyłka!" */;
    Delay(100);
    Text_Clear(0);
    Hero_Explode();
    Dlg_End();
  }
  return;
}


/* ======== FUN_0001bb38 @ 0001bb38 ======== */
/* role: script 41 on_trigger */

void FUN_0001bb38(void)

{
  Pocket_Give(8);
  return;
}


/* ======== FUN_0001bb58 @ 0001bb58 ======== */
/* role: script 42 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001bb58(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_30..MSG_33) /* "Nie śpieszyło się koleżce, co? / Od tego wycia dostałem migr" ... "Phiii... domyślałem się!" */;
  _DAT_00089334 = 1;
  Dlg_End();
  return;
}


/* ======== FUN_0001bb98 @ 0001bb98 ======== */
/* role: script 43 on_trigger */

void FUN_0001bb98(void)

{
  Pocket_Give(0x13);
  return;
}


/* ======== FUN_0001bbb8 @ 0001bbb8 ======== */
/* role: script 44 on_trigger */

void FUN_0001bbb8(void)

{
  Pocket_Give(0x20);
  return;
}


/* ======== FUN_0001bbd8 @ 0001bbd8 ======== */
/* role: script 45 on_trigger */

void FUN_0001bbd8(void)

{
  Hero_StartTeleport(4,5,0xe,0x53);
  return;
}


/* ======== Script64_Witch @ 0001bc08 ======== */
/* role: script 64 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script64_Witch(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_SayRange(MSG_88..MSG_91) /* "O jejku! Najnowszy numer! / Dziękuję ci drogi chłopcze! / Ja" ... "Trudno, niech będzie mikstura." */;
  Pocket_Find(0x21);
  Pocket_Remove();
  Dlg_Print(MSG_92) /* "Czego byś się napił? /  / " */;
  g_menuOpt = 0x1d;
  DAT_0008931c = 0x1e;
  _DAT_00089320 = 0x1f;
  iVar1 = Dlg_Menu(/*options = MSG_64 + g_menuOpt[i]*/ 3);
  Text_Clear(0);
  if (iVar1 == 1) {
    Dlg_SayRange(MSG_96..MSG_97) /* "Do przyrządzenia tej mikstury / będę potrzebowała trzech mag" ... "Gdy je odnajdziesz, wróć tu / i wrzuć je do kotła." */;
    Pocket_Add(0x22);
    Dlg_End();
  }
  else {
    Dlg_Say(MSG_99) /* "Świetnie! Zabieram się do roboty!" */;
    Dlg_SayKeep(MSG_100) /* "Chwileczkę! / " */;
    WaitKeyFireEnterSpace();
    Dlg_SayKeep(MSG_101) /* "Momencik! / " */;
    WaitKeyFireEnterSpace();
    Dlg_Say(MSG_102) /* "I oto jest! / " */;
    Dlg_Say(MSG_103) /* "To chluśniem, bo uśniem!" */;
    if (iVar1 == 0) {
      _DAT_00089388 = 1;
      _DAT_0008935c = 0;
      Delay(100);
      g_quitLoop = 1;
      g_heroDead = 1;
      Dlg_Say2(MSG_122) /* "Oops!! Musiałam coś popieprzyć! / PRZEPRASZAM!!!" */;
      Dlg_End();
    }
    else {
      FadePalette(&g_palGame,&g_palBlack,6);
      g_curPalette = &g_palBlack;
      ShowPCXAndWait(s_DATA21_RES_0005990c);
      g_quitLoop = 1;
      g_heroDead = 2;
    }
  }
  return;
}


/* ======== Script65_Cauldron @ 0001bd98 ======== */
/* role: script 65 on_trigger */

void Script65_Cauldron(void)

{
  int iVar1;
  int local_20;
  int local_1c;
  
  iVar1 = Pocket_Find(0x22);
  if ((-1 < iVar1) && (DAT_00089360 != 3)) {
    local_1c = 0x1e;
    for (local_20 = 1; local_20 < 4; local_20 = local_20 + 1) {
      iVar1 = Pocket_Find(local_1c);
      if (-1 < iVar1) {
        Pocket_Remove(iVar1);
        DAT_00089360 = DAT_00089360 + 1;
      }
      local_1c = local_1c + 1;
      iVar1 = local_20;
    }
    Dlg_Begin(iVar1);
    if (DAT_00089360 == 3) {
      Dlg_Say(MSG_99) /* "Świetnie! Zabieram się do roboty!" */;
      Dlg_SayKeep(MSG_100) /* "Chwileczkę! / " */;
      WaitKeyFireEnterSpace();
      Dlg_SayKeep(MSG_101) /* "Momencik! / " */;
      WaitKeyFireEnterSpace();
      Dlg_Say(MSG_102) /* "I oto jest! / " */;
      Dlg_Say(MSG_104) /* "Mam nadzieję, że wiesz co z tym zrobić." */;
      Pocket_Find(0x22);
      Pocket_Remove();
      Pocket_Add(0xe);
      Dlg_End();
    }
    else {
      Dlg_Say(MSG_98) /* "Potrzebuję TRZECH kwiatów!" */;
      Dlg_End();
    }
  }
  return;
}


/* ======== FUN_0001bea8 @ 0001bea8 ======== */
/* role: script 66 on_trigger */

void FUN_0001bea8(void)

{
  Pocket_Give(9);
  return;
}


/* ======== FUN_0001bec8 @ 0001bec8 ======== */
/* role: script 67 on_trigger */

void FUN_0001bec8(void)

{
  Dlg_Begin();
  Pocket_Remove(g_invSel);
  Pocket_Add(10);
  Dlg_SayKeep(MSG_65) /* "Do pełna proszę! / " */;
  WaitKeyFireEnterSpace();
  Dlg_Say(MSG_66) /* "No i wiaderko jest pełne!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001bf20 @ 0001bf20 ======== */
/* role: script 68 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001bf20(void)

{
  Dlg_Begin();
  Pocket_Remove(g_invSel);
  Pocket_Add(0xb);
  Dlg_SayRange(MSG_73..MSG_75) /* "Wielkie dzięki! W dowód mojej wdzięczności / przyjmij ten gw" ... "Wygląda chłamowato, ale dzięki grubasie!" */;
  Dlg_SayRange(MSG_83..MSG_85) /* "Magiczne słowo DZIĘKUJĘ zawsze mnie / wzrusza, więc oto jesz" ... "Co za dużo to niezdrowo!" */;
  _DAT_00089338 = 1;
  Dlg_End();
  return;
}


/* ======== FUN_0001bf88 @ 0001bf88 ======== */
/* role: script 69 on_trigger */

void FUN_0001bf88(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_67..MSG_71) /* "Co ci się tak czacha kopci? / Od myślenia?" ... "Łał! No niezła bajka! / Postaram się o jakąś wodę." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001bfbc @ 0001bfbc ======== */
/* role: script 70 on_trigger */

void FUN_0001bfbc(void)

{
  Pocket_Give(0xd);
  return;
}


/* ======== FUN_0001bfdc @ 0001bfdc ======== */
/* role: script 71 on_trigger */

void FUN_0001bfdc(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_78) /* "Tu leży Long John Silver. / Zmarł na katar." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c00c @ 0001c00c ======== */
/* role: script 72 on_trigger */

void FUN_0001c00c(void)

{
  Dlg_Begin();
  Dlg_SayKeep(MSG_79) /* "O ręka wystaje! Sprawdzę puls, / może jeszcze dycha. / " */;
  Dlg_Say(MSG_80) /* "Mój Boże! Za późno!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c04c @ 0001c04c ======== */
/* role: script 73 on_trigger */

void FUN_0001c04c(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_81) /* "Ś.P. Gereon Świniopas / pożarty przez wieprza." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c07c @ 0001c07c ======== */
/* role: script 74 on_trigger */

void FUN_0001c07c(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_82) /* "R.I.P. Jaksra Tokwili. / Udławił się spłuczką." */;
  Dlg_End();
  return;
}


/* ======== Script75_Undertaker @ 0001c0ac ======== */
/* role: script 75 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script75_Undertaker(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Say(MSG_54) /* "Prowadzisz tutaj zakład pogrzebowy?" */;
  Dlg_Print(MSG_55) /* "Prowadziłem, ale obsłużyłem już wszystkich / klientów. Zwijam interes, ale mam coś co / może cię zai" */;
  g_menuOpt = 0x13;
  DAT_0008931c = 0x14;
  _DAT_00089320 = 0x15;
  _DAT_00089324 = 0x16;
  iVar1 = Dlg_Menu(/*options = MSG_37 + g_menuOpt[i]*/ 4);
  Text_Clear(0);
  if (iVar1 == 3) {
    Dlg_Say(MSG_63) /* "Twoja strata!" */;
    Dlg_End();
  }
  else if (g_money < 10) {
    Dlg_Say(MSG_43) /* "Nie stać cię na to! Żegnaj!" */;
    Dlg_End();
  }
  else {
    Money_Spend(10);
    if (iVar1 == 0) {
      _DAT_00089338 = 1;
      Dlg_Say(MSG_60) /* "Oto hasło: Otchłań." */;
    }
    else if (iVar1 == 1) {
      Dlg_Say(MSG_61) /* "Mądry wybór! / Nie mam przy sobie blankietu, / ale masz moje słowo!" */;
    }
    else {
      Pocket_Add(0xf);
    }
    Dlg_Say(MSG_62) /* "To do zobaczenia!" */;
    Dlg_End();
  }
  return;
}


/* ======== FUN_0001c1d8 @ 0001c1d8 ======== */
/* role: script 79 on_trigger */

void FUN_0001c1d8(void)

{
  Pocket_Give(0x16);
  return;
}


/* ======== FUN_0001c1f8 @ 0001c1f8 ======== */
/* role: script 80 on_trigger */

void FUN_0001c1f8(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_106..MSG_120) /* "Czy to.. ty jesteś.. Jouler de Generat?" ... "Dziękuję sir! Zakopię na pewno!" */;
  Pocket_Add(0x23);
  Dlg_End();
  return;
}


/* ======== FUN_0001c238 @ 0001c238 ======== */
/* role: script 81 on_trigger */

void FUN_0001c238(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_121) /* "Zakopany, aż miło!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c268 @ 0001c268 ======== */
/* role: script 97 on_trigger */

void FUN_0001c268(void)

{
  Pocket_Give(0x10);
  return;
}


/* ======== FUN_0001c288 @ 0001c288 ======== */
/* role: script 98 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c288(void)

{
  Dlg_Begin();
  Hero_StartTeleport(4,2,100,0x79);
  _DAT_0008933c = 1;
  Dlg_End();
  return;
}


/* ======== FUN_0001c2cc @ 0001c2cc ======== */
/* role: script 99 on_trigger */

void FUN_0001c2cc(void)

{
  Pocket_Give(0x14);
  return;
}


/* ======== FUN_0001c2ec @ 0001c2ec ======== */
/* role: script 100 on_trigger */

void FUN_0001c2ec(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_123) /* "Pomocy! To monstrum chce mnie pożreć! / Zrób coś! Długo już nie wytrzymam!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c318 @ 0001c318 ======== */
/* role: script 101 on_trigger */

void FUN_0001c318(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_124) /* "Dziękuję przyjacielu! / Myślałem, że to bydlę mnie zeżre!" */;
  Dlg_Say(MSG_125) /* "Nie ma sprawy! Za to mi płacą!" */;
  Dlg_Print(MSG_126) /* "Jednak pozwól, że zdradzę ci pewną tajemnicę: / Wiedz, że jeden z sekretnych kluczy znajduje / się z" */;
  Dlg_Say(&PTR_DAT_00053f50,DAT_00089368 + 4);
  Dlg_Say(MSG_130) /* "Dzięki!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c388 @ 0001c388 ======== */
/* role: script 102 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001c388(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_145..MSG_155) /* "Wiedziałam, że przybędziesz!" ... "Żegnaj mesjaszu! Mój czas nadszedł!" */;
  _DAT_00089340 = 1;
  Dlg_End();
  return;
}


/* ======== FUN_0001c3c8 @ 0001c3c8 ======== */
/* role: script 103 on_trigger */

void FUN_0001c3c8(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_133..MSG_139) /* "Co tu tak sterczysz nieboraku?" ... "Hmmm.. Nie wiem po co ktoś miałby kraść / jakąś śmierdzącą s" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c3fc @ 0001c3fc ======== */
/* role: script 104 on_trigger */

void FUN_0001c3fc(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_141..MSG_144) /* "Myślałem, że już jej nigdy nie zobaczę! / Wielkie dzięki!" ... "Dobra! Dawaj!" */;
  Pocket_Find(0x19);
  Pocket_Remove();
  Pocket_Add(0x1a);
  Dlg_End();
  return;
}


/* ======== FUN_0001c448 @ 0001c448 ======== */
/* role: script 105 on_trigger */

void FUN_0001c448(void)

{
  Dlg_Begin();
  if (((*(int *)(&DAT_0005442c + DAT_00089350 * 8) == g_roomCol) &&
      (*(int *)(&DAT_00054430 + DAT_00089350 * 8) == g_roomRow)) && (DAT_00089354 == 0)) {
    Dlg_Say(MSG_132) /* "Znalazłem jakąś śmierdzącą skarpetę!" */;
    Pocket_Add(0x19);
    DAT_00089354 = 1;
    Dlg_End();
  }
  else {
    Dlg_Say(MSG_131) /* "W środku nic nie ma." */;
    Dlg_End();
  }
  return;
}


/* ======== FUN_0001c4e0 @ 0001c4e0 ======== */
/* role: script 106 on_trigger */

void FUN_0001c4e0(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_131) /* "W środku nic nie ma." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c510 @ 0001c510 ======== */
/* role: script 107 on_trigger */

void FUN_0001c510(void)

{
  Dlg_Begin();
  Pocket_Find(0x11);
  Pocket_Remove();
  Dlg_Say2(MSG_157) /* "W porządku! Płyniemy!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c550 @ 0001c550 ======== */
/* role: script 108 on_trigger */

void FUN_0001c550(void)

{
  g_fuel = 0;
  g_hudDirty._0_1_ = (byte)g_hudDirty | 4;
  return;
}


/* ======== FUN_0001c578 @ 0001c578 ======== */
/* role: script 128 on_trigger */

void FUN_0001c578(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_0) /* "O! paliwo do plecaka!" */;
  Pocket_Add(5);
  Dlg_End();
  return;
}


/* ======== FUN_0001c5b0 @ 0001c5b0 ======== */
/* role: script 129 on_trigger */

void FUN_0001c5b0(void)

{
  Pocket_Give(3);
  return;
}


/* ======== FUN_0001c5d0 @ 0001c5d0 ======== */
/* role: script 130 on_trigger */

void FUN_0001c5d0(void)

{
  Pocket_Give(1);
  return;
}


/* ======== FUN_0001c5f0 @ 0001c5f0 ======== */
/* role: script 131 on_trigger */

void FUN_0001c5f0(void)

{
  Pocket_Give(4);
  return;
}


/* ======== FUN_0001c610 @ 0001c610 ======== */
/* role: script 132 on_trigger */

void FUN_0001c610(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_6) /* "Naprawione!" */;
  Pocket_Find(4);
  Pocket_Remove();
  FUN_0001d4b8();
  Dlg_End();
  return;
}


/* ======== Fuel_AddThird @ 0001c654 ======== */
/* role: script 134 on_trigger */

void Fuel_AddThird(void)

{
  g_fuel = &DAT_000faaaa + (int)g_fuel;
  if (0x2f0000 < (int)g_fuel) {
    g_fuel = (undefined *)0x2f0000;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 4;
  return;
}


/* ======== Energy_AddThird @ 0001c690 ======== */
/* role: script 136 on_trigger, script 137 on_trigger */

void Energy_AddThird(void)

{
  g_energy = &DAT_000faaaa + (int)g_energy;
  if (0x2f0000 < (int)g_energy) {
    g_energy = (undefined *)0x2f0000;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 1;
  return;
}


/* ======== FUN_0001c6cc @ 0001c6cc ======== */
/* role: script 138 on_trigger */

void FUN_0001c6cc(void)

{
  Dlg_Begin();
  Dlg_Say(MSG_7) /* "Hmm.. trochę daleko do drugiego brzegu... / Chyba tego nie przeskoczę..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c6fc @ 0001c6fc ======== */
/* role: script 139 on_trigger */

void FUN_0001c6fc(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_2) /* "Chłopie, nie wiem skąd się tutaj / wziąłeś, ale błagam cię, pomóż mi! / Jeszcze trochę i wykrwawię s" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c72c @ 0001c72c ======== */
/* role: script 140 on_trigger */

void FUN_0001c72c(void)

{
  Dlg_Begin();
  Pocket_Remove(g_invSel);
  Pocket_Add(2);
  Dlg_Say2(MSG_4) /* "Dziękuję ci z całego serca, / prawdopodobnie uratowałeś mi życie! / Jeżeli chcesz się wydostać z tej" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001c770 @ 0001c770 ======== */
/* role: script 141 on_trigger */

void FUN_0001c770(void)

{
  Pocket_Give(0x15);
  return;
}


/* ======== FUN_0001c790 @ 0001c790 ======== */
/* role: script 142 on_trigger */

void FUN_0001c790(void)

{
  Pocket_Give(0x1e);
  return;
}


/* ======== Script160_VendingMachine @ 0001c7b0 ======== */
/* role: script 160 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Script160_VendingMachine(void)

{
  int iVar1;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  Dlg_Begin();
  _DAT_0008936c = (uint)(g_energy != 0x2f0000);
  local_1c = 0;
  local_20 = 0;
  local_2c = 0;
  local_24 = 0x1a;
  for (local_28 = 5; -1 < local_28; local_28 = local_28 + -1) {
    if (*(int *)(&DAT_0008936c + local_1c * 4) != 0) {
      (&g_menuOpt)[local_20] = local_24;
      local_2c = local_2c + 1;
      local_20 = local_20 + 1;
    }
    local_24 = local_24 + 1;
    local_1c = local_1c + 1;
  }
  Dlg_Print(MSG_232) /* "Witamy w naszym sklepiku! / Czym możemy służyć? /  / " */;
  iVar1 = Dlg_Menu(/*options = MSG_207 + g_menuOpt[i]*/ local_2c);
  local_34 = 0;
  local_30 = -1;
  for (local_1c = 0; local_1c < 6; local_1c = local_1c + 1) {
    if (*(int *)(&DAT_0008936c + local_1c * 4) != 0) {
      local_30 = local_30 + 1;
    }
    if (local_30 == iVar1) {
      local_34 = local_1c;
      local_1c = 6;
    }
  }
  Text_Clear(0);
  if (local_34 == 0) {
    if (g_money < 5) {
      Dlg_Say(MSG_239) /* "Niestety, nie stać cię na to!" */;
      Dlg_End();
    }
    else {
      Money_Spend(5);
      Energy_AddThird();
      Dlg_Say(MSG_240) /* "Życzymy miłego dnia!" */;
      Dlg_End();
    }
  }
  else if (local_34 == 1) {
    if (g_money < 2) {
      Dlg_Say(MSG_239) /* "Niestety, nie stać cię na to!" */;
      Dlg_End();
    }
    else {
      Money_Spend(2);
      iVar1 = Pocket_Find(0x24);
      if (iVar1 < 0) {
        Pocket_Add(0x24);
      }
      DAT_00089310 = DAT_00089310 + 1;
      Dlg_Say(MSG_240) /* "Życzymy miłego dnia!" */;
      Dlg_End();
    }
  }
  else if (local_34 == 2) {
    if (g_money < 0x14) {
      Dlg_Say(MSG_239) /* "Niestety, nie stać cię na to!" */;
      Dlg_End();
    }
    else {
      Money_Spend(0x14);
      FUN_0001d190();
      _DAT_00089374 = 0;
      Dlg_Say(MSG_240) /* "Życzymy miłego dnia!" */;
      Dlg_End();
    }
  }
  else if (local_34 == 3) {
    if (g_money < 0x5f) {
      Dlg_Say(MSG_239) /* "Niestety, nie stać cię na to!" */;
      Dlg_End();
    }
    else {
      Money_Spend(0x5f);
      Pocket_Add(0x11);
      _DAT_00089378 = 0;
      Dlg_Say(MSG_240) /* "Życzymy miłego dnia!" */;
      Dlg_End();
    }
  }
  else if (local_34 == 4) {
    if (g_money < 0x1e) {
      Dlg_Say(MSG_239) /* "Niestety, nie stać cię na to!" */;
      Dlg_End();
    }
    else {
      Money_Spend(0x1e);
      Pocket_Add(0x25);
      _DAT_0008937c = 0;
      Dlg_Say(MSG_240) /* "Życzymy miłego dnia!" */;
      Dlg_End();
    }
  }
  else {
    Dlg_End();
  }
  return;
}


/* ======== Script161_MagicKeySlot @ 0001cab8 ======== */
/* role: script 161 on_trigger */

void Script161_MagicKeySlot(void)

{
  int iVar1;
  undefined4 *local_1c;
  
  if (DAT_0008938c != 5) {
    DAT_0008938c = DAT_0008938c + 1;
    Pocket_Remove(g_invSel);
    if (DAT_0008938c == 5) {
      for (local_1c = g_platformList; local_1c != (undefined4 *)0x0;
          local_1c = (undefined4 *)*local_1c) {
        iVar1 = (**(code **)(local_1c[1] + 0x10))(local_1c);
        if (iVar1 == 0xc) {
          (**(code **)(local_1c[1] + 0x18))(local_1c);
        }
      }
    }
  }
  return;
}


/* ======== FUN_0001cb30 @ 0001cb30 ======== */
/* role: script 162 on_trigger */

void FUN_0001cb30(void)

{
  Dlg_Begin();
  Pocket_Find(0x23);
  Pocket_Remove();
  Dlg_Say2(MSG_231) /* "Brawo chłopcze! / Drzwi do twego świata stoją otworem! / Wpadnij tu kiedyś pogadać. Trzymaj się!" */;
  Dlg_End();
  return;
}


/* ======== Script163_TimeGuardian @ 0001cb70 ======== */
/* role: script 163 on_trigger */

void Script163_TimeGuardian(void)

{
  int local_1c;
  
  Dlg_Begin();
  Dlg_SayRange(MSG_208..MSG_228) /* "Przepraszam, którędy do Strażnika Czasu?" ... "Ja również!" */;
  Dlg_SayRange(MSG_241..MSG_242) /* "W zamian dam ci niekończące się / amunicję i paliwo. Powinny" ... "Dziękuję!" */;
  g_cheatInfinite = 1;
  for (local_1c = 0; local_1c < 6; local_1c = local_1c + 1) {
    *(undefined4 *)(&g_ammo + local_1c * 4) = 0x2f0000;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 2;
  Pocket_Add(0x21);
  Dlg_End();
  return;
}


/* ======== FUN_0001cc00 @ 0001cc00 ======== */
/* role: script 164 on_trigger */

void FUN_0001cc00(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_207) /* "Zaufaj mocy, Lucek!" */;
  Dlg_End();
  return;
}


/* ======== Script165_Win @ 0001cc2c ======== */
/* role: script 165 on_trigger */

void Script165_Win(void)

{
  FadePalette(&g_palGame,&g_palBlack,6);
  g_curPalette = &g_palBlack;
  g_quitLoop = 1;
  g_heroDead = 3;
  return;
}


/* ======== FUN_0001cc70 @ 0001cc70 ======== */
/* role: script 192 on_trigger */

void FUN_0001cc70(void)

{
  Pocket_Give(0x12);
  return;
}


/* ======== FUN_0001cc90 @ 0001cc90 ======== */
/* role: script 193 on_trigger */

void FUN_0001cc90(void)

{
  Pocket_Give(0xc);
  return;
}


/* ======== FUN_0001ccb0 @ 0001ccb0 ======== */
/* role: script 194 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ccb0(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Say(MSG_161) /* "Dqwq wqeącew er hnduyqe erfdbg / judoioiu, ewiue uh x iuytwqu ju yterewr!" */;
  Dlg_SayRange(MSG_164..MSG_166) /* "Ten drań mnie oszukał! / Dekoder nie działa!" ... "To jest walkman?!! No, no! Człowiek / uczy się przez całe ży" */;
  Dlg_Print(MSG_167) /* "Mam przy sobie kilka drobiazgów. / Może chcesz za niego: /  / " */;
  g_menuOpt = 9;
  DAT_0008931c = 10;
  _DAT_00089320 = 0xb;
  _DAT_00089324 = 0xc;
  iVar1 = Dlg_Menu(/*options = MSG_159 + g_menuOpt[i]*/ 4);
  Text_Clear(0);
  if (iVar1 == 3) {
    Dlg_Say(MSG_172) /* "Twoja strata palancie!" */;
    Dlg_End();
  }
  else {
    Pocket_Find(0x1a);
    Pocket_Remove();
    if (iVar1 == 2) {
      Dlg_Say(MSG_174) /* "Przepraszamy na chwilkę..." */;
      FadePalette(g_curPalette,&g_palBlack,7);
      thunk_FUN_00037417(5000);
      FadePalette(&g_palBlack,g_curPalette,7);
      Dlg_Say(MSG_175) /* "Ufff! Było warto! / To jest lepsze niż jazda na rowerze!" */;
      Dlg_Say(MSG_173) /* "Świetnie! Miło było cię poznać!" */;
      Dlg_End();
    }
    else if (iVar1 == 1) {
      Pocket_Add(0x1b);
      Dlg_Say(MSG_173) /* "Świetnie! Miło było cię poznać!" */;
      Dlg_End();
    }
    else {
      Money_Add(0x1e);
      Dlg_Say(MSG_173) /* "Świetnie! Miło było cię poznać!" */;
      Dlg_End();
    }
  }
  return;
}


/* ======== FUN_0001ce20 @ 0001ce20 ======== */
/* role: script 195 on_trigger */

void FUN_0001ce20(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_176..MSG_181) /* "Wyglądasz jakbyś potrzebował pomocy.. / Co mam zrobić: ściąg" ... "Oto ona." */;
  if (DAT_00089314 == 0) {
    ShowPicture(0x439);
  }
  else if (DAT_00089314 == 1) {
    ShowPicture(0x43a);
  }
  else {
    ShowPicture(0x43b);
  }
  Dlg_Say(MSG_182) /* "Przyjdź do mnie jeśli znajdziesz / rozwiązanie. Zastanów się dobrze!" */;
  Pocket_Add(0x1c);
  Dlg_End();
  return;
}


/* ======== FUN_0001ceac @ 0001ceac ======== */
/* role: script 196 on_trigger */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ceac(void)

{
  uint uVar1;
  bool bVar2;
  
  Dlg_Begin();
  Dlg_Print(MSG_184) /* "Doskonale! / Wskaż właściwą liczbę: /  / " */;
  _DAT_00089320 = DAT_00089314 * 3;
  g_menuOpt = _DAT_00089320 + 0x1a;
  DAT_0008931c = _DAT_00089320 + 0x1b;
  _DAT_00089320 = _DAT_00089320 + 0x1c;
  uVar1 = Dlg_Menu(/*options = MSG_159 + g_menuOpt[i]*/ 3);
  Text_Clear(0);
  if (uVar1 != 0) {
    if (uVar1 < 2) {
      bVar2 = DAT_00089314 < 2;
      goto LAB_0001cf6e;
    }
    if (uVar1 == 2) {
      bVar2 = DAT_00089314 == 2;
      goto LAB_0001cf6e;
    }
  }
  bVar2 = false;
LAB_0001cf6e:
  if (bVar2) {
    Dlg_Say(MSG_194) /* "Brawo! Bystrzak z ciebie! / Możesz iść dalej. Powodzenia!" */;
    DAT_00089549 = 1;
  }
  else {
    Dlg_Say(MSG_195) /* "Niestety! Pudło! / Z takim IQ daleko nie zajdziesz! / Żegnaj!" */;
  }
  Pocket_Find(0x1c);
  Pocket_Remove();
  Dlg_End();
  return;
}


/* ======== FUN_0001cfb8 @ 0001cfb8 ======== */
/* role: script 198 on_trigger */

void FUN_0001cfb8(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_196..MSG_201) /* "Hej! Wyglądasz na twardziela! / Mam dla ciebie robotę." ... "Hmm.. Wprawdzie nie specjalizuję się / w odnajdywaniu zabawe" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001cfec @ 0001cfec ======== */
/* role: script 199 on_trigger */

void FUN_0001cfec(void)

{
  Dlg_Begin();
  Dlg_SayRange(MSG_204..MSG_205) /* "Dziękuję, mój zbawco! / Oto pieniądze!" ... "Cała przyjemność po mojej stronie!" */;
  Pocket_Find(0x1d);
  Pocket_Remove();
  Money_Add(100);
  Dlg_End();
  return;
}


/* ======== FUN_0001d038 @ 0001d038 ======== */
/* role: script 200 on_trigger */

void FUN_0001d038(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_203) /* "NIE WRACAJ BEZ MISIACZKA!!!" */;
  Dlg_End();
  return;
}


/* ======== FUN_0001d068 @ 0001d068 ======== */
/* role: script 201 on_trigger */

void FUN_0001d068(void)

{
  Pocket_Give(0x1d);
  return;
}


/* ======== FUN_0001d088 @ 0001d088 ======== */
/* role: script 202 on_trigger */

void FUN_0001d088(void)

{
  Pocket_Give(0x1f);
  return;
}


/* ======== FUN_0001d0a8 @ 0001d0a8 ======== */
/* role: script 203 on_trigger */

void FUN_0001d0a8(void)

{
  int iVar1;
  
  iVar1 = Random(3);
  if (iVar1 == 0) {
    Hero_StartTeleport(9,6,0xba,0xb2);
  }
  else {
    Hero_StartTeleport(8,8,0x6c,0x7d);
  }
  return;
}


/* ======== FUN_0001d100 @ 0001d100 ======== */
/* role: script 204 on_trigger */

void FUN_0001d100(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_206) /* "UWAGA! / Teleport uszkodzony. / Użycie może być niebezpieczne." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001d130 @ 0001d130 ======== */
/* role: script 224 on_trigger */

void FUN_0001d130(void)

{
  Money_Add(1);
  return;
}


/* ======== FUN_0001d150 @ 0001d150 ======== */
/* role: script 225 on_trigger */

void FUN_0001d150(void)

{
  Weapon_Give(1);
  return;
}


/* ======== FUN_0001d170 @ 0001d170 ======== */
/* role: script 228 on_trigger */

void FUN_0001d170(void)

{
  Weapon_Give(2);
  return;
}


/* ======== FUN_0001d190 @ 0001d190 ======== */
/* role: script 226 on_trigger */

void FUN_0001d190(void)

{
  Weapon_Give(3);
  return;
}


/* ======== FUN_0001d1b0 @ 0001d1b0 ======== */
/* role: script 227 on_trigger */

void FUN_0001d1b0(void)

{
  Weapon_Give(4);
  return;
}


/* ======== FUN_0001d1d0 @ 0001d1d0 ======== */
/* role: script 229 on_trigger */

void FUN_0001d1d0(void)

{
  Weapon_Give(5);
  return;
}


/* ======== FUN_0001d1f0 @ 0001d1f0 ======== */
/* role: script 230 on_trigger */

void FUN_0001d1f0(void)

{
  Money_Add(10);
  return;
}


/* ======== Ammo_AddThird @ 0001d210 ======== */
/* role: script 231 on_trigger */

void Ammo_AddThird(void)

{
  *(undefined **)(&g_ammo + g_curWeapon * 4) = &DAT_000faaaa + *(int *)(&g_ammo + g_curWeapon * 4);
  if (0x2f0000 < *(int *)(&g_ammo + g_curWeapon * 4)) {
    *(undefined4 *)(&g_ammo + g_curWeapon * 4) = 0x2f0000;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 2;
  return;
}


/* ======== FUN_0001d270 @ 0001d270 ======== */
/* role: script 232 on_trigger */

void FUN_0001d270(void)

{
  Pocket_Add(5);
  return;
}


/* ======== FUN_0001d290 @ 0001d290 ======== */
/* role: script 233 on_trigger */

void FUN_0001d290(void)

{
  g_energy = 0x2f0000;
  g_hudDirty._0_1_ = (byte)g_hudDirty | 1;
  return;
}


/* ======== Script240_TeleportMenu @ 0001d2b8 ======== */
/* role: script 240 on_trigger */

void Script240_TeleportMenu(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  
  Dlg_Begin();
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  for (local_24 = 6; 0 < local_24; local_24 = local_24 + -1) {
    if (*(int *)(&DAT_00089330 + local_30 * 4) != 0) {
      (&g_menuOpt)[local_2c] = local_28;
      local_2c = local_2c + 1;
    }
    local_28 = local_28 + 1;
    local_30 = local_30 + 1;
  }
  if (local_2c == 0) {
    Dlg_Say(MSG_250) /* "Nie znasz żadnego hasła, nędzniku! / POZOSTANIESZ TU NA WIEKI!!!" */;
    Dlg_End();
  }
  else {
    Dlg_Print(MSG_249) /* "Gdzie chcesz się teleportować? /  / " */;
    iVar3 = Dlg_Menu(/*options = MSG_243 + g_menuOpt[i]*/ local_2c);
    local_30 = 0;
    for (local_1c = 0; local_1c <= iVar3; local_1c = local_1c + 1) {
      do {
        iVar2 = local_30 + 1;
        iVar1 = local_30 * 4;
        local_30 = iVar2;
      } while (*(int *)(&DAT_00089330 + iVar1) == 0);
    }
    Text_Clear(0);
    Dlg_End();
    switch(local_30) {
    case 1:
      Hero_StartTeleport(7,0,0x16,0x53);
      break;
    case 2:
      Hero_StartTeleport(7,8,0x26,0xb2);
      break;
    case 3:
      Hero_StartTeleport(1,6,0x1b,0x40);
      break;
    case 4:
      Hero_StartTeleport(4,2,100,0x79);
      break;
    case 5:
      Hero_StartTeleport(1,1,0x5e,0x1a);
      break;
    case 6:
      Hero_StartTeleport(5,5,0x7c,0x1a);
      break;
    default:
      Dlg_Say(MSG_250) /* "Nie znasz żadnego hasła, nędzniku! / POZOSTANIESZ TU NA WIEKI!!!" */;
      Dlg_End();
    }
  }
  return;
}


/* ======== FUN_0001d4b8 @ 0001d4b8 ======== */
/* role: script 241 on_trigger */

void FUN_0001d4b8(void)

{
  Hero_StartTeleport(0,0,0x35,0xb2);
  return;
}


/* ======== FUN_0001d4e0 @ 0001d4e0 ======== */
/* role: script 255 on_trigger */

void FUN_0001d4e0(void)

{
  Pocket_Remove(g_invSel);
  return;
}


/* ======== FUN_0001d500 @ 0001d500 ======== */

void FUN_0001d500(void)

{
  Dlg_Begin();
  Dlg_Say2(MSG_251) /* "Cholera jasna! Zmoczyłem sobie / gacie paliwem z plecaka! / Ach te teleporty..." */;
  Dlg_End();
  return;
}


/* ======== FUN_0001d530 @ 0001d530 ======== */

undefined8 FUN_0001d530(int param_1,undefined4 unaff_EDX)

{
  *(undefined ***)(param_1 + 4) = &PTR_FUN_000658a8;
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0001d560 @ 0001d560 ======== */

undefined8 FUN_0001d560(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_0001d530(param_1);
  *(undefined ***)(iVar1 + 4) = &PTR_Hero_EraseOld_000658d8;
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0001d5a0 @ 0001d5a0 ======== */

void FUN_0001d5a0(void)

{
  return;
}


/* ======== FUN_0001d5c0 @ 0001d5c0 ======== */

undefined4 FUN_0001d5c0(void)

{
  return 0;
}


/* ======== FUN_0001d5f0 @ 0001d5f0 ======== */

longlong FUN_0001d5f0(undefined4 param_1,uint unaff_EDX)

{
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_0001d620 @ 0001d620 ======== */

undefined8 FUN_0001d620(int param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,*(undefined4 *)(param_1 + 0x39));
}


/* ======== FUN_0001d650 @ 0001d650 ======== */

undefined4 FUN_0001d650(void)

{
  return 0;
}


/* ======== FUN_0001d680 @ 0001d680 ======== */

void FUN_0001d680(void)

{
  return;
}


/* ======== FUN_0001d6a0 @ 0001d6a0 ======== */

void FUN_0001d6a0(void)

{
  return;
}


/* ======== FUN_0001d6c0 @ 0001d6c0 ======== */

void FUN_0001d6c0(undefined4 param_1,byte unaff_DL)

{
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0xc);
  FUN_00033e1b(DAT_00057d71,unaff_DL & 0xf);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0001d730 @ 0001d730 ======== */

undefined8 FUN_0001d730(undefined4 *param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint local_24;
  
  *param_1 = 0x220;
  param_1[1] = 1;
  param_1[2] = 1;
  param_1[3] = 0xb;
  param_1[4] = 5;
  iVar1 = FUN_00033e41(s_ULTRASND_0005d3e8);
  if (iVar1 != 0) {
    FUN_00033ef6();
  }
  local_24 = (uint)(iVar1 != 0);
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== FUN_0001d7e0 @ 0001d7e0 ======== */

void FUN_0001d7e0(byte param_1)

{
  byte local_1c;
  
  local_1c = param_1 & 0xc2 | 0x21;
  if (3 < DAT_00057d0c) {
    local_1c = param_1 & 0xc2 | 0x25;
  }
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d69,0x41);
  FUN_00033e1b(DAT_00057d71,local_1c);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0001d84c @ 0001d84c ======== */

void FUN_0001d84c(byte param_1)

{
  byte local_1c;
  
  local_1c = param_1 & 0x82 | 0x21;
  if (3 < DAT_00057d10) {
    local_1c = param_1 & 0x82 | 0x25;
  }
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d69,0x49);
  FUN_00033e1b(DAT_00057d71,local_1c);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0001d8b8 @ 0001d8b8 ======== */

void FUN_0001d8b8(byte *param_1,int unaff_EDX)

{
  uint uVar1;
  
  *param_1 = *param_1 & 0xfb;
  *(undefined4 *)(param_1 + 0x39) = *(undefined4 *)(param_1 + 0x3d);
  *(undefined4 *)(param_1 + 0x3d) = *(undefined4 *)(param_1 + 0x49);
  uVar1 = *(uint *)(param_1 + 0x49);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 8));
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x24),0);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x14),*(uint *)(param_1 + 0x45) & 0xff);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x14),*(uint *)(param_1 + 0x45) >> 8 & 0xff);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x41));
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x20),param_1[0x30]);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x24),0);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x18),uVar1 & 0xff);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x18),uVar1 >> 8 & 0xff);
  FUN_00033e1b(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0xc));
  if (unaff_EDX == 0) {
    FUN_0001d7e0(param_1[0x4d]);
  }
  else {
    FUN_0001d84c(param_1[0x4d]);
  }
  return;
}


/* ======== FUN_0001d9d4 @ 0001d9d4 ======== */

undefined4 FUN_0001d9d4(uint param_1,int unaff_EDX,uint unaff_EBX,uint unaff_ECX)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 local_48;
  uint local_40;
  uint local_3c;
  uint local_28;
  
  iVar2 = (unaff_ECX - 1) * 0x4e;
  pbVar3 = &DAT_00057a90 + iVar2;
  if ((*pbVar3 & 2) == 0) {
    *pbVar3 = *pbVar3 | 2;
    *pbVar3 = *pbVar3 | 0x10;
    local_3c = (param_1 + unaff_EBX) - 1;
    uVar1 = local_3c >> 0x10;
    local_40 = param_1;
    if (3 < unaff_ECX) {
      local_40 = param_1 >> 1;
      local_3c = local_3c >> 1;
      unaff_EBX = unaff_EBX >> 1;
    }
    local_28 = local_3c & 0xffff;
    if (param_1 >> 0x10 == uVar1) {
      *pbVar3 = *pbVar3 & 0xfb;
    }
    else {
      *pbVar3 = *pbVar3 | 4;
      *(uint *)(&DAT_00057ad1 + iVar2) = uVar1;
      if (unaff_ECX < 4) {
        *(undefined4 *)(&DAT_00057ad5 + iVar2) = 0;
      }
      else {
        if (((&DAT_00057ad1)[iVar2] & 1) == 0) {
          *(undefined4 *)(&DAT_00057ad5 + iVar2) = 0;
        }
        else {
          *(undefined4 *)(&DAT_00057ad5 + iVar2) = 0x8000;
        }
        local_28 = local_3c & 0x7fff;
      }
      *(uint *)(&DAT_00057ad9 + iVar2) = local_28;
      unaff_EBX = (unaff_EBX - local_28) - 1;
    }
    if ((unaff_EDX == 3) && ((*pbVar3 & 4) != 0)) {
      local_48 = 7;
    }
    else {
      *(uint *)(&DAT_00057ac1 + iVar2) = param_1 >> 0x10;
      *(uint *)(&DAT_00057ac5 + iVar2) = local_40 & 0xffff;
      *(undefined4 *)(&DAT_00057ac9 + iVar2) = 0;
      *(uint *)(&DAT_00057acd + iVar2) = unaff_EBX;
      switch(unaff_EDX) {
      case 1:
        (&DAT_00057ac0)[iVar2] = (&DAT_00057abc)[iVar2];
        break;
      case 2:
        (&DAT_00057ac0)[iVar2] = (&DAT_00057ab8)[iVar2];
        break;
      case 3:
        (&DAT_00057ac0)[iVar2] = (&DAT_00057abc)[iVar2] | 0x10;
        break;
      case 4:
        (&DAT_00057ac0)[iVar2] = (&DAT_00057ab8)[iVar2] | 0x10;
      }
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aac + iVar2),*(undefined4 *)(&DAT_00057a98 + iVar2));
      FUN_00033e1b(*(undefined4 *)(&DAT_00057ab0 + iVar2),(&DAT_00057ac0)[iVar2]);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057ab4 + iVar2),0);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aa4 + iVar2),*(uint *)(&DAT_00057ac5 + iVar2) & 0xff);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aa4 + iVar2),
                   *(uint *)(&DAT_00057ac5 + iVar2) >> 8 & 0xff);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aa0 + iVar2),*(undefined4 *)(&DAT_00057ac1 + iVar2));
      FUN_00033e1b(*(undefined4 *)(&DAT_00057ab4 + iVar2),0);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aa8 + iVar2),unaff_EBX - 1 & 0xff);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aa8 + iVar2),unaff_EBX - 1 >> 8 & 0xff);
      FUN_00033e1b(*(undefined4 *)(&DAT_00057aac + iVar2),*(undefined4 *)(&DAT_00057a9c + iVar2));
      local_48 = 1;
    }
  }
  else {
    local_48 = 6;
  }
  return local_48;
}


/* ======== FUN_0001ddc0 @ 0001ddc0 ======== */

void FUN_0001ddc0(void)

{
  DAT_00057d04 = DAT_00057d04 & 0xf7;
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  do {
  } while ((DAT_00057d04 & 2) != 0);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0001de04 @ 0001de04 ======== */

int FUN_0001de04(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,byte param_4,int param_5)

{
  int iVar1;
  uint local_30;
  int local_2c;
  undefined4 local_24;
  
  iVar1 = DAT_00057d0c - 1;
  if ((param_4 & 2) == 0) {
    if ((param_4 & 1) == 0) {
      local_24 = 2;
    }
    else {
      local_24 = 4;
    }
  }
  else if ((param_4 & 1) == 0) {
    local_24 = 1;
  }
  else {
    local_24 = 3;
  }
  local_2c = FUN_0001d9d4(param_1,local_24,unaff_EDX,DAT_00057d0c);
  if (local_2c == 1) {
    local_30 = unaff_EBX;
    if (3 < DAT_00057d0c) {
      local_30 = FUN_0002ec8c(unaff_EBX);
    }
    DAT_0008adbc = DAT_0008adbc + 1;
    FUN_000350bd();
    FUN_00033e1b(DAT_00057d69,0x42);
    FUN_00033e25(DAT_00057d6d,local_30 >> 4);
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
    DAT_00057d04 = DAT_00057d04 | 2;
    *(byte *)(iVar1 * 0x4e + 0x57add) = param_4 & 0xfe;
    FUN_0001d7e0(param_4 & 0xfe);
    if (param_5 == 0) {
      DAT_00057d04 = DAT_00057d04 | 8;
    }
    else {
      FUN_0001ddc0();
    }
    local_2c = 1;
  }
  return local_2c;
}


/* ======== FUN_0001df28 @ 0001df28 ======== */

int FUN_0001df28(int param_1,int unaff_EDX,uint unaff_EBX,undefined param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  int local_44;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  uVar1 = (unaff_EBX + unaff_EDX) - 1;
  uVar2 = uVar1 >> 0x12;
  bVar4 = unaff_EBX >> 0x12 != uVar2;
  local_38 = unaff_EDX;
  if (bVar4) {
    local_30 = uVar2 * 0x40000;
    local_34 = uVar1 + uVar2 * -0x40000;
    local_38 = unaff_EDX - local_34;
    local_3c = param_1 + local_38;
  }
  local_44 = FUN_0001de04(param_1,local_38,unaff_EBX,param_4,param_5);
  if (local_44 == 1) {
    if (bVar4) {
      if (param_5 == 0) {
        FUN_0001ddc0();
      }
      iVar3 = FUN_0001de04(local_3c,local_34,local_30,param_4,param_5);
      if (iVar3 != 1) {
        return iVar3;
      }
    }
    local_44 = 1;
  }
  return local_44;
}


/* ======== FUN_0001e00c @ 0001e00c ======== */

undefined4 FUN_0001e00c(undefined *param_1,undefined4 param_2,int unaff_EBX,uint unaff_ECX)

{
  uint local_24;
  undefined *local_20;
  
  local_20 = param_1;
  for (local_24 = 0; local_24 < unaff_ECX; local_24 = local_24 + 1) {
    FUN_0002d6ec(DAT_00057d08,unaff_EBX,*local_20);
    unaff_EBX = unaff_EBX + 1;
    local_20 = local_20 + 1;
  }
  return 1;
}


/* ======== FUN_0001e0c0 @ 0001e0c0 ======== */

void FUN_0001e0c0(void)

{
  FUN_0001d560(&g_hero);
  return;
}


/* ======== FUN_0001e0e0 @ 0001e0e0 ======== */

void FUN_0001e0e0(uint param_1)

{
  FUN_00033e1b(0x3d4,0xc);
  FUN_00033e1b(0x3d5,(int)param_1 >> 8 & 0xff);
  FUN_00033e1b(0x3d4,0xd);
  FUN_00033e1b(0x3d5,param_1 & 0xff);
  return;
}


/* ======== FUN_0001e140 @ 0001e140 ======== */

void FUN_0001e140(void)

{
  FUN_00010a22(DAT_00097488,g_backBuffer);
  if (DAT_00097490 == 0) {
    DAT_00097490 = 0x4b00;
  }
  else {
    DAT_00097490 = 0;
  }
  FUN_000108d5(DAT_00097490);
  FUN_0001e0e0(DAT_00097490);
  return;
}


/* ======== FUN_0001e198 @ 0001e198 ======== */

void FUN_0001e198(void)

{
  FUN_00034682(&DAT_000a0000,DAT_00097488,64000);
  return;
}


/* ======== PlayFLC @ 0001e1c4 ======== */

void PlayFLC(undefined4 param_1,uint unaff_EDX,int unaff_EBX)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *local_30;
  int local_28;
  
  local_28 = 0;
  bVar2 = false;
  DAT_0009747c = FUN_00033280(param_1,2);
  if (DAT_0009747c != 0) {
    if (((*(ushort *)(DAT_0009747c + 2) < 0x141) && (*(ushort *)(DAT_0009747c + 4) < 0xc9)) ||
       (DAT_00097488 = (undefined4 *)
                       malloc((uint)*(ushort *)(DAT_0009747c + 4) *
                              (uint)*(ushort *)(DAT_0009747c + 2)),
       DAT_00097488 != (undefined4 *)0x0)) {
      DAT_0009748c = (uint)(*(ushort *)(DAT_0009747c + 4) < 0xc9);
      if (unaff_EDX == 0xffffffff) {
        unaff_EDX = (uint)*(ushort *)(DAT_0009747c + 6);
      }
      g_quitLoop = '\0';
      while (((g_quitLoop == '\0' && (!bVar2)) && (g_keySpace == 0))) {
        ProcessInput();
        do {
        } while (DAT_0007c32c < (int)unaff_EDX);
        DAT_0007c32c = 0;
        if (DAT_0009748c == 0) {
          local_30 = DAT_00097488;
        }
        else {
          local_30 = &DAT_000a0000;
        }
        FUN_00033b2c(DAT_0009747c,local_30,(int)*(short *)(DAT_0009747c + 2));
        if (DAT_00097488 != (undefined4 *)0x0) {
          if (DAT_0009748c == 0) {
            FUN_0001e140();
          }
          else {
            FUN_0001e198();
          }
        }
        iVar1 = local_28 + 1;
        bVar3 = local_28 == unaff_EBX;
        local_28 = iVar1;
        if (bVar3) {
          bVar2 = true;
        }
      }
      if (g_keySpace != 0) {
        g_quitLoop = '\x01';
      }
      FUN_00033de4(DAT_0009747c);
      DAT_00097490 = 0;
      FUN_0001e0e0(0);
      if (DAT_00097488 != (undefined4 *)0x0) {
        free(DAT_00097488);
      }
    }
    else {
      FUN_00033de4(DAT_0009747c);
    }
  }
  return;
}


/* ======== FUN_0001e390 @ 0001e390 ======== */

void FUN_0001e390(undefined4 param_1)

{
  undefined4 *local_28;
  
  DAT_0009747c = FUN_00033280(param_1,2);
  if (DAT_0009747c != 0) {
    if (((*(ushort *)(DAT_0009747c + 2) < 0x141) && (*(ushort *)(DAT_0009747c + 4) < 0xc9)) ||
       (DAT_00097488 = (undefined4 *)
                       malloc((uint)*(ushort *)(DAT_0009747c + 4) *
                              (uint)*(ushort *)(DAT_0009747c + 2)),
       DAT_00097488 != (undefined4 *)0x0)) {
      DAT_0009748c = (uint)(*(ushort *)(DAT_0009747c + 4) < 0xc9);
      if (DAT_0009748c == 0) {
        local_28 = DAT_00097488;
      }
      else {
        local_28 = &DAT_000a0000;
      }
      FUN_00033b2c(DAT_0009747c,local_28,(int)*(short *)(DAT_0009747c + 2));
      if (DAT_00097488 != (undefined4 *)0x0) {
        if (DAT_0009748c == 0) {
          FUN_0001e140();
        }
        else {
          FUN_0001e198();
        }
      }
      FUN_00033de4(DAT_0009747c);
      DAT_00097490 = 0;
      FUN_0001e0e0(0);
      if (DAT_00097488 != (undefined4 *)0x0) {
        free(DAT_00097488);
      }
    }
    else {
      FUN_00033de4(DAT_0009747c);
    }
  }
  return;
}


/* ======== FUN_0001e4d4 @ 0001e4d4 ======== */

void FUN_0001e4d4(undefined4 param_1,int unaff_EDX,undefined4 unaff_EBX)

{
  byte *pbVar1;
  byte **ppbVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar5;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 uVar6;
  byte local_80;
  byte local_7c;
  int local_64;
  int local_5c;
  int local_58;
  short local_54;
  short local_50;
  byte local_48;
  byte local_38 [4];
  byte local_34 [4];
  byte local_30 [16];
  byte local_20 [4];
  undefined4 local_1c;
  
  local_1c = param_1;
  ppbVar2 = (byte **)fopen(param_1,&DAT_0005d400);
  if (ppbVar2 != (byte **)0x0) {
    iVar3 = malloc(0x80);
    iVar4 = fread(iVar3,1,0x80,ppbVar2);
    if (iVar4 != 0) {
      local_54 = (*(short *)(iVar3 + 8) - *(short *)(iVar3 + 4)) + 1;
      local_50 = (*(short *)(iVar3 + 10) - *(short *)(iVar3 + 6)) + 1;
      local_58 = 0;
      free(iVar3);
      DAT_00097494 = malloc(&LAB_0001f400);
      for (; local_58 < local_50; local_58 = local_58 + 1) {
        local_5c = 0;
        while (local_5c < local_54) {
          if (((((int)ppbVar2[1] < 1) || ((*(byte *)(ppbVar2 + 3) & 4) != 0)) || (**ppbVar2 == 0xd))
             || (**ppbVar2 == 0x1a)) {
            local_7c = FUN_00034e61(ppbVar2);
          }
          else {
            ppbVar2[1] = ppbVar2[1] + -1;
            pbVar1 = *ppbVar2;
            *ppbVar2 = *ppbVar2 + 1;
            local_7c = *pbVar1;
          }
          local_20[0] = local_7c;
          if (local_7c < 0xc0) {
            *(byte *)(DAT_00097494 + local_5c + local_58 * 0x140) = local_7c;
            local_5c = local_5c + 1;
          }
          else {
            if (local_7c == 0xc0) {
              local_48 = 1;
            }
            else {
              local_48 = local_7c & 0x3f;
              if ((((int)ppbVar2[1] < 1) || ((*(byte *)(ppbVar2 + 3) & 4) != 0)) ||
                 ((**ppbVar2 == 0xd || (**ppbVar2 == 0x1a)))) {
                local_80 = FUN_00034e61(ppbVar2);
              }
              else {
                ppbVar2[1] = ppbVar2[1] + -1;
                pbVar1 = *ppbVar2;
                *ppbVar2 = *ppbVar2 + 1;
                local_80 = *pbVar1;
              }
              local_20[0] = local_80;
            }
            for (local_64 = 0; local_64 < (int)(uint)local_48; local_64 = local_64 + 1) {
              *(byte *)(local_58 * 0x140 + local_5c + DAT_00097494) = local_20[0];
              local_5c = local_5c + 1;
            }
          }
        }
      }
      fread(local_20,1,1,ppbVar2);
      uVar6 = 64000;
      memset(&DAT_000a0000,0,64000);
      uVar5 = extraout_EDX;
      for (local_64 = 0; local_64 < 0x100; local_64 = local_64 + 1) {
        fread(local_38,1,1,ppbVar2);
        fread(local_34,1,1,ppbVar2);
        uVar6 = 1;
        fread(local_30,1);
        FUN_00033e1b(0x3c8,local_64);
        FUN_00033e1b(0x3c9,(int)(uint)local_38[0] >> 2);
        FUN_00033e1b(0x3c9,(int)(uint)local_34[0] >> 2);
        FUN_00033e1b(0x3c9,(int)(uint)local_30[0] >> 2);
        uVar5 = extraout_EDX_00;
      }
      fclose(ppbVar2,uVar5,uVar6,ppbVar2);
      FUN_00034682(&DAT_000a0000,DAT_00097494,64000);
      Delay(unaff_EBX);
      if (g_quitLoop == '\0') {
        uVar5 = extraout_EDX_01;
        for (local_64 = 0; DAT_0007c32c = 0, local_64 < unaff_EDX; local_64 = local_64 + 1) {
          local_20[0] = GetScancode();
          if (local_20[0] == 1 || local_20[0] == 0x39) {
            g_quitLoop = 1;
            free(DAT_00097494,extraout_EDX_02,64000);
            return;
          }
          FUN_00034682(&DAT_000a0000,DAT_00097494 + local_64 * 0x140);
          do {
          } while (DAT_0007c32c < 3);
          uVar5 = extraout_EDX_03;
        }
        free(DAT_00097494,uVar5,64000);
      }
      else {
        free(DAT_00097494);
      }
    }
  }
  return;
}


/* ======== PlayIntro @ 0001e8d0 ======== */

void PlayIntro(void)

{
  undefined4 uVar1;
  
  FUN_00010471();
  DAT_0009748c = 1;
  Delay(0x32);
  if ((((g_quitLoop != '\x01') &&
       (FUN_0001e4d4(s_DATA33_RES_0005d403,200,0x96), g_quitLoop != '\x01')) &&
      (Delay(200), g_quitLoop != '\x01')) &&
     (((PlayFLC(s_DATA05_RES_0005d40e,4,0x3a), g_quitLoop != '\x01' &&
       (PlayFLC(s_DATA06_RES_0005d419,0xffffffff,0x5a), g_quitLoop != '\x01')) &&
      (PlayFLC(s_DATA07_RES_0005d424,0xffffffff,0x2d), g_quitLoop != '\x01')))) {
    Delay(0x19);
    PlayFLC(s_DATA08_RES_0005d42f,0xffffffff,0x3b);
    if ((g_quitLoop != '\x01') && (PlayFLC(s_DATA09_RES_0005d43a,4,0x55), g_quitLoop != '\x01')) {
      uVar1 = FUN_0001ec70();
      FUN_0001e4d4(s_DATA34_RES_0005d445,1,uVar1);
      Delay(0xfa);
      if (g_quitLoop != '\x01') {
        uVar1 = FUN_0001ec70();
        FUN_0001e4d4(s_DATA35_RES_0005d450,1,uVar1);
        Delay(0xfa);
        if ((((g_quitLoop != '\x01') &&
             (FUN_0001e4d4(s_DATA36_RES_0005d45b,200,300), g_quitLoop != '\x01')) &&
            (Delay(300), g_quitLoop != '\x01')) &&
           ((PlayFLC(s_DATA11_RES_0005d466,3,0x46), g_quitLoop != '\x01' &&
            (PlayFLC(s_DATA12_RES_0005d471,3,0x32), g_quitLoop != '\x01')))) {
          SetModeX320x240();
          DAT_00097490 = 0;
          FUN_0001e0e0(0);
          PlayFLC(s_DATA15_RES_0005d47c,8,0x3c);
          if (((g_quitLoop != '\x01') &&
              ((PlayFLC(s_DATA13_RES_0005d487,8,0x1e), g_quitLoop != '\x01' &&
               (PlayFLC(s_DATA14_RES_0005d492,10,4), g_quitLoop != '\x01')))) &&
             (PlayFLC(s_DATA10_RES_0005d49d,0x1e,6), g_quitLoop != '\x01')) {
            while ((((g_quitLoop == '\0' && (g_keyEnter == 0)) && (g_keyFire == 0)) &&
                   (g_keySpace == 0))) {
              ProcessInput();
            }
          }
        }
      }
    }
  }
  return;
}


/* ======== EndingSequence @ 0001ebc4 ======== */

void EndingSequence(void)

{
  int iVar1;
  int local_1c;
  
  DAT_00097490 = 0;
  FUN_0001e0e0(0);
  FUN_0001e390(s_DATA17_RES_0005d4a8);
  FUN_000108d5(0);
  Delay(100);
  FUN_0001eff4(0);
  iVar1 = Dlg_Begin();
  for (local_1c = 0; local_1c < 9; local_1c = local_1c + 1) {
    Dlg_Print(&PTR_DAT_000541d4,local_1c);
    Delay(0x5a);
    iVar1 = local_1c;
  }
  Dlg_End(iVar1);
  PlayFLC(s_DATA17_RES_0005d4b3,0x14,6);
  Delay(200);
  return;
}


/* ======== FUN_0001ec70 @ 0001ec70 ======== */

undefined8 FUN_0001ec70(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_0001ecb0 @ 0001ecb0 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ecb0(byte param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000a3b4c;
  if (DAT_000a3b4c != 0) {
    if (DAT_000a3b4c < 2) {
      FUN_0001efa0((uint)DAT_000a3b59 * 10 + (uint)DAT_000a3b58 * 100 + (uint)DAT_000a3b5a,
                   DAT_00052393);
      DAT_000a3b4c = 0;
    }
    else if (DAT_000a3b4c < 5) {
      DAT_000a3b4c = DAT_000a3b4c - 1;
      *(byte *)(0xa3b5c - uVar1) = param_1 - 0x30;
      return;
    }
  }
  uVar1 = DAT_000a3b50;
  if (DAT_000a3b50 != 0) {
    if (DAT_000a3b50 < 2) {
      FUN_0001efa0(DAT_0005238f,
                   (uint)DAT_000a3b59 * 10 + (uint)DAT_000a3b58 * 100 + (uint)DAT_000a3b5a);
      DAT_000a3b50 = 0;
    }
    else if (DAT_000a3b50 < 5) {
      DAT_000a3b50 = DAT_000a3b50 - 1;
      *(byte *)(0xa3b5c - uVar1) = param_1 - 0x30;
      return;
    }
  }
  uVar1 = DAT_000a3b54;
  if (DAT_000a3b54 != 0) {
    if (DAT_000a3b54 < 2) {
      FUN_0001efd4(DAT_000a3b59 * '\n' + DAT_000a3b58 * 'd' + DAT_000a3b5a);
      DAT_000a3b54 = 0;
    }
    else if (DAT_000a3b54 < 5) {
      DAT_000a3b54 = DAT_000a3b54 - 1;
      *(byte *)(0xa3b5c - uVar1) = param_1 - 0x30;
      return;
    }
  }
  if (param_1 < 0xe0) {
    if (9 < param_1) {
      if (param_1 < 0xb) {
        FUN_0001ef74(DAT_0005239b,DAT_00052393 + DAT_0005239f);
        return;
      }
      if (param_1 == 0x20) {
        if (DAT_000a3b48 == 0) {
          FUN_000111bd(0x20);
        }
        else {
          FUN_00011256(0x20);
        }
        DAT_0005238f = DAT_0005238f + DAT_000546b4 + _DAT_00052397;
      }
    }
  }
  else {
    if (param_1 < 0xe1) {
      DAT_000a3b4c = 4;
      return;
    }
    if (param_1 < 0xe2) {
      DAT_000a3b50 = 4;
      return;
    }
    if (param_1 == 0xe2) {
      DAT_000a3b54 = 4;
      return;
    }
  }
  if (0x1f < param_1) {
    if (DAT_000a3b48 == 0) {
      FUN_000111bd(param_1);
    }
    else {
      FUN_00011256(param_1);
    }
    DAT_0005238f = DAT_0005238f + (uint)(byte)(&DAT_0005228f)[param_1] + _DAT_00052397;
  }
  return;
}


/* ======== FUN_0001ef74 @ 0001ef74 ======== */

void FUN_0001ef74(undefined4 param_1,undefined4 unaff_EDX)

{
  DAT_0005238f = param_1;
  DAT_00052393 = unaff_EDX;
  return;
}


/* ======== FUN_0001efa0 @ 0001efa0 ======== */

void FUN_0001efa0(undefined4 param_1,undefined4 unaff_EDX)

{
  DAT_0005239b = param_1;
  DAT_0005238f = param_1;
  DAT_00052393 = unaff_EDX;
  return;
}


/* ======== FUN_0001efd4 @ 0001efd4 ======== */

void FUN_0001efd4(undefined param_1)

{
  DAT_000522ac = param_1;
  return;
}


/* ======== FUN_0001eff4 @ 0001eff4 ======== */

void FUN_0001eff4(undefined param_1)

{
  DAT_000522ad = param_1;
  return;
}


/* ======== FUN_0001f014 @ 0001f014 ======== */

void FUN_0001f014(undefined4 param_1)

{
  DAT_000546b4 = param_1;
  return;
}


/* ======== LoadFont @ 0001f034 ======== */

undefined8 LoadFont(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = fopen(param_1,&DAT_0005d4c0);
  if (iVar1 == 0) {
    FUN_00010460();
    printf();
    exit(0);
  }
  fread(&DAT_000522af,0xe0,1,iVar1);
  iVar2 = FileLength(iVar1);
  uVar3 = malloc(iVar2 + -0xe0);
  DAT_000522a8 = (byte *)uVar3;
  iVar2 = FileLength(iVar1,(int)((ulonglong)uVar3 >> 0x20),1,iVar1);
  fread(DAT_000522a8,iVar2 + -0xe0);
  fclose(iVar1);
  DAT_0005239f = (uint)DAT_000522a8[1];
  DAT_000523a3 = (uint)*DAT_000522a8 * 4;
  DAT_000522a4 = (uint)DAT_000522a8[1] * (uint)*DAT_000522a8 * 4 + 2;
  return CONCAT44(unaff_EDX,DAT_000522a8);
}


/* ======== FUN_0001f118 @ 0001f118 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f118(undefined4 param_1)

{
  _DAT_00052397 = param_1;
  return;
}


/* ======== Text_Draw @ 0001f138 ======== */

void Text_Draw(char *param_1)

{
  char *local_1c;
  
  local_1c = param_1;
  while (*local_1c != '\0') {
    FUN_0001ecb0(*local_1c);
    local_1c = local_1c + 1;
  }
  return;
}


/* ======== FUN_0001f168 @ 0001f168 ======== */

void FUN_0001f168(byte *param_1)

{
  byte *local_1c;
  
  local_1c = param_1;
  while (*local_1c != 0) {
    if ((*local_1c < 0xe0) || (0xe2 < *local_1c)) {
      FUN_0001ecb0(*local_1c);
      local_1c = local_1c + 1;
    }
    else {
      local_1c = local_1c + 4;
    }
  }
  return;
}


/* ======== Text_DrawNumber @ 0001f1c0 ======== */

void Text_DrawNumber(undefined4 param_1)

{
  undefined local_30 [20];
  undefined4 local_1c;
  
  local_1c = param_1;
  FUN_0003515f(param_1,local_30,10);
  Text_Draw();
  return;
}


/* ======== Text_Clear @ 0001f224 ======== */

void Text_Clear(void)

{
  FUN_00011049();
  return;
}


/* ======== Text_Flip @ 0001f244 ======== */

void Text_Flip(void)

{
  FUN_000108d5(0);
  return;
}


/* ======== FUN_0001f260 @ 0001f260 ======== */

void FUN_0001f260(void)

{
  FUN_0001d560(&g_hero);
  return;
}


/* ======== FUN_0001f280 @ 0001f280 ======== */

void FUN_0001f280(undefined4 param_1)

{
  FUN_00032e70(param_1,0x9c);
  FUN_00032560(param_1,0x5622);
  FUN_0001d6c0(param_1,7);
  return;
}


/* ======== FUN_0001f2c0 @ 0001f2c0 ======== */

undefined4
FUN_0001f2c0(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined unaff_CL)

{
  int iVar1;
  undefined4 local_2c;
  undefined2 local_24 [2];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_1;
  local_20 = fopen(param_1,&DAT_0005d500);
  iVar1 = FUN_00020f68(unaff_EDX,local_24);
  if (iVar1 == 0) {
    fclose(local_20);
    local_2c = 3;
  }
  else {
    fread(iVar1,unaff_EDX,1,local_20);
    fclose(local_20);
    local_2c = FUN_0001e00c(iVar1,unaff_CL,unaff_EBX,unaff_EDX,1);
    FUN_00020fd4(local_24[0]);
  }
  return local_2c;
}


/* ======== FUN_0001f354 @ 0001f354 ======== */

void FUN_0001f354(void)

{
  if (*(short *)(&DAT_00051386 + *(int *)(DAT_000892d8 * 4 + g_sound + 0xd8) * 0x20) == 0) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))
              (g_sound,*(undefined4 *)(g_sound + DAT_000892d8 * 4 + 0xd8));
  }
  return;
}


/* ======== FUN_0001f3c8 @ 0001f3c8 ======== */

void FUN_0001f3c8(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x158) + 4))(param_1);
  FUN_0001f2c0(s_DATA41_RES_0005d503,0x11568,0,0x80);
  return;
}


/* ======== FUN_0001f40c @ 0001f40c ======== */

int FUN_0001f40c(int param_1,int unaff_EDX)

{
  int iVar1;
  int local_28;
  int local_20;
  
  iVar1 = FUN_0001d730(&DAT_000b0b1c);
  if (iVar1 == 0) {
    if (unaff_EDX != 0) {
      printf();
    }
    local_28 = 2;
  }
  else {
    if (unaff_EDX != 0) {
      printf();
    }
    local_28 = FUN_00020264(DAT_000b0b1c);
    if (local_28 == 1) {
      local_28 = FUN_0002c190(&DAT_000b0b1c,0x20);
      if (local_28 == 1) {
        if (7 < DAT_000b0b28) {
          FatalError(s_W_tej_wersji__1_35__nie_jest_moz_0005d617,0);
        }
        if (unaff_EDX != 0) {
          printf();
          printf();
          printf();
          printf();
          printf();
          printf();
          FUN_0002c284();
        }
        for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
          FUN_0001f280(local_20);
          *(undefined4 *)(local_20 * 4 + param_1 + 0xd8) = 0xffffffff;
        }
        for (local_20 = 0; local_20 < 0x36; local_20 = local_20 + 1) {
          *(undefined4 *)(local_20 * 4 + param_1) = 0xffffffff;
        }
        FUN_0001fda4(FUN_0001f354);
      }
      else if (unaff_EDX != 0) {
        printf();
      }
    }
    else if (unaff_EDX != 0) {
      printf();
    }
  }
  return local_28;
}


/* ======== FUN_0001f5e8 @ 0001f5e8 ======== */

void FUN_0001f5e8(int param_1)

{
  int local_20;
  
  FUN_0002c190(&DAT_000b0b1c,0x20);
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    FUN_0001f280(local_20);
    *(undefined4 *)(local_20 * 4 + param_1 + 0xd8) = 0xffffffff;
  }
  for (local_20 = 0; local_20 < 0x36; local_20 = local_20 + 1) {
    *(undefined4 *)(local_20 * 4 + param_1) = 0xffffffff;
  }
  FUN_0001fda4(FUN_0001f354);
  return;
}


/* ======== FUN_0001f67c @ 0001f67c ======== */

void FUN_0001f67c(int param_1,int unaff_EDX)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int local_20;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  for (local_20 = 0; (*(int *)(local_20 * 4 + param_1 + 0xd8) != -1 && (local_20 < 0x20));
      local_20 = local_20 + 1) {
  }
  if (local_20 == 0x20) {
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
  }
  else {
    *(int *)(local_20 * 4 + param_1 + 0xd8) = unaff_EDX;
    iVar3 = *(int *)(&DAT_00051374 + unaff_EDX * 0x20);
    iVar4 = *(int *)(&DAT_0005137e + unaff_EDX * 0x20) + iVar3;
    sVar1 = *(short *)(&DAT_00051378 + unaff_EDX * 0x20);
    sVar2 = *(short *)(&DAT_0005137a + unaff_EDX * 0x20);
    if (*(short *)(&DAT_00051386 + unaff_EDX * 0x20) == 0) {
      FUN_00032e70(local_20,*(short *)(&DAT_0005137c + unaff_EDX * 0x20) * 8 + -1);
      FUN_00032c90(local_20,iVar3,iVar4,iVar4 + sVar1,0x20,(int)sVar2 / 2);
    }
    else {
      FUN_00032e70(local_20,*(short *)(&DAT_0005137c + unaff_EDX * 0x20) * 8 + -1);
      FUN_00032c90(local_20,iVar3,iVar4,iVar4 + sVar1,0x28,(int)sVar2 / 2);
    }
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
  }
  return;
}


/* ======== FUN_0001f7f4 @ 0001f7f4 ======== */

int FUN_0001f7f4(int param_1,int unaff_EDX)

{
  int iVar1;
  int local_20;
  
  iVar1 = param_1;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(local_20 * 4 + param_1 + 0xd8) == unaff_EDX) {
      FUN_00032b30(local_20);
      *(undefined4 *)(local_20 * 4 + param_1 + 0xd8) = 0xffffffff;
    }
    iVar1 = local_20;
  }
  return iVar1;
}


/* ======== FUN_0001f85c @ 0001f85c ======== */

undefined8 FUN_0001f85c(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_20;
  
  iVar1 = param_1;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    FUN_00032b30(local_20);
    *(undefined4 *)(local_20 * 4 + param_1 + 0xd8) = 0xffffffff;
    iVar1 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0001f8ac @ 0001f8ac ======== */

undefined8 FUN_0001f8ac(int param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  int iVar2;
  int local_20;
  
  iVar2 = param_1;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    uVar1 = *(uint *)(local_20 * 4 + param_1 + 0xd8);
    if ((uVar1 < 0x10) || ((0x10 < uVar1 && ((uVar1 < 0x1b || (0x1c < uVar1)))))) {
      FUN_00032b30(local_20);
      *(undefined4 *)(local_20 * 4 + param_1 + 0xd8) = 0xffffffff;
    }
    iVar2 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_0001f938 @ 0001f938 ======== */

void FUN_0001f938(void)

{
  FUN_0002c284();
  return;
}


/* ======== FUN_0001f958 @ 0001f958 ======== */

void FUN_0001f958(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00032560(unaff_EDX,unaff_EBX,unaff_EBX,unaff_ECX,param_1);
  return;
}


/* ======== FUN_0001f980 @ 0001f980 ======== */

void FUN_0001f980(undefined4 param_1,undefined4 unaff_EDX,int unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00033100(unaff_EDX,(int)*(short *)(&DAT_000541f8 + unaff_EBX * 2),unaff_EBX,unaff_ECX,param_1)
  ;
  return;
}


/* ======== FUN_0001f9b0 @ 0001f9b0 ======== */

void FUN_0001f9b0(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_0001d6c0(unaff_EDX,unaff_EBX,unaff_EBX,unaff_ECX,param_1);
  return;
}


/* ======== FUN_0001f9d8 @ 0001f9d8 ======== */

void FUN_0001f9d8(undefined4 param_1,undefined4 unaff_EDX)

{
  FUN_00032b30(unaff_EDX);
  return;
}


/* ======== FUN_0001f9fc @ 0001f9fc ======== */

void FUN_0001f9fc(undefined4 param_1,undefined4 unaff_EDX,int unaff_EBX,int unaff_ECX,int param_5,
                 int param_6,undefined param_7)

{
  FUN_00032ae4(unaff_EDX,unaff_ECX + unaff_EBX,param_5 + unaff_EBX,param_6 + unaff_EBX,param_7);
  return;
}


/* ======== FUN_0001fa38 @ 0001fa38 ======== */

void FUN_0001fa38(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00032cd0(unaff_EDX,unaff_EBX,unaff_EBX,unaff_ECX,param_1);
  return;
}


/* ======== FUN_0001fa60 @ 0001fa60 ======== */

void FUN_0001fa60(void)

{
  FUN_000321b8();
  return;
}


/* ======== FUN_0001fa80 @ 0001fa80 ======== */

void FUN_0001fa80(undefined4 param_1,undefined4 unaff_EDX,undefined unaff_BL,undefined4 unaff_ECX)

{
  FUN_0002d6ec(DAT_000b0b1c,unaff_EDX,unaff_BL,unaff_ECX,param_1);
  return;
}


/* ======== FUN_0001faac @ 0001faac ======== */

undefined4 FUN_0001faac(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0002d650(DAT_000b0b1c,unaff_EDX);
  return uVar1;
}


/* ======== FUN_0001fb0c @ 0001fb0c ======== */

void FUN_0001fb0c(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined param_4,
                 undefined param_5)

{
  FUN_00032f14(unaff_EDX,unaff_EBX,param_4,param_5,param_1);
  return;
}


/* ======== FUN_0001fb3c @ 0001fb3c ======== */

void FUN_0001fb3c(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00032e70(unaff_EDX,unaff_EBX,unaff_EBX,unaff_ECX,param_1);
  return;
}


/* ======== FUN_0001fb64 @ 0001fb64 ======== */

undefined4 FUN_0001fb64(undefined4 param_1,int unaff_EDX,uint *unaff_EBX)

{
  if ((int)(DAT_000b0b30 + unaff_EDX) >> 0x12 < (int)DAT_000b0b30 >> 0x12) {
    DAT_000b0b30 = DAT_000b0b30 + unaff_EDX & 0x3ffff;
  }
  *unaff_EBX = DAT_000b0b30;
  DAT_000b0b30 = DAT_000b0b30 + unaff_EDX;
  return 1;
}


/* ======== FUN_0001fbc8 @ 0001fbc8 ======== */

undefined8 FUN_0001fbc8(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_20;
  
  iVar1 = param_1;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(local_20 * 4 + param_1 + 0xd8) != -1) {
      FUN_00032b30(local_20);
    }
    iVar1 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0001fc18 @ 0001fc18 ======== */

undefined8 FUN_0001fc18(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_20;
  
  iVar1 = param_1;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(local_20 * 4 + param_1 + 0xd8) != -1) {
      FUN_00032a6c(local_20,(*(short *)(&DAT_00051386 +
                                       *(int *)(local_20 * 4 + param_1 + 0xd8) * 0x20) != 0) << 3);
    }
    iVar1 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0001fda4 @ 0001fda4 ======== */

undefined8 FUN_0001fda4(undefined *param_1,undefined4 unaff_EDX)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_00057d38;
  PTR_FUN_00057d38 = param_1;
  return CONCAT44(unaff_EDX,puVar1);
}


/* ======== FUN_0001ff44 @ 0001ff44 ======== */

void FUN_0001ff44(int param_1,int unaff_EDX,undefined4 unaff_EBX,int unaff_ECX)

{
  byte local_28;
  byte local_24;
  undefined local_20;
  char local_1c;
  
  local_1c = (char)param_1;
  local_28 = local_1c << 3;
  if (unaff_EDX == 0) {
    local_24 = local_1c << 3 | 2;
    if (*(int *)(&DAT_000b0b44 + param_1 * 4) == 1) {
      local_20 = 0;
    }
    else if (unaff_ECX == 5) {
      local_20 = (&DAT_000547cc)[param_1];
    }
    else {
      local_20 = 1;
    }
  }
  else {
    local_28 = local_28 | 1;
    local_24 = local_1c << 3 | 3;
    if (*(int *)(&DAT_000b0b44 + param_1 * 4) == 1) {
      local_20 = 0;
    }
    else if (unaff_ECX == 5) {
      local_20 = (&DAT_000547d4)[param_1];
    }
    else {
      local_20 = 2;
    }
  }
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_000b0b3c,local_28);
  FUN_00033e1b(DAT_000b0b40,local_20);
  FUN_00033e1b(DAT_000b0b3c,local_24);
  FUN_00033e1b(DAT_000b0b40,unaff_EBX);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00020000 @ 00020000 ======== */

void FUN_00020000(void)

{
  int unaff_EBP;
  
  FUN_00033e1b(DAT_000b0b40);
  FUN_00033e1b(DAT_000b0b3c,*(undefined *)(unaff_EBP + -0x18));
  FUN_00033e1b(DAT_000b0b40,*(undefined4 *)(unaff_EBP + -8));
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00020178 @ 00020178 ======== */

void FUN_00020178(int param_1,undefined4 unaff_EDX)

{
  *(undefined4 *)(&DAT_000b0b44 + param_1 * 4) = unaff_EDX;
  return;
}


/* ======== FUN_000201b0 @ 000201b0 ======== */

undefined8 FUN_000201b0(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined uVar1;
  undefined uVar2;
  char cVar3;
  char cVar4;
  undefined4 local_30;
  
  uVar1 = FUN_0002d650(param_1,0);
  uVar2 = FUN_0002d650(param_1,1);
  FUN_0002d6ec(param_1,0,0xaa);
  FUN_0002d6ec(param_1,1,0x55);
  cVar3 = FUN_0002d650(param_1,0);
  cVar4 = FUN_0002d650(param_1,1);
  FUN_0002d6ec(param_1,0,uVar1);
  FUN_0002d6ec(param_1,1,uVar2);
  if ((cVar3 == -0x56) && (cVar4 == 'U')) {
    local_30 = 1;
  }
  else {
    local_30 = 5;
  }
  return CONCAT44(unaff_EDX,local_30);
}


/* ======== FUN_00020264 @ 00020264 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00020264(int param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  
  DAT_00057d5d = param_1 + 0x101;
  DAT_00057d61 = param_1 + 0x100;
  DAT_00057d65 = param_1 + 0x102;
  DAT_00057d69 = param_1 + 0x103;
  DAT_00057d6d = param_1 + 0x104;
  DAT_00057d71 = param_1 + 0x105;
  DAT_00057d75 = param_1 + 6;
  DAT_00057d79 = param_1 + 0x107;
  _DAT_00057d85 = param_1 + 8;
  _DAT_00057d89 = param_1 + 9;
  DAT_00057d81 = param_1 + 0xb;
  DAT_00057d08 = param_1;
  DAT_00057d7d = param_1;
  FUN_00033e1b(DAT_00057d69,0x4c);
  FUN_00033e1b(DAT_00057d71,0);
  FUN_0002ebdc();
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d69,0x4c);
  FUN_00033e1b(DAT_00057d71,1);
  FUN_0002ebdc();
  FUN_0002ebdc();
  uVar1 = FUN_000201b0(param_1);
  return CONCAT44(unaff_EDX,uVar1);
}


/* ======== FUN_00020374 @ 00020374 ======== */

void FUN_00020374(int param_1,int unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  byte bVar1;
  byte local_34;
  byte local_28;
  char local_24;
  byte local_20;
  
  local_28 = 0;
  local_24 = '\0';
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  bVar1 = DAT_00057d4c;
  if (param_1 != 0) {
    local_28 = (&DAT_00057a94)[(param_1 + -1) * 0x4e];
  }
  if (unaff_EDX != 0) {
    local_24 = (&DAT_00057a94)[(unaff_EDX + -1) * 0x4e];
  }
  if ((unaff_EBX == unaff_ECX) && (unaff_EBX != 0)) {
    local_20 = (&DAT_00057cb4)[unaff_EBX * 5] | 0x40;
  }
  else {
    local_20 = (&DAT_00057cb4)[unaff_EBX * 5] | (&DAT_00057cb4)[unaff_ECX * 5] << 3;
  }
  if ((param_1 == unaff_EDX) && (param_1 != 0)) {
    local_34 = local_28 | 0x40;
  }
  else {
    local_34 = local_28 | local_24 << 3;
  }
  FUN_00033e1b(DAT_00057d08 + 0xf,5);
  FUN_00033e1b(DAT_00057d7d,bVar1);
  FUN_00033e1b(DAT_00057d81,0);
  FUN_00033e1b(DAT_00057d08 + 0xf,0);
  FUN_00033e1b(DAT_00057d7d,bVar1);
  FUN_00033e1b(DAT_00057d81,local_34 | 0x80);
  FUN_00033e1b(DAT_00057d7d,bVar1 | 0x40);
  FUN_00033e1b(DAT_00057d81,local_20);
  FUN_00033e1b(DAT_00057d7d,bVar1);
  FUN_00033e1b(DAT_00057d81,local_34);
  FUN_00033e1b(DAT_00057d7d,bVar1 | 0x40);
  FUN_00033e1b(DAT_00057d81,local_20);
  FUN_00033e1b(DAT_00057d65,0);
  bVar1 = bVar1 | 9;
  FUN_00033e1b(DAT_00057d7d,bVar1);
  FUN_00033e1b(DAT_00057d65,0);
  DAT_0008adbc = DAT_0008adbc + -1;
  DAT_00057d4c = bVar1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_000205e8 @ 000205e8 ======== */

void FUN_000205e8(undefined param_1,undefined4 param_2,undefined4 unaff_EBX,undefined2 unaff_CX)

{
  undefined4 local_38;
  undefined local_34;
  undefined2 local_30;
  undefined4 local_2c;
  
  local_38 = 0x205;
  local_34 = param_1;
  local_30 = unaff_CX;
  local_2c = unaff_EBX;
  FUN_0003478a(0x31,&local_38,&local_38);
  return;
}


/* ======== FUN_00020634 @ 00020634 ======== */

undefined8 FUN_00020634(undefined4 param_1)

{
  undefined2 uStack_36;
  undefined4 local_34;
  undefined local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  
  local_34 = 0x204;
  local_18._0_1_ = (undefined)param_1;
  local_30 = (undefined)local_18;
  local_18 = param_1;
  FUN_0003478a(0x31,&local_34,&local_34);
  return CONCAT26(uStack_36,CONCAT24(local_2c,local_28));
}


/* ======== FUN_0002067c @ 0002067c ======== */

void FUN_0002067c(int param_1,int unaff_EDX)

{
  int local_1c;
  
  if (param_1 != 0) {
    if (param_1 < 8) {
      local_1c = param_1 + 8;
    }
    else {
      local_1c = param_1 + 0x68;
    }
    FUN_00034817(local_1c,local_1c,DAT_00057d1c,DAT_00057d20);
  }
  if ((param_1 != unaff_EDX) && (unaff_EDX != 0)) {
    if (unaff_EDX < 8) {
      unaff_EDX = unaff_EDX + 8;
    }
    else {
      unaff_EDX = unaff_EDX + 0x68;
    }
    FUN_00034817(unaff_EDX,unaff_EDX,DAT_00057d22,DAT_00057d26);
  }
  return;
}


/* ======== FUN_00020708 @ 00020708 ======== */

void FUN_00020708(int param_1,int unaff_EDX)

{
  byte bVar1;
  
  if (param_1 != 0) {
    bVar1 = FUN_00033e30((&DAT_00057cb8)[param_1 * 5]);
    FUN_00033e1b((&DAT_00057cb8)[param_1 * 5],bVar1 & (&DAT_00057cb5)[param_1 * 5]);
    FUN_00033e1b((&DAT_00057cb7)[param_1 * 5],(&DAT_00057cb6)[param_1 * 5]);
  }
  if ((unaff_EDX != param_1) && (unaff_EDX != 0)) {
    bVar1 = FUN_00033e30((&DAT_00057cb8)[unaff_EDX * 5]);
    FUN_00033e1b((&DAT_00057cb8)[unaff_EDX * 5],bVar1 & (&DAT_00057cb5)[unaff_EDX * 5]);
    FUN_00033e1b((&DAT_00057cb7)[unaff_EDX * 5],(&DAT_00057cb6)[unaff_EDX * 5]);
  }
  if ((7 < unaff_EDX) || (7 < param_1)) {
    bVar1 = FUN_00033e30(DAT_00057cc2);
    FUN_00033e1b(DAT_00057cc2,bVar1 & DAT_00057cbf);
    FUN_00033e1b(DAT_00057cc1,DAT_00057cc0);
  }
  return;
}


/* ======== FUN_00020830 @ 00020830 ======== */

void FUN_00020830(int param_1,int unaff_EDX)

{
  byte bVar1;
  
  if ((param_1 != 2) && (param_1 != 0)) {
    bVar1 = FUN_00033e30((&DAT_00057cb8)[param_1 * 5]);
    FUN_00033e1b((&DAT_00057cb8)[param_1 * 5],bVar1 | ~(&DAT_00057cb5)[param_1 * 5]);
  }
  if ((unaff_EDX != 2) && (unaff_EDX != 0)) {
    bVar1 = FUN_00033e30((&DAT_00057cb8)[unaff_EDX * 5]);
    FUN_00033e1b((&DAT_00057cb8)[unaff_EDX * 5],bVar1 | ~(&DAT_00057cb5)[unaff_EDX * 5]);
  }
  return;
}


/* ======== FUN_000208e0 @ 000208e0 ======== */

void FUN_000208e0(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d69,0x41);
  bVar1 = FUN_00033e30(DAT_00057d71);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  if ((bVar1 & 0x40) != 0) {
    iVar2 = (DAT_00057d0c + -1) * 0x4e;
    pbVar3 = &DAT_00057a90 + iVar2;
    if ((*pbVar3 & 4) == 0) {
      *pbVar3 = *pbVar3 & 0xfd;
      DAT_00057d04 = DAT_00057d04 & 0xfd;
      *(int *)(&DAT_00057ac9 + iVar2) =
           *(int *)(&DAT_00057ac9 + iVar2) + *(int *)(&DAT_00057acd + iVar2);
      (*(code *)PTR_FUN_00057d40)();
    }
    else {
      FUN_0001d8b8(pbVar3,0);
    }
  }
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d69,0x49);
  bVar1 = FUN_00033e30(DAT_00057d71);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  if ((bVar1 & 0x40) != 0) {
    iVar2 = (DAT_00057d10 + -1) * 0x4e;
    pbVar3 = &DAT_00057a90 + iVar2;
    if ((*pbVar3 & 4) == 0) {
      *pbVar3 = *pbVar3 & 0xfd;
      DAT_00057d04 = DAT_00057d04 & 0xfb;
      *(int *)(&DAT_00057ac9 + iVar2) =
           *(int *)(&DAT_00057ac9 + iVar2) + *(int *)(&DAT_00057acd + iVar2);
      (*(code *)PTR_FUN_00057d44)();
    }
    else {
      FUN_0001d8b8(pbVar3,1);
    }
  }
  return;
}


/* ======== FUN_00020a08 @ 00020a08 ======== */

void FUN_00020a08(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint local_34;
  uint local_2c;
  
  local_2c = 0;
  local_34 = 0;
  while( true ) {
    DAT_0008adbc = DAT_0008adbc + 1;
    FUN_000350bd();
    FUN_00033e1b(DAT_00057d69,0x8f);
    bVar1 = FUN_00033e30(DAT_00057d71);
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
    uVar4 = (uint)(bVar1 & 0x1f);
    DAT_000892d8 = uVar4;
    if ((bVar1 & 0xc0) == 0xc0) break;
    uVar5 = 1 << (bVar1 & 0x1f);
    if (((bVar1 & 0x80) == 0) && ((uVar5 & local_2c) == 0)) {
      local_2c = local_2c | uVar5;
      FUN_00033e1b(DAT_00057d65,uVar4);
      FUN_00033e1b(DAT_00057d69,0x80);
      bVar2 = FUN_00033e30(DAT_00057d71);
      FUN_00033e1b(DAT_00057d69,0x8d);
      bVar3 = FUN_00033e30(DAT_00057d71);
      if (((bVar2 & 8) == 0) && ((bVar3 & 4) == 0)) {
        FUN_00032b30(uVar4);
      }
      (*(code *)PTR_FUN_00057d38)();
    }
    if (((bVar1 & 0x40) == 0) && ((uVar5 & local_34) == 0)) {
      local_34 = local_34 | uVar5;
      FUN_00033e1b(DAT_00057d65,uVar4);
      FUN_00033e1b(DAT_00057d69,0x8d);
      bVar1 = FUN_00033e30(DAT_00057d71);
      if ((bVar1 & 8) == 0) {
        FUN_00033170(uVar4);
      }
      (*(code *)PTR_FUN_00057d3c)();
    }
  }
  return;
}


/* ======== FUN_00020b68 @ 00020b68 ======== */

void FUN_00020b68(void)

{
  byte bVar1;
  
  while (bVar1 = FUN_00033e30(DAT_00057d75), bVar1 != 0) {
    if ((bVar1 & 0x80) != 0) {
      FUN_000208e0();
    }
    if ((bVar1 & 3) != 0) {
      FUN_00033e30(DAT_00057d61);
      if ((bVar1 & 1) != 0) {
        (*(code *)PTR_FUN_00057d28)();
      }
      if ((bVar1 & 2) != 0) {
        FUN_00033e30(DAT_00057d5d);
        (*(code *)PTR_FUN_00057d2c)();
      }
    }
    if ((bVar1 & 4) != 0) {
      DAT_0008adbc = DAT_0008adbc + 1;
      FUN_000350bd();
      FUN_00033e1b(DAT_00057d69,0x45);
      FUN_00033e1b(DAT_00057d71,DAT_00057d5b & 0xfb);
      FUN_00033e1b(DAT_00057d69,0x45);
      FUN_00033e1b(DAT_00057d71,DAT_00057d5b);
      (*(code *)PTR_FUN_00057d30)();
      DAT_0008adbc = DAT_0008adbc + -1;
      if (DAT_0008adbc == 0) {
        FUN_000350bf();
      }
    }
    if ((bVar1 & 8) != 0) {
      DAT_0008adbc = DAT_0008adbc + 1;
      FUN_000350bd();
      FUN_00033e1b(DAT_00057d69,0x45);
      FUN_00033e1b(DAT_00057d71,DAT_00057d5b & 0xf7);
      FUN_00033e1b(DAT_00057d69,0x45);
      FUN_00033e1b(DAT_00057d71,DAT_00057d5b);
      (*(code *)PTR_FUN_00057d34)();
      DAT_0008adbc = DAT_0008adbc + -1;
      if (DAT_0008adbc == 0) {
        FUN_000350bf();
      }
    }
    if ((bVar1 & 0x60) != 0) {
      FUN_00020a08();
    }
  }
  return;
}


/* ======== FUN_00020d40 @ 00020d40 ======== */

void FUN_00020d40(void)

{
  return;
}


/* ======== FUN_00020d58 @ 00020d58 ======== */

void FUN_00020d58(int param_1,int unaff_EDX)

{
  int iVar1;
  undefined2 in_CS;
  undefined6 uVar2;
  
  if (param_1 != 0) {
    if (param_1 < 8) {
      iVar1 = param_1 + 8;
      uVar2 = FUN_000347e5(iVar1);
      DAT_00057d20 = (undefined2)((uint6)uVar2 >> 0x20);
      DAT_00057d1c = (undefined4)uVar2;
      FUN_00034817(iVar1,iVar1,&LAB_00020cc8,in_CS);
    }
    else {
      iVar1 = param_1 + 0x68;
      uVar2 = FUN_00020634(iVar1);
      DAT_00057d20 = (undefined2)((uint6)uVar2 >> 0x20);
      DAT_00057d1c = (undefined4)uVar2;
      FUN_000205e8(iVar1,iVar1,&LAB_00020cc8,in_CS);
    }
  }
  if ((unaff_EDX != 0) && (unaff_EDX != param_1)) {
    if (unaff_EDX < 8) {
      unaff_EDX = unaff_EDX + 8;
    }
    else {
      unaff_EDX = unaff_EDX + 0x68;
    }
    if (unaff_EDX < 0x10) {
      uVar2 = FUN_000347e5(unaff_EDX);
      DAT_00057d26 = (undefined2)((uint6)uVar2 >> 0x20);
      DAT_00057d22 = (undefined4)uVar2;
      FUN_00034817(unaff_EDX,unaff_EDX,&LAB_00020d04,in_CS);
    }
    else {
      uVar2 = FUN_00020634(unaff_EDX);
      DAT_00057d26 = (undefined2)((uint6)uVar2 >> 0x20);
      DAT_00057d22 = (undefined4)uVar2;
      FUN_000205e8(unaff_EDX,unaff_EDX,&LAB_00020d04,in_CS);
    }
  }
  return;
}


/* ======== FUN_00020f68 @ 00020f68 ======== */

int FUN_00020f68(int param_1,undefined2 *unaff_EDX)

{
  int local_3c;
  uint local_38;
  uint local_34;
  undefined2 local_2c;
  int local_20;
  int local_1c;
  
  local_38 = 0x100;
  local_34 = param_1 + 0xfU >> 4;
  local_1c = param_1;
  FUN_0003478a(0x31,&local_38,&local_38);
  if (local_20 == 0) {
    if (unaff_EDX != (undefined2 *)0x0) {
      *unaff_EDX = local_2c;
    }
    local_3c = (local_38 & 0xffff) << 4;
  }
  else {
    local_3c = 0;
  }
  return local_3c;
}


/* ======== FUN_00020fd4 @ 00020fd4 ======== */

undefined8 FUN_00020fd4(uint param_1,undefined4 unaff_EDX)

{
  uint local_3c;
  undefined4 local_38 [3];
  uint local_2c;
  int local_20;
  uint local_1c;
  
  local_38[0] = 0x100;
  local_2c = param_1 & 0xffff;
  local_1c = param_1;
  FUN_0003478a(0x31,local_38,local_38);
  local_3c = (uint)(local_20 == 0);
  return CONCAT44(unaff_EDX,local_3c);
}


/* ======== FUN_00021024 @ 00021024 ======== */

void FUN_00021024(void)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar1;
  ushort in_CS;
  undefined2 in_DS;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  undefined *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_30;
  undefined4 local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (DAT_000b15a4 == 0) {
    local_20 = 1;
    local_1c = 1;
    local_60 = 0x204;
    local_5c._0_1_ = 9;
    FUN_0003478a(0x31,&local_60,&local_60);
    DAT_000b1588 = (undefined2)local_58;
    DAT_000b1584 = local_54;
    local_60 = 0x200;
    local_5c = CONCAT31(local_5c._1_3_,9);
    FUN_0003478a(0x31,&local_60,&local_60);
    DAT_000b1580 = (undefined2)local_58;
    DAT_000b1582 = SUB42(local_54,0);
    local_28 = FUN_00020f68(400,&DAT_0005136c);
    uVar1 = extraout_var;
    if (local_28 == 0) {
      printf();
      exit(1);
      uVar1 = extraout_var_00;
    }
    DAT_0005136e = local_28 + 0x5a;
    *(undefined4 *)(local_28 + 0x56) = 0;
    FUN_000351b9(local_28,CONCAT22(4,in_DS),0x40000,CONCAT22(uVar1,in_CS),400);
    local_24 = 0;
    while (local_24 < 0x102) {
      *(undefined *)(local_24 + DAT_0005136e) = 0;
      local_24 = local_24 + 1;
    }
    local_2c = CONCAT22(local_2c._2_2_,in_CS);
    local_30 = &LAB_0001041c;
    local_60 = 0x205;
    local_5c = 9;
    local_58 = (uint)in_CS;
    local_54 = &LAB_0001041c;
    FUN_0003478a(0x31,&local_60,&local_60);
    local_60 = 0x600;
    local_5c = 1;
    local_58 = 0x41c;
    local_50 = 0;
    local_4c = 0x100;
    FUN_0003478a(0x31,&local_60,&local_60);
    local_60 = 0x201;
    local_5c = 9;
    local_58 = local_28 >> 4 & 0xffff;
    local_54 = (undefined *)(local_28 & 0xf);
    FUN_0003478a(0x31,&local_60,&local_60);
    DAT_000b15a4 = 1;
    DAT_000b157c = 0;
  }
  return;
}


/* ======== FUN_00021204 @ 00021204 ======== */

void FUN_00021204(void)

{
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  
  if (DAT_000b15a4 != 0) {
    DAT_000b15a4 = 0;
    local_34 = 0x201;
    local_30 = 9;
    local_2c = (uint)DAT_000b1580;
    local_28 = (uint)DAT_000b1582;
    FUN_0003478a(0x31,&local_34,&local_34);
    local_34 = 0x205;
    local_30 = 9;
    local_2c = (uint)DAT_000b1588;
    local_28 = DAT_000b1584;
    FUN_0003478a(0x31,&local_34,&local_34);
  }
  return;
}


/* ======== FUN_00021290 @ 00021290 ======== */

void FUN_00021290(void)

{
  undefined2 in_CS;
  undefined6 uVar1;
  
  if (DAT_000b15a8 == 0) {
    FUN_000350bd();
    uVar1 = FUN_000347e5(8);
    DAT_000b15a0 = (undefined2)((uint6)uVar1 >> 0x20);
    DAT_000b159c = (undefined4)uVar1;
    FUN_00034817(8,8,&LAB_00020ed0,in_CS);
    FUN_00033e1b(0x43,0x36);
    FUN_00033e1b(0x40,0x38);
    FUN_00033e1b(0x40,0x5d);
    DAT_000b15a8 = 1;
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00021328 @ 00021328 ======== */

void FUN_00021328(void)

{
  FUN_000350bd();
  if (DAT_000b15a8 != 0) {
    FUN_00034817(8,8,DAT_000b159c,DAT_000b15a0);
    FUN_00033e1b(0x43,0x36);
    FUN_00033e1b(0x40,0);
    FUN_00033e1b(0x40,0);
    DAT_000b15a8 = 0;
    FUN_000350bf();
  }
  return;
}


/* ======== GetScancode @ 000213a0 ======== */

undefined8 GetScancode(undefined4 param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  undefined3 uVar2;
  byte local_28;
  
  bVar1 = DAT_0005136e[1];
  uVar2 = (undefined3)((uint)(DAT_0005136e + 2) >> 8);
  if (*DAT_0005136e == bVar1) {
    local_28 = 0;
  }
  else {
    local_28 = (DAT_0005136e + 2)[bVar1];
    uVar2 = 0;
    DAT_0005136e[1] = (byte)((bVar1 + 1) % 0x100);
  }
  return CONCAT44(unaff_EDX,CONCAT31(uVar2,local_28));
}


/* ======== FUN_00021418 @ 00021418 ======== */

void FUN_00021418(void)

{
  int local_1c;
  
  local_1c = 0;
  while (local_1c < 0x100) {
    *(undefined *)(local_1c + DAT_0005136e + 2) = 0;
    local_1c = local_1c + 1;
  }
  return;
}


/* ======== FUN_00021454 @ 00021454 ======== */

void FUN_00021454(void)

{
  if (DAT_000b157c == 0) {
    FUN_00034682(&DAT_000b1478,DAT_0005136e,0x102);
    DAT_000b157c = 1;
  }
  return;
}


/* ======== FUN_00021494 @ 00021494 ======== */

void FUN_00021494(void)

{
  if (DAT_000b157c != 0) {
    FUN_00034682(DAT_0005136e,&DAT_000b1478,0x102);
    DAT_000b157c = 0;
  }
  return;
}


/* ======== RoomTrigger_ctor @ 000214f0 ======== */

undefined4 * RoomTrigger_ctor(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 *puVar1;
  char cVar2;
  
  puVar1 = (undefined4 *)FUN_0001d530(param_1);
  puVar1[1] = &PTR_TileAnim_Erase_00065938;
  cVar2 = (char)((uint)unaff_EDX >> 0x10);
  puVar1[4] = *(int *)(&g_tileAnimSeq + cVar2 * 4) + (char)((uint)unaff_EDX >> 0x18) * 2;
  puVar1[5] = *(undefined4 *)(&g_tileAnimSeq + cVar2 * 4);
  puVar1[2] = (int)(char)unaff_EDX;
  puVar1[3] = (int)(char)((uint)unaff_EDX >> 8);
  *puVar1 = 0;
  return puVar1;
}


/* ======== TileAnim_Erase @ 0002157c ======== */

void TileAnim_Erase(int param_1)

{
  FUN_0001105d(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  return;
}


/* ======== TileAnim_Draw @ 000215a8 ======== */

void TileAnim_Draw(int param_1)

{
  if (*(int *)(param_1 + 8) < 0 || DAT_0007d174 != 0) {
    if ((*(int *)(param_1 + 8) < 0 & DAT_0007d174) != 0) {
      DrawPlatformTile(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                       (int)**(short **)(param_1 + 0x10));
    }
  }
  else {
    DrawPlatformTile(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                     (int)**(short **)(param_1 + 0x10));
  }
  return;
}


/* ======== FUN_00021658 @ 00021658 ======== */

void FUN_00021658(int param_1)

{
  FUN_00010f97(*(int *)(param_1 + 0xc) * 0x5f0 + ((int)((*(uint *)(param_1 + 8) & 0x7f) << 4) >> 2))
  ;
  return;
}


/* ======== TileAnim_Step @ 000216a0 ======== */

void TileAnim_Step(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 2;
  if (**(short **)(param_1 + 0x10) == -1) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x14);
  }
  return;
}


/* ======== FUN_000216dc @ 000216dc ======== */

undefined8 FUN_000216dc(int param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,
                  (uint)(byte)(&g_tileType)
                              [*(ushort *)
                                (&DAT_000887d6 +
                                *(int *)(param_1 + 0xc) * 2 + *(int *)(param_1 + 8) * 0x1c)]);
}


/* ======== TileAnim_Overlaps @ 0002171c ======== */

undefined TileAnim_Overlaps(int param_1,byte param_2,int unaff_EBX,int unaff_ECX,int param_5,
                           int param_6)

{
  undefined uVar1;
  int iVar2;
  
  iVar2 = (int)**(short **)(param_1 + 0x10);
  if ((param_2 & (&g_tileType)[iVar2]) == 0) {
    uVar1 = 0;
  }
  else if (((((int)((*(uint *)(param_1 + 8) & 0x7f) * 0x10 + (uint)(byte)(&DAT_0007c70a)[iVar2 * 4])
              < unaff_EBX) ||
            (param_5 < (int)((*(uint *)(param_1 + 8) & 0x7f) * 0x10 +
                            (uint)(byte)(&g_tileBox)[iVar2 * 4]))) ||
           ((int)(*(int *)(param_1 + 0xc) * 0x13 + (uint)(byte)(&DAT_0007c70b)[iVar2 * 4]) <
            unaff_ECX)) ||
          (param_6 < (int)(*(int *)(param_1 + 0xc) * 0x13 + (uint)(byte)(&DAT_0007c709)[iVar2 * 4]))
          ) {
    uVar1 = 0;
  }
  else {
    uVar1 = (&g_tileType)[iVar2];
  }
  return uVar1;
}


/* ======== Bob_GroupFirstFrame @ 00021820 ======== */

undefined8 Bob_GroupFirstFrame(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  
  local_24 = 0;
  local_28 = 0;
  while ((local_28 < param_1 && (local_24 < g_bobCount))) {
    iVar1 = local_24 + 1;
    iVar2 = local_24 * 9;
    local_24 = iVar1;
    if (*(char *)(g_bobDesc + iVar2) == -1) {
      local_28 = local_28 + 1;
    }
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== BobFindFrame @ 00021884 ======== */

int BobFindFrame(int param_1,char *unaff_EDX)

{
  int iVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  
  local_24 = 0;
  local_28 = 0;
  while ((local_28 < (short)(*(ushort *)(param_1 + 0x1a) & 0x7fff) && (local_24 < g_bobCount))) {
    iVar1 = local_24 + 1;
    iVar2 = local_24 * 9;
    local_24 = iVar1;
    if (*(char *)(g_bobDesc + iVar2) == -1) {
      local_28 = local_28 + 1;
    }
  }
  local_20 = (int)(short)(*(ushort *)(param_1 + 0x1c) & 0x7fff);
  *unaff_EDX = '\0';
  while (0 < local_20) {
    if (local_20 < *(char *)(g_bobDesc + local_24 * 9)) {
      *unaff_EDX = *(char *)(g_bobDesc + local_24 * 9) - (char)local_20;
      local_20 = 0;
    }
    else {
      local_20 = local_20 - *(char *)(g_bobDesc + local_24 * 9);
      local_24 = local_24 + 1;
    }
  }
  return local_24;
}


/* ======== RoomObject_ResetPath @ 00021958 ======== */

void RoomObject_ResetPath(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0xa5) & 0x40) == 0) {
    *(undefined *)(param_1 + 0x14) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + 0xe;
    *(undefined4 *)(param_1 + 0x10) = 0;
    uVar1 = BobFindFrame(*(undefined4 *)(param_1 + 0xc),param_1 + 0x79);
    *(undefined4 *)(param_1 + 0x3d) = uVar1;
    *(int *)(param_1 + 0x35) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 1);
    *(undefined *)(param_1 + 0x79) = *(undefined *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9);
    *(undefined4 *)(param_1 + 0x15) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    *(undefined4 *)(param_1 + 0x19) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    *(undefined4 *)(param_1 + 0x25) = **(undefined4 **)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x29) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
    *(undefined4 *)(param_1 + 0x2d) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
    *(undefined4 *)(param_1 + 0x31) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
    *(undefined4 *)(param_1 + 0x7f) = *(undefined4 *)(param_1 + 0x15);
    *(undefined4 *)(param_1 + 0x83) = *(undefined4 *)(param_1 + 0x19);
    *(undefined4 *)(param_1 + 0x39) = *(undefined4 *)(param_1 + 0x35);
    *(undefined4 *)(param_1 + 0x41) = *(undefined4 *)(param_1 + 0x3d);
    *(uint *)(param_1 + 0x49) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 5);
    *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x51) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x55) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 8);
    *(int *)(param_1 + 0x87) = (int)(uint)(*(ushort *)(param_1 + 0xa5) & 0x3c00) >> 7;
    *(undefined4 *)(param_1 + 0x8b) = 0;
    *(undefined4 *)(param_1 + 0x93) = 0;
  }
  else {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + 0xe;
    *(int *)(param_1 + 0xc) =
         *(int *)(param_1 + 0xc) + (uint)*(byte *)(*(int *)(param_1 + 8) + 1) * 0x20 + -0x20;
    uVar1 = BobFindFrame(*(undefined4 *)(param_1 + 0xc),param_1 + 0x79);
    *(undefined4 *)(param_1 + 0x3d) = uVar1;
    *(int *)(param_1 + 0x35) = g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
    *(undefined4 *)(param_1 + 0x15) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    *(undefined4 *)(param_1 + 0x19) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    *(undefined4 *)(param_1 + 0x7f) = *(undefined4 *)(param_1 + 0x15);
    *(undefined4 *)(param_1 + 0x83) = *(undefined4 *)(param_1 + 0x19);
    *(undefined4 *)(param_1 + 0x39) = *(undefined4 *)(param_1 + 0x35);
    *(undefined4 *)(param_1 + 0x41) = *(undefined4 *)(param_1 + 0x3d);
    *(uint *)(param_1 + 0x49) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x51) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 7);
    *(uint *)(param_1 + 0x55) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 8);
    *(int *)(param_1 + 0x87) = (int)(uint)(*(ushort *)(param_1 + 0xa5) & 0x3c00) >> 7;
    *(undefined4 *)(param_1 + 0x8b) = 0;
    *(undefined4 *)(param_1 + 0x93) = 0;
  }
  *(int *)(param_1 + 0xb7) = *(int *)(param_1 + 0x15) >> 0x10;
  *(int *)(param_1 + 0xbb) = *(int *)(param_1 + 0x19) >> 0x10;
  *(uint *)(param_1 + 0xbf) = *(int *)(param_1 + 0xb7) + (uint)**(byte **)(param_1 + 0x35);
  *(uint *)(param_1 + 0xc3) =
       *(int *)(param_1 + 0xbb) + (uint)*(byte *)(*(int *)(param_1 + 0x35) + 1);
  *(undefined4 *)(param_1 + 0xa7) = *(undefined4 *)(param_1 + 0xb7);
  *(undefined4 *)(param_1 + 0xab) = *(undefined4 *)(param_1 + 0xbb);
  *(undefined4 *)(param_1 + 0xaf) = *(undefined4 *)(param_1 + 0xbf);
  *(undefined4 *)(param_1 + 0xb3) = *(undefined4 *)(param_1 + 0xc3);
  if (((int)*(short *)(*(int *)(param_1 + 0xc) + 0x1c) & 0x8000U) == 0) {
    *(undefined4 *)(param_1 + 0x9f) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x9f) = 1;
  }
  *(undefined4 *)(param_1 + 0x8f) = 0;
  *(undefined4 *)(param_1 + 199) = 0;
  return;
}


/* ======== RoomObject_ctor @ 00021d5c ======== */

undefined4 * RoomObject_ctor(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0001d530(param_1);
  puVar1[1] = &PTR_FUN_00065908;
  puVar1[2] = unaff_EDX;
  *(undefined2 *)((int)puVar1 + 0xa5) = *(undefined2 *)(puVar1[2] + 6);
  *(undefined4 *)((int)puVar1 + 0x7a) = unaff_EBX;
  *(undefined4 *)((int)puVar1 + 0x9b) = 0;
  (**(code **)(puVar1[1] + 0x20))(puVar1);
  *puVar1 = 0;
  *(undefined *)((int)puVar1 + 0x7e) = 0;
  *(undefined4 *)((int)puVar1 + 0x97) = 0;
  if ((*(byte *)((int)puVar1 + 0xa6) & 0x80) == 0) {
    if (((*(byte *)((int)puVar1 + 0xa5) & 1) != 0) && (*(char *)(puVar1[2] + 3) == '\x03')) {
      *(byte *)(puVar1[2] + 6) = *(byte *)(puVar1[2] + 6) | 0x40;
    }
  }
  else if ((*(byte *)(puVar1[2] + 2) & 2) == 0) {
    if (*(byte *)(puVar1[2] + 0xd) < 3) {
      *(byte *)((int)puVar1 + 0xa5) = *(byte *)((int)puVar1 + 0xa5) & 0xfe;
    }
    else if ((*(byte *)((int)puVar1 + 0xa5) & 4) == 0) {
      if ((&g_gameFlags)[*(byte *)(puVar1[2] + 0xd)] == '\0') {
        *(byte *)((int)puVar1 + 0xa5) = *(byte *)((int)puVar1 + 0xa5) & 0xfe;
      }
    }
    else if (((*(byte *)((int)puVar1 + 0xa6) & 0x10) == 0) &&
            ((&g_gameFlags)[*(byte *)(puVar1[2] + 0xd)] != '\0')) {
      *(undefined4 *)((int)puVar1 + 0x8b) = 1;
      *(byte *)((int)puVar1 + 0xa5) = *(byte *)((int)puVar1 + 0xa5) | 1;
      puVar1[4] = 0;
    }
  }
  else if (((*(byte *)((int)puVar1 + 0xa6) & 0x10) == 0) &&
          ((&g_gameFlags)[*(byte *)(puVar1[2] + 0xd)] != '\0')) {
    *(undefined4 *)((int)puVar1 + 0x8b) = 1;
    *(byte *)((int)puVar1 + 0xa5) = *(byte *)((int)puVar1 + 0xa5) | 1;
    puVar1[4] = 0;
  }
  return puVar1;
}


/* ======== FUN_00021f88 @ 00021f88 ======== */

void FUN_00021f88(int param_1,int unaff_EDX)

{
  *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) | 1;
  if (unaff_EDX == 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x20))(param_1);
  }
  if ((short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3800) >> 0xb == 1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))
              (g_sound,*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff);
    if (*(short *)(&DAT_00051386 +
                  (short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff) * 0x20) != 0) {
      (&DAT_0007d158)[*(int *)(param_1 + 0x7a)] = *(undefined *)(*(int *)(param_1 + 0xc) + 0x1e);
    }
  }
  return;
}


/* ======== FUN_00022034 @ 00022034 ======== */

void FUN_00022034(int param_1)

{
  *(undefined4 *)(param_1 + 0x8b) = 1;
  return;
}


/* ======== Object_FireTrigger @ 0002205c ======== */

void Object_FireTrigger(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *local_28;
  
  local_28 = g_platformList;
  if ((*(byte *)(param_1 + 0xa5) & 0x10) != 0) {
    while ((local_28 != (undefined4 *)0x0 &&
           (iVar1 = (**(code **)(local_28[1] + 0x10))(local_28),
           *(int *)(param_1 + 0x7a) + 1 != iVar1))) {
      local_28 = (undefined4 *)*local_28;
    }
    if ((*(byte *)((int)local_28 + 0xa6) & 0x80) == 0) {
      *(undefined4 *)((int)local_28 + 0x8b) = 1;
      local_28[4] = 0;
      (**(code **)(local_28[1] + 0x14))(local_28,1);
    }
    else {
      (**(code **)(local_28[1] + 0x14))(local_28,1);
      if (*(char *)(local_28[2] + 0xd) == '\0') {
        *(byte *)((int)local_28 + 0xa6) = *(byte *)((int)local_28 + 0xa6) & 0x7f;
        *(byte *)(local_28[2] + 7) = *(byte *)(local_28[2] + 7) & 0x7f;
      }
    }
    if ((*(byte *)(param_1 + 0xa6) & 0x40) == 0) {
      return;
    }
  }
  if (*(byte *)(*(int *)(param_1 + 8) + 0xc) < 0x14) {
    local_28 = g_objList;
    while ((local_28 != (undefined4 *)0x0 &&
           (uVar2 = (**(code **)(local_28[1] + 0x10))(local_28),
           *(byte *)(*(int *)(param_1 + 8) + 0xc) != uVar2))) {
      local_28 = (undefined4 *)*local_28;
    }
    if ((*(byte *)((int)local_28 + 0xa6) & 0x80) == 0) {
      *(undefined4 *)((int)local_28 + 0x8b) = 1;
      local_28[4] = 0;
      (**(code **)(local_28[1] + 0x14))(local_28,1);
    }
    else {
      (**(code **)(local_28[1] + 0x14))(local_28,1);
      if (*(char *)(local_28[2] + 0xd) == '\0') {
        *(byte *)(local_28[2] + 7) = *(byte *)(local_28[2] + 7) & 0x7f;
        *(byte *)((int)local_28 + 0xa6) = *(byte *)((int)local_28 + 0xa6) & 0x7f;
      }
    }
  }
  else {
    (&g_gameFlags)[*(byte *)(*(int *)(param_1 + 8) + 0xc)] = 1;
    (*(code *)(&g_scriptTable)[(uint)*(byte *)(*(int *)(param_1 + 8) + 0xc) * 2])();
  }
  return;
}


/* ======== Object_Hide @ 00022238 ======== */

void Object_Hide(int param_1)

{
  *(undefined4 *)(param_1 + 0x69) = *(undefined4 *)(param_1 + 0x59);
  *(undefined4 *)(param_1 + 0x71) = *(undefined4 *)(param_1 + 0x61);
  *(undefined4 *)(param_1 + 0x6d) = *(undefined4 *)(param_1 + 0x5d);
  *(undefined4 *)(param_1 + 0x75) = *(undefined4 *)(param_1 + 0x65);
  *(undefined4 *)(param_1 + 0x45) = *(undefined4 *)(param_1 + 0x35);
  *(undefined4 *)(param_1 + 0x1d) = *(undefined4 *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x21) = *(undefined4 *)(param_1 + 0x19);
  *(undefined4 *)(param_1 + 0x97) = 1;
  return;
}


/* ======== FUN_000222b4 @ 000222b4 ======== */

void FUN_000222b4(int param_1)

{
  int iVar1;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0xa7) < *(int *)(param_1 + 0xb7)) {
    local_2c = *(int *)(param_1 + 0xa7);
  }
  else {
    local_2c = *(int *)(param_1 + 0xb7);
  }
  if (*(int *)(param_1 + 0xab) < *(int *)(param_1 + 0xbb)) {
    local_28 = *(int *)(param_1 + 0xab);
  }
  else {
    local_28 = *(int *)(param_1 + 0xbb);
  }
  if (*(int *)(param_1 + 0xbf) < *(int *)(param_1 + 0xaf)) {
    local_24 = *(int *)(param_1 + 0xaf);
  }
  else {
    local_24 = *(int *)(param_1 + 0xbf);
  }
  iVar1 = (local_24 - local_2c) + 1;
  if (*(int *)(param_1 + 0xc3) < *(int *)(param_1 + 0xb3)) {
    local_20 = *(int *)(param_1 + 0xb3);
  }
  else {
    local_20 = *(int *)(param_1 + 0xc3);
  }
  local_20 = local_20 - local_28;
  if ((*(int *)(param_1 + 0x97) == 0) || ((*(byte *)(param_1 + 0xa5) & 8) != 0)) {
    if ((*(char *)(param_1 + 0x7e) == '\0') || ((*(byte *)(param_1 + 0xa5) & 8) != 0)) {
      if (((*(byte *)(param_1 + 0xa5) & 1) != 0) && ((*(byte *)(param_1 + 0xa5) & 8) == 0)) {
        FUN_000110c2(local_2c,local_28,iVar1,local_20);
      }
    }
    else {
      FUN_000110c2(local_2c,local_28,iVar1,local_20);
      *(undefined *)(param_1 + 0x7e) = 0;
      *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) & 0xfe;
    }
  }
  else {
    FUN_000110c2(local_2c,local_28,iVar1,local_20);
    *(undefined4 *)(param_1 + 0x97) = 0;
  }
  return;
}


/* ======== FUN_00022448 @ 00022448 ======== */

void FUN_00022448(int param_1)

{
  if ((*(int *)(param_1 + 0x97) == 0) || ((*(byte *)(param_1 + 0xa5) & 8) != 0)) {
    if ((*(byte *)(*(int *)(param_1 + 8) + 2) & 8) == 0) {
      if ((*(char *)(param_1 + 0x7e) == '\0') || ((*(byte *)(param_1 + 0xa5) & 8) != 0)) {
        if (((*(byte *)(param_1 + 0xa5) & 1) != 0) && ((*(byte *)(param_1 + 0xa5) & 8) == 0)) {
          *(int *)(param_1 + 0xa7) = *(int *)(param_1 + 0x7f) >> 0x10;
          *(int *)(param_1 + 0xab) = *(int *)(param_1 + 0x83) >> 0x10;
          *(uint *)(param_1 + 0xaf) = *(int *)(param_1 + 0xa7) + (uint)**(byte **)(param_1 + 0x39);
          *(uint *)(param_1 + 0xb3) =
               *(int *)(param_1 + 0xab) + (uint)*(byte *)(*(int *)(param_1 + 0x39) + 1);
          FUN_00011145(*(int *)(param_1 + 0x7f) >> 0x10,*(int *)(param_1 + 0x83) >> 0x10,
                       **(undefined **)(param_1 + 0x39),*(undefined *)(*(int *)(param_1 + 0x39) + 1)
                      );
        }
      }
      else {
        *(int *)(param_1 + 0xa7) = *(int *)(param_1 + 0x7f) >> 0x10;
        *(int *)(param_1 + 0xab) = *(int *)(param_1 + 0x83) >> 0x10;
        *(uint *)(param_1 + 0xaf) = *(int *)(param_1 + 0xa7) + (uint)**(byte **)(param_1 + 0x39);
        *(uint *)(param_1 + 0xb3) =
             *(int *)(param_1 + 0xab) + (uint)*(byte *)(*(int *)(param_1 + 0x39) + 1);
        FUN_00011145(*(undefined4 *)(param_1 + 0xa7),*(undefined4 *)(param_1 + 0xab),
                     **(undefined **)(param_1 + 0x39),*(undefined *)(*(int *)(param_1 + 0x39) + 1));
      }
    }
  }
  else {
    *(int *)(param_1 + 0xa7) = *(int *)(param_1 + 0x1d) >> 0x10;
    *(int *)(param_1 + 0xab) = *(int *)(param_1 + 0x21) >> 0x10;
    *(uint *)(param_1 + 0xaf) = *(int *)(param_1 + 0xa7) + (uint)**(byte **)(param_1 + 0x45);
    *(uint *)(param_1 + 0xb3) =
         *(int *)(param_1 + 0xab) + (uint)*(byte *)(*(int *)(param_1 + 0x45) + 1);
    FUN_00011145(*(undefined4 *)(param_1 + 0xa7),*(undefined4 *)(param_1 + 0xab),
                 **(undefined **)(param_1 + 0x45),*(undefined *)(*(int *)(param_1 + 0x45) + 1));
  }
  return;
}


/* ======== FUN_00022674 @ 00022674 ======== */

void FUN_00022674(int param_1)

{
  if ((((DAT_0007d174 == '\0') && (*(char *)(param_1 + 0x7e) == '\0')) &&
      (*(int *)(param_1 + 0x9f) == 0)) &&
     (((*(byte *)(param_1 + 0xa5) & 1) != 0 && ((*(byte *)(param_1 + 0xa5) & 8) == 0)))) {
    *(int *)(param_1 + 0xb7) = *(int *)(param_1 + 0x15) >> 0x10;
    *(int *)(param_1 + 0xbb) = *(int *)(param_1 + 0x19) >> 0x10;
    *(uint *)(param_1 + 0xbf) = *(int *)(param_1 + 0xb7) + (uint)**(byte **)(param_1 + 0x35);
    *(uint *)(param_1 + 0xc3) =
         *(int *)(param_1 + 0xbb) + (uint)*(byte *)(*(int *)(param_1 + 0x35) + 1);
    if (*(int *)(param_1 + 0x8f) == 0) {
      FUN_00010ba3(*(undefined4 *)(param_1 + 0xb7),*(undefined4 *)(param_1 + 0xbb),
                   *(undefined4 *)(param_1 + 0x35));
    }
    else {
      FUN_00010f26(*(undefined4 *)(param_1 + 0xb7),*(undefined4 *)(param_1 + 0xbb),
                   *(undefined4 *)(param_1 + 0x35),0x1d);
      *(undefined4 *)(param_1 + 0x8f) = 0;
    }
  }
  return;
}


/* ======== FUN_00022788 @ 00022788 ======== */

undefined8 FUN_00022788(int param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,*(undefined4 *)(param_1 + 0x87));
}


/* ======== Object_Overlaps @ 000227b0 ======== */

undefined4
Object_Overlaps(int param_1,uint unaff_EDX,int unaff_EBX,int unaff_ECX,int param_5,int param_6)

{
  undefined4 local_30;
  
  *(undefined4 *)(param_1 + 0xcb) = 0;
  if (((*(byte *)(param_1 + 0xa5) & 1) == 0) || (*(int *)(param_1 + 0x8b) != 0)) {
    local_30 = 0;
  }
  else if ((unaff_EDX & *(uint *)(param_1 + 0x87)) == 0) {
    local_30 = 0;
  }
  else if ((((*(int *)(param_1 + 0x51) + (*(int *)(param_1 + 0x15) >> 0x10) < unaff_EBX) ||
            (param_5 < *(int *)(param_1 + 0x49) + (*(int *)(param_1 + 0x15) >> 0x10))) ||
           (*(int *)(param_1 + 0x55) + (*(int *)(param_1 + 0x19) >> 0x10) < unaff_ECX)) ||
          (param_6 < *(int *)(param_1 + 0x4d) + (*(int *)(param_1 + 0x19) >> 0x10))) {
    local_30 = 0;
  }
  else {
    if ((unaff_EDX & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0xcb) = 1;
      DAT_0008898c._0_1_ = (byte)DAT_0008898c | 4;
    }
    local_30 = *(undefined4 *)(param_1 + 0x87);
  }
  return local_30;
}


/* ======== Platform_PushCarryHero @ 000228c4 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Platform_PushCarryHero(int param_1)

{
  int iVar1;
  int iVar2;
  int local_2c;
  int local_28;
  
  if (*(int *)(param_1 + 0xcb) != 0) {
    local_2c = DAT_0007d45a;
    local_28 = DAT_0007d45e;
    iVar1 = *(int *)(param_1 + 0x15) >> 0x10;
    iVar2 = *(int *)(param_1 + 0x19) >> 0x10;
    if (*(int *)(param_1 + 0x4d) + (*(int *)(param_1 + 0x83) >> 0x10) < DAT_0007d452 + _DAT_0007d410
       ) {
      if (DAT_0007d452 + _DAT_0007d408 <
          *(int *)(param_1 + 0x55) + (*(int *)(param_1 + 0x83) >> 0x10)) {
        if (*(int *)(param_1 + 0x49) + (*(int *)(param_1 + 0x7f) >> 0x10) <
            DAT_0007d44e + _DAT_0007d40c) {
          if (*(int *)(param_1 + 0x51) + (*(int *)(param_1 + 0x7f) >> 0x10) <=
              DAT_0007d44e + _DAT_0007d404) {
            local_2c = ((iVar1 + *(int *)(param_1 + 0x51)) - _DAT_0007d3f4) + 1;
          }
        }
        else {
          local_2c = ((iVar1 + *(int *)(param_1 + 0x49)) - _DAT_0007d3fc) + -1;
        }
      }
      else {
        local_28 = ((iVar2 + *(int *)(param_1 + 0x55)) - _DAT_0007d3f8) + 1;
      }
    }
    else {
      iVar1 = (iVar2 + *(int *)(param_1 + 0x4d)) - _DAT_0007d400;
      local_28 = iVar1 + -1;
      if ((*(int *)(param_1 + 0x2d) != 0) || (*(int *)(param_1 + 0x31) != 0)) {
        local_2c = DAT_0007d45a +
                   ((*(int *)(param_1 + 0x15) >> 0x10) - (*(int *)(param_1 + 0x7f) >> 0x10));
        DAT_0008899c = 1;
        if (0 < *(int *)(param_1 + 0x31)) {
          local_28 = iVar1;
        }
      }
    }
    DAT_0007d45a = local_2c;
    DAT_0007d45e = local_28;
  }
  return;
}


/* ======== Object_Hit @ 00022a6c ======== */

undefined4 Object_Hit(int param_1,byte unaff_DL)

{
  char *pcVar1;
  undefined4 local_20;
  
  if (*(char *)(*(int *)(param_1 + 8) + 8) == -1) {
    *(undefined4 *)(param_1 + 0x8f) = 1;
    local_20 = 1;
  }
  else if (*(int *)(param_1 + 0x87) == 0x20) {
    local_20 = 0;
  }
  else if (*(char *)(*(int *)(param_1 + 8) + 8) == -2) {
    local_20 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x8f) = 1;
    if (*(byte *)(*(int *)(param_1 + 8) + 8) < unaff_DL) {
      *(undefined *)(*(int *)(param_1 + 8) + 8) = 0;
    }
    else {
      pcVar1 = (char *)(*(int *)(param_1 + 8) + 8);
      *pcVar1 = *pcVar1 - unaff_DL;
    }
    if (*(char *)(*(int *)(param_1 + 8) + 8) == '\0') {
      FUN_00029050(param_1);
    }
    local_20 = 1;
  }
  return local_20;
}


/* ======== FUN_00022b34 @ 00022b34 ======== */

void FUN_00022b34(int param_1)

{
  *(undefined4 *)(param_1 + 0x6e) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0x403;
  *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
  *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
  *(undefined4 *)(param_1 + 0x7e) = 0x16;
  *(undefined4 *)(param_1 + 0x82) = 0x52;
  *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
  *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x5e) = 0;
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
  *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 6);
  *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
  *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
  *(int *)(param_1 + 0x4e) = *(int *)(param_1 + 0x7e) >> 0x10;
  *(int *)(param_1 + 0x52) = *(int *)(param_1 + 0x82) >> 0x10;
  *(uint *)(param_1 + 0x56) = *(int *)(param_1 + 0x4e) + (uint)**(byte **)(param_1 + 8);
  *(uint *)(param_1 + 0x5a) = *(int *)(param_1 + 0x52) + (uint)*(byte *)(*(int *)(param_1 + 8) + 1);
  *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(param_1 + 0x4e);
  *(undefined4 *)(param_1 + 0x42) = *(undefined4 *)(param_1 + 0x52);
  *(undefined4 *)(param_1 + 0x46) = *(undefined4 *)(param_1 + 0x56);
  *(undefined4 *)(param_1 + 0x4a) = *(undefined4 *)(param_1 + 0x5a);
  return;
}


/* ======== Hero_InitStates @ 00022d18 ======== */

void Hero_InitStates(undefined4 *param_1)

{
  (**(code **)(param_1[1] + 0x20))(param_1);
  *(undefined *)((int)param_1 + 0x96) = 0;
  *param_1 = 0;
  *(undefined4 *)((int)param_1 + 0x7a) = 0;
  DAT_00088988 = 0;
  g_heroStateTable = FUN_00029020;
  DAT_0007d314 = 0;
  DAT_0007d318 = 0;
  DAT_0007d31c = FUN_00028ff0;
  DAT_0007d320 = 0;
  DAT_0007d324 = 0;
  DAT_0007d328 = FUN_00028fc0;
  DAT_0007d32c = 0;
  DAT_0007d330 = 0;
  DAT_0007d334 = FUN_00028f90;
  DAT_0007d338 = 0;
  DAT_0007d33c = 0;
  DAT_0007d340 = FUN_00028f60;
  DAT_0007d344 = 0;
  DAT_0007d348 = 0;
  DAT_0007d34c = FUN_00028f30;
  DAT_0007d350 = 0;
  DAT_0007d354 = 0;
  DAT_0007d358 = FUN_00028f00;
  DAT_0007d35c = 0;
  DAT_0007d360 = 0;
  DAT_0007d364 = FUN_00028ed0;
  DAT_0007d368 = 0;
  DAT_0007d36c = 0;
  DAT_0007d370 = FUN_00028ea0;
  DAT_0007d374 = 0;
  DAT_0007d378 = 0;
  DAT_0007d37c = FUN_00028e70;
  DAT_0007d380 = 0;
  DAT_0007d384 = 0;
  DAT_0007d388 = FUN_00028e40;
  DAT_0007d38c = 0;
  DAT_0007d390 = 0;
  DAT_0007d394 = FUN_00028e10;
  DAT_0007d398 = 0;
  DAT_0007d39c = 0;
  DAT_0007d3a0 = FUN_00028de0;
  DAT_0007d3a4 = 0;
  DAT_0007d3a8 = 0;
  DAT_0007d3ac = FUN_00028db0;
  DAT_0007d3b0 = 0;
  DAT_0007d3b4 = 0;
  DAT_0007d3b8 = FUN_00028d80;
  DAT_0007d3bc = 0;
  DAT_0007d3c0 = 0;
  DAT_0007d3c4 = FUN_00028d50;
  DAT_0007d3c8 = 0;
  DAT_0007d3cc = 0;
  return;
}


/* ======== TileCollide @ 000230fc ======== */

undefined4
TileCollide(int param_1,int unaff_EDX,int unaff_EBX,int unaff_ECX,int param_5,int param_6)

{
  uint uVar1;
  undefined4 local_44;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = param_5;
  local_20 = param_6;
  if (param_5 < 0) {
    local_2c = -1;
    local_24 = 0xd;
  }
  else if (0xd < param_5) {
    local_2c = 1;
    local_24 = 0;
  }
  if (param_6 < 0) {
    local_28 = -1;
    local_20 = 0xb;
  }
  else if (0xb < param_6) {
    local_28 = 1;
    local_20 = 0;
  }
  uVar1 = (uint)*(ushort *)
                 (&DAT_0007d4ee +
                 (local_24 % 0xe) * 2 +
                 (g_roomRow + local_28) * 0x11e4 + (g_roomCol + local_2c) * 0x1ca +
                 (local_20 % 0xc) * 0x1c);
  if ((&g_tileType)[uVar1] == '\x02') {
    local_44 = 0;
  }
  else if (((((int)(param_5 * 0x10 + (uint)(byte)(&DAT_0007c70a)[uVar1 * 4]) < param_1) ||
            (unaff_EBX < (int)(param_5 * 0x10 + (uint)(byte)(&g_tileBox)[uVar1 * 4]))) ||
           ((int)(param_6 * 0x13 + (uint)(byte)(&DAT_0007c70b)[uVar1 * 4]) < unaff_EDX)) ||
          (unaff_ECX < (int)(param_6 * 0x13 + (uint)(byte)(&DAT_0007c709)[uVar1 * 4]))) {
    local_44 = 0;
  }
  else if ((&g_tileType)[uVar1] == '\x01') {
    DAT_0007d472 = 1;
    g_heroHit = 1;
    local_44 = 1;
  }
  else {
    local_44 = 2;
  }
  return local_44;
}


/* ======== Hero_MoveCollide @ 000232c4 ======== */

void Hero_MoveCollide(int param_1,int unaff_EDX,int unaff_EBX)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar8;
  undefined8 uVar9;
  int local_54;
  int local_4c;
  int local_3c;
  int local_38;
  undefined4 *local_24;
  
  bVar1 = true;
  bVar2 = true;
  local_54 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c);
  local_4c = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20);
  iVar4 = *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24);
  iVar5 = local_54 + unaff_EDX >> 4;
  local_3c = iVar5;
  while ((local_3c < iVar5 + 3 && (local_38 = iVar3 / 0x13, bVar1))) {
    while ((local_38 < iVar3 / 0x13 + 3 && (bVar1))) {
      iVar8 = TileCollide(local_54 + unaff_EDX,iVar3,local_4c + unaff_EDX,iVar4,local_3c,local_38);
      if (iVar8 == 2) {
        bVar1 = false;
      }
      local_38 = local_38 + 1;
    }
    local_3c = local_3c + 1;
  }
  if (bVar1) {
    *(int *)(param_1 + 0x7e) = *(int *)(param_1 + 0x7e) + unaff_EDX;
    local_54 = local_54 + unaff_EDX;
    local_4c = local_4c + unaff_EDX;
  }
  else {
    DAT_0008898c._0_1_ = (byte)DAT_0008898c | 1;
  }
  iVar6 = (int)((local_54 + (local_54 >> 0x1f) * -0x10) - (uint)((local_54 >> 0x1f) << 3 < 0)) >> 4;
  iVar8 = 0x13;
  iVar7 = (iVar3 + unaff_EBX) / 0x13;
  iVar5 = (iVar3 + unaff_EBX) % 0x13;
  local_3c = iVar6;
  while ((local_3c < iVar6 + 3 && (local_38 = iVar7, bVar2))) {
    while ((local_38 < iVar7 + 3 && (bVar2))) {
      uVar9 = TileCollide(local_54,iVar3 + unaff_EBX,local_4c,iVar4 + unaff_EBX,local_3c,local_38);
      iVar5 = (int)((ulonglong)uVar9 >> 0x20);
      if ((int)uVar9 == 2) {
        bVar2 = false;
      }
      iVar8 = local_4c;
      local_38 = local_38 + 1;
    }
    local_3c = local_3c + 1;
  }
  if (bVar2) {
    *(int *)(param_1 + 0x82) = *(int *)(param_1 + 0x82) + unaff_EBX;
    iVar5 = param_1;
  }
  else {
    DAT_0008898c._0_1_ = (byte)DAT_0008898c | 2;
  }
  DAT_00053428 = 0;
  for (local_24 = g_platformList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24)
  {
    iVar8 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    (**(code **)(local_24[1] + 0x28))
              (local_24,0x40,iVar8,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
               *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
               *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar5 = extraout_EDX;
  }
  if (((byte)DAT_0008898c & 6) != 0) {
    for (local_24 = g_platformList; local_24 != (undefined4 *)0x0;
        local_24 = (undefined4 *)*local_24) {
      Platform_PushCarryHero(local_24);
      iVar5 = extraout_EDX_00;
    }
  }
  iVar3 = *(int *)(param_1 + 0x7e) + 0xb;
  if (iVar3 < 0) {
    if (g_roomCol < 1) {
      *(undefined4 *)(param_1 + 0x7e) = 0xfffffff5;
    }
    else {
      g_roomCol = g_roomCol + -1;
      FreeRoomObjects(iVar3,iVar5,iVar8);
      EnterRoom(g_roomCol,g_roomRow);
      *(undefined4 *)(param_1 + 0x7e) = 0xd5;
    }
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
    iVar5 = param_1;
  }
  iVar3 = *(int *)(param_1 + 0x7e) + 0xb;
  if (0xe0 < iVar3) {
    if (g_roomCol < 9) {
      g_roomCol = g_roomCol + 1;
      FreeRoomObjects(iVar3,iVar5,iVar8);
      EnterRoom(g_roomCol,g_roomRow);
      *(undefined4 *)(param_1 + 0x7e) = 0xfffffff5;
    }
    else {
      *(undefined4 *)(param_1 + 0x7e) = 0xd5;
    }
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
    iVar5 = param_1;
  }
  if (*(int *)(param_1 + 0x82) < 0) {
    if (g_roomRow < 1) {
      *(undefined4 *)(param_1 + 0x82) = 0;
    }
    else {
      g_roomRow = g_roomRow + -1;
      FreeRoomObjects(param_1,iVar5,iVar8);
      EnterRoom(g_roomCol,g_roomRow);
      *(undefined4 *)(param_1 + 0x82) = 0xc5;
    }
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
    iVar5 = param_1;
  }
  iVar3 = *(int *)(param_1 + 0x82) + 0xf;
  if (0xe4 < iVar3) {
    if (g_roomRow < 9) {
      g_roomRow = g_roomRow + 1;
      FreeRoomObjects(iVar3,iVar5,iVar8);
      EnterRoom(g_roomCol,g_roomRow);
      *(undefined4 *)(param_1 + 0x82) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x82) = 0xd5;
    }
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  }
  return;
}


/* ======== FUN_00023740 @ 00023740 ======== */

void FUN_00023740(int param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  *(undefined4 *)(param_1 + 0x7e) = unaff_EDX;
  *(undefined4 *)(param_1 + 0x82) = unaff_EBX;
  return;
}


/* ======== Hero_FlushRect @ 00023770 ======== */

void Hero_FlushRect(int param_1)

{
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0x3e) < *(int *)(param_1 + 0x4e)) {
    local_2c = *(uint *)(param_1 + 0x3e);
  }
  else {
    local_2c = *(uint *)(param_1 + 0x4e);
  }
  if (*(int *)(param_1 + 0x42) < *(int *)(param_1 + 0x52)) {
    local_28 = *(int *)(param_1 + 0x42);
  }
  else {
    local_28 = *(int *)(param_1 + 0x52);
  }
  if (*(int *)(param_1 + 0x56) < *(int *)(param_1 + 0x46)) {
    local_24 = *(int *)(param_1 + 0x46);
  }
  else {
    local_24 = *(int *)(param_1 + 0x56);
  }
  if (*(int *)(param_1 + 0x5a) < *(int *)(param_1 + 0x4a)) {
    local_20 = *(int *)(param_1 + 0x4a);
  }
  else {
    local_20 = *(int *)(param_1 + 0x5a);
  }
  DAT_0007c327 = 1;
  if (((((int)local_2c < 0) || (0xdf < local_24)) || (local_28 < 0)) || (0xe3 < local_20)) {
    if ((int)local_2c < 0) {
      FUN_000110c2(0,local_28,local_24 >> 2,local_20 - local_28);
    }
    else if (local_28 < 0) {
      FUN_000110c2(local_2c,0,(int)(local_24 - local_2c) >> 2,local_20);
    }
    else if (local_24 < 0xe0) {
      if (0xe3 < local_20) {
        FUN_000110c2(local_2c,local_28,(int)(local_24 - local_2c) >> 2,0xe4 - local_28);
      }
    }
    else {
      FUN_000110c2(local_2c & 0xfffffffc,local_28,(int)(0xe4 - local_2c) >> 2,local_20 - local_28);
    }
  }
  else {
    FUN_000110c2(local_2c,local_28,(int)(local_24 - local_2c) >> 2,local_20 - local_28);
  }
  return;
}


/* ======== Hero_EraseOld @ 00023904 ======== */

void Hero_EraseOld(int param_1)

{
  DAT_0007c326 = 1;
  *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(param_1 + 0x72);
  *(undefined4 *)(param_1 + 0x42) = *(undefined4 *)(param_1 + 0x76);
  *(uint *)(param_1 + 0x46) = (uint)**(byte **)(param_1 + 0xc) * 4 + *(int *)(param_1 + 0x72) + 3;
  *(uint *)(param_1 + 0x4a) =
       *(int *)(param_1 + 0x76) + (uint)*(byte *)(*(int *)(param_1 + 0xc) + 1);
  if ((((*(int *)(param_1 + 0x3e) < 0) || (*(int *)(param_1 + 0x42) < 0)) ||
      (0xdf < *(int *)(param_1 + 0x46))) || (0xe3 < *(int *)(param_1 + 0x4a))) {
    if (*(int *)(param_1 + 0x72) < 0) {
      FUN_00011145(0,*(undefined4 *)(param_1 + 0x42),**(undefined **)(param_1 + 0xc),
                   *(undefined *)(*(int *)(param_1 + 0xc) + 1));
    }
    else if (*(int *)(param_1 + 0x76) < 0) {
      FUN_00011145(*(undefined4 *)(param_1 + 0x3e),0,**(undefined **)(param_1 + 0xc),
                   (uint)*(byte *)(*(int *)(param_1 + 0xc) + 1) + *(int *)(param_1 + 0x76));
    }
    else if (*(int *)(param_1 + 0x46) < 0xe0) {
      if (0xe3 < *(int *)(param_1 + 0x4a)) {
        FUN_00011145(*(undefined4 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x42),
                     **(undefined **)(param_1 + 0xc),0xe4 - *(int *)(param_1 + 0x42));
      }
    }
    else {
      FUN_00011145(*(uint *)(param_1 + 0x3e) & 0xfffffffc,*(undefined4 *)(param_1 + 0x42),
                   0xe4 - *(int *)(param_1 + 0x3e) >> 2,*(undefined *)(*(int *)(param_1 + 0xc) + 1))
      ;
    }
  }
  else {
    FUN_00011145(*(undefined4 *)(param_1 + 0x3e),*(undefined4 *)(param_1 + 0x42),
                 **(undefined **)(param_1 + 0xc),*(undefined *)(*(int *)(param_1 + 0xc) + 1));
  }
  return;
}


/* ======== Hero_Draw @ 00023a98 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Hero_Draw(int param_1)

{
  DAT_0007c324 = 1;
  _DAT_0007c328 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x4e) = *(undefined4 *)(param_1 + 0x7e);
  *(undefined4 *)(param_1 + 0x52) = *(undefined4 *)(param_1 + 0x82);
  *(uint *)(param_1 + 0x56) = *(int *)(param_1 + 0x4e) + (uint)**(byte **)(param_1 + 8) * 4;
  *(uint *)(param_1 + 0x5a) = *(int *)(param_1 + 0x52) + (uint)*(byte *)(*(int *)(param_1 + 8) + 1);
  if (g_heroHit == 0) {
    if ((((*(int *)(param_1 + 0x4e) < 0) || (*(int *)(param_1 + 0x52) < 0)) ||
        (0xdf < *(int *)(param_1 + 0x56))) || (0xe3 < *(int *)(param_1 + 0x5a))) {
      if (*(int *)(param_1 + 0x52) < 0) {
        FUN_00010c81(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                     *(undefined4 *)(param_1 + 8),-*(int *)(param_1 + 0x52));
      }
      else if (*(int *)(param_1 + 0x5a) < 0xe4) {
        if (*(int *)(param_1 + 0x4e) < 0) {
          FUN_00010d7f(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                       *(undefined4 *)(param_1 + 8),-*(int *)(param_1 + 0x4e));
        }
        else if (0xdf < *(int *)(param_1 + 0x56)) {
          FUN_00010e1b(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                       *(undefined4 *)(param_1 + 8),0xdf - *(int *)(param_1 + 0x4e));
        }
      }
      else {
        FUN_00010d00(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                     *(undefined4 *)(param_1 + 8),0xe4 - *(int *)(param_1 + 0x52));
      }
    }
    else {
      FUN_00010ba3(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                   *(undefined4 *)(param_1 + 8));
    }
  }
  else if (((*(int *)(param_1 + 0x4e) < 0) || (*(int *)(param_1 + 0x52) < 0)) ||
          ((0xdf < *(int *)(param_1 + 0x56) || (0xe3 < *(int *)(param_1 + 0x5a))))) {
    if (*(int *)(param_1 + 0x52) < 0) {
      FUN_00010c81(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                   *(undefined4 *)(param_1 + 8),-*(int *)(param_1 + 0x52));
    }
    else if (*(int *)(param_1 + 0x5a) < 0xe4) {
      if (*(int *)(param_1 + 0x4e) < 0) {
        FUN_00010d7f(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                     *(undefined4 *)(param_1 + 8),-*(int *)(param_1 + 0x4e));
      }
      else if (0xdf < *(int *)(param_1 + 0x56)) {
        FUN_00010e1b(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                     *(undefined4 *)(param_1 + 8),0xdf - *(int *)(param_1 + 0x4e));
      }
    }
    else {
      FUN_00010d00(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                   *(undefined4 *)(param_1 + 8),0xe4 - *(int *)(param_1 + 0x52));
    }
  }
  else {
    FUN_00010f26(*(undefined4 *)(param_1 + 0x7e),*(undefined4 *)(param_1 + 0x82),
                 *(undefined4 *)(param_1 + 8),DAT_00053430);
  }
  return;
}


/* ======== FatalError @ 00023d58 ======== */

void FatalError(undefined4 param_1,int unaff_EDX)

{
  int local_20;
  
  if (DAT_000523a7 != 0) {
    FUN_00010460();
  }
  printf();
  if (DAT_00055c80 == 0) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x14))(g_sound);
  }
  FUN_00021204();
  FUN_00021328();
  for (local_20 = 0; local_20 < unaff_EDX; local_20 = local_20 + 1) {
    printf();
  }
  exit(1);
  return;
}


/* ======== Object_Interact @ 00023e0c ======== */

void Object_Interact(int param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 8) + 2);
  uVar2 = (uint)*(byte *)(*(int *)(param_1 + 8) + 0xd);
  bVar3 = (*(byte *)(param_1 + 0xa5) & 0x20) == 0;
  if (((bVar1 & 4) != 0) && (DAT_00088988 != 0)) {
    bVar3 = false;
  }
  if (((g_keyEnter != 0) && ((bVar1 & 4) == 0)) && ((*(byte *)(param_1 + 0xa5) & 0x20) == 0)) {
    bVar3 = false;
  }
  if (!bVar3) {
    if ((*(byte *)(param_1 + 0xa6) & 0x80) != 0) {
      if ((bVar1 & 2) == 0) {
        if (((*(byte *)(param_1 + 0xa5) & 4) != 0) && ((&g_gameFlags)[uVar2] == '\0')) {
          g_keyDown = 0;
          g_keyEnter = 0;
          return;
        }
      }
      else if (uVar2 != *(uint *)(&g_pocketSlots + g_invSel * 4)) {
        (*(code *)(&PTR_FUN_00053568)[uVar2 * 2])();
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x8b) = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) | 1;
    g_keyEnter = 0;
    g_keyDown = 0;
    return;
  }
  return;
}


/* ======== Object_Think @ 00023f4c ======== */

void Object_Think(int param_1)

{
  byte *pbVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *local_50;
  uint local_24;
  
  *(undefined4 *)(param_1 + 0x7f) = *(undefined4 *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x83) = *(undefined4 *)(param_1 + 0x19);
  *(undefined4 *)(param_1 + 0x39) = *(undefined4 *)(param_1 + 0x35);
  *(undefined4 *)(param_1 + 0x41) = *(undefined4 *)(param_1 + 0x3d);
  if (*(int *)(param_1 + 0x8b) != 0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      cVar2 = *(char *)(param_1 + 0x79);
      *(char *)(param_1 + 0x79) = *(char *)(param_1 + 0x79) + -1;
      if (cVar2 == '\0') {
        *(int *)(param_1 + 0x3d) = *(int *)(param_1 + 0x3d) + 1;
        *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
        if (*(char *)(param_1 + 0x79) != -1) {
          *(uint *)(param_1 + 0x49) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 5);
          *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
          *(uint *)(param_1 + 0x51) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 7);
          *(uint *)(param_1 + 0x55) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 8);
          *(int *)(param_1 + 0x35) =
               g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
        }
      }
      if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9) != -1) {
        return;
      }
      *(undefined4 *)(param_1 + 0x93) = 1;
      *(undefined4 *)(param_1 + 0x35) = *(undefined4 *)(param_1 + 0x39);
      *(undefined4 *)(param_1 + 0x3d) = *(undefined4 *)(param_1 + 0x41);
      *(undefined4 *)(param_1 + 0x10) = 0;
      return;
    }
    iVar5 = *(int *)(param_1 + 199);
    *(int *)(param_1 + 199) = *(int *)(param_1 + 199) + 1;
    if ((iVar5 == 0) && (*(char *)(*(int *)(param_1 + 8) + 4) != '\0')) {
      (**(code **)(*(int *)(g_sound + 0x158) + 0xc))
                (g_sound,*(ushort *)(*(int *)(param_1 + 8) + 4) & 0xff);
    }
    if (*(int *)(param_1 + 0x93) != 0) {
      *(undefined4 *)(param_1 + 0x8b) = 0;
      if ((*(ushort *)(param_1 + 0xa5) & 0x4010) != 0) {
        Object_FireTrigger(param_1);
      }
      if ((*(byte *)(param_1 + 0xa5) & 0x80) == 0) {
        Object_Hide(param_1);
        *(undefined *)(param_1 + 0x7e) = 1;
        *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) & 0xfe;
        if ((*(byte *)(param_1 + 0xa6) & 1) != 0) {
          (**(code **)(*(int *)(param_1 + 4) + 0x20))(param_1);
          *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) | 1;
          *(undefined *)(param_1 + 0x7e) = 0;
        }
        *(undefined *)(*(int *)(param_1 + 8) + 8) = *(undefined *)(*(int *)(param_1 + 8) + 9);
      }
      else {
        pbVar1 = (byte *)(*(int *)(param_1 + 8) + 6);
        *pbVar1 = *pbVar1 & 0xfe;
        pbVar1 = (byte *)(*(int *)(param_1 + 8) + 7);
        *pbVar1 = *pbVar1 & 0x3f;
        *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) & 0xfe;
        *(byte *)(param_1 + 0xa6) = *(byte *)(param_1 + 0xa6) & 0x3f;
        Object_Hide(param_1);
        *(undefined *)(param_1 + 0x7e) = 1;
      }
      *(undefined4 *)(param_1 + 0x93) = 0;
      return;
    }
    if (((int)*(short *)(*(int *)(param_1 + 8) + 10) & 0x8000U) != 0) {
      *(undefined4 *)(param_1 + 0x93) = 1;
      return;
    }
    uVar4 = Bob_GroupFirstFrame((int)*(short *)(*(int *)(param_1 + 8) + 10));
    *(undefined4 *)(param_1 + 0x3d) = uVar4;
    *(int *)(param_1 + 0x35) = g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
    *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x49) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 5);
    *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x51) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 7);
    *(uint *)(param_1 + 0x55) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 8);
    *(undefined4 *)(param_1 + 0x25) = 0;
    *(undefined4 *)(param_1 + 0x29) = 0;
    *(undefined4 *)(param_1 + 0x2d) = 0;
    *(undefined4 *)(param_1 + 0x31) = 0;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    return;
  }
  if ((*(byte *)(param_1 + 0xa5) & 1) == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0xa5) & 0x40) != 0) {
    return;
  }
  if (*(int *)(param_1 + 0x9b) != 0) {
    return;
  }
  if (((*(byte *)(param_1 + 0xa5) & 1) != 0) && (*(char *)(*(int *)(param_1 + 8) + 3) == '\x03')) {
    pbVar1 = (byte *)(*(int *)(param_1 + 8) + 6);
    *pbVar1 = *pbVar1 | 0x40;
  }
  cVar2 = *(char *)(param_1 + 0x79);
  *(char *)(param_1 + 0x79) = *(char *)(param_1 + 0x79) + -1;
  if (cVar2 == '\0') {
    *(int *)(param_1 + 0x3d) = *(int *)(param_1 + 0x3d) + 1;
    *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
    if (*(char *)(param_1 + 0x79) != -1) {
      *(uint *)(param_1 + 0x49) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 5);
      *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x51) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x55) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 8);
      *(int *)(param_1 + 0x35) = g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
    }
  }
  if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9) == -1) {
    local_24 = *(int *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 1) >> 0x10;
    *(uint *)(param_1 + 0x3d) = *(uint *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 1) & 0xffff;
    *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
    while (local_24 != 0) {
      if (local_24 < (uint)(int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9)) {
        *(char *)(param_1 + 0x79) =
             *(char *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9) - (char)local_24;
        local_24 = 0;
      }
      else {
        local_24 = local_24 - (int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9);
        *(int *)(param_1 + 0x3d) = *(int *)(param_1 + 0x3d) + 1;
        *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
      }
    }
    *(uint *)(param_1 + 0x49) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x3d) * 9 + 5);
    *(uint *)(param_1 + 0x4d) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x51) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x55) = (uint)*(byte *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 8);
  }
  uVar3 = *(ushort *)(*(int *)(param_1 + 0xc) + 0x18);
  iVar5 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  if (iVar5 < (short)(uVar3 & 0x3ff)) {
    *(int *)(param_1 + 0x2d) = *(int *)(param_1 + 0x2d) + *(int *)(param_1 + 0x25);
    *(int *)(param_1 + 0x31) = *(int *)(param_1 + 0x31) + *(int *)(param_1 + 0x29);
    *(int *)(param_1 + 0x15) = *(int *)(param_1 + 0x15) + *(int *)(param_1 + 0x2d);
    *(int *)(param_1 + 0x19) = *(int *)(param_1 + 0x19) + *(int *)(param_1 + 0x31);
    *(int *)(param_1 + 0x35) = g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
    return;
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x20;
  switch((short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3800) >> 0xb) {
  case 0:
    break;
  case 1:
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))
              (g_sound,*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff);
    if (*(short *)(&DAT_00051386 +
                  (short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff) * 0x20) != 0) {
      (&DAT_0007d158)[*(int *)(param_1 + 0x7a)] = *(undefined *)(*(int *)(param_1 + 0xc) + 0x1e);
    }
    break;
  case 2:
    break;
  case 3:
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))
              (g_sound,(&DAT_0007d158)[(short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff)]
              );
  }
  *(char *)(param_1 + 0x14) = *(char *)(param_1 + 0x14) + '\x01';
  if (*(char *)(param_1 + 0x14) != *(char *)(*(int *)(param_1 + 8) + 1))
  goto switchD_00024864_caseD_4;
  switch(*(undefined *)(*(int *)(param_1 + 8) + 3)) {
  case 0:
    *(undefined4 *)(param_1 + 0x29) = 0;
    *(undefined4 *)(param_1 + 0x25) = *(undefined4 *)(param_1 + 0x29);
    *(undefined4 *)(param_1 + 0x31) = *(undefined4 *)(param_1 + 0x25);
    *(undefined4 *)(param_1 + 0x2d) = *(undefined4 *)(param_1 + 0x31);
    *(undefined4 *)(param_1 + 0x35) = *(undefined4 *)(param_1 + 0x39);
    *(undefined4 *)(param_1 + 0x3d) = *(undefined4 *)(param_1 + 0x41);
    *(undefined4 *)(param_1 + 0x9b) = 1;
    break;
  case 1:
    *(undefined *)(param_1 + 0x7e) = 1;
    break;
  case 2:
    *(undefined *)(param_1 + 0x14) = **(undefined **)(param_1 + 8);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 8) + 0xe + (uint)*(byte *)(param_1 + 0x14) * 0x20;
    switch((short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3800) >> 0xb) {
    case 0:
      break;
    case 1:
      (**(code **)(*(int *)(g_sound + 0x158) + 0xc))
                (g_sound,*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff);
      if (*(short *)(&DAT_00051386 +
                    (short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff) * 0x20) != 0) {
        (&DAT_0007d158)[*(int *)(param_1 + 0x7a)] = *(undefined *)(*(int *)(param_1 + 0xc) + 0x1e);
      }
      break;
    case 2:
      break;
    case 3:
      (**(code **)(*(int *)(g_sound + 0x158) + 0x10))
                (g_sound,(&DAT_0007d158)
                         [(short)(*(ushort *)(*(int *)(param_1 + 0xc) + 0x1e) & 0x3ff)]);
    }
    goto switchD_00024864_caseD_4;
  case 3:
    *(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) | 0x40;
    pbVar1 = (byte *)(*(int *)(param_1 + 8) + 6);
    *pbVar1 = *pbVar1 | 0x40;
    break;
  default:
    *(undefined *)(param_1 + 0x14) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + 0xe;
switchD_00024864_caseD_4:
    *(undefined4 *)(param_1 + 0x10) = 0;
    uVar4 = BobFindFrame(*(undefined4 *)(param_1 + 0xc),param_1 + 0x79);
    *(undefined4 *)(param_1 + 0x3d) = uVar4;
    if (((int)*(short *)(*(int *)(param_1 + 0xc) + 0x1c) & 0x8000U) == 0) {
      *(undefined4 *)(param_1 + 0x9f) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x9f) = 1;
    }
    *(undefined *)(param_1 + 0x79) = *(undefined *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc);
    *(int *)(param_1 + 0x35) = g_bobData + *(int *)(*(int *)(param_1 + 0x3d) * 9 + g_bobDesc + 1);
    *(undefined4 *)(param_1 + 0x15) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    *(undefined4 *)(param_1 + 0x19) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    *(undefined4 *)(param_1 + 0x25) = **(undefined4 **)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x29) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
    *(undefined4 *)(param_1 + 0x2d) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
    *(undefined4 *)(param_1 + 0x31) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
    if (((int)*(short *)(*(int *)(param_1 + 0xc) + 0x18) & 0x8000U) != 0) {
      local_50 = g_objList;
      uVar3 = *(ushort *)(*(int *)(param_1 + 0xc) + 0x18);
      for (; local_50 != (undefined4 *)0x0; local_50 = (undefined4 *)*local_50) {
        iVar5 = (**(code **)(local_50[1] + 0x10))(local_50);
        if (iVar5 == (int)(short)(uVar3 & 0x7e00) >> 10) {
          (**(code **)(local_50[1] + 0x14))(local_50,0);
          return;
        }
      }
    }
  }
  return;
}


/* ======== Hero_Think @ 00024a24 ======== */

void Hero_Think(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  *(undefined4 *)(param_1 + 0x72) = *(undefined4 *)(param_1 + 0x7e);
  *(undefined4 *)(param_1 + 0x76) = *(undefined4 *)(param_1 + 0x82);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
  iVar1 = (&DAT_0007d314)[*(int *)(param_1 + 0x7a) * 3];
  pcVar2 = (code *)(*(code *)(&g_heroStateTable)[*(int *)(param_1 + 0x7a) * 3])(&g_hero + iVar1);
  (*pcVar2)(&g_hero + iVar1);
  DAT_0008899c = 0;
  return;
}


/* ======== Hero_DamageTick @ 00024adc ======== */

void Hero_DamageTick(void)

{
  if ((g_heroHit == 0) || (g_cheatImmortal != 0)) {
    g_heroHit = 0;
  }
  else if (g_heroHitTimer == 0) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))
              (g_sound,(int)*(short *)(&DAT_000559cc + DAT_000c0050 * 2));
    DAT_000c0050 = DAT_000c0050 + 1;
    if (*(short *)(&DAT_000559cc + DAT_000c0050 * 2) == -1) {
      DAT_000c0050 = 0;
    }
    g_heroHitTimer = 4;
    g_energy = g_energy + -0x6000;
    if (g_energy < 0) {
      g_energy = 0;
      g_heroDead = 1;
      g_quitLoop = 1;
    }
    else {
      g_hudDirty._0_1_ = (byte)g_hudDirty | 1;
      DAT_00053430 = 0x1d;
    }
  }
  else {
    g_heroHitTimer = g_heroHitTimer + -1;
    if (g_heroHitTimer == 0) {
      g_heroHit = 0;
      g_heroHitTimer = 0;
    }
    else if (DAT_00053430 == 0x14) {
      DAT_00053430 = 0x1d;
    }
    else {
      DAT_00053430 = 0x14;
    }
  }
  return;
}


/* ======== HeroState00 @ 00024c08 ======== */

void HeroState00(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x401;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))();
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),1);
  if ((*(int *)(param_1 + 0x76) < *(int *)(param_1 + 0x82)) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 4;
  }
  else if (DAT_00053428 == 0) {
    if ((*(int *)(param_1 + 0x8e) < 0) && (*(int *)(param_1 + 0x92) == 0)) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 2;
    }
    else if ((*(int *)(param_1 + 0x8e) < 1) || (*(int *)(param_1 + 0x92) != 0)) {
      if (g_jetpackOn == 0) {
        if (g_keyDown != 0) {
          *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x7a) = 10;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 8;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 6;
  }
  return;
}


/* ======== HeroState01 @ 00024f98 ======== */

void HeroState01(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x403;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))();
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),1);
  if ((*(int *)(param_1 + 0x76) < *(int *)(param_1 + 0x82)) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 5;
  }
  else if (DAT_00053428 == 0) {
    if ((*(int *)(param_1 + 0x8e) < 1) || (*(int *)(param_1 + 0x92) != 0)) {
      if ((*(int *)(param_1 + 0x8e) < 0) && (*(int *)(param_1 + 0x92) == 0)) {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 0;
      }
      else if (g_jetpackOn == 0) {
        if (g_keyDown != 0) {
          *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x7a) = 0xb;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 9;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 3;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 7;
  }
  return;
}


/* ======== HeroState02 @ 00025328 ======== */

void HeroState02(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *local_28;
  uint local_20;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    DAT_000c0054 = 0;
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 3;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    g_keyUp = 0;
  }
  else {
    if ((DAT_000c0054 == 0x12) || (DAT_000c0054 == 0x23)) {
      (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    }
    DAT_000c0054 = DAT_000c0054 + 1;
    if (DAT_000c0054 == 0x25) {
      DAT_000c0054 = 0;
    }
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      local_20 = *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) >> 0x10;
      *(uint *)(param_1 + 0x10) = *(uint *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) & 0xffff;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      while (local_20 != 0) {
        if (local_20 < (uint)(int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9)) {
          *(char *)(param_1 + 0x38) =
               *(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) - (char)local_20;
          local_20 = 0;
        }
        else {
          local_20 = local_20 - (int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
        }
      }
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
      *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
    }
  }
  iVar4 = 1;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),1);
  iVar3 = *(int *)(param_1 + 0x82);
  if ((*(int *)(param_1 + 0x76) < iVar3) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  bVar2 = false;
  for (local_28 = g_objList; local_28 != (undefined4 *)0x0; local_28 = (undefined4 *)*local_28) {
    iVar3 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar3 != 0) {
      (**(code **)(local_28[1] + 0x2c))(local_28);
      bVar2 = true;
    }
    iVar4 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar5 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x11,iVar4,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar2)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar3,iVar4);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 4;
  }
  else if (DAT_00053428 == 0) {
    if ((*(int *)(param_1 + 0x8e) == 0) && (*(int *)(param_1 + 0x92) == 0)) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 0;
    }
    else if (*(int *)(param_1 + 0x8e) < 1) {
      if (g_jetpackOn == 0) {
        if (g_keyDown != 0) {
          *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x7a) = 10;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 8;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 3;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 6;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState03 @ 00025944 ======== */

void HeroState03(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *local_28;
  uint local_20;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    DAT_000c0054 = 0;
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xe;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    g_keyUp = 0;
  }
  else {
    if ((DAT_000c0054 == 0x12) || (DAT_000c0054 == 0x23)) {
      (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x2e);
    }
    DAT_000c0054 = DAT_000c0054 + 1;
    if (DAT_000c0054 == 0x25) {
      DAT_000c0054 = 0;
    }
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      local_20 = *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) >> 0x10;
      *(uint *)(param_1 + 0x10) = *(uint *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) & 0xffff;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      while (local_20 != 0) {
        if (local_20 < (uint)(int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9)) {
          *(char *)(param_1 + 0x38) =
               *(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) - (char)local_20;
          local_20 = 0;
        }
        else {
          local_20 = local_20 - (int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
        }
      }
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
      *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
    }
  }
  iVar4 = 1;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),1);
  iVar3 = *(int *)(param_1 + 0x82);
  if ((*(int *)(param_1 + 0x76) < iVar3) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  bVar2 = false;
  for (local_28 = g_objList; local_28 != (undefined4 *)0x0; local_28 = (undefined4 *)*local_28) {
    iVar3 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar3 != 0) {
      (**(code **)(local_28[1] + 0x2c))(local_28);
      bVar2 = true;
    }
    iVar4 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar5 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x11,iVar4,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar2)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar3,iVar4);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 5;
  }
  else if (DAT_00053428 == 0) {
    if ((*(int *)(param_1 + 0x8e) == 0) && (*(int *)(param_1 + 0x92) == 0)) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 1;
    }
    else if (*(int *)(param_1 + 0x8e) < 0) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 2;
    }
    else if (g_jetpackOn == 0) {
      if (g_keyDown != 0) {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 0xb;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 9;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 7;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState06 @ 00025f60 ======== */

void HeroState06(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3ed;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
  }
  *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x3851;
  if (0xa0000 < *(int *)(param_1 + 0x62)) {
    *(undefined4 **)(param_1 + 0x62) = &DAT_000a0000;
  }
  iVar3 = (*(int *)(param_1 + 0x62) >> 0x10) + 1;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),iVar3);
  iVar2 = *(int *)(param_1 + 0x82);
  if (iVar2 != *(int *)(param_1 + 0x76)) {
    DAT_00053428 = 1;
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar3 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar4 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,iVar3,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar2,iVar3);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (g_jetpackOn == 0) {
    if (DAT_00053428 == 0) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x62) = 0;
      *(undefined4 *)(param_1 + 0x92) = 0;
      *(undefined4 *)(param_1 + 0x7a) = 0;
    }
    else if (0 < *(int *)(param_1 + 0x8e)) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 7;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 8;
  }
  return;
}


/* ======== HeroState07 @ 00026274 ======== */

void HeroState07(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f1;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
  }
  *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x3851;
  if (0xa0000 < *(int *)(param_1 + 0x62)) {
    *(undefined4 **)(param_1 + 0x62) = &DAT_000a0000;
  }
  iVar3 = (*(int *)(param_1 + 0x62) >> 0x10) + 1;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),iVar3);
  iVar2 = *(int *)(param_1 + 0x82);
  if (iVar2 != *(int *)(param_1 + 0x76)) {
    DAT_00053428 = 1;
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar3 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar4 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,iVar3,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar2,iVar3);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (g_jetpackOn == 0) {
    if (DAT_00053428 == 0) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 1;
      *(undefined4 *)(param_1 + 0x62) = 0;
      *(undefined4 *)(param_1 + 0x92) = 0;
    }
    else if (*(int *)(param_1 + 0x8e) < 0) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 6;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 9;
  }
  return;
}


/* ======== HeroState10 @ 00026588 ======== */

void HeroState10(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *local_2c;
  int local_20;
  
  if (g_keyDown == 0) {
    local_20 = -1;
  }
  else {
    local_20 = 1;
  }
  DAT_000b15ac = local_20;
  DAT_00088988 = 0;
  if (*(int *)(param_1 + 0x6e) == -1) {
    DAT_0005342c = 0;
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f5;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    DAT_000b15ac = 1;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + DAT_000b15ac;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + DAT_000b15ac * -2;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (g_keyDown == 0) {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 0;
        DAT_0005342c = 1;
        return;
      }
    }
    if (g_keyDown != 0) {
      DAT_00088988 = 1;
      for (local_2c = g_objList; local_2c != (undefined4 *)0x0; local_2c = (undefined4 *)*local_2c)
      {
        iVar2 = (**(code **)(local_2c[1] + 0x28))
                          (local_2c,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                           *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                           *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                           *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
        if (iVar2 != 0) {
          (**(code **)(local_2c[1] + 0x2c))(local_2c);
        }
      }
      DAT_00088988 = 0;
    }
  }
  iVar3 = 1;
  Hero_MoveCollide(param_1,0,1);
  iVar2 = *(int *)(param_1 + 0x82);
  if ((*(int *)(param_1 + 0x76) < iVar2) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  for (local_2c = g_objList; local_2c != (undefined4 *)0x0; local_2c = (undefined4 *)*local_2c) {
    iVar3 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar4 = (**(code **)(local_2c[1] + 0x28))
                      (local_2c,0x11,iVar3,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if (g_keyEnter != 0) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar2,iVar3);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (DAT_00053428 != 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 6;
    DAT_0005342c = 1;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState11 @ 00026a00 ======== */

void HeroState11(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *local_2c;
  
  if (g_keyDown == 0) {
    DAT_000b15b0 = -1;
  }
  else {
    DAT_000b15b0 = 1;
  }
  DAT_00088988 = 0;
  if (*(int *)(param_1 + 0x6e) == -1) {
    DAT_0005342c = 0;
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f9;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    DAT_000b15b0 = 1;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + DAT_000b15b0;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + DAT_000b15b0 * -2;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (g_keyDown == 0) {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 1;
        DAT_0005342c = 1;
        return;
      }
    }
    if (g_keyDown != 0) {
      DAT_00088988 = 1;
      for (local_2c = g_objList; local_2c != (undefined4 *)0x0; local_2c = (undefined4 *)*local_2c)
      {
        iVar2 = (**(code **)(local_2c[1] + 0x28))
                          (local_2c,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                           *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                           *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                           *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
        if (iVar2 != 0) {
          (**(code **)(local_2c[1] + 0x2c))(local_2c);
        }
      }
      DAT_00088988 = 0;
    }
  }
  iVar3 = 1;
  Hero_MoveCollide(param_1,0,1);
  iVar2 = *(int *)(param_1 + 0x82);
  if ((*(int *)(param_1 + 0x76) < iVar2) && (DAT_0008899c == 0)) {
    DAT_00053428 = 1;
  }
  for (local_2c = g_objList; local_2c != (undefined4 *)0x0; local_2c = (undefined4 *)*local_2c) {
    iVar3 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar4 = (**(code **)(local_2c[1] + 0x28))
                      (local_2c,0x11,iVar3,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar2 = (int)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if (g_keyEnter != 0) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar2,iVar3);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  if (DAT_00053428 != 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 7;
    DAT_0005342c = 1;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState04 @ 00026e84 ======== */

void HeroState04(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3ed;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x62) = 0xfffb1df3;
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))();
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  DAT_0008898c = 0;
  *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x3851;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),*(int *)(param_1 + 0x62) >> 0x10);
  if ((((DAT_0008898c & 6) == 0) && (*(int *)(param_1 + 0x62) < 1)) &&
     (*(int *)(param_1 + 0x92) < 0)) {
    if (*(int *)(param_1 + 0x8e) < 1) {
      if (g_jetpackOn != 0) {
        *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x7a) = 8;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x7a) = 5;
      *(undefined4 *)(param_1 + 0x6e) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0x403;
      *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 6;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState05 @ 00027238 ======== */

void HeroState05(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_24;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f1;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x62) = 0xfffb1df3;
  }
  bVar1 = false;
  for (local_24 = g_objList; local_24 != (undefined4 *)0x0; local_24 = (undefined4 *)*local_24) {
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      (**(code **)(local_24[1] + 0x2c))(local_24);
      bVar1 = true;
    }
    iVar2 = (**(code **)(local_24[1] + 0x28))
                      (local_24,0x11,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar2 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar1)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))();
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  DAT_0008898c = 0;
  *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x3851;
  Hero_MoveCollide(param_1,*(undefined4 *)(param_1 + 0x8e),*(int *)(param_1 + 0x62) >> 0x10);
  if ((((DAT_0008898c & 6) == 0) && (*(int *)(param_1 + 0x62) < 1)) &&
     (*(int *)(param_1 + 0x92) < 0)) {
    if (*(int *)(param_1 + 0x8e) < 0) {
      *(undefined4 *)(param_1 + 0x7a) = 4;
      *(undefined4 *)(param_1 + 0x6e) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0x401;
      *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    }
    else if (g_jetpackOn != 0) {
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x7a) = 9;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 7;
    *(undefined4 *)(param_1 + 0x62) = 0;
  }
  return;
}


/* ======== HeroState08 @ 000275ec ======== */

void HeroState08(int param_1)

{
  char cVar1;
  bool bVar2;
  int extraout_EDX;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *local_28;
  uint local_20;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    DAT_000c0058 = 1;
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1b);
    g_heroDir = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3ed;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x62) = 0xfffe0000;
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      local_20 = *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) >> 0x10;
      *(uint *)(param_1 + 0x10) = *(uint *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) & 0xffff;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      while (local_20 != 0) {
        if (local_20 < (uint)(int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9)) {
          *(char *)(param_1 + 0x38) =
               *(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) - (char)local_20;
          local_20 = 0;
        }
        else {
          local_20 = local_20 - (int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
        }
      }
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
      *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
    }
  }
  if ((*(int *)(param_1 + 0x92) < 0) && (DAT_000c0058 != 2)) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1b);
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1c);
    DAT_000c0058 = 2;
  }
  if ((-1 < *(int *)(param_1 + 0x92)) && (DAT_000c0058 != 1)) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1c);
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1b);
    DAT_000c0058 = 1;
  }
  if (*(int *)(param_1 + 0x8e) < 1) {
    if (*(int *)(param_1 + 0x8e) < 0) {
      *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + -0x1800;
    }
    else if (*(int *)(param_1 + 0x8e) == 0) {
      if (*(int *)(param_1 + 0x5e) < 1) {
        if (*(int *)(param_1 + 0x5e) < 0) {
          *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + 0x400;
        }
      }
      else {
        *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + -0x400;
      }
    }
  }
  else {
    *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + 0x1800;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + -0x1800;
  }
  else {
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x1000;
  }
  if (0x30000 < *(int *)(param_1 + 0x5e)) {
    *(undefined4 *)(param_1 + 0x5e) = 0x30000;
  }
  if (0x30000 < *(int *)(param_1 + 0x62)) {
    *(undefined4 *)(param_1 + 0x62) = 0x30000;
  }
  if (*(int *)(param_1 + 0x5e) < -0x30000) {
    *(undefined4 *)(param_1 + 0x5e) = 0xfffd0000;
  }
  if (*(int *)(param_1 + 0x62) < -0x30000) {
    *(undefined4 *)(param_1 + 0x62) = 0xfffd0000;
  }
  *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x86) + *(int *)(param_1 + 0x5e);
  *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x8a) + *(int *)(param_1 + 0x62);
  DAT_0008898c = 0;
  iVar4 = (*(int *)(param_1 + 0x8a) >> 0x10) - *(int *)(param_1 + 0x82);
  Hero_MoveCollide(param_1,(*(int *)(param_1 + 0x86) >> 0x10) - *(int *)(param_1 + 0x7e),iVar4);
  if (DAT_0008898c == 4) {
    *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) >> 1;
    *(int *)(param_1 + 0x5e) = -*(int *)(param_1 + 0x5e);
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) >> 1;
    *(int *)(param_1 + 0x62) = -*(int *)(param_1 + 0x62);
    *(undefined4 *)(param_1 + 0x66) = 0;
    *(undefined4 *)(param_1 + 0x6a) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
    iVar3 = param_1;
  }
  else {
    iVar3 = extraout_EDX;
    if (DAT_0008898c == 1) {
      *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) >> 1;
      *(int *)(param_1 + 0x5e) = -*(int *)(param_1 + 0x5e);
      *(undefined4 *)(param_1 + 0x66) = 0;
      *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
      iVar3 = param_1;
    }
    if (DAT_0008898c == 2) {
      *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) >> 1;
      *(int *)(param_1 + 0x62) = -*(int *)(param_1 + 0x62);
      *(undefined4 *)(param_1 + 0x6a) = 0;
      *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
      iVar3 = param_1;
    }
  }
  bVar2 = false;
  for (local_28 = g_objList; local_28 != (undefined4 *)0x0; local_28 = (undefined4 *)*local_28) {
    iVar4 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar4 != 0) {
      (**(code **)(local_28[1] + 0x2c))(local_28);
      bVar2 = true;
    }
    iVar4 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar5 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x11,iVar4,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar2)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar3,iVar4);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  g_fuel = g_fuel + -0x800;
  if (g_fuel < 0) {
    g_fuel = 0;
    g_jetpackOn = 0;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 4;
  if (g_jetpackOn == 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 6;
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1b);
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1c);
  }
  else if (0 < *(int *)(param_1 + 0x8e)) {
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f1;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x7a) = 9;
    g_heroDir = 1;
  }
  return;
}


/* ======== HeroState09 @ 00027ef8 ======== */

void HeroState09(int param_1)

{
  char cVar1;
  bool bVar2;
  int extraout_EDX;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *local_28;
  uint local_20;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    DAT_000c0058 = 1;
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1b);
    g_heroDir = 1;
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3f1;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x62) = 0xfffe0000;
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      local_20 = *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) >> 0x10;
      *(uint *)(param_1 + 0x10) = *(uint *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1) & 0xffff;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      while (local_20 != 0) {
        if (local_20 < (uint)(int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9)) {
          *(char *)(param_1 + 0x38) =
               *(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) - (char)local_20;
          local_20 = 0;
        }
        else {
          local_20 = local_20 - (int)*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9);
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
          *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
        }
      }
      *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
      *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
      *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
      *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
      *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
    }
  }
  if ((*(int *)(param_1 + 0x92) < 0) && (DAT_000c0058 != 2)) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1b);
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1c);
    DAT_000c0058 = 2;
  }
  if ((-1 < *(int *)(param_1 + 0x92)) && (DAT_000c0058 != 1)) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1c);
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x1b);
    DAT_000c0058 = 1;
  }
  if (*(int *)(param_1 + 0x8e) < 1) {
    if (*(int *)(param_1 + 0x8e) < 0) {
      *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + -0x1800;
    }
    else if (*(int *)(param_1 + 0x8e) == 0) {
      if (*(int *)(param_1 + 0x5e) < 1) {
        if (*(int *)(param_1 + 0x5e) < 0) {
          *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + 0x400;
        }
      }
      else {
        *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + -0x400;
      }
    }
  }
  else {
    *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + 0x1800;
  }
  if (*(int *)(param_1 + 0x92) < 0) {
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + -0x1800;
  }
  else {
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) + 0x1000;
  }
  if (0x30000 < *(int *)(param_1 + 0x5e)) {
    *(undefined4 *)(param_1 + 0x5e) = 0x30000;
  }
  if (0x30000 < *(int *)(param_1 + 0x62)) {
    *(undefined4 *)(param_1 + 0x62) = 0x30000;
  }
  if (*(int *)(param_1 + 0x5e) < -0x30000) {
    *(undefined4 *)(param_1 + 0x5e) = 0xfffd0000;
  }
  if (*(int *)(param_1 + 0x62) < -0x30000) {
    *(undefined4 *)(param_1 + 0x62) = 0xfffd0000;
  }
  *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x86) + *(int *)(param_1 + 0x5e);
  *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x8a) + *(int *)(param_1 + 0x62);
  DAT_0008898c = 0;
  iVar4 = (*(int *)(param_1 + 0x8a) >> 0x10) - *(int *)(param_1 + 0x82);
  Hero_MoveCollide(param_1,(*(int *)(param_1 + 0x86) >> 0x10) - *(int *)(param_1 + 0x7e),iVar4);
  if (DAT_0008898c == 4) {
    *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) >> 1;
    *(int *)(param_1 + 0x5e) = -*(int *)(param_1 + 0x5e);
    *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) >> 1;
    *(int *)(param_1 + 0x62) = -*(int *)(param_1 + 0x62);
    *(undefined4 *)(param_1 + 0x66) = 0;
    *(undefined4 *)(param_1 + 0x6a) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
    iVar3 = param_1;
  }
  else {
    iVar3 = extraout_EDX;
    if (DAT_0008898c == 1) {
      *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) >> 1;
      *(int *)(param_1 + 0x5e) = -*(int *)(param_1 + 0x5e);
      *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
      *(undefined4 *)(param_1 + 0x66) = 0;
      iVar3 = param_1;
    }
    if (DAT_0008898c == 2) {
      *(int *)(param_1 + 0x62) = *(int *)(param_1 + 0x62) >> 1;
      *(int *)(param_1 + 0x62) = -*(int *)(param_1 + 0x62);
      *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
      *(undefined4 *)(param_1 + 0x6a) = 0;
      iVar3 = param_1;
    }
  }
  bVar2 = false;
  for (local_28 = g_objList; local_28 != (undefined4 *)0x0; local_28 = (undefined4 *)*local_28) {
    iVar4 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x20,*(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    if (iVar4 != 0) {
      (**(code **)(local_28[1] + 0x2c))(local_28);
      bVar2 = true;
    }
    iVar4 = *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x18);
    uVar5 = (**(code **)(local_28[1] + 0x28))
                      (local_28,0x11,iVar4,*(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x1c),
                       *(int *)(param_1 + 0x7e) + *(int *)(param_1 + 0x20),
                       *(int *)(param_1 + 0x82) + *(int *)(param_1 + 0x24));
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) {
      DAT_0007d472 = 4;
      g_heroHit = 1;
    }
  }
  if ((g_keyEnter != 0) && (!bVar2)) {
    (**(code **)(&g_itemUseTable + *(int *)(&g_pocketSlots + g_invSel * 4) * 8))
              (*(int *)(&g_pocketSlots + g_invSel * 4) * 8,iVar3,iVar4);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x92) = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
  }
  g_fuel = g_fuel + -0x800;
  if (g_fuel < 0) {
    g_fuel = 0;
    g_jetpackOn = 0;
  }
  g_hudDirty._0_1_ = (byte)g_hudDirty | 4;
  if (g_jetpackOn == 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7a) = 7;
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1b);
    (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x1c);
  }
  else if (*(int *)(param_1 + 0x8e) < 0) {
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x3ed;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x7a) = 8;
    g_heroDir = 0;
  }
  return;
}


/* ======== HeroState12 @ 00028804 ======== */

void HeroState12(void)

{
  return;
}


/* ======== HeroState13 @ 0002881c ======== */

void HeroState13(void)

{
  return;
}


/* ======== HeroState14 @ 00028834 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HeroState14(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x29);
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x441;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      g_jetpackOn = 0;
      _DAT_0007d456 = 0xf;
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      FreeRoomObjects();
      g_roomCol = g_tpDestCol;
      g_roomRow = g_tpDestRow;
      FUN_00023740(&g_hero,g_tpDestX,g_tpDestY);
      EnterRoom(g_tpDestCol,g_tpDestRow);
      DAT_0007d175 = 1;
      _g_inputX = 0;
      _g_inputY = 0;
      g_keyFire = 0;
      g_keyEnter = 0;
      g_keyDown = 0;
    }
  }
  return;
}


/* ======== HeroState15 @ 00028afc ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HeroState15(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x6e) == -1) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x29);
    *(undefined4 *)(param_1 + 0x6e) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x451;
    *(int *)(param_1 + 8) = g_bobData + *(int *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 1);
    *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
    *(uint *)(param_1 + 0x18) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 5);
    *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
    *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
    *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
    *(undefined4 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(int *)(param_1 + 0x86) = *(int *)(param_1 + 0x7e) << 0x10;
    *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x82) << 0x10;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x38);
    *(char *)(param_1 + 0x38) = *(char *)(param_1 + 0x38) + -1;
    if (cVar1 == '\0') {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      *(undefined *)(param_1 + 0x38) = *(undefined *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x38) != -1) {
        *(uint *)(param_1 + 0x18) = (uint)*(byte *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9 + 5);
        *(uint *)(param_1 + 0x1c) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 6);
        *(uint *)(param_1 + 0x20) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 7);
        *(uint *)(param_1 + 0x24) = (uint)*(byte *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 8);
        *(int *)(param_1 + 8) = g_bobData + *(int *)(*(int *)(param_1 + 0x10) * 9 + g_bobDesc + 1);
      }
    }
    if (*(char *)(g_bobDesc + *(int *)(param_1 + 0x10) * 9) == -1) {
      _DAT_0007d456 = g_heroDir + 1;
      *(undefined4 *)(param_1 + 0x6e) = 0xffffffff;
      DAT_00088984 = 1;
    }
  }
  return;
}


/* ======== FUN_00028d50 @ 00028d50 ======== */

undefined8 FUN_00028d50(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState15);
}


/* ======== FUN_00028d80 @ 00028d80 ======== */

undefined8 FUN_00028d80(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState14);
}


/* ======== FUN_00028db0 @ 00028db0 ======== */

undefined8 FUN_00028db0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState13);
}


/* ======== FUN_00028de0 @ 00028de0 ======== */

undefined8 FUN_00028de0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState12);
}


/* ======== FUN_00028e10 @ 00028e10 ======== */

undefined8 FUN_00028e10(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState11);
}


/* ======== FUN_00028e40 @ 00028e40 ======== */

undefined8 FUN_00028e40(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState10);
}


/* ======== FUN_00028e70 @ 00028e70 ======== */

undefined8 FUN_00028e70(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState09);
}


/* ======== FUN_00028ea0 @ 00028ea0 ======== */

undefined8 FUN_00028ea0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState08);
}


/* ======== FUN_00028ed0 @ 00028ed0 ======== */

undefined8 FUN_00028ed0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState07);
}


/* ======== FUN_00028f00 @ 00028f00 ======== */

undefined8 FUN_00028f00(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState06);
}


/* ======== FUN_00028f30 @ 00028f30 ======== */

undefined8 FUN_00028f30(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState05);
}


/* ======== FUN_00028f60 @ 00028f60 ======== */

undefined8 FUN_00028f60(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState04);
}


/* ======== FUN_00028f90 @ 00028f90 ======== */

undefined8 FUN_00028f90(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState03);
}


/* ======== FUN_00028fc0 @ 00028fc0 ======== */

undefined8 FUN_00028fc0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState02);
}


/* ======== FUN_00028ff0 @ 00028ff0 ======== */

undefined8 FUN_00028ff0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState01);
}


/* ======== FUN_00029020 @ 00029020 ======== */

undefined8 FUN_00029020(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,HeroState00);
}


/* ======== FUN_00029050 @ 00029050 ======== */

void FUN_00029050(int param_1)

{
  *(undefined4 *)(param_1 + 0x8b) = 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


/* ======== FUN_00029080 @ 00029080 ======== */

undefined8 FUN_00029080(int param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,*(undefined4 *)(param_1 + 0x7a));
}


/* ======== FUN_000290b0 @ 000290b0 ======== */

void FUN_000290b0(void)

{
  return;
}


/* ======== FUN_000290d0 @ 000290d0 ======== */

void FUN_000290d0(void)

{
  return;
}


/* ======== FUN_000290f0 @ 000290f0 ======== */

undefined8 FUN_000290f0(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,0xffffffff);
}


/* ======== FUN_00029120 @ 00029120 ======== */

undefined4 FUN_00029120(void)

{
  return 1;
}


/* ======== FUN_00029150 @ 00029150 ======== */

void FUN_00029150(void)

{
  return;
}


/* ======== FUN_00029170 @ 00029170 ======== */

void FUN_00029170(void)

{
  return;
}


/* ======== FUN_00029190 @ 00029190 ======== */

void FUN_00029190(void)

{
  FUN_0001d560(&g_hero);
  return;
}


/* ======== InitTileAnimTable @ 000291b0 ======== */

undefined8 InitTileAnimTable(int param_1,undefined4 unaff_EDX)

{
  short *psVar1;
  short sVar2;
  int local_20;
  short *local_1c;
  
  local_1c = &DAT_00050004;
  for (local_20 = 0; local_20 < 0x4c; local_20 = local_20 + 1) {
    *(short **)(&g_tileAnimSeq + local_20 * 4) = local_1c + 1;
    do {
      psVar1 = local_1c + 1;
      sVar2 = *local_1c;
      local_1c = psVar1;
    } while (sVar2 != -1);
    param_1 = local_20;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== DrawRoomTiles @ 00029208 ======== */

void DrawRoomTiles(int param_1,int unaff_EDX)

{
  undefined *puVar1;
  int local_24;
  int local_20;
  
  puVar1 = g_backBuffer;
  g_backBuffer = g_roomBuffer;
  for (local_20 = 0; local_20 < 6; local_20 = local_20 + 1) {
    for (local_24 = 0; local_24 < 7; local_24 = local_24 + 1) {
      DrawBackgroundTile(local_24,local_20,
                         (&DAT_0007d4c4)
                         [local_20 * 7 + param_1 * 0x11e4 + unaff_EDX * 0x1ca + local_24]);
    }
  }
  for (local_20 = 0; local_20 < 0xc; local_20 = local_20 + 1) {
    for (local_24 = 0; local_24 < 0xe; local_24 = local_24 + 1) {
      DrawPlatformTile(local_24,local_20,
                       *(undefined2 *)
                        (&DAT_0007d4ee +
                        local_20 * 0x1c + unaff_EDX * 0x1ca + param_1 * 0x11e4 + local_24 * 2));
    }
  }
  g_backBuffer = puVar1;
  DrawHudPanel();
  FUN_00011049();
  FUN_000108d5(0);
  return;
}


/* ======== EnterRoom @ 00029304 ======== */

void EnterRoom(int param_1,int unaff_EDX)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_a8;
  undefined4 *local_94;
  undefined4 local_8c;
  undefined4 *local_78;
  undefined4 local_60;
  undefined *local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_60 = DAT_00115874;
  DAT_00115874 = &local_60;
  local_5c = &DAT_00065968;
  local_58 = 0;
  local_38 = 0;
  DAT_0007d175 = 1;
  DAT_0007d3d4 = (undefined4 *)0x0;
  local_4c = (undefined4 *)0x0;
  local_34 = g_sound;
  local_1c = param_1;
  (**(code **)(*(int *)(g_sound + 0x158) + 0x24))(g_sound);
  local_54 = 0;
  while (local_54 < 0x14) {
    (&DAT_0007d158)[local_54] = 0;
    local_54 = local_54 + 1;
  }
  DrawRoomTiles(unaff_EDX,local_1c);
  for (local_54 = 0; local_54 < 0x14; local_54 = local_54 + 1) {
    if ((&DAT_0007d476)[local_54 * 4 + unaff_EDX * 0x11e4 + local_1c * 0x1ca] != -1) {
      if (local_38 == 0) {
        iVar1 = operator_new(0x18);
        if (iVar1 == 0) {
          local_78 = (undefined4 *)0x0;
        }
        else {
          local_58 = 1;
          local_78 = (undefined4 *)
                     RoomTrigger_ctor(iVar1,*(undefined4 *)
                                             (&g_roomMaps +
                                             local_54 * 4 + unaff_EDX * 0x11e4 + local_1c * 0x1ca));
          local_58 = 0;
        }
        DAT_0007d3d4 = local_78;
        local_50 = local_78;
        local_4c = local_78;
        local_38 = 1;
      }
      else {
        iVar1 = operator_new(0x18);
        if (iVar1 == 0) {
          local_8c = 0;
        }
        else {
          local_58 = 3;
          local_8c = RoomTrigger_ctor(iVar1,*(undefined4 *)
                                             (&g_roomMaps +
                                             local_54 * 4 + unaff_EDX * 0x11e4 + local_1c * 0x1ca));
          local_58 = 0;
        }
        *local_50 = local_8c;
        local_50 = (undefined4 *)*local_50;
        local_4c = local_50;
      }
    }
  }
  local_54 = 0;
  local_50 = (undefined4 *)0x0;
  local_30 = *(int *)(&g_roomDefPtr + local_1c * 0x28 + unaff_EDX * 4) + 10;
  local_2c = local_30;
  local_24 = operator_new(0xcf);
  local_20 = local_24;
  if (local_24 == 0) {
    local_94 = (undefined4 *)0x0;
  }
  else {
    local_58 = 5;
    local_94 = (undefined4 *)RoomObject_ctor(local_24,local_30,0);
    local_58 = 0;
    local_28 = local_94;
  }
  g_platformList = local_94;
  local_50 = local_94;
  for (local_54 = 1;
      local_54 < (int)(uint)**(byte **)(&g_roomDefPtr + unaff_EDX * 4 + local_1c * 0x28);
      local_54 = local_54 + 1) {
    local_30 = local_2c + (uint)*(byte *)(local_30 + 1) * 0x20 + 0xe;
    local_2c = local_30;
    iVar1 = operator_new(0xcf);
    if (iVar1 == 0) {
      local_a8 = 0;
    }
    else {
      local_58 = 7;
      local_a8 = RoomObject_ctor(iVar1,local_30,local_54);
      local_58 = 0;
    }
    *local_50 = local_a8;
    local_50 = (undefined4 *)*local_50;
    local_48 = local_50;
  }
  if (DAT_0007d3d4 == (undefined4 *)0x0) {
    g_objList = g_platformList;
  }
  else {
    g_objList = DAT_0007d3d4;
    *local_4c = g_platformList;
  }
  puVar2 = (undefined4 *)(&g_roomMaps + local_1c * 0x1ca + unaff_EDX * 0x11e4);
  puVar3 = (undefined4 *)&DAT_0008875c;
  for (iVar1 = 0x72; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = *(undefined2 *)puVar2;
  g_hudDirty = 0xff;
  DAT_00115874 = (undefined4 *)local_60;
  return;
}


/* ======== FreeRoomObjects @ 000296d0 ======== */

void FreeRoomObjects(void)

{
  undefined4 *puVar1;
  undefined4 *local_1c;
  
  local_1c = g_objList;
  while (local_1c != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_1c;
    operator_delete(local_1c);
    local_1c = puVar1;
  }
  return;
}


/* ======== TitleMenu @ 00029714 ======== */

/* WARNING: Removing unreachable block (ram,0x000297f3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TitleMenu(uint param_1,undefined4 unaff_EDX)

{
  undefined *puVar1;
  uint local_34;
  int local_2c;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  g_quitLoop = '\0';
  g_keySpace = 0;
  puVar1 = (undefined *)(*(int *)(g_bobDesc + 0x2986) + g_bobData);
  local_1c = param_1;
  while( true ) {
    if (local_1c == 0) {
      local_2c = *(int *)(g_bobDesc + 0x296b) + g_bobData;
      local_24 = 0x8b;
      local_20 = 0x59;
    }
    else if (local_1c < 2) {
      local_2c = *(int *)(g_bobDesc + 0x2974) + g_bobData;
      local_24 = 0x71;
      local_20 = 0x7a;
    }
    else if (local_1c == 2) {
      local_2c = *(int *)(g_bobDesc + 0x297d) + g_bobData;
      local_24 = 0x74;
      local_20 = 0xa0;
    }
    FUN_00010c15(0,0,puVar1);
    FUN_00010ba3(local_24,local_20,local_2c);
    FUN_000110c2(0,0xfffffffa,*puVar1,puVar1[1]);
    DAT_000cec7c = 0;
    while ((((DAT_000cec7c == 0 && (g_keyEnter == 0)) && (g_quitLoop == '\0')) && (g_keySpace == 0))
          ) {
      ProcessInput();
    }
    if (g_quitLoop != '\0') break;
    if ((g_keyEnter != 0) || (g_keySpace != 0)) {
      g_keyEnter = 0;
      g_keySpace = 0;
      _g_inputY = 0;
      g_keyDown = 0;
      local_34 = local_1c;
LAB_00029905:
      return CONCAT44(unaff_EDX,local_34);
    }
    if (DAT_000cec7c < 0) {
      if ((int)local_1c < 1) {
        local_1c = 2;
      }
      else {
        local_1c = local_1c - 1;
      }
    }
    if (0 < DAT_000cec7c) {
      if ((int)local_1c < 2) {
        local_1c = local_1c + 1;
      }
      else {
        local_1c = 0;
      }
    }
    DAT_000cec7c = 0;
  }
  local_34 = 2;
  goto LAB_00029905;
}


/* ======== ShowPCXAndWait @ 00029910 ======== */

void ShowPCXAndWait(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = malloc(&LAB_00025800);
  g_quitLoop = '\0';
  g_keyEnter = 0;
  g_keyFire = 0;
  RenderPCX(param_1,uVar1,1);
  free(uVar1);
  while ((((g_quitLoop == '\0' && (g_keyEnter == 0)) && (g_keyFire == 0)) && (g_keySpace == 0))) {
    ProcessInput();
  }
  SetModeX320x240();
  g_quitLoop = 0;
  g_keyEnter = 0;
  g_keyFire = 0;
  return;
}


/* ======== EndingCredits @ 000299bc ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EndingCredits(void)

{
  int iVar1;
  
  EndingSequence();
  free(g_backBuffer);
  free(g_roomBuffer);
  free(PTR_DAT_00051afe);
  free(g_bobDesc);
  free(g_bobData);
  iVar1 = malloc(&DAT_000a2800);
  if (iVar1 == 0) {
    _DAT_00088928 = s_Nie_powiodlo_sie_zaalokowanie_pa_0006121c;
    _DAT_0008892c = &DAT_000a2800;
    FatalError(s_Nie_moge_zaalokowac_klatki_na_sc_00061264,1);
  }
  g_quitLoop = '\0';
  g_keyEnter = 0;
  g_keyFire = 0;
  PlayModule(s_DATA39_RES_0006128b);
  RenderPCX(s_DATA40_RES_00061296,iVar1,0x640);
  free(iVar1);
  while ((((g_quitLoop == '\0' && (g_keyEnter == 0)) && (g_keyFire == 0)) && (g_keySpace == 0))) {
    ProcessInput();
  }
  StopModule();
  FUN_00010460();
  g_quitLoop = 0;
  g_keyEnter = 0;
  g_keyFire = 0;
  return;
}


/* ======== main @ 00029ad4 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(int param_1,int unaff_EDX)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined *puVar5;
  undefined8 uVar6;
  int local_a8;
  int local_90;
  int local_78;
  undefined4 local_50;
  undefined *local_4c;
  undefined4 local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_50 = DAT_00115874;
  DAT_00115874 = &local_50;
  local_4c = &DAT_000659a4;
  local_48 = 0;
  local_34 = 0;
  local_30 = 1;
  local_2c = 0;
  DAT_00000417 = DAT_00000417 & 0x8f;
  local_1c = param_1;
  FUN_00033e1b(100,0xed);
  thunk_FUN_00037417(10);
  FUN_00033e1b(100,0);
  FUN_00033e1b(0x60,0xed);
  thunk_FUN_00037417(10);
  FUN_00033e1b(0x60,0);
  g_cheatNoFrameWait = 0;
  DAT_000889b4 = 0;
  DAT_000889b8 = 0;
  g_cheatImmortal = 0;
  _DAT_000892e0 = 3;
  for (local_40 = 1; local_40 < local_1c; local_40 = local_40 + 1) {
    switch(*(undefined *)(*(int *)(local_40 * 4 + unaff_EDX) + 1)) {
    case 0x44:
    case 100:
      local_34 = 1;
      break;
    case 0x45:
    case 0x65:
      g_cheatImmortal = 1;
      break;
    case 0x47:
    case 0x67:
      DAT_000889b4 = 1;
      break;
    case 0x49:
    case 0x69:
      local_30 = 0;
      break;
    case 0x4d:
    case 0x6d:
      g_cheatFpsMeter = 1;
      break;
    case 0x52:
    case 0x72:
      local_3c = *(int *)(local_40 * 4 + unaff_EDX) + 2;
      local_38 = FUN_0003523b(local_3c);
      if ((3999 < local_38) && (local_38 < 0xabe1)) {
        DAT_00057560 = local_38;
      }
    case 0x4e:
    case 0x6e:
      _DAT_000892e0 = 0;
      break;
    case 0x53:
    case 0x73:
      bVar1 = *(byte *)(*(int *)(local_40 * 4 + unaff_EDX) + 2);
      if (bVar1 < 0x31) {
        if (bVar1 == 0x30) {
          _DAT_000892e0 = 0;
        }
        else {
LAB_00029cc8:
          _DAT_000892e0 = 0;
        }
      }
      else if (bVar1 < 0x32) {
        _DAT_000892e0 = 1;
      }
      else {
        if (bVar1 != 0x32) goto LAB_00029cc8;
        _DAT_000892e0 = 2;
      }
      break;
    case 0x54:
    case 0x74:
      g_cheatNoFrameWait = 1;
      break;
    case 0x55:
    case 0x75:
      DAT_000889b8 = 1;
      break;
    case 0x7e:
      local_2c = 1;
    }
  }
  if (local_2c == 0) {
    FUN_00010460();
    printf();
    exit(0);
  }
  if (local_34 != 0) {
    FUN_00010460();
  }
  if ((DAT_00055c80 != 0) && ((_DAT_000892e0 & 2) != 0)) {
    iVar2 = operator_new(0x15c);
    if (iVar2 == 0) {
      local_78 = 0;
    }
    else {
      local_48 = 1;
      local_78 = FUN_0002b510(iVar2);
      local_48 = 0;
    }
    local_28 = local_78;
    iVar2 = (***(code ***)(local_78 + 0x158))(local_78,local_34);
    if (iVar2 == 1) {
      g_sound = local_28;
      _DAT_000892e0 = 2;
      DAT_00055c80 = 0;
    }
    else {
      operator_delete(local_28);
    }
  }
  if ((DAT_00055c80 != 0) && ((_DAT_000892e0 & 1) != 0)) {
    iVar2 = operator_new(0x162);
    if (iVar2 == 0) {
      local_90 = 0;
    }
    else {
      local_48 = 3;
      local_90 = FUN_0002b4d0(iVar2);
      local_48 = 0;
    }
    local_28 = local_90;
    iVar2 = (***(code ***)(local_90 + 0x158))(local_90,local_34);
    if (iVar2 == 1) {
      g_sound = local_28;
      _DAT_000892e0 = 1;
      DAT_00055c80 = 0;
    }
    else {
      operator_delete(local_28);
      if (local_34 != 0) {
        printf();
      }
    }
  }
  if (DAT_00055c80 != 0) {
    iVar2 = operator_new(0x15c);
    if (iVar2 == 0) {
      local_a8 = 0;
    }
    else {
      local_48 = 5;
      local_a8 = FUN_0002b550(iVar2);
      local_48 = 0;
    }
    g_sound = local_a8;
    _DAT_000892e0 = 0;
    if (local_34 != 0) {
      printf();
    }
  }
  if (local_34 != 0) {
    printf();
    exit(0);
  }
  local_24 = g_sound;
  (**(code **)(*(int *)(g_sound + 0x158) + 0x14))(g_sound);
  FUN_00021024();
  FUN_00021290();
  g_backBuffer = (undefined *)malloc(&LAB_00012c00);
  if (g_backBuffer == (undefined *)0x0) {
    FatalError(s_HALTED__cannot_allocate_memory_f_0006137c,0);
  }
  g_keySpace = 0;
  if (local_30 != 0) {
    PlayModule(s_DATA39_RES_000613af);
    PlayIntro();
    StopModule();
  }
  local_20 = 0;
  LoadPlatformTiles();
  LoadBackgroundTiles();
  LoadHudPanel();
  iVar2 = LoadFont(s_DATA26_RES_000613ba);
  if (iVar2 == 0) {
    FatalError(s_Nie_moge_zaalokowac_pamieci_na_c_000613c5,0);
  }
  FUN_0001efd4(1);
  FUN_0001eff4(0x2a);
  FUN_0001f014(4);
  FUN_0001f118(0xffffffff);
  LoadFrames(s_DATA03_RES_000613ed);
  g_roomBuffer = (undefined *)malloc(&LAB_00012c00);
  if (g_roomBuffer == (undefined *)0x0) {
    FatalError(s_HALTED__cannot_allocate_memory_f_000613f8,0);
  }
  PTR_DAT_00051afe = (undefined *)malloc(&LAB_00012c00);
  if (PTR_DAT_00051afe == (undefined *)0x0) {
    FatalError(s_HALTED__cannot_allocate_memory_f_0006142b,0);
  }
  PTR_DAT_00051b02 = g_backBuffer;
  memset(g_backBuffer,0,&LAB_00012c00);
  puVar5 = &LAB_00012c00;
  memset(g_roomBuffer,0,&LAB_00012c00);
  LoadRoomMaps();
  InitTileAnimTable();
  SetModeX320x240();
  local_20 = 0;
  LoadPalettes();
  g_heroDead = 0;
  uVar4 = extraout_EDX;
switchD_0002a3ca_caseD_4:
  do {
    while( true ) {
      if (local_20 != 0) {
        FadePalette(&g_palMenu,&g_palBlack,10);
        StopModule();
        FUN_00021328();
        FUN_00021204();
        FUN_00010460();
        printf();
        DAT_00115874 = (undefined4 *)local_50;
        return;
      }
      PlayModule(s_DATA23_RES_00061464,uVar4,puVar5);
      SetPalette(&g_palBlack);
      ClearVRAM();
      SetPalette(&g_palMenu);
      g_keyEnter = 0;
      g_keySpace = 0;
      uVar6 = TitleMenu(0);
      uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar3 = (uint)uVar6;
      if (uVar3 != 0) break;
LAB_0002a259:
      FadePalette(&g_palMenu,&g_palBlack,3);
      StopModule();
      (**(code **)(*(int *)(g_sound + 0x158) + 8))(g_sound);
      ClearVRAM();
      LoadRoomsDef();
      g_roomCol = 7;
      g_roomRow = 0;
      Hero_InitStates(&g_hero);
      EnterRoom(g_roomCol,g_roomRow);
      FadePalette(&g_palBlack,&g_palGame,3);
      SetPalette(&g_palGame);
      g_curPalette = &g_palGame;
      _DAT_000cec74 = clock_ticks();
      g_quitLoop = 0;
      NewGameState();
      GameLoop(local_1c);
      (**(code **)(*(int *)(g_sound + 0x158) + 0x18))(g_sound);
      (**(code **)(*(int *)(g_sound + 0x158) + 0x14))(g_sound);
      free(g_roomsDef);
      puVar5 = (undefined *)0x3;
      FadePalette(g_curPalette,&g_palBlack);
      uVar4 = extraout_EDX_01;
      switch(g_heroDead) {
      case 0:
        break;
      case 1:
        ShowPCXAndWait(s_DATA20_RES_0006147a);
        uVar4 = extraout_EDX_02;
        break;
      case 2:
        local_20 = 1;
        break;
      case 3:
        EndingCredits();
        local_20 = 1;
        uVar4 = extraout_EDX_03;
      }
    }
    if (uVar3 < 2) {
      ClearVRAM();
      puVar5 = (undefined *)FUN_0002b590();
      PlayFLC(s_DATA04_RES_0006146f,4);
      uVar4 = extraout_EDX_00;
      goto switchD_0002a3ca_caseD_4;
    }
    if (uVar3 != 2) goto LAB_0002a259;
    local_20 = 1;
  } while( true );
}


/* ======== CheatAccepted @ 0002a4e0 ======== */

void CheatAccepted(void)

{
  DAT_000cec80 = 1;
  FUN_00033e1b(0x3c8,0);
  FUN_00033e1b(0x3c9,0x3f);
  FUN_00033e1b(0x3c9,0);
  FUN_00033e1b(0x3c9,0);
  return;
}


/* ======== FUN_0002a534 @ 0002a534 ======== */

void FUN_0002a534(void)

{
  DAT_000cec80 = 0;
  FUN_00033e1b(0x3c8,0);
  FUN_00033e1b(0x3c9,0);
  FUN_00033e1b(0x3c9,0);
  FUN_00033e1b(0x3c9,0);
  return;
}


/* ======== ProcessInput @ 0002a614 ======== */

/* WARNING: Removing unreachable block (ram,0x0002ad7d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessInput(void)

{
  bool bVar1;
  byte bVar2;
  uint local_40;
  undefined4 local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  bVar1 = false;
  if (DAT_000cec80 != 0) {
    FUN_0002a534();
  }
  do {
    if (bVar1) {
      return;
    }
    bVar2 = GetScancode();
    if ((bVar2 < 0x33) && (0x11 < bVar2)) {
      g_cheatHash = g_cheatHash * 0x40 + (uint)bVar2;
      if (g_cheatHash < 0x5e0c98) {
        if (g_cheatHash < 0x17830) {
          if (g_cheatHash < 0x1781f) {
            if ((g_cheatHash < 0x17) || ((0x17 < g_cheatHash && (g_cheatHash != 0x5e0))))
            goto LAB_0002a7f1;
          }
          else if ((0x1781f < g_cheatHash) &&
                  ((g_cheatHash < 0x17821 || ((0x17821 < g_cheatHash && (g_cheatHash != 0x17826)))))
                  ) {
LAB_0002a7f1:
            g_cheatHash = 0;
          }
        }
        else if (0x17830 < g_cheatHash) {
          if (g_cheatHash < 0x5e0853) {
            if ((g_cheatHash < 0x17832) || ((0x17832 < g_cheatHash && (g_cheatHash != 0x5e07d7))))
            goto LAB_0002a7f1;
          }
          else if (0x5e0853 < g_cheatHash) {
            if (g_cheatHash < 0x5e0c16) {
              if (g_cheatHash != 0x5e0996) goto LAB_0002a7f1;
            }
            else if ((0x5e0c16 < g_cheatHash) && (g_cheatHash != 0x5e0c94)) goto LAB_0002a7f1;
          }
        }
      }
      else if (0x5e0c98 < g_cheatHash) {
        if (g_cheatHash < 0x17832613) {
          if (g_cheatHash < 0x178265a1) {
            if ((g_cheatHash < 0x1781f5de) ||
               ((0x1781f5de < g_cheatHash && (g_cheatHash != 0x178214f2)))) goto LAB_0002a7f1;
          }
          else if ((0x178265a1 < g_cheatHash) &&
                  ((g_cheatHash < 0x178305a6 ||
                   ((0x178305a6 < g_cheatHash && (g_cheatHash != 0x17832512)))))) goto LAB_0002a7f1;
        }
        else if (0x17832613 < g_cheatHash) {
          if (g_cheatHash < 0xe099685e) {
            if (g_cheatHash < 0xe07d7793) goto LAB_0002a7f1;
            if (g_cheatHash < 0xe07d7794) {
              local_2c = (uint)(g_cheatInfinite == 0);
              g_cheatInfinite = local_2c;
              g_cheatHash = 0;
              CheatAccepted();
            }
            else {
              if (g_cheatHash != 0xe0853c92) goto LAB_0002a7f1;
              local_28 = (uint)(g_cheatNoFrameWait == 0);
              g_cheatNoFrameWait = local_28;
              g_cheatHash = 0;
              CheatAccepted();
            }
          }
          else if (g_cheatHash < 0xe099685f) {
            _g_weaponOwned = 1;
            _DAT_000893a0 = 1;
            _DAT_000893a4 = 1;
            _DAT_000893a8 = 1;
            _DAT_000893ac = 1;
            _DAT_000893b0 = 1;
            g_cheatHash = 0;
            CheatAccepted();
          }
          else if (g_cheatHash < 0xe0c94493) {
            if (g_cheatHash != 0xe0c169a6) goto LAB_0002a7f1;
            g_energy = 0x2f0000;
            *(undefined4 *)(&g_ammo + g_curWeapon * 4) = 0x2f0000;
            g_hudDirty = g_hudDirty | 3;
            g_cheatHash = 0;
            CheatAccepted();
          }
          else if (g_cheatHash < 0xe0c94494) {
            local_30 = (uint)(g_cheatFpsMeter == 0);
            g_cheatFpsMeter = local_30;
            g_cheatHash = 0;
            CheatAccepted();
          }
          else {
            if (g_cheatHash != 0xe0c984d4) goto LAB_0002a7f1;
            local_34 = (uint)(g_cheatImmortal == 0);
            g_cheatImmortal = local_34;
            g_cheatHash = 0;
            CheatAccepted();
          }
        }
      }
    }
    if (g_inputLocked == '\0') {
      if (bVar2 < 0x4b) {
        if (bVar2 < 0x1d) {
          if (bVar2 == 0) {
            bVar1 = true;
          }
          else if (bVar2 < 2) {
            g_quitLoop = 1;
            bVar1 = true;
          }
          else if (bVar2 == 0x1c) {
            if (g_keyDown == 0) {
              g_keyEnter = 1;
            }
            bVar1 = true;
          }
        }
        else if (bVar2 < 0x1e) {
          g_keyFire = 1;
          bVar1 = true;
        }
        else if (bVar2 < 0x34) {
          if ((bVar2 == 0x33) && (0 < g_invSel)) {
            g_invSel = g_invSel + -1;
            g_hudDirty = g_hudDirty | 8;
          }
        }
        else if (bVar2 < 0x35) {
          if (*(int *)(&g_pockets + g_invSel * 4) != 0) {
            g_invSel = g_invSel + 1;
            g_hudDirty = g_hudDirty | 8;
          }
        }
        else if (0x38 < bVar2) {
          if (bVar2 < 0x3a) {
            local_40 = (uint)(g_jetpackOn == 0);
            g_jetpackOn = local_40;
            if (g_fuel == 0) {
              g_jetpackOn = 0;
            }
            bVar1 = true;
            g_keySpace = 1;
          }
          else if (bVar2 == 0x48) {
            if (g_keyUp == 0) {
              _g_inputY = 0xffffffff;
              g_keyUp = 1;
            }
            bVar1 = true;
            DAT_000cec7c = 0xffffffff;
          }
        }
      }
      else if (bVar2 < 0x4c) {
        _g_inputX = 0xffffffff;
        bVar1 = true;
      }
      else if (bVar2 < 0xb9) {
        if (bVar2 < 0x50) {
          if (bVar2 == 0x4d) {
            _g_inputX = 1;
            bVar1 = true;
          }
        }
        else if (bVar2 < 0x51) {
          DAT_000cec7c = 1;
          g_keyDown = 1;
          bVar1 = true;
        }
        else if (0x9b < bVar2) {
          if (bVar2 < 0x9d) {
            g_keyEnter = 0;
            bVar1 = true;
          }
          else if (bVar2 == 0x9d) {
            g_keyFire = 0;
            if ((g_keyDown == 0) && (DAT_000889a0 == 0)) {
              local_3c = 1;
            }
            else {
              local_3c = 0;
            }
            DAT_0005342c = local_3c;
            bVar1 = true;
          }
        }
      }
      else if (bVar2 < 0xba) {
        g_keySpace = 0;
      }
      else if (bVar2 < 0xcb) {
        if (bVar2 == 200) {
          _g_inputY = 0;
          bVar1 = true;
          g_keyUp = 0;
        }
      }
      else if (bVar2 < 0xcc) {
        _g_inputX = 0;
        bVar1 = true;
      }
      else if (0xcc < bVar2) {
        if (bVar2 < 0xce) {
          _g_inputX = 0;
          bVar1 = true;
        }
        else if (bVar2 == 0xd0) {
          g_keyDown = 0;
          bVar1 = true;
        }
      }
    }
    if (((1 < bVar2) && (bVar2 < 8)) && ((&g_invSel)[bVar2] != 0)) {
      g_curWeapon = bVar2 - 2;
      g_hudDirty = g_hudDirty | 0x12;
      DAT_0005342c = 1;
      DAT_000892e8 = 0;
    }
  } while( true );
}


/* ======== GameLoop @ 0002ade0 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GameLoop(undefined4 param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_98;
  undefined4 local_84;
  undefined4 *local_70;
  undefined4 local_58;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  uint local_20;
  undefined4 local_1c;
  
  local_40 = DAT_00115874;
  puVar3 = &local_40;
  local_3c = &DAT_000659d0;
  local_38 = 0;
  local_2c = 0;
  local_28 = (undefined4 *)0x0;
  local_20 = 0;
  DAT_0007c32c = 1;
  DAT_00115874 = puVar3;
  local_1c = param_1;
  while (iVar4 = g_cheatNoFrameWait, g_quitLoop == '\0') {
    do {
      bVar1 = iVar4 == 0;
      iVar4 = DAT_0007c32c;
    } while (bVar1);
    DAT_0007c32c = 0;
    if (DAT_000b1598 != 0) {
      puVar3 = (undefined4 *)FUN_000303e4();
    }
    puVar2 = DAT_0007c330;
    if (g_cheatFpsMeter != 0) {
      if (DAT_0007c334 == 0) {
        DAT_0007c330 = (undefined4 *)((int)DAT_0007c330 + 1);
        puVar3 = puVar2;
      }
      else {
        local_24 = DAT_000a3b48;
        DAT_000a3b48 = (undefined4 *)0x1;
        FUN_0001ef74(0x118,0);
        Text_DrawNumber(DAT_0007c330);
        FUN_000110c2(0x118,0,4,10);
        DAT_000a3b48 = local_24;
        DAT_0007c330 = (undefined4 *)0x0;
        DAT_0007c334 = 0;
        puVar3 = local_24;
      }
    }
    if (g_hudDirty != 0) {
      Hud_Redraw(puVar3);
    }
    DAT_0007d174 = 0;
    for (local_34 = g_objList; local_34 != (undefined4 *)0x0; local_34 = (undefined4 *)*local_34) {
      (**(code **)(local_34[1] + 4))(local_34);
    }
    Hero_Draw(&g_hero);
    DAT_0007d174 = 1;
    for (local_34 = g_objList; local_34 != (undefined4 *)0x0; local_34 = (undefined4 *)*local_34) {
      (**(code **)(local_34[1] + 4))(local_34);
    }
    for (local_30 = g_bulletList; local_30 != (undefined4 *)0x0;
        local_30 = *(undefined4 **)((int)local_30 + 0x87)) {
      FUN_0003131c(local_30);
    }
    for (local_34 = g_objList; local_34 != (undefined4 *)0x0; local_34 = (undefined4 *)*local_34) {
      (**(code **)(local_34[1] + 8))(local_34);
    }
    Hero_FlushRect(&g_hero);
    for (local_30 = g_bulletList; local_30 != (undefined4 *)0x0;
        local_30 = *(undefined4 **)((int)local_30 + 0x87)) {
      FUN_00031160(local_30);
    }
    ProcessInput();
    DAT_0007d175 = '\0';
    local_28 = (undefined4 *)0x0;
    for (local_34 = g_objList; local_34 != (undefined4 *)0x0; local_34 = (undefined4 *)*local_34) {
      local_28 = (undefined4 *)((int)local_28 + 1);
      (**(code **)(local_34[1] + 0xc))(local_34);
    }
    Hero_Think(&g_hero);
    Hero_DamageTick();
    if (local_20 != 0) {
      FUN_0001d500();
      local_20 = 0;
    }
    for (local_30 = g_bulletList; local_30 != (undefined4 *)0x0;
        local_30 = *(undefined4 **)((int)local_30 + 0x87)) {
      FUN_00031714(local_30);
    }
    if ((g_quitLoop != '\0') && (g_heroDead == 0)) {
      QuitDialog();
    }
    iVar4 = (int)local_28 + 1;
    puVar3 = local_28;
    if ((g_bombActive != 0) && (g_bombTimer = g_bombTimer + -1, g_bombTimer == 0)) {
      local_28 = (undefined4 *)iVar4;
      puVar3 = (undefined4 *)Hero_Explode();
      iVar4 = (int)local_28;
    }
    local_28 = (undefined4 *)iVar4;
    if (DAT_00088984 != 0) {
      DAT_00088984 = 0;
      local_20 = (uint)(g_fuel != 0);
      g_fuel = 0;
      g_hudDirty = g_hudDirty | 4;
    }
    if (DAT_0007d175 == '\0') {
      for (local_34 = g_objList; local_34 != (undefined4 *)0x0; local_34 = (undefined4 *)*local_34)
      {
        (**(code **)local_34[1])(local_34);
      }
      Hero_EraseOld(&g_hero);
      puVar3 = g_bulletList;
      while (local_30 = puVar3, puVar3 != (undefined4 *)0x0) {
        FUN_00031260(puVar3);
        puVar3 = *(undefined4 **)((int)local_30 + 0x87);
      }
    }
    if (((g_keyFire == 0) || (DAT_0005342c == 0)) ||
       (puVar3 = (undefined4 *)(g_curWeapon * 4), (int)puVar3[0x224bd] < 1)) {
      if ((g_keyFire != 0) && (DAT_0005342c != 0)) {
        puVar3 = (undefined4 *)(**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,0x28);
        DAT_0005342c = 0;
      }
    }
    else {
      puVar3 = (undefined4 *)(int)*(short *)(&DAT_00054292 + (g_curWeapon * 2 + g_heroDir) * 0x24);
      if (puVar3 == (undefined4 *)0x0) {
        if (g_bulletList == (undefined4 *)0x0) {
          iVar4 = operator_new(0x8f);
          if (iVar4 == 0) {
            local_70 = (undefined4 *)0x0;
          }
          else {
            local_38 = 3;
            local_70 = (undefined4 *)Bullet_ctor(iVar4,g_bulletList,g_curWeapon * 2 + g_heroDir);
            local_38 = 0;
          }
          g_bulletList = local_70;
        }
        else {
          iVar4 = operator_new(0x8f);
          if (iVar4 == 0) {
            local_58 = 0;
          }
          else {
            local_38 = 1;
            local_58 = Bullet_ctor(iVar4,g_bulletList,g_curWeapon * 2 + g_heroDir);
            local_38 = 0;
          }
          *(undefined4 *)((int)g_bulletList + 0x8b) = local_58;
          g_bulletList = *(undefined4 **)((int)g_bulletList + 0x8b);
        }
        puVar3 = (undefined4 *)(g_curWeapon * 4);
        puVar3[0x224bd] = puVar3[0x224bd] - *(int *)((int)g_bulletList + 0x83);
        g_hudDirty = g_hudDirty | 2;
        g_keyFire = 0;
        DAT_0005342c = 0;
      }
      else {
        DAT_000892e4 = DAT_000892e4 + -1;
        if (DAT_000892e4 == -1) {
          if (g_bulletList == (undefined4 *)0x0) {
            iVar4 = operator_new(0x8f);
            if (iVar4 == 0) {
              local_98 = (undefined4 *)0x0;
            }
            else {
              local_38 = 7;
              local_98 = (undefined4 *)Bullet_ctor(iVar4,g_bulletList,g_curWeapon * 2 + g_heroDir);
              local_38 = 0;
            }
            g_bulletList = local_98;
          }
          else {
            iVar4 = operator_new(0x8f);
            if (iVar4 == 0) {
              local_84 = 0;
            }
            else {
              local_38 = 5;
              local_84 = Bullet_ctor(iVar4,g_bulletList,g_curWeapon * 2 + g_heroDir);
              local_38 = 0;
            }
            *(undefined4 *)((int)g_bulletList + 0x8b) = local_84;
            g_bulletList = *(undefined4 **)((int)g_bulletList + 0x8b);
          }
          puVar3 = (undefined4 *)(g_curWeapon * 4);
          puVar3[0x224bd] = puVar3[0x224bd] - *(int *)((int)g_bulletList + 0x83);
          g_hudDirty = g_hudDirty | 2;
        }
      }
    }
    if (g_cheatInfinite != 0) {
      g_fuel = 0x2f0000;
      puVar3 = (undefined4 *)(g_curWeapon * 4);
      puVar3[0x224bd] = 0x2f0000;
      g_hudDirty = g_hudDirty | 6;
    }
  }
  _DAT_000cec78 = clock_ticks();
  DAT_00115874 = (undefined4 *)local_40;
  return;
}


/* ======== FUN_0002b4a0 @ 0002b4a0 ======== */

undefined8 FUN_0002b4a0(int param_1,undefined4 unaff_EDX)

{
  *(undefined ***)(param_1 + 0x158) = &PTR_FUN_00065a84;
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0002b4d0 @ 0002b4d0 ======== */

undefined8 FUN_0002b4d0(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_0002b4a0(param_1);
  *(undefined ***)(iVar1 + 0x158) = &PTR_FUN_00065af0;
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0002b510 @ 0002b510 ======== */

undefined8 FUN_0002b510(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_0002b4a0(param_1);
  *(undefined ***)(iVar1 + 0x158) = &PTR_FUN_00065b5c;
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0002b550 @ 0002b550 ======== */

undefined8 FUN_0002b550(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_0002b4a0(param_1);
  *(undefined ***)(iVar1 + 0x158) = &PTR_FUN_00065bc8;
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0002b590 @ 0002b590 ======== */

undefined8 FUN_0002b590(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,0xffffffff);
}


/* ======== FUN_0002b5b0 @ 0002b5b0 ======== */

void FUN_0002b5b0(void)

{
  return;
}


/* ======== FUN_0002b5d0 @ 0002b5d0 ======== */

void FUN_0002b5d0(void)

{
  return;
}


/* ======== FUN_0002b5f0 @ 0002b5f0 ======== */

void FUN_0002b5f0(void)

{
  return;
}


/* ======== FUN_0002b610 @ 0002b610 ======== */

undefined4 FUN_0002b610(void)

{
  undefined4 param_5;
  
  return param_5;
}


/* ======== FUN_0002b640 @ 0002b640 ======== */

void FUN_0002b640(void)

{
  return;
}


/* ======== FUN_0002b660 @ 0002b660 ======== */

void FUN_0002b660(void)

{
  return;
}


/* ======== FUN_0002b680 @ 0002b680 ======== */

void FUN_0002b680(void)

{
  return;
}


/* ======== FUN_0002b6a0 @ 0002b6a0 ======== */

void FUN_0002b6a0(void)

{
  return;
}


/* ======== FUN_0002b6c0 @ 0002b6c0 ======== */

void FUN_0002b6c0(void)

{
  return;
}


/* ======== FUN_0002b6e0 @ 0002b6e0 ======== */

void FUN_0002b6e0(void)

{
  return;
}


/* ======== FUN_0002b700 @ 0002b700 ======== */

undefined4 FUN_0002b700(void)

{
  return 1;
}


/* ======== FUN_0002b730 @ 0002b730 ======== */

undefined4 FUN_0002b730(void)

{
  return 0;
}


/* ======== FUN_0002b750 @ 0002b750 ======== */

void FUN_0002b750(void)

{
  return;
}


/* ======== FUN_0002b770 @ 0002b770 ======== */

void FUN_0002b770(void)

{
  return;
}


/* ======== FUN_0002b790 @ 0002b790 ======== */

void FUN_0002b790(void)

{
  return;
}


/* ======== FUN_0002b7b0 @ 0002b7b0 ======== */

void FUN_0002b7b0(void)

{
  return;
}


/* ======== FUN_0002b7d0 @ 0002b7d0 ======== */

void FUN_0002b7d0(void)

{
  return;
}


/* ======== FUN_0002b7f0 @ 0002b7f0 ======== */

void FUN_0002b7f0(void)

{
  return;
}


/* ======== FUN_0002b810 @ 0002b810 ======== */

void FUN_0002b810(void)

{
  return;
}


/* ======== FUN_0002b830 @ 0002b830 ======== */

void FUN_0002b830(void)

{
  return;
}


/* ======== FUN_0002b850 @ 0002b850 ======== */

void FUN_0002b850(void)

{
  return;
}


/* ======== FUN_0002b870 @ 0002b870 ======== */

void FUN_0002b870(void)

{
  return;
}


/* ======== FUN_0002b890 @ 0002b890 ======== */

void FUN_0002b890(void)

{
  return;
}


/* ======== FUN_0002b8b0 @ 0002b8b0 ======== */

void FUN_0002b8b0(void)

{
  return;
}


/* ======== FUN_0002b8d0 @ 0002b8d0 ======== */

void FUN_0002b8d0(void)

{
  return;
}


/* ======== FUN_0002b8f0 @ 0002b8f0 ======== */

void FUN_0002b8f0(void)

{
  return;
}


/* ======== FUN_0002b910 @ 0002b910 ======== */

undefined4 FUN_0002b910(void)

{
  return 1;
}


/* ======== FUN_0002b940 @ 0002b940 ======== */

void FUN_0002b940(void)

{
  return;
}


/* ======== FUN_0002b960 @ 0002b960 ======== */

void FUN_0002b960(void)

{
  return;
}


/* ======== FUN_0002b980 @ 0002b980 ======== */

void FUN_0002b980(void)

{
  return;
}


/* ======== FUN_0002b9a0 @ 0002b9a0 ======== */

undefined4 FUN_0002b9a0(void)

{
  return 0;
}


/* ======== FUN_0002b9d0 @ 0002b9d0 ======== */

void FUN_0002b9d0(void)

{
  return;
}


/* ======== FUN_0002b9f0 @ 0002b9f0 ======== */

undefined4 FUN_0002b9f0(void)

{
  return 0;
}


/* ======== FUN_0002ba20 @ 0002ba20 ======== */

void FUN_0002ba20(void)

{
  return;
}


/* ======== FUN_0002ba40 @ 0002ba40 ======== */

void FUN_0002ba40(void)

{
  return;
}


/* ======== FUN_0002ba60 @ 0002ba60 ======== */

void FUN_0002ba60(void)

{
  return;
}


/* ======== FUN_0002badc @ 0002badc ======== */

undefined4 FUN_0002badc(int param_1,int *unaff_EDX)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  
  uVar1 = param_1 + 0x1fU & 0xffffffe0;
  local_30 = DAT_00057d57;
  while( true ) {
    if (local_30 == 0) {
      return 3;
    }
    iVar2 = FUN_0002be48(local_30 + 8);
    if ((int)uVar1 <= iVar2) break;
    local_30 = FUN_0002be48(local_30);
  }
  if ((int)(iVar2 - uVar1) < 0xc) {
    iVar2 = FUN_0002be48(local_30);
    iVar3 = FUN_0002be48(local_30 + 4);
    if (iVar2 != 0) {
      FUN_0002bdf0(iVar2 + 4,iVar3);
    }
    if (iVar3 != 0) {
      FUN_0002bdf0(iVar3,iVar2);
      iVar2 = DAT_00057d57;
    }
    DAT_00057d57 = iVar2;
    *unaff_EDX = local_30;
  }
  else {
    FUN_0002bdf0(local_30 + 8,iVar2 - uVar1);
    *unaff_EDX = local_30 + (iVar2 - uVar1);
  }
  return 1;
}


/* ======== FUN_0002bbd0 @ 0002bbd0 ======== */

void FUN_0002bbd0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
  local_2c = DAT_00057d57;
  while (local_2c != 0) {
    iVar1 = FUN_0002be48(local_2c);
    iVar2 = FUN_0002be48(local_2c + 8);
    if (local_2c + iVar2 == iVar1) {
      iVar3 = FUN_0002be48(iVar1);
      iVar1 = FUN_0002be48(iVar1 + 8);
      FUN_0002bdf0(local_2c + 8,iVar2 + iVar1);
      FUN_0002bdf0(local_2c,iVar3);
      if (iVar3 == 0) {
        local_2c = 0;
      }
      else {
        FUN_0002bdf0(iVar3 + 4,local_2c);
      }
    }
    else {
      local_2c = FUN_0002be48(local_2c);
    }
  }
  return;
}


/* ======== FUN_0002bc84 @ 0002bc84 ======== */

undefined4 FUN_0002bc84(int param_1,int unaff_EDX)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30;
  int local_2c;
  
  bVar2 = false;
  uVar1 = param_1 + 0x1fU & 0xffffffe0;
  local_2c = DAT_00057d57;
  if (DAT_00057d57 == 0) {
    DAT_00057d57 = unaff_EDX;
    FUN_0002bdf0(unaff_EDX,0);
    FUN_0002bdf0(unaff_EDX + 4,0);
    FUN_0002bdf0(unaff_EDX + 8,uVar1);
    bVar2 = true;
  }
  else {
    while ((local_2c != 0 && (!bVar2))) {
      iVar3 = FUN_0002be48(local_2c);
      iVar4 = FUN_0002be48(local_2c + 4);
      if (unaff_EDX < local_2c) {
        iVar3 = unaff_EDX;
        if (iVar4 != 0) {
          FUN_0002bdf0(iVar4,unaff_EDX);
          iVar3 = DAT_00057d57;
        }
        DAT_00057d57 = iVar3;
        FUN_0002bdf0(unaff_EDX,local_2c);
        FUN_0002bdf0(unaff_EDX + 4,iVar4);
        FUN_0002bdf0(unaff_EDX + 8,uVar1);
        FUN_0002bdf0(local_2c + 4,unaff_EDX);
        bVar2 = true;
      }
      else if (iVar3 == 0) {
        FUN_0002bdf0(local_2c,unaff_EDX);
        FUN_0002bdf0(unaff_EDX,0);
        FUN_0002bdf0(unaff_EDX + 4,local_2c);
        FUN_0002bdf0(unaff_EDX + 8,uVar1);
        bVar2 = true;
      }
      local_2c = FUN_0002be48(local_2c);
    }
  }
  if (bVar2) {
    FUN_0002bbd0();
    local_30 = 1;
  }
  else {
    local_30 = 4;
  }
  return local_30;
}


/* ======== FUN_0002bdf0 @ 0002bdf0 ======== */

undefined * FUN_0002bdf0(int param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *local_28;
  undefined *local_20;
  int local_1c;
  
  uVar1 = DAT_00057d08;
  puVar2 = &stack0xffffffe8;
  local_28 = &stack0xffffffe8;
  local_1c = param_1;
  for (local_20 = (undefined *)0x0; (int)local_20 < 4; local_20 = local_20 + 1) {
    FUN_0002d6ec(uVar1,local_1c,*local_28);
    puVar2 = local_20;
    local_28 = local_28 + 1;
    local_1c = local_1c + 1;
  }
  return puVar2;
}


/* ======== FUN_0002be48 @ 0002be48 ======== */

undefined8 FUN_0002be48(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 *puVar2;
  undefined uVar3;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  
  local_24 = DAT_00057d08;
  local_28 = &local_2c;
  local_1c = param_1;
  for (local_20 = 0; iVar1 = local_1c, local_20 < 4; local_20 = local_20 + 1) {
    local_1c = local_1c + 1;
    uVar3 = FUN_0002d650(local_24,iVar1);
    puVar2 = (undefined4 *)((int)local_28 + 1);
    *(undefined *)local_28 = uVar3;
    local_28 = puVar2;
  }
  return CONCAT44(unaff_EDX,local_2c);
}


/* ======== FUN_0002bea8 @ 0002bea8 ======== */

undefined8 FUN_0002bea8(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  undefined local_20 [4];
  int local_1c;
  
  if (0x40000 < DAT_00057d53) {
    DAT_00057d53 = 0x20;
  }
  local_1c = FUN_00031ed0();
  uVar1 = (local_1c * 0x400 + -0x20) - DAT_00057d53;
  DAT_00057d57 = DAT_00057d53;
  FUN_0002bdf0(DAT_00057d53,0);
  FUN_0002bdf0(DAT_00057d53 + 4,0);
  FUN_0002bdf0(DAT_00057d53 + 8,uVar1);
  if (0x40000 < uVar1) {
    FUN_0002badc(uVar1,local_20);
    if (0xc0000 < uVar1) {
      FUN_0002bc84(0x3ffe0,&DAT_000c0020);
    }
    if (0x80000 < uVar1) {
      FUN_0002bc84(0x3ffe0,&DAT_00080020);
    }
    FUN_0002bc84(0x3ffe0,&LAB_00040020);
    FUN_0002bc84(0x40000 - DAT_00057d53,DAT_00057d53);
  }
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_0002c190 @ 0002c190 ======== */

int FUN_0002c190(undefined4 *param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_24;
  
  DAT_00057d08 = *param_1;
  DAT_00057d0c = param_1[1];
  DAT_00057d10 = param_1[2];
  DAT_00057d14 = param_1[3];
  DAT_00057d18 = param_1[4];
  DAT_00057d4c = 0xb;
  DAT_00057d4d = (undefined)unaff_EDX;
  iVar1 = FUN_00020264(DAT_00057d08);
  if (iVar1 == 5) {
    local_24 = 5;
  }
  else {
    FUN_00032280();
    FUN_00032308();
    FUN_000321e8();
    local_24 = FUN_0002e7d0(unaff_EDX);
    if (local_24 == 1) {
      FUN_00020374(DAT_00057d0c,DAT_00057d10,DAT_00057d14,DAT_00057d18);
      FUN_00020d58(DAT_00057d14,DAT_00057d18);
      FUN_00020708(DAT_00057d14,DAT_00057d18);
      FUN_000321b8();
      FUN_0002bea8();
      local_24 = 1;
    }
  }
  return local_24;
}


/* ======== FUN_0002c284 @ 0002c284 ======== */

undefined8 FUN_0002c284(undefined4 param_1,undefined4 unaff_EDX)

{
  FUN_000321e8();
  FUN_00032280();
  FUN_00032308();
  FUN_0002e7d0(0xe);
  FUN_00020830(DAT_00057d14,DAT_00057d18);
  FUN_0002067c(DAT_00057d14,DAT_00057d18);
  return CONCAT44(unaff_EDX,1);
}


/* ======== NewGameState @ 0002c300 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NewGameState(void)

{
  int iVar1;
  int local_1c;
  
  FUN_0003531e(_DAT_0000046c);
  memset(&g_gameFlags,0,0x100);
  _DAT_000893b4 = 1;
  g_invSel = 0;
  _DAT_000893b8 = 1;
  memset(&g_pocketSlots,0,0x28);
  Pocket_Add(0x18);
  _DAT_0008945c = 0;
  g_jetpackOn = 0;
  _DAT_00089460 = 0;
  _DAT_00089388 = 0;
  _DAT_00089464 = 0;
  _DAT_0007d456 = 1;
  g_fuel = 0;
  g_energy = 0x2f0000;
  g_money = 10;
  DAT_000892e8 = 0;
  local_1c = 0;
  while (local_1c < 6) {
    *(undefined4 *)(&g_ammo + local_1c * 4) = 0x2f0000;
    *(undefined4 *)(&g_weaponOwned + local_1c * 4) = DAT_000889b4;
    local_1c = local_1c + 1;
  }
  g_curWeapon = 0;
  _g_weaponOwned = 1;
  DAT_000892e4 = (uint)(byte)(&DAT_00054294)[g_heroDir * 0x24];
  DAT_00089310 = 0;
  _DAT_00089468 = 0;
  _DAT_0008946c = 0;
  _DAT_00089470 = 0;
  _DAT_00089474 = 0;
  g_cheatInfinite = DAT_000889b8;
  g_heroDead = 0;
  DAT_00089360 = 0;
  DAT_0008938c = 0;
  g_bombActive = 0;
  g_bombTimer = 3000;
  local_1c = 0;
  while (local_1c < 6) {
    *(undefined4 *)(&DAT_00089330 + local_1c * 4) = 0;
    local_1c = local_1c + 1;
  }
  _DAT_00089330 = 1;
  _DAT_00089344 = 1;
  local_1c = 0;
  while (local_1c < 6) {
    *(undefined4 *)(&DAT_0008936c + local_1c * 4) = 1;
    local_1c = local_1c + 1;
  }
  DAT_00089348 = Random(3);
  DAT_000894d0 = 0;
  DAT_000894d1 = 0;
  DAT_000894d2 = 0;
  DAT_00089368 = Random(3);
  (&DAT_000894d0)[DAT_00089368] = 1;
  DAT_00089350 = Random(0xb);
  DAT_00089354 = 0;
  DAT_00089314 = Random(3);
  iVar1 = Random(2);
  if (iVar1 == 0) {
    DAT_0008947c = 0x437;
  }
  else {
    DAT_0008947c = 0x436;
  }
  return;
}


/* ======== QuitDialog @ 0002c5a0 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QuitDialog(void)

{
  int iVar1;
  
  Dlg_Begin();
  Dlg_Print(MSG_280) /* "Czy naprawdę chcesz / wyjść z gry? / " */;
  g_menuOpt = 0x1d;
  DAT_0008931c = 0x1e;
  _DAT_00089320 = 0x1f;
  iVar1 = Dlg_Menu(/*options = MSG_252 + g_menuOpt[i]*/ 3);
  Text_Clear(0);
  if (iVar1 != 0) {
    g_quitLoop = 0;
  }
  Dlg_End();
  return;
}


/* ======== Hud_Redraw @ 0002c618 ======== */

void Hud_Redraw(void)

{
  undefined *puVar1;
  
  if (((g_hudDirty & 1) != 0) && (-1 < g_energy)) {
    FUN_00010d00(0x104,0x6f,g_bobData + *(int *)(g_bobDesc + 0x261d),0x2f - (g_energy >> 0x10));
    FUN_00010c81(0x104,0x6f,g_bobData + *(int *)(g_bobDesc + 0x2626),0x2f - (g_energy >> 0x10));
    FUN_000110c2(0x104,0x6f,2,0x2f);
  }
  if (((g_hudDirty & 2) != 0) && (-1 < *(int *)(&g_ammo + g_curWeapon * 4))) {
    FUN_00010d00(0x114,0x6f,g_bobData + *(int *)(g_bobDesc + 0x261d),
                 0x2f - (*(int *)(&g_ammo + g_curWeapon * 4) >> 0x10));
    FUN_00010c81(0x114,0x6f,g_bobData + *(int *)(g_bobDesc + 0x2638),
                 0x2f - (*(int *)(&g_ammo + g_curWeapon * 4) >> 0x10));
    FUN_000110c2(0x114,0x6f,2,0x2f);
  }
  if (((g_hudDirty & 4) != 0) && (-1 < g_fuel)) {
    FUN_00010d00(0x124,0x6f,g_bobData + *(int *)(g_bobDesc + 0x261d),0x2f - (g_fuel >> 0x10));
    FUN_00010c81(0x124,0x6f,g_bobData + *(int *)(g_bobDesc + 0x262f),0x2f - (g_fuel >> 0x10));
    FUN_000110c2(0x124,0x6f,2,0x2f);
  }
  if ((g_hudDirty & 8) != 0) {
    puVar1 = (undefined *)
             (g_bobData +
             *(int *)(g_bobDesc +
                      (*(int *)(&DAT_00053434 + *(int *)(&g_pocketSlots + g_invSel * 4) * 8) + 0x40a
                      ) * 9 + 1));
    FUN_00010ba3(0x114,0xcc,puVar1);
    FUN_000110c2(0x114,0xcc,*puVar1,puVar1[1]);
  }
  if ((g_hudDirty & 0x10) != 0) {
    FUN_00010ba3(0xff,8,g_bobData + *(int *)((g_curWeapon * 2 + 0x428) * 9 + g_bobDesc + 1));
    FUN_000110c2(0xff,8,0xe,0x12);
  }
  g_hudDirty = 0;
  return;
}


/* ======== WaitKeyFireEnterSpace @ 0002c900 ======== */

void WaitKeyFireEnterSpace(void)

{
  char local_1c;
  
  FUN_00021454();
  FUN_00021418();
  local_1c = GetScancode();
  while (((local_1c != '\x1d' && (local_1c != '\x1c')) && (local_1c != '9'))) {
    local_1c = GetScancode();
  }
  FUN_00021494();
  return;
}


/* ======== Random @ 0002c958 ======== */

undefined8 Random(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  
  iVar1 = FUN_000352fa();
  return CONCAT44(unaff_EDX,iVar1 % param_1);
}


/* ======== FadePalette @ 0002c988 ======== */

int FadePalette(int param_1,int unaff_EDX)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_34;
  int local_2c;
  
  iVar4 = param_1;
  for (local_2c = 0; local_2c < 0x41; local_2c = local_2c + 1) {
    for (local_34 = 0; local_34 < 0x100; local_34 = local_34 + 1) {
      iVar4 = ((uint)*(byte *)(local_34 * 3 + unaff_EDX) - (uint)*(byte *)(local_34 * 3 + param_1))
              * local_2c;
      iVar5 = iVar4 >> 0x1f;
      bVar1 = *(byte *)(local_34 * 3 + param_1);
      iVar6 = ((uint)*(byte *)(local_34 * 3 + unaff_EDX + 1) -
              (uint)*(byte *)(local_34 * 3 + param_1 + 1)) * local_2c;
      iVar7 = iVar6 >> 0x1f;
      bVar2 = *(byte *)(local_34 * 3 + param_1 + 1);
      iVar8 = ((uint)*(byte *)(local_34 * 3 + unaff_EDX + 2) -
              (uint)*(byte *)(local_34 * 3 + param_1 + 2)) * local_2c;
      iVar9 = iVar8 >> 0x1f;
      bVar3 = *(byte *)(local_34 * 3 + param_1 + 2);
      FUN_00033e1b(0x3c8,local_34);
      FUN_00033e1b(0x3c9,(uint)bVar1 +
                         ((int)((iVar4 + iVar5 * -0x40) - (uint)(iVar5 << 5 < 0)) >> 6));
      FUN_00033e1b(0x3c9,(uint)bVar2 +
                         ((int)((iVar6 + iVar7 * -0x40) - (uint)(iVar7 << 5 < 0)) >> 6));
      FUN_00033e1b(0x3c9,(uint)bVar3 +
                         ((int)((iVar8 + iVar9 * -0x40) - (uint)(iVar9 << 5 < 0)) >> 6));
    }
    thunk_FUN_00037417(10);
    iVar4 = local_2c;
  }
  return iVar4;
}


/* ======== Bomb_StartSound @ 0002cadc ======== */

void Bomb_StartSound(void)

{
  Sfx_Play(0x10,0,0);
  return;
}


/* ======== Bomb_StopSound @ 0002cb00 ======== */

void Bomb_StopSound(void)

{
  (**(code **)(*(int *)(g_sound + 0x158) + 0x10))(g_sound,0x10);
  return;
}


/* ======== Delay @ 0002cb34 ======== */

void Delay(int param_1)

{
  char cVar1;
  int local_24;
  
  local_24 = 0;
  while( true ) {
    if (param_1 <= local_24) {
      return;
    }
    do {
    } while (DAT_0007c32c == 0);
    DAT_0007c32c = 0;
    cVar1 = GetScancode();
    if ((cVar1 == '\x01') || (cVar1 == '9')) break;
    local_24 = local_24 + 1;
  }
  g_quitLoop = 1;
  return;
}


/* ======== Hero_Explode @ 0002cb9c ======== */

void Hero_Explode(void)

{
  (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,5);
  SetPalette(&g_palWhite);
  FadePalette(&g_palWhite,&g_palRed,10);
  (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,6);
  SetPalette(&g_palRed);
  FadePalette(&g_palRed,&g_palBlack,0xf);
  (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,6);
  SetPalette(&g_palWhite);
  FadePalette(&g_palWhite,&g_palRed,10);
  g_curPalette = &g_palRed;
  g_quitLoop = 1;
  g_heroDead = 1;
  return;
}


/* ======== Hero_StartTeleport @ 0002cc7c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Hero_StartTeleport(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,
                       undefined4 unaff_ECX)

{
  g_tpDestCol = param_1;
  g_tpDestRow = unaff_EDX;
  g_tpDestX = unaff_EBX;
  g_tpDestY = unaff_ECX;
  g_jetpackOn = 0;
  _DAT_0007d456 = 0xe;
  _DAT_0007d44a = 0xffffffff;
  return;
}


/* ======== Weapon_Give @ 0002cd00 ======== */

void Weapon_Give(int param_1)

{
  *(undefined4 *)(&g_weaponOwned + param_1 * 4) = 1;
  DAT_000892e8 = 0;
  g_hudDirty._0_1_ = (byte)g_hudDirty | 0x10;
  g_curWeapon = param_1;
  Ammo_AddThird();
  Ammo_AddThird();
  Ammo_AddThird();
  return;
}


/* ======== Sfx_Play @ 0002cd54 ======== */

void Sfx_Play(undefined4 param_1)

{
  (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,param_1);
  return;
}


/* ======== Dlg_Begin @ 0002cd88 ======== */

void Dlg_Begin(void)

{
  if (DAT_000dd76c == 0) {
    (**(code **)(*(int *)(g_sound + 0x158) + 0x1c))(g_sound);
    PTR_DAT_00051b06 = g_backBuffer;
    PTR_DAT_00051b0a = g_roomBuffer;
    PTR_DAT_00051b0e = PTR_DAT_00051b02;
    FUN_00034682(PTR_DAT_00051afe,g_backBuffer,&LAB_00012c00);
    g_roomBuffer = g_backBuffer;
    g_backBuffer = PTR_DAT_00051afe;
    PTR_DAT_00051b02 = PTR_DAT_00051afe;
    DAT_000dd76c = 1;
  }
  return;
}


/* ======== Dlg_End @ 0002ce18 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Dlg_End(void)

{
  if (DAT_000dd76c != 0) {
    g_backBuffer = PTR_DAT_00051b06;
    g_roomBuffer = PTR_DAT_00051b0a;
    PTR_DAT_00051b02 = PTR_DAT_00051b0e;
    FUN_000108d5(0);
    DAT_000dd76c = 0;
    _g_inputX = 0;
    _g_inputY = 0;
    g_keyFire = 0;
    g_keyEnter = 0;
    FUN_00021418();
    (**(code **)(*(int *)(g_sound + 0x158) + 0x20))(g_sound);
  }
  return;
}


/* ======== Dlg_Say @ 0002ceac ======== */

void Dlg_Say(int param_1,int unaff_EDX)

{
  Text_Draw(*(undefined4 *)(unaff_EDX * 4 + param_1));
  Text_Flip();
  WaitKeyFireEnterSpace();
  Text_Clear(0);
  return;
}


/* ======== Dlg_SayKeep @ 0002ceec ======== */

void Dlg_SayKeep(int param_1,int unaff_EDX)

{
  Text_Draw(*(undefined4 *)(unaff_EDX * 4 + param_1));
  Text_Flip();
  WaitKeyFireEnterSpace();
  return;
}


/* ======== Dlg_Print @ 0002cf24 ======== */

void Dlg_Print(int param_1,int unaff_EDX)

{
  Text_Draw(*(undefined4 *)(unaff_EDX * 4 + param_1));
  Text_Flip();
  return;
}


/* ======== Dlg_Say2 @ 0002cf58 ======== */

void Dlg_Say2(undefined4 param_1,undefined4 unaff_EDX)

{
  Dlg_Say(param_1,unaff_EDX);
  return;
}


/* ======== FUN_0002cf7c @ 0002cf7c ======== */

void FUN_0002cf7c(undefined4 param_1)

{
  Text_DrawNumber(param_1);
  Text_Flip();
  return;
}


/* ======== Dlg_SayRange @ 0002cfa4 ======== */

void Dlg_SayRange(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  int local_20;
  
  for (local_20 = unaff_EDX; local_20 <= unaff_EBX; local_20 = local_20 + 1) {
    Dlg_Say(param_1,local_20);
  }
  return;
}


/* ======== Pocket_Add @ 0002cfe4 ======== */

void Pocket_Add(undefined4 param_1)

{
  int iVar1;
  int local_20;
  
  local_20 = 0;
  iVar1 = local_20;
  do {
    local_20 = iVar1;
    iVar1 = local_20 + 1;
  } while (*(int *)(&g_pocketSlots + local_20 * 4) != 0);
  if (0x28 < iVar1) {
    FatalError(s_AddPocket__Out_of_PocketTab_000614cc,0);
  }
  *(undefined4 *)(&DAT_000893b8 + iVar1 * 4) = param_1;
  g_invSel = local_20;
  g_hudDirty._0_1_ = (byte)g_hudDirty | 8;
  return;
}


/* ======== Pocket_Find @ 0002d050 ======== */

undefined8 Pocket_Find(int param_1,undefined4 unaff_EDX)

{
  int local_24;
  int local_20;
  
  for (local_20 = 0; (local_20 < 0x28 && (*(int *)(&g_pocketSlots + local_20 * 4) != param_1));
      local_20 = local_20 + 1) {
  }
  if (local_20 < 0x28) {
    local_24 = local_20;
  }
  else {
    local_24 = -1;
  }
  return CONCAT44(unaff_EDX,local_24);
}


/* ======== Pocket_Remove @ 0002d0ac ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Pocket_Remove(int param_1,undefined4 unaff_EDX)

{
  int local_20;
  
  local_20 = param_1;
  if (param_1 != -1) {
    for (; local_20 < 0x27; local_20 = local_20 + 1) {
      *(undefined4 *)(&g_pocketSlots + local_20 * 4) = *(undefined4 *)(&g_pockets + local_20 * 4);
      param_1 = local_20;
    }
    _DAT_00089458 = 0;
    g_invSel = 0;
    g_hudDirty._0_1_ = (byte)g_hudDirty | 8;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== Dlg_Menu @ 0002d11c ======== */

int Dlg_Menu(undefined4 param_1,undefined4 param_2,int unaff_EBX,int unaff_ECX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  bool bVar4;
  undefined4 local_4c;
  undefined4 local_34;
  int local_2c;
  int local_28;
  
  local_2c = 0;
  Text_Draw(&DAT_000614e9);
  uVar2 = DAT_00052393;
  uVar1 = DAT_0005238f;
  FUN_0001efa0(DAT_0005238f,DAT_00052393);
  for (local_28 = 0; local_28 < unaff_ECX; local_28 = local_28 + 1) {
    if (local_28 == 0) {
      local_34 = 0x10;
    }
    else {
      local_34 = 1;
    }
    FUN_0001efd4(local_34);
    FUN_0001f168(*(undefined4 *)((&g_menuOpt)[local_28] * 4 + unaff_EBX));
  }
  Text_Flip();
  do {
    cVar3 = GetScancode();
    bVar4 = false;
    switch(cVar3) {
    case 'G':
      bVar4 = local_2c != 0;
      local_2c = 0;
      break;
    case 'H':
      if (local_2c < 1) {
        local_2c = unaff_ECX + -1;
      }
      else {
        local_2c = local_2c + -1;
      }
      bVar4 = true;
      break;
    case 'O':
      bVar4 = local_2c != unaff_ECX;
      local_2c = unaff_ECX + -1;
      break;
    case 'P':
      local_2c = (local_2c + 1) % unaff_ECX;
      bVar4 = true;
    }
    if (bVar4) {
      FUN_0001efa0(uVar1,uVar2);
      for (local_28 = 0; local_28 < unaff_ECX; local_28 = local_28 + 1) {
        if (local_2c == local_28) {
          local_4c = 0x10;
        }
        else {
          local_4c = 1;
        }
        FUN_0001efd4(local_4c);
        FUN_0001f168(*(undefined4 *)((&g_menuOpt)[local_28] * 4 + unaff_EBX));
      }
      Text_Flip();
    }
  } while (cVar3 != '\x1c');
  return local_2c;
}


/* ======== ShowPicture @ 0002d378 ======== */

void ShowPicture(int param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  
  puVar1 = g_backBuffer;
  (**(code **)(*(int *)(g_sound + 0x158) + 0x1c))(g_sound);
  FadePalette(g_curPalette,&g_palBlack,3);
  ClearVRAM();
  g_backBuffer = (undefined *)malloc(&LAB_00012c00);
  if (g_backBuffer == (undefined *)0x0) {
    FatalError(s_HALTED__ShowPic____cannot_alloca_000614eb,0);
  }
  memset(g_backBuffer,0,&LAB_00012c00);
  pbVar2 = (byte *)(*(int *)(g_bobDesc + param_1 * 9 + 1) + g_bobData);
  FUN_00010ba3((uint)*pbVar2 * -2 + 0xa0,0x78 - ((int)(uint)pbVar2[1] >> 1),pbVar2);
  FUN_000110c2((uint)*pbVar2 * -2 + 0xa0,0x78 - ((int)(uint)pbVar2[1] >> 1),*pbVar2,pbVar2[1]);
  FadePalette(&g_palBlack,&g_palPicture,3);
  WaitKeyFireEnterSpace();
  FadePalette(&g_palPicture,&g_palBlack,3);
  g_backBuffer = puVar1;
  FUN_000108d5(0);
  FadePalette(&g_palBlack,g_curPalette,3);
  (**(code **)(*(int *)(g_sound + 0x158) + 0x20))(g_sound);
  return;
}


/* ======== SetPalette @ 0002d544 ======== */

undefined8 SetPalette(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_20;
  
  iVar1 = param_1;
  for (local_20 = 0; local_20 < 0x100; local_20 = local_20 + 1) {
    FUN_00033e1b(0x3c8,local_20);
    FUN_00033e1b(0x3c9,*(undefined *)(local_20 * 3 + param_1));
    FUN_00033e1b(0x3c9,*(undefined *)(local_20 * 3 + param_1 + 1));
    FUN_00033e1b(0x3c9,*(undefined *)(local_20 * 3 + param_1 + 2));
    iVar1 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== Money_Spend @ 0002d5c8 ======== */

void Money_Spend(int param_1)

{
  if (g_money < param_1) {
    FatalError(s_HALTED__HeroMoney_<_subtracted_a_00061526,0);
  }
  g_money = g_money - param_1;
  return;
}


/* ======== Money_Add @ 0002d600 ======== */

void Money_Add(int param_1)

{
  g_money = g_money + param_1;
  return;
}


/* ======== Pocket_Give @ 0002d624 ======== */

void Pocket_Give(undefined4 param_1)

{
  Pocket_Add(param_1);
  return;
}


/* ======== FUN_0002d650 @ 0002d650 ======== */

undefined FUN_0002d650(int param_1,int unaff_EDX)

{
  undefined uVar1;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(param_1 + 0x103,0x43);
  FUN_00033e25(param_1 + 0x104,unaff_EDX);
  FUN_00033e1b(param_1 + 0x103,0x44);
  FUN_00033e1b(param_1 + 0x105,unaff_EDX >> 0x10 & 0xff);
  uVar1 = FUN_00033e30(param_1 + 0x107);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return uVar1;
}


/* ======== FUN_0002d6ec @ 0002d6ec ======== */

void FUN_0002d6ec(int param_1,int unaff_EDX,undefined unaff_BL)

{
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(param_1 + 0x103,0x43);
  FUN_00033e25(param_1 + 0x104,unaff_EDX);
  FUN_00033e1b(param_1 + 0x103,0x44);
  FUN_00033e1b(param_1 + 0x105,unaff_EDX >> 0x10 & 0xff);
  FUN_00033e1b(param_1 + 0x107,unaff_BL);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0002d780 @ 0002d780 ======== */

void FUN_0002d780(void)

{
  FUN_0001d560(&g_hero);
  return;
}


/* ======== FileLength @ 0002d7a0 ======== */

undefined8 FileLength(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00034d7b(param_1);
  FUN_00034c7f(param_1,0,2);
  uVar2 = FUN_00034d7b(param_1);
  FUN_00034c7f(param_1,uVar1,0);
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== LoadRoomMaps @ 0002d7f4 ======== */

undefined8 LoadRoomMaps(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar1 = fopen(s_DATA29_RES_00065023,&DAT_00065020);
  if (iVar1 == 0) {
    printf();
    exit(0);
  }
  fread(&g_roomMaps,0xb2e8,1,iVar1);
  iVar1 = fclose(iVar1);
  for (local_20 = 0; local_20 < 10; local_20 = local_20 + 1) {
    for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
      for (local_28 = 0; local_28 < 0xe; local_28 = local_28 + 1) {
        for (local_24 = 0; local_24 < 0xc; local_24 = local_24 + 1) {
          *(ushort *)
           (&DAT_0007d4ee + local_28 * 2 + local_24 * 0x1c + local_20 * 0x11e4 + local_1c * 0x1ca) =
               (*(ushort *)
                 (&DAT_0007d4ee +
                 local_20 * 0x11e4 + local_1c * 0x1ca + local_24 * 0x1c + local_28 * 2) >> 8) +
               (*(ushort *)
                 (&DAT_0007d4ee +
                 local_28 * 2 + local_24 * 0x1c + local_1c * 0x1ca + local_20 * 0x11e4) % 0x100) *
               0x100;
        }
      }
    }
    iVar1 = local_20;
  }
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== LoadBackgroundTiles @ 0002d954 ======== */

undefined8 LoadBackgroundTiles(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar1 = fopen(s_DATA01_RES_00065052,&DAT_0006504f);
  FileLength(uVar1);
  uVar3 = malloc();
  DAT_00051b1a = (undefined4)uVar3;
  uVar2 = FileLength(uVar1,(int)((ulonglong)uVar3 >> 0x20),1,uVar1);
  fread(DAT_00051b1a,uVar2);
  fclose(uVar1);
  return CONCAT44(unaff_EDX,DAT_00051b1a);
}


/* ======== LoadHudPanel @ 0002d9bc ======== */

undefined8 LoadHudPanel(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar1 = fopen(s_DATA31_RES_00065060,&DAT_0006505d);
  FileLength(uVar1);
  uVar3 = malloc();
  DAT_00051b1e = (undefined4)uVar3;
  uVar2 = FileLength(uVar1,(int)((ulonglong)uVar3 >> 0x20),1,uVar1);
  fread(DAT_00051b1e,uVar2);
  fclose(uVar1);
  return CONCAT44(unaff_EDX,DAT_00051b1e);
}


/* ======== LoadPlatformTiles @ 0002da24 ======== */

undefined8 LoadPlatformTiles(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar4;
  int local_28;
  int local_24;
  
  iVar1 = fopen(s_DATA24_RES_0006506e,&DAT_0006506b);
  if (iVar1 == 0) {
    printf();
    exit(0);
  }
  uVar4 = malloc(&LAB_00030fc0);
  DAT_00051b16 = (int)uVar4;
  if (DAT_00051b16 == 0) {
    printf();
    exit(0);
    uVar4 = CONCAT44(extraout_EDX,DAT_00051b16);
  }
  DAT_00051b16 = (int)uVar4;
  uVar2 = FileLength(iVar1,(int)((ulonglong)uVar4 >> 0x20),1,iVar1);
  fread(DAT_00051b16,uVar2);
  fclose(iVar1);
  uVar2 = fopen(s_DATA32_RES_000650c6,&DAT_000650c3);
  fread(&g_tileType,0x294,1,uVar2);
  fclose(uVar2);
  for (local_28 = 0; local_28 < 0x294; local_28 = local_28 + 1) {
    if ((&g_tileType)[local_28] == '\0') {
      (&g_tileType)[local_28] = 4;
    }
  }
  uVar3 = fopen(s_DATA38_RES_000650d4,&DAT_000650d1);
  FileLength(uVar3);
  uVar4 = malloc();
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  if (iVar1 == 0) {
    FatalError(s_Nie_moge_zaalokowac_pamieci_dla_P_000650df,0);
    uVar2 = extraout_EDX_00;
  }
  uVar2 = FileLength(uVar3,uVar2,1,uVar3);
  fread(iVar1,uVar2);
  fclose(uVar3);
  local_24 = 1;
  for (local_28 = 0; local_28 < 0xa50; local_28 = local_28 + 1) {
    (&g_tileBox)[local_28] = *(undefined *)(iVar1 + local_24);
    local_24 = local_24 + 2;
  }
  free(iVar1);
  return CONCAT44(unaff_EDX,DAT_00051b16);
}


/* ======== LoadPalettes @ 0002dbc4 ======== */

void LoadPalettes(void)

{
  undefined4 uVar1;
  int local_1c;
  
  uVar1 = fopen(s_DATA25_RES_0006510e,&DAT_0006510b);
  fread(&g_palGame,0x300,1,uVar1);
  fclose(uVar1);
  uVar1 = fopen(s_DATA27_RES_0006511c,&DAT_00065119);
  fread(&g_palPicture,0x300,1,uVar1);
  fclose(uVar1);
  uVar1 = fopen(s_DATA16_RES_0006512a,&DAT_00065127);
  fread(&g_palAlarm,0x300,1,uVar1);
  fclose(uVar1);
  uVar1 = fopen(s_DATA28_RES_00065138,&DAT_00065135);
  fread(&g_palMenu,0x300,1,uVar1);
  fclose(uVar1);
  uVar1 = fopen(s_DATA19_RES_00065146,&DAT_00065143);
  fread(&g_palDATA19,0x300,1,uVar1);
  fclose(uVar1);
  g_curPalette = &g_palGame;
  SetPalette(&g_palGame);
  for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
    (&g_palRed)[local_1c * 3] = (&g_palGame)[local_1c * 3];
    (&DAT_0008aa89)[local_1c * 3] = 0;
    (&DAT_0008aa8a)[local_1c * 3] = 0;
  }
  memset(&g_palBlack,0,0x300);
  memset(&g_palWhite,0x3f,0x300);
  return;
}


/* ======== LoadFrames @ 0002dd54 ======== */

void LoadFrames(undefined4 param_1)

{
  int iVar1;
  undefined local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = param_1;
  iVar1 = fopen(param_1,&DAT_00065151);
  if (iVar1 == 0) {
    FatalError(s_Procedura_LoadFrames__Nie_znalez_00065154,0);
  }
  fread(local_24,4,1,iVar1);
  fread(&g_bobCount,4,1,iVar1);
  fread(&local_20,4,1,iVar1);
  g_bobDesc = malloc(g_bobCount * 9);
  if (g_bobDesc == 0) {
    FatalError(s_Nie_moge_zaalokowac_miejsca_na_B_0006518c,0);
  }
  g_bobData = malloc(local_20);
  if (g_bobData == 0) {
    FatalError(s_Nie_moge_zaalokowac_miejsca_na_B_000651bb,0);
  }
  fread(g_bobDesc,g_bobCount * 9,1,iVar1);
  fclose(iVar1);
  iVar1 = fopen(s_DATA02_RES_000651e8,&DAT_000651e5);
  if (iVar1 == 0) {
    FatalError(s_Procedura_LoadFrames__Nie_znalez_000651f3,0);
  }
  fread(g_bobData,local_20,1,iVar1);
  fclose(iVar1);
  return;
}


/* ======== LoadRoomsDef @ 0002de7c ======== */

undefined8 LoadRoomsDef(undefined4 param_1,undefined4 unaff_EDX)

{
  char *pcVar1;
  char cVar2;
  undefined uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int local_38;
  undefined *local_34;
  undefined *local_2c;
  char local_20;
  char local_1c;
  
  iVar4 = fopen(s_DATA30_RES_0006522a,&DAT_00065227);
  if (iVar4 == 0) {
    FatalError(s_Procedura_LoadRoomsDef__Nie_znal_00065235,0);
  }
  uVar5 = FileLength(iVar4);
  g_roomsDef = (undefined *)malloc(uVar5);
  if (g_roomsDef == (undefined *)0x0) {
    FatalError(s_Nie_moge_zaalokowac_miejsca_na_R_0006526e,0);
  }
  fread(g_roomsDef,uVar5,1,iVar4);
  fclose(iVar4);
  local_2c = g_roomsDef;
  puVar6 = g_roomsDef;
  for (local_34 = (undefined *)0x0; (int)local_34 < 10; local_34 = local_34 + 1) {
    for (local_38 = 0; local_38 < 10; local_38 = local_38 + 1) {
      *(undefined **)(&g_roomDefPtr + (int)local_34 * 4 + local_38 * 0x28) = local_2c;
      local_20 = local_2c[1];
      uVar3 = *local_2c;
      *local_2c = local_2c[1];
      local_2c[1] = uVar3;
      local_2c = local_2c + 10;
      while (cVar2 = local_20 + -1, local_20 != '\0') {
        uVar3 = local_2c[6];
        local_2c[6] = local_2c[7];
        local_2c[7] = uVar3;
        uVar3 = local_2c[10];
        local_2c[10] = local_2c[0xb];
        local_2c[0xb] = uVar3;
        uVar3 = local_2c[4];
        local_2c[4] = local_2c[5];
        local_2c[5] = uVar3;
        pcVar1 = local_2c + 1;
        local_2c = local_2c + 0xe;
        local_1c = *pcVar1;
        while (local_20 = cVar2, local_1c != '\0') {
          uVar3 = *local_2c;
          *local_2c = local_2c[3];
          local_2c[3] = uVar3;
          uVar3 = local_2c[1];
          local_2c[1] = local_2c[2];
          local_2c[2] = uVar3;
          uVar3 = local_2c[4];
          local_2c[4] = local_2c[7];
          local_2c[7] = uVar3;
          uVar3 = local_2c[5];
          local_2c[5] = local_2c[6];
          local_2c[6] = uVar3;
          uVar3 = local_2c[8];
          local_2c[8] = local_2c[0xb];
          local_2c[0xb] = uVar3;
          uVar3 = local_2c[9];
          local_2c[9] = local_2c[10];
          local_2c[10] = uVar3;
          uVar3 = local_2c[0xc];
          local_2c[0xc] = local_2c[0xf];
          local_2c[0xf] = uVar3;
          uVar3 = local_2c[0xd];
          local_2c[0xd] = local_2c[0xe];
          local_2c[0xe] = uVar3;
          uVar3 = local_2c[0x10];
          local_2c[0x10] = local_2c[0x13];
          local_2c[0x13] = uVar3;
          uVar3 = local_2c[0x11];
          local_2c[0x11] = local_2c[0x12];
          local_2c[0x12] = uVar3;
          uVar3 = local_2c[0x14];
          local_2c[0x14] = local_2c[0x17];
          local_2c[0x17] = uVar3;
          uVar3 = local_2c[0x15];
          local_2c[0x15] = local_2c[0x16];
          local_2c[0x16] = uVar3;
          uVar3 = local_2c[0x18];
          local_2c[0x18] = local_2c[0x19];
          local_2c[0x19] = uVar3;
          uVar3 = local_2c[0x1a];
          local_2c[0x1a] = local_2c[0x1b];
          local_2c[0x1b] = uVar3;
          uVar3 = local_2c[0x1c];
          local_2c[0x1c] = local_2c[0x1d];
          local_2c[0x1d] = uVar3;
          uVar3 = local_2c[0x1e];
          local_2c[0x1e] = local_2c[0x1f];
          local_2c[0x1f] = uVar3;
          local_2c = local_2c + 0x20;
          local_1c = local_1c + -1;
        }
      }
    }
    puVar6 = local_34;
  }
  return CONCAT44(unaff_EDX,puVar6);
}


/* ======== RenderPCX @ 0002e210 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderPCX(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  byte *pbVar1;
  byte **ppbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte local_98;
  byte local_94;
  int local_8c;
  int local_78;
  int local_70;
  undefined4 *local_6c;
  uint local_68;
  int local_64;
  undefined4 *local_5c;
  byte local_24;
  byte local_20;
  
  ppbVar2 = (byte **)fopen(param_1,&DAT_000652a1);
  if (ppbVar2 == (byte **)0x0) {
    _DAT_0008892c = 0;
    _DAT_00088928 = param_1;
    FatalError(s_RenderPCX__Nie_znaleziono_pliku_o_000652a4,1);
  }
  iVar3 = malloc(0x80);
  if (iVar3 == 0) {
    _DAT_0008892c = 0;
    _DAT_00088928 = param_1;
    FatalError(s_RenderPCX__Nie_moge_zaalokowac_m_000652cc,1);
  }
  iVar4 = fread(iVar3,1,0x80,ppbVar2);
  if (iVar4 == 0) {
    _DAT_0008892c = 0;
    _DAT_00088928 = param_1;
    FatalError(s_RenderPCX__Blad_odczytu_naglowka_0006530e,1);
  }
  iVar5 = ((int)*(short *)(iVar3 + 10) - (int)*(short *)(iVar3 + 6)) + 1;
  iVar4 = ((((int)*(short *)(iVar3 + 8) - (int)*(short *)(iVar3 + 4)) + 1) * iVar5) / 2;
  for (local_8c = 0; local_8c < iVar5; local_8c = local_8c + 1) {
    local_70 = 0;
    while (local_70 < 0x140) {
      if (((((int)ppbVar2[1] < 1) || ((*(byte *)(ppbVar2 + 3) & 4) != 0)) || (**ppbVar2 == 0xd)) ||
         (**ppbVar2 == 0x1a)) {
        local_94 = FUN_00034e61(ppbVar2);
      }
      else {
        ppbVar2[1] = ppbVar2[1] + -1;
        pbVar1 = *ppbVar2;
        *ppbVar2 = *ppbVar2 + 1;
        local_94 = *pbVar1;
      }
      local_24 = local_94;
      iVar6 = iVar4 >> 2;
      if (local_94 < 0xc0) {
        *(byte *)(local_70 % 0x50 + (local_70 / 0x50) * iVar6 + local_8c * 0x50 + unaff_EDX) =
             local_94;
        local_70 = local_70 + 1;
      }
      else {
        if (local_94 == 0xc0) {
          local_20 = 1;
        }
        else {
          local_20 = local_94 & 0x3f;
          if ((((int)ppbVar2[1] < 1) || ((*(byte *)(ppbVar2 + 3) & 4) != 0)) ||
             ((**ppbVar2 == 0xd || (**ppbVar2 == 0x1a)))) {
            local_98 = FUN_00034e61(ppbVar2);
          }
          else {
            ppbVar2[1] = ppbVar2[1] + -1;
            pbVar1 = *ppbVar2;
            *ppbVar2 = *ppbVar2 + 1;
            local_98 = *pbVar1;
          }
          local_24 = local_98;
        }
        for (local_78 = 0; local_78 < (int)(uint)local_20; local_78 = local_78 + 1) {
          *(byte *)(local_70 % 0x50 + (local_70 / 0x50) * iVar6 + local_8c * 0x50 + unaff_EDX) =
               local_24;
          local_70 = local_70 + 1;
        }
      }
    }
  }
  fclose(ppbVar2);
  SetMode640x480x16();
  for (local_68 = 0; (int)local_68 < 0x10; local_68 = local_68 + 1) {
    FUN_00033e1b(0x3c8,local_68 & 0xff);
    FUN_00033e1b(0x3c9,(int)(uint)*(byte *)(local_68 * 3 + iVar3 + 0x10) >> 2);
    FUN_00033e1b(0x3c9,(int)(uint)*(byte *)(local_68 * 3 + iVar3 + 0x11) >> 2);
    FUN_00033e1b(0x3c9,(int)(uint)*(byte *)(local_68 * 3 + iVar3 + 0x12) >> 2);
    FUN_00033e30(0x3da);
    FUN_00033e1b(0x3c0,local_68 & 0xff);
    FUN_00033e1b(0x3c0,local_68 & 0xff);
  }
  FUN_00033e30(0x3da);
  FUN_00033e1b(0x3c0,0x20);
  for (local_78 = 0; local_78 < unaff_EBX; local_78 = local_78 + 1) {
    ProcessInput();
    if (g_quitLoop != '\0') {
      local_78 = unaff_EBX;
    }
    FUN_000111ae();
    FUN_000111ae();
    FUN_000111ae();
    FUN_000111ae();
    FUN_00033e1b(0x3ce,8);
    FUN_00033e1b(0x3cf,0xff);
    FUN_00033e1b(0x3c4,2);
    FUN_00033e1b(0x3c5,1);
    local_5c = &DAT_000a0000;
    local_6c = (undefined4 *)(unaff_EDX + local_78 * 0x50);
    for (local_64 = 0; local_64 < 0x2580; local_64 = local_64 + 1) {
      *local_5c = *local_6c;
      local_6c = local_6c + 1;
      local_5c = local_5c + 1;
    }
    FUN_00033e1b(0x3c4,2);
    FUN_00033e1b(0x3c5,2);
    local_5c = &DAT_000a0000;
    iVar5 = iVar4 >> 4;
    local_6c = (undefined4 *)(unaff_EDX + local_78 * 0x50 + iVar5 * 4);
    for (local_64 = 0; local_64 < 0x2580; local_64 = local_64 + 1) {
      *local_5c = *local_6c;
      local_6c = local_6c + 1;
      local_5c = local_5c + 1;
    }
    FUN_00033e1b(0x3c4,2);
    FUN_00033e1b(0x3c5,4);
    local_5c = &DAT_000a0000;
    local_6c = (undefined4 *)(unaff_EDX + local_78 * 0x50 + iVar5 * 8);
    for (local_64 = 0; local_64 < 0x2580; local_64 = local_64 + 1) {
      *local_5c = *local_6c;
      local_6c = local_6c + 1;
      local_5c = local_5c + 1;
    }
    FUN_00033e1b(0x3c4,2);
    FUN_00033e1b(0x3c5,8);
    local_5c = &DAT_000a0000;
    local_6c = (undefined4 *)(unaff_EDX + local_78 * 0x50 + iVar5 * 0xc);
    for (local_64 = 0; local_64 < 0x2580; local_64 = local_64 + 1) {
      *local_5c = *local_6c;
      local_6c = local_6c + 1;
      local_5c = local_5c + 1;
    }
  }
  free(iVar3);
  return;
}


/* ======== FUN_0002e7d0 @ 0002e7d0 ======== */

undefined8 FUN_0002e7d0(int param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_30;
  int local_2c;
  char local_1c;
  
  uVar3 = DAT_00057d71;
  uVar2 = DAT_00057d6d;
  uVar1 = DAT_00057d69;
  if ((param_1 < 0xe) || (0x20 < param_1)) {
    local_30 = 2;
  }
  else {
    local_1c = (char)param_1;
    DAT_00057d4d = local_1c;
    DAT_00057d5b = 0;
    DAT_00057d5c = 0;
    FUN_0002d6ec(DAT_00057d08,0);
    FUN_0002d6ec(DAT_00057d08,1,0);
    DAT_0008adbc = DAT_0008adbc + 1;
    FUN_000350bd();
    FUN_00033e1b(uVar1,0x4c);
    iVar4 = FUN_00033e1b(uVar3,0);
    for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
      FUN_0002ebdc(iVar4);
      iVar4 = local_2c;
    }
    FUN_00033e1b(uVar1,0x4c);
    iVar4 = FUN_00033e1b(uVar3,1);
    for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
      FUN_0002ebdc(iVar4);
      iVar4 = local_2c;
    }
    iVar4 = FUN_00033e1b(DAT_00057d61,3);
    for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
      FUN_0002ebdc(iVar4);
      iVar4 = local_2c;
    }
    FUN_00033e1b(DAT_00057d61,0);
    FUN_00033e1b(uVar1,0x41);
    FUN_00033e1b(uVar3,0);
    FUN_00033e1b(uVar1,0x45);
    FUN_00033e1b(uVar3,0);
    FUN_00033e1b(uVar1,0x49);
    FUN_00033e1b(uVar3,0);
    FUN_00033e1b(uVar1,0xe);
    FUN_00033e1b(uVar3,local_1c - 1U | 0xc0);
    FUN_00033e30(DAT_00057d75);
    FUN_00033e1b(uVar1,0x41);
    FUN_00033e30(uVar3);
    FUN_00033e1b(uVar1,0x49);
    FUN_00033e30(uVar3);
    FUN_00033e1b(uVar1,0x8f);
    FUN_00033e30(uVar3);
    for (local_2c = 0; local_2c < param_1; local_2c = local_2c + 1) {
      FUN_00033e1b(DAT_00057d65,local_2c);
      FUN_00033e1b(uVar1,0);
      FUN_00033e1b(uVar3,3);
      FUN_00033e1b(uVar1,0xd);
      FUN_00033e1b(uVar3,3);
      FUN_0002ebdc();
      FUN_00033e1b(uVar1,1);
      FUN_00033e25(uVar2,0x400);
      FUN_00033e1b(uVar1,2);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,3);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,4);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,5);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,6);
      FUN_00033e1b(uVar3,1);
      FUN_00033e1b(uVar1,7);
      FUN_00033e1b(uVar3,0x10);
      FUN_00033e1b(uVar1,8);
      FUN_00033e1b(uVar3,0xe0);
      FUN_00033e1b(uVar1,9);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,10);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,0xb);
      FUN_00033e25(uVar2,0);
      FUN_00033e1b(uVar1,0xc);
      FUN_00033e1b(uVar3,7);
    }
    FUN_00033e30(DAT_00057d75);
    FUN_00033e1b(uVar1,0x41);
    FUN_00033e30(uVar3);
    FUN_00033e1b(uVar1,0x49);
    FUN_00033e30(uVar3);
    FUN_00033e1b(uVar1,0x8f);
    FUN_00033e30(uVar3);
    FUN_00033e1b(uVar1,0x4c);
    FUN_00033e1b(uVar3,7);
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
    local_30 = 1;
  }
  return CONCAT44(unaff_EDX,local_30);
}


/* ======== FUN_0002ebdc @ 0002ebdc ======== */

undefined8 FUN_0002ebdc(int param_1,undefined4 unaff_EDX)

{
  int local_1c;
  
  for (local_1c = 0; local_1c < 7; local_1c = local_1c + 1) {
    FUN_00033e30(DAT_00057d79);
    param_1 = local_1c;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0002ec14 @ 0002ec14 ======== */

uint FUN_0002ec14(uint param_1,uint unaff_EDX,byte unaff_BL)

{
  uint local_28;
  
  local_28 = ((unaff_EDX & 0x1ff) << 7 | param_1 >> 9 & 0x7f) + (unaff_EDX >> 9) * 0x10000;
  if ((unaff_BL & 4) != 0) {
    local_28 = local_28 * 2 & 0x3ffff | local_28 & 0xc0000;
  }
  return local_28;
}


/* ======== FUN_0002ec8c @ 0002ec8c ======== */

undefined8 FUN_0002ec8c(uint param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,param_1 >> 1 & 0x1ffff | param_1 & 0xc0000);
}


/* ======== FUN_0002ed00 @ 0002ed00 ======== */

void FUN_0002ed00(void)

{
  DAT_00057d04 = DAT_00057d04 & 0xef;
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  do {
  } while ((DAT_00057d04 & 4) != 0);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_0002eda8 @ 0002eda8 ======== */

undefined4 FUN_0002eda8(undefined4 param_1,undefined4 unaff_EDX,int unaff_EBX)

{
  undefined4 uVar1;
  undefined4 local_24;
  
  if (unaff_EBX == 0) {
    local_24 = 1;
  }
  else {
    local_24 = 3;
  }
  uVar1 = FUN_0001d9d4(param_1,local_24,unaff_EDX,DAT_00057d10);
  return uVar1;
}


/* ======== FUN_0002edf8 @ 0002edf8 ======== */

undefined8 FUN_0002edf8(undefined param_1,undefined4 unaff_EDX)

{
  DAT_00057d04 = DAT_00057d04 | 4;
  *(undefined *)((DAT_00057d10 + -1) * 0x4e + 0x57add) = param_1;
  FUN_0001d84c(param_1);
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_0002eeac @ 0002eeac ======== */

undefined8 FUN_0002eeac(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int local_34;
  int local_20;
  
  local_20 = 5;
  iVar1 = (param_1 + -1) * 0x4e;
  pbVar7 = &DAT_00057a90 + iVar1;
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  if ((*pbVar7 & 0x10) != 0) {
    *pbVar7 = *pbVar7 & 0xef;
    do {
      if (local_20 < 1) goto LAB_0002ef6a;
      FUN_00033e1b(*(undefined4 *)(&DAT_00057ab4 + iVar1),0);
      iVar2 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
      iVar3 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
      iVar4 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
      iVar5 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
      local_20 = local_20 + -1;
    } while (iVar3 != iVar5);
    *(uint *)(&DAT_0005739c + param_1 * 4) = ((uint)(iVar2 - iVar4) >> 1) + 2;
  }
LAB_0002ef6a:
  local_34 = 1;
  iVar2 = local_34;
  do {
    local_34 = iVar2;
    FUN_00033e1b(*(undefined4 *)(&DAT_00057ab4 + iVar1),0);
    uVar6 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
    iVar2 = FUN_00033e30(*(undefined4 *)(&DAT_00057aa8 + iVar1));
    iVar2 = uVar6 + iVar2 * 0x100;
    iVar3 = iVar2;
    if (((*(uint *)(&DAT_0005739c + param_1 * 4) < uVar6) && (uVar6 != 0xff)) || (iVar2 == 0xffff))
    break;
    iVar3 = local_34;
  } while (local_34 != iVar2);
  local_34 = iVar3;
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return CONCAT44(unaff_EDX,local_34 + 1);
}


/* ======== FUN_0002f090 @ 0002f090 ======== */

undefined4 FUN_0002f090(int param_1,int unaff_EDX)

{
  int iVar1;
  uint uVar2;
  undefined4 local_2c;
  int local_28;
  undefined2 local_20 [2];
  int local_1c;
  
  local_1c = param_1;
  if (unaff_EDX != 0) {
    printf();
    printf();
  }
  iVar1 = FUN_00030ab0();
  if ((iVar1 == 0) && (unaff_EDX != 0)) {
    printf();
    local_2c = 5;
  }
  else {
    if (unaff_EDX != 0) {
      printf();
      printf();
    }
    iVar1 = FUN_00030cd8(local_1c,DAT_000ecb20);
    if (iVar1 == 0) {
      if (unaff_EDX != 0) {
        printf();
        printf();
      }
      local_2c = 5;
    }
    else {
      if (unaff_EDX != 0) {
        printf();
        printf();
      }
      FUN_00030e7c(0xd3);
      FUN_00030804(local_1c,unaff_EDX);
      if (DAT_000ecb2c == 0) {
        if (unaff_EDX != 0) {
          printf();
        }
        FUN_00030a10(local_1c);
        local_2c = 0xc;
      }
      else {
        if (unaff_EDX != 0) {
          printf();
          printf();
        }
        iVar1 = FUN_00030670(local_1c,unaff_EDX);
        if (iVar1 == -1) {
          if (unaff_EDX != 0) {
            printf();
          }
          FUN_00030a10(local_1c);
          local_2c = 0xd;
        }
        else {
          if (unaff_EDX != 0) {
            printf();
            printf();
          }
          for (local_28 = 0; local_28 < 0x20; local_28 = local_28 + 1) {
            *(undefined4 *)(&DAT_000889d8 + local_28 * 0x40) = 0xffffffff;
            *(undefined4 *)(&DAT_000889ee + local_28 * 0x40) = 0xffffffff;
            *(undefined4 *)(local_28 * 4 + local_1c + 0xd8) = 0xffffffff;
          }
          for (local_28 = 0; local_28 < 0x36; local_28 = local_28 + 1) {
            *(undefined4 *)(local_28 * 4 + local_1c) = 0xffffffff;
          }
          *(undefined4 *)(local_1c + 0x15e) = 0;
          DAT_000ecbd4 = FUN_00020f68(0x8010,local_1c + 0x15c);
          if ((DAT_000ecbd4 == 0) || (0x10000 < (DAT_000ecbd4 & 0xffff) + 0x8010)) {
            uVar2 = FUN_00020f68(0x8010,local_20);
            if ((uVar2 == 0) || (0x10000 < (uVar2 & 0xffff) + 0x8010)) {
              FatalError(s_SOUND_SB__LoadSound__nie_powiodl_00065624,0);
            }
            FUN_00020fd4(*(undefined2 *)(local_1c + 0x15c));
            DAT_000ecbd4 = uVar2;
            *(undefined2 *)(local_1c + 0x15c) = local_20[0];
          }
          local_2c = 1;
        }
      }
    }
  }
  return local_2c;
}


/* ======== FUN_0002f390 @ 0002f390 ======== */

void FUN_0002f390(undefined4 param_1)

{
  FUN_00030cd8(param_1,DAT_000ecb20);
  FUN_00030e7c(0xd3);
  FUN_00030804(param_1,0);
  return;
}


/* ======== FUN_0002f3cc @ 0002f3cc ======== */

void FUN_0002f3cc(int param_1)

{
  int local_20;
  
  (**(code **)(*(int *)(param_1 + 0x158) + 4))(param_1);
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    *(undefined4 *)(&DAT_000889d8 + local_20 * 0x40) = 0xffffffff;
  }
  DAT_000ecbd0 = 0;
  if (*(int *)(param_1 + 0x15e) == 0) {
    Sfx_LoadBank(param_1,s_DATA41_RES_00065686,0x11568,0,0x80);
    *(undefined4 *)(param_1 + 0x15e) = 1;
  }
  FUN_0003043c(1);
  DAT_000b1598 = 1;
  return;
}


/* ======== Sfx_LoadBank @ 0002f474 ======== */

undefined4
Sfx_LoadBank(undefined4 param_1,undefined4 param_2,int unaff_EBX,undefined4 param_4,byte param_5)

{
  undefined4 uVar1;
  int local_24;
  
  uVar1 = fopen(s_DATA41_RES_00065694,&DAT_00065691);
  DAT_000ecbd8 = malloc(unaff_EBX);
  fread(DAT_000ecbd8,unaff_EBX,1,uVar1);
  fclose(uVar1);
  if ((param_5 & 0x80) != 0) {
    for (local_24 = 0; local_24 < unaff_EBX; local_24 = local_24 + 1) {
      *(char *)(DAT_000ecbd8 + local_24) = *(char *)(DAT_000ecbd8 + local_24) + -0x80;
    }
  }
  return 1;
}


/* ======== Sfx_Start @ 0002f504 ======== */

void Sfx_Start(undefined4 param_1,int unaff_EDX)

{
  int local_20;
  
  for (local_20 = 0; (*(int *)(&DAT_000889d8 + local_20 * 0x40) != -1 && (local_20 < 0x20));
      local_20 = local_20 + 1) {
  }
  if (local_20 != 0x20) {
    *(int *)(&DAT_000889d8 + local_20 * 0x40) = unaff_EDX;
    *(undefined4 *)(&DAT_000889de + local_20 * 0x40) = 0;
    *(int *)(&DAT_000889e2 + local_20 * 0x40) =
         DAT_000ecbd8 + *(int *)(&DAT_00051374 + unaff_EDX * 0x20);
    *(undefined4 *)(&DAT_000889e6 + local_20 * 0x40) =
         *(undefined4 *)(&DAT_0005137e + unaff_EDX * 0x20);
    *(int *)(&DAT_000889ea + local_20 * 0x40) = (int)*(short *)(&DAT_00051378 + unaff_EDX * 0x20);
    *(short *)(&DAT_000889dc + local_20 * 0x40) = *(short *)(&DAT_0005137a + unaff_EDX * 0x20) / 2;
    *(int *)(&DAT_000889f2 + local_20 * 0x40) = (int)*(short *)(&DAT_00051386 + unaff_EDX * 0x20);
    *(undefined4 *)(&DAT_000889f6 + local_20 * 0x40) = 0;
    *(undefined4 *)(&DAT_000889fa + local_20 * 0x40) = 0;
    *(undefined4 *)(&DAT_000889ee + local_20 * 0x40) = 0;
    if (*(short *)(&DAT_00051386 + unaff_EDX * 0x20) == 0) {
      FUN_00030650(param_1,local_20);
    }
    else {
      FUN_00030650(param_1,local_20);
    }
  }
  return;
}


/* ======== FUN_0002f654 @ 0002f654 ======== */

int FUN_0002f654(int param_1,int unaff_EDX)

{
  int local_20;
  
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(&DAT_000889d8 + local_20 * 0x40) == unaff_EDX) {
      *(undefined4 *)(&DAT_000889d8 + local_20 * 0x40) = 0xffffffff;
      DAT_000ecbd0 = DAT_000ecbd0 + -1;
    }
    param_1 = local_20;
  }
  return param_1;
}


/* ======== FUN_0002f6ac @ 0002f6ac ======== */

void FUN_0002f6ac(undefined4 param_1,int unaff_EDX)

{
  *(undefined4 *)(&DAT_000891d8 + unaff_EDX * 0x40) = 0xffffffff;
  return;
}


/* ======== FUN_0002f6d8 @ 0002f6d8 ======== */

void FUN_0002f6d8(undefined4 param_1,int unaff_EDX,undefined4 unaff_EBX)

{
  *(undefined4 *)(&DAT_000891fe + unaff_EDX * 0x40) = unaff_EBX;
  return;
}


/* ======== FUN_0002f704 @ 0002f704 ======== */

void FUN_0002f704(undefined4 param_1,int unaff_EDX,undefined2 unaff_BX)

{
  *(undefined2 *)(&DAT_000891dc + unaff_EDX * 0x40) = unaff_BX;
  return;
}


/* ======== FUN_0002f730 @ 0002f730 ======== */

void FUN_0002f730(undefined4 param_1,int unaff_EDX,int unaff_EBX,int unaff_ECX,undefined4 param_5,
                 undefined4 param_6,uint param_7)

{
  *(int *)(&DAT_000891e2 + unaff_EDX * 0x40) = unaff_ECX + unaff_EBX;
  *(undefined4 *)(&DAT_000891e6 + unaff_EDX * 0x40) = param_5;
  *(undefined4 *)(&DAT_000891ea + unaff_EDX * 0x40) = param_6;
  *(uint *)(&DAT_000891f2 + unaff_EDX * 0x40) = param_7 & 8;
  *(undefined4 *)(&DAT_000891fa + unaff_EDX * 0x40) = 0;
  *(undefined4 *)(&DAT_000891de + unaff_EDX * 0x40) = 0;
  *(int *)(&DAT_000891d8 + unaff_EDX * 0x40) = unaff_EDX;
  return;
}


/* ======== FUN_0002f7c0 @ 0002f7c0 ======== */

void FUN_0002f7c0(void)

{
  FUN_0002fa60();
  FUN_0003043c();
  return;
}


/* ======== FUN_0002f7e4 @ 0002f7e4 ======== */

void FUN_0002f7e4(void)

{
  FUN_00030508();
  return;
}


/* ======== FUN_0002f804 @ 0002f804 ======== */

undefined8 FUN_0002f804(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int local_20;
  
  DAT_000b1598 = 0;
  iVar1 = FUN_00030508();
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    *(undefined4 *)(&DAT_000889d8 + local_20 * 0x40) = 0xffffffff;
    iVar1 = local_20;
  }
  DAT_000ecbd0 = 0;
  return CONCAT44(unaff_EDX,iVar1);
}


/* ======== FUN_0002f85c @ 0002f85c ======== */

undefined8 FUN_0002f85c(int param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  int local_20;
  
  DAT_000ecbd0 = 0;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    uVar1 = *(uint *)(&DAT_000889d8 + local_20 * 0x40);
    if ((uVar1 < 0x10) || ((0x10 < uVar1 && ((uVar1 < 0x1b || (0x1c < uVar1)))))) {
      *(undefined4 *)(&DAT_000889d8 + local_20 * 0x40) = 0xffffffff;
    }
    if (*(int *)(&DAT_000889d8 + local_20 * 0x40) != -1) {
      DAT_000ecbd0 = DAT_000ecbd0 + 1;
    }
    param_1 = local_20;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0002f8f4 @ 0002f8f4 ======== */

void FUN_0002f8f4(undefined4 param_1)

{
  FUN_00030a10(param_1);
  return;
}


/* ======== FUN_0002f914 @ 0002f914 ======== */

bool FUN_0002f914(undefined4 param_1,undefined4 unaff_EDX,int *unaff_EBX)

{
  int iVar1;
  
  iVar1 = malloc(unaff_EDX);
  *unaff_EBX = iVar1;
  return *unaff_EBX != 0;
}


/* ======== FUN_0002f960 @ 0002f960 ======== */

void FUN_0002f960(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  *(int *)(&DAT_000891fe + unaff_EDX * 0x40) = unaff_EBX >> 3;
  return;
}


/* ======== FUN_0002f990 @ 0002f990 ======== */

void FUN_0002f990(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  *(int *)(&DAT_000891fe + unaff_EDX * 0x40) = unaff_EBX >> 3;
  return;
}


/* ======== FUN_0002f9bc @ 0002f9bc ======== */

void FUN_0002f9bc(undefined4 param_1,int unaff_EDX,int unaff_EBX)

{
  if (unaff_EBX == 0) {
    *(undefined4 *)(&DAT_000891d8 + unaff_EDX * 0x40) = 0xffffffff;
    *(undefined4 *)(&DAT_000891fe + unaff_EDX * 0x40) = 0;
  }
  else {
    *(undefined4 *)(&DAT_000891f2 + unaff_EDX * 0x40) = 0;
  }
  return;
}


/* ======== FUN_0002fa10 @ 0002fa10 ======== */

void FUN_0002fa10(undefined4 param_1,undefined *unaff_EDX,undefined unaff_BL)

{
  *unaff_EDX = unaff_BL;
  return;
}


/* ======== FUN_0002fa34 @ 0002fa34 ======== */

undefined FUN_0002fa34(undefined4 param_1,undefined *unaff_EDX)

{
  return *unaff_EDX;
}


/* ======== FUN_0002fa60 @ 0002fa60 ======== */

longlong FUN_0002fa60(undefined4 param_1,uint unaff_EDX)

{
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_0002fa80 @ 0002fa80 ======== */

void FUN_0002fa80(void)

{
  FUN_0001d560(&g_hero);
  return;
}


/* ======== FUN_0002faa0 @ 0002faa0 ======== */

/* WARNING: Removing unreachable block (ram,0x0002fb5d) */

void FUN_0002faa0(uint param_1,int unaff_EDX,uint unaff_EBX)

{
  param_1 = param_1 & 3;
  FUN_00033e1b(10,param_1 + 4);
  FUN_00033e1b(0xc,0);
  FUN_00033e1b(0xb,param_1 + 0x48);
  FUN_00033e1b(param_1 * 2,unaff_EDX);
  FUN_00033e1b(param_1 * 2,unaff_EDX >> 8);
  unaff_EDX = unaff_EDX >> 0x10;
  if (param_1 == 0) {
    FUN_00033e1b(0x87,unaff_EDX);
  }
  else if (param_1 < 2) {
    FUN_00033e1b(0x83,unaff_EDX);
  }
  else if (param_1 == 3) {
    FUN_00033e1b(0x82,unaff_EDX);
  }
  FUN_00033e1b(param_1 * 2 + 1,unaff_EBX);
  FUN_00033e1b(param_1 * 2 + 1,unaff_EBX >> 8);
  FUN_00033e1b(10,param_1);
  return;
}


/* ======== FUN_0002fb90 @ 0002fb90 ======== */

undefined8 FUN_0002fb90(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int iVar2;
  int local_1c;
  
  FUN_00033e1b(0xc,0);
  iVar1 = FUN_00033e30(DAT_000ecb28 * 2);
  iVar2 = FUN_00033e30(DAT_000ecb28 * 2);
  DAT_00106320 = (iVar2 * 0x100 + iVar1) - (DAT_000ecbd4 & 0xffff);
  if (0x8000 < DAT_00106320) {
    DAT_00106320 = 0;
    FUN_0002fa60();
    FUN_0003043c();
  }
  if (DAT_00106320 < DAT_00106324) {
    local_1c = 0x8000 - DAT_00106324;
  }
  else {
    local_1c = -DAT_00106324;
  }
  local_1c = DAT_00106320 + local_1c;
  DAT_00106324 = DAT_00106320;
  return CONCAT44(unaff_EDX,local_1c);
}


/* ======== FUN_0002fcdc @ 0002fcdc ======== */

void FUN_0002fcdc(int param_1)

{
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  if (param_1 == 0) {
    for (local_34 = 0; local_34 < DAT_00057560 / 0x28; local_34 = local_34 + 1) {
      *(undefined *)((DAT_00106320 + local_34) % 0x8000 + DAT_000ecbd4) = 0x80;
    }
  }
  else {
    for (local_34 = 0; local_34 < 0x20; local_34 = local_34 + 1) {
      *(undefined4 *)(&DAT_00106334 + local_34 * 4) =
           *(undefined4 *)(&DAT_000889fa + local_34 * 0x40);
    }
    for (local_34 = 0; local_34 < DAT_00057560 / 0x28; local_34 = local_34 + 1) {
      local_28 = 0xff;
      local_24 = 0xffffff01;
      for (local_30 = 0; local_30 < 0x20; local_30 = local_30 + 1) {
        if (*(int *)(&DAT_000889d8 + local_30 * 0x40) == -1) {
          if ((int)local_24 < 0x80) {
            local_24 = local_2c;
          }
          if (0x80 < (int)local_28) {
            local_28 = local_2c;
          }
        }
        else {
          if (*(int *)(&DAT_000889ea + local_30 * 0x40) <
              *(int *)(&DAT_00106334 + local_30 * 4) >> 0x10) {
            if (*(int *)(&DAT_000889f2 + local_30 * 0x40) == 0) {
              *(undefined4 *)(&DAT_000889d8 + local_30 * 0x40) = 0xffffffff;
              goto LAB_0002fdc0;
            }
            *(int *)(&DAT_00106334 + local_30 * 4) =
                 *(int *)(&DAT_000889e6 + local_34 * 0x40) *
                 *(int *)(&DAT_000889de + local_30 * 0x40);
          }
          local_2c = (uint)*(byte *)(*(int *)(&DAT_000889e2 + local_30 * 0x40) +
                                    (*(int *)(&DAT_00106334 + local_30 * 4) >> 0x10));
          if ((int)local_24 < (int)local_2c) {
            local_24 = local_2c;
          }
          if ((int)local_2c < (int)local_28) {
            local_28 = local_2c;
          }
          *(int *)(&DAT_00106334 + local_30 * 4) =
               *(int *)(&DAT_00106334 + local_30 * 4) + *(int *)(&DAT_000889de + local_30 * 0x40);
        }
LAB_0002fdc0:
      }
      *(char *)((DAT_00106320 + local_34) % 0x8000 + DAT_000ecbd4) =
           (char)((int)(local_24 + local_28) >> 1);
    }
  }
  return;
}


/* ======== FUN_0002ff10 @ 0002ff10 ======== */

void FUN_0002ff10(int param_1)

{
  int local_34;
  int local_30;
  int local_2c;
  
  if (param_1 == 0) {
    for (local_34 = 0; local_34 < DAT_00057560 / 0x28; local_34 = local_34 + 1) {
      *(undefined *)((DAT_00106320 + local_34) % 0x8000 + DAT_000ecbd4) = 0x80;
    }
  }
  else {
    for (local_34 = 0; local_34 < 4; local_34 = local_34 + 1) {
      *(undefined4 *)(&DAT_00106334 + local_34 * 4) =
           *(undefined4 *)(&DAT_000891fa + local_34 * 0x40);
    }
    for (local_34 = 0; local_34 < DAT_00057560 / 0x28; local_34 = local_34 + 1) {
      local_2c = 0;
      for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1) {
        if (*(int *)(&DAT_000891d8 + local_30 * 0x40) == -1) {
          local_2c = local_2c + 0x80;
        }
        else {
          if (*(int *)(&DAT_000891ea + local_30 * 0x40) <
              *(int *)(&DAT_00106334 + local_30 * 4) >> 0x10) {
            if (*(int *)(&DAT_000891f2 + local_30 * 0x40) == 0) {
              *(undefined4 *)(&DAT_000891d8 + local_30 * 0x40) = 0xffffffff;
              goto LAB_0002fff4;
            }
            *(int *)(&DAT_00106334 + local_30 * 4) =
                 *(int *)(&DAT_000891e6 + local_34 * 0x40) *
                 *(int *)(&DAT_000891de + local_30 * 0x40);
          }
          local_2c = local_2c +
                     ((int)(*(int *)(&DAT_000891fe + local_30 * 0x40) *
                           (uint)*(byte *)(*(int *)(&DAT_000891e2 + local_30 * 0x40) +
                                          (*(int *)(&DAT_00106334 + local_30 * 4) >> 0x10))) >> 6);
          *(int *)(&DAT_00106334 + local_30 * 4) =
               *(int *)(&DAT_00106334 + local_30 * 4) + *(int *)(&DAT_000891de + local_30 * 0x40);
        }
LAB_0002fff4:
      }
      *(char *)((DAT_00106320 + local_34) % 0x8000 + DAT_000ecbd4) = (char)(local_2c >> 2);
    }
  }
  return;
}


/* ======== FUN_0003011c @ 0003011c ======== */

undefined8 FUN_0003011c(undefined4 param_1,undefined4 unaff_EDX)

{
  int local_20;
  
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if ((*(int *)(&DAT_000889d8 + local_20 * 0x40) != -1) &&
       (*(int *)(&DAT_000889fa + local_20 * 0x40) =
             DAT_00106318 * *(int *)(&DAT_000889de + local_20 * 0x40) +
             *(int *)(&DAT_000889fa + local_20 * 0x40),
       *(int *)(&DAT_000889ea + local_20 * 0x40) <=
       (*(int *)(&DAT_000889fa + local_20 * 0x40) >> 0x10) + 1)) {
      if (*(int *)(&DAT_000889f2 + local_20 * 0x40) == 0) {
        *(undefined4 *)(&DAT_000889d8 + local_20 * 0x40) = 0xffffffff;
      }
      else {
        *(int *)(&DAT_000889fa + local_20 * 0x40) =
             *(int *)(&DAT_000889e6 + local_20 * 0x40) << 0x10;
      }
    }
  }
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(&DAT_000889d8 + local_20 * 0x40) != -1) {
      *(int *)(&DAT_000889de + local_20 * 0x40) =
           ((int)*(short *)(&DAT_000889dc + local_20 * 0x40) << 0x10) / DAT_00057560;
    }
  }
  DAT_000ecbd0 = 0;
  for (local_20 = 0; local_20 < 0x20; local_20 = local_20 + 1) {
    if (*(int *)(&DAT_000889d8 + local_20 * 0x40) != -1) {
      DAT_000ecbd0 = DAT_000ecbd0 + 1;
    }
  }
  FUN_0002fcdc(DAT_000ecbd0);
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_00030280 @ 00030280 ======== */

undefined8 FUN_00030280(undefined4 param_1,undefined4 unaff_EDX)

{
  int local_20;
  
  for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
    if ((*(int *)(&DAT_000891d8 + local_20 * 0x40) != -1) &&
       (*(int *)(&DAT_000891fa + local_20 * 0x40) =
             DAT_00106318 * *(int *)(&DAT_000891de + local_20 * 0x40) +
             *(int *)(&DAT_000891fa + local_20 * 0x40),
       *(int *)(&DAT_000891ea + local_20 * 0x40) <=
       (*(int *)(&DAT_000891fa + local_20 * 0x40) >> 0x10) + 1)) {
      if (*(int *)(&DAT_000891f2 + local_20 * 0x40) == 0) {
        *(undefined4 *)(&DAT_000891d8 + local_20 * 0x40) = 0xffffffff;
      }
      else {
        *(int *)(&DAT_000891fa + local_20 * 0x40) =
             *(int *)(&DAT_000891e6 + local_20 * 0x40) << 0x10;
      }
    }
  }
  for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
    if (*(int *)(&DAT_000891d8 + local_20 * 0x40) != -1) {
      *(int *)(&DAT_000891de + local_20 * 0x40) =
           ((int)*(short *)(&DAT_000891dc + local_20 * 0x40) << 0x10) / DAT_00057560;
    }
  }
  DAT_000ecbd0 = 0;
  for (local_20 = 0; local_20 < 4; local_20 = local_20 + 1) {
    if (*(int *)(&DAT_000891d8 + local_20 * 0x40) != -1) {
      DAT_000ecbd0 = DAT_000ecbd0 + 1;
    }
  }
  FUN_0002ff10(DAT_000ecbd0);
  return CONCAT44(unaff_EDX,1);
}


/* ======== FUN_000303e4 @ 000303e4 ======== */

void FUN_000303e4(void)

{
  if (DAT_00106330 != 0) {
    DAT_00106318 = FUN_0002fb90();
    FUN_0003011c();
  }
  return;
}


/* ======== FUN_00030414 @ 00030414 ======== */

void FUN_00030414(void)

{
  DAT_00106318 = FUN_0002fb90();
  FUN_00030280();
  return;
}


/* ======== FUN_0003043c @ 0003043c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003043c(int param_1)

{
  if (param_1 != 0) {
    memset(DAT_000ecbd4,0x80,0x8000);
  }
  DAT_00106328 = DAT_00057560;
  DAT_000ecb34 = 1;
  FUN_00030e7c(0x40);
  FUN_00030e7c(0x100U - (int)(1000000 / (longlong)DAT_00106328) & 0xff);
  _DAT_0010632c = DAT_00106328;
  FUN_0002faa0(DAT_000ecb28,DAT_000ecbd4,0x8000);
  FUN_00030e7c(0x14);
  FUN_00030e7c(0);
  FUN_00030e7c(0x80);
  FUN_00030e7c(0xd1);
  FUN_00030e7c(0xd4);
  DAT_00106330 = 1;
  return;
}


/* ======== FUN_00030508 @ 00030508 ======== */

void FUN_00030508(void)

{
  DAT_00106330 = 0;
  FUN_00030e7c(0xd0);
  DAT_000ecb34 = 0;
  FUN_00030e7c(0xd3);
  return;
}


/* ======== FUN_00030548 @ 00030548 ======== */

void FUN_00030548(void)

{
  FUN_00030e7c(0xd0);
  DAT_00106330 = 0;
  return;
}


/* ======== FUN_00030574 @ 00030574 ======== */

void FUN_00030574(void)

{
  DAT_00106330 = 1;
  FUN_00030e7c(0xd4);
  return;
}


/* ======== FUN_00030650 @ 00030650 ======== */

void FUN_00030650(void)

{
  DAT_000ecbd0 = DAT_000ecbd0 + 1;
  return;
}


/* ======== FUN_00030670 @ 00030670 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00030670(void)

{
  undefined4 local_28;
  
  DAT_000ecb3c = 1;
  _DAT_0010632c = 22000;
  DAT_000ecb34 = 0;
  FUN_0002faa0(DAT_000ecb28,0,0x14);
  FUN_00030e7c(0x40);
  FUN_00030e7c(0xd3);
  FUN_00030e7c(0x14);
  FUN_00030e7c(0x14);
  FUN_00030e7c(0);
  FUN_00030e7c(0xd3);
  FUN_00030e7c(0xd4);
  thunk_FUN_00037417(200);
  FUN_00030e7c(0xd0);
  if (DAT_000ecb3c == 0) {
    local_28 = DAT_000ecb28;
  }
  else {
    local_28 = 0xffffffff;
  }
  return local_28;
}


/* ======== FUN_00030804 @ 00030804 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00030804(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined2 in_CS;
  undefined2 uVar3;
  undefined6 uVar4;
  uint local_64;
  undefined4 uStack_60;
  undefined2 auStack_5c [26];
  uint local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  DAT_00106328 = DAT_00057560;
  local_1c = param_1;
  iVar1 = FUN_00030da4(param_1);
  if (iVar1 == 0) {
    local_24 = 0;
  }
  else {
    DAT_000ecb48 = FUN_00033e30(0x21);
    FUN_00033e1b(0x21,DAT_000ecb48 & 0x53);
    for (local_20 = 2; local_20 < 8; local_20 = local_20 + local_28 + 1) {
      uVar4 = FUN_000347e5(local_20 + 8);
      auStack_5c[local_20 * 3] = (short)((uint6)uVar4 >> 0x20);
      *(int *)((int)&uStack_60 + local_20 * 6) = (int)uVar4;
      FUN_00034817(local_20 + 8,local_20 + 8,&LAB_00030740,
                   CONCAT22((short)((uint)(local_20 * 6) >> 0x10),in_CS));
      local_28 = (uint)(2 < local_20);
    }
    DAT_001063b8 = 0;
    puVar2 = &LAB_000307c0;
    uVar3 = in_CS;
    FUN_00034817(DAT_000ecb2c + 8,DAT_000ecb2c + 8,&LAB_000307c0,in_CS);
    FUN_00030e7c(0x40);
    FUN_00030e7c(0x9c);
    _DAT_0010632c = 0;
    FUN_00030e7c(0x80);
    FUN_00030e7c(1);
    FUN_00030e7c(0);
    thunk_FUN_00037417(100);
    for (local_20 = 2; local_20 < 8; local_20 = local_20 + local_64 + 1) {
      in_CS = auStack_5c[local_20 * 3];
      puVar2 = *(undefined **)((int)&uStack_60 + local_20 * 6);
      FUN_00034817(local_20 + 8);
      local_64 = (uint)(2 < local_20);
    }
    if (DAT_001063b8 == 0) {
      FUN_00033e1b(0x21,DAT_000ecb48,puVar2,in_CS);
      local_24 = 0;
    }
    else {
      FUN_00033e1b(0x21,0xffU - (1 << ((byte)DAT_000ecb2c & 0x1f)) & DAT_000ecb48,puVar2);
      uVar4 = FUN_000347e5(DAT_000ecb2c + 8);
      DAT_000ecb44 = (undefined2)((uint6)uVar4 >> 0x20);
      DAT_000ecb40 = (undefined4)uVar4;
      FUN_00034817(DAT_000ecb2c + 8,DAT_000ecb2c + 8,&LAB_0002fc54,uVar3);
      local_24 = DAT_000ecb2c;
    }
  }
  return local_24;
}


/* ======== FUN_00030a10 @ 00030a10 ======== */

void FUN_00030a10(undefined4 param_1)

{
  int iVar1;
  
  FUN_00033e30(DAT_000ecb20 + 0xe);
  FUN_00033e1b(0x20,0x20);
  iVar1 = FUN_00030da4(param_1);
  if (iVar1 != 0) {
    FUN_00030508();
    DAT_000b1598 = 0;
    DAT_000b1594 = 0;
    FUN_00034817(DAT_000ecb2c + 8,DAT_000ecb2c + 8,DAT_000ecb40,DAT_000ecb44);
    FUN_00033e1b(0x21,DAT_000ecb48);
    FUN_00030cd8(param_1,DAT_000ecb20);
  }
  return;
}


/* ======== FUN_00030ab0 @ 00030ab0 ======== */

undefined8 FUN_00030ab0(undefined4 param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  int iVar2;
  undefined local_5c [32];
  undefined4 local_3c;
  byte *local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_34 = FUN_00033e41(s_BLASTER_000656a0);
  if (local_34 == 0) {
    local_3c = 0;
  }
  else {
    local_30 = 0x220;
    local_2c = 7;
    local_28 = 1;
    local_24 = 5;
    local_20 = 0x330;
    local_1c = 1;
    FUN_0003532e(local_5c,local_34,0x20);
    FUN_0003517a();
    local_38 = (byte *)FUN_00035353(local_5c,&DAT_000656a8);
    while (local_38 != (byte *)0x0) {
      bVar1 = *local_38;
      if (bVar1 < 0x48) {
        if (0x40 < bVar1) {
          if (bVar1 < 0x42) {
            iVar2 = FUN_00033ef6();
            if (iVar2 == 0) {
              local_3c = 0;
              goto LAB_00030ccd;
            }
          }
          else if ((bVar1 == 0x44) && (iVar2 = FUN_00033ef6(), iVar2 == 0)) {
            local_3c = 0;
            goto LAB_00030ccd;
          }
        }
      }
      else if (bVar1 < 0x49) {
        iVar2 = FUN_00033ef6();
        if (iVar2 == 0) {
          local_3c = 0;
          goto LAB_00030ccd;
        }
      }
      else if (bVar1 < 0x50) {
        if ((bVar1 == 0x49) && (iVar2 = FUN_00033ef6(), iVar2 == 0)) {
          local_3c = 0;
          goto LAB_00030ccd;
        }
      }
      else if (bVar1 < 0x51) {
        iVar2 = FUN_00033ef6();
        if (iVar2 == 0) {
          local_3c = 0;
          goto LAB_00030ccd;
        }
      }
      else if ((bVar1 == 0x54) && (iVar2 = FUN_00033ef6(), iVar2 == 0)) {
        local_3c = 0;
        goto LAB_00030ccd;
      }
      local_38 = (byte *)FUN_00035353(0,&DAT_000656aa);
    }
    DAT_000ecb20 = local_30;
    DAT_000ecb2c = local_2c;
    DAT_000ecb28 = local_28;
    local_3c = 1;
  }
LAB_00030ccd:
  return CONCAT44(unaff_EDX,local_3c);
}


/* ======== FUN_00030cd8 @ 00030cd8 ======== */

undefined4 FUN_00030cd8(undefined4 param_1,int unaff_EDX)

{
  uint uVar1;
  int iVar2;
  int local_20;
  
  FUN_00033e1b(unaff_EDX + 6,1);
  FUN_00033e30(unaff_EDX + 6);
  FUN_00033e30(unaff_EDX + 6);
  FUN_00033e30(unaff_EDX + 6);
  FUN_00033e30(unaff_EDX + 6);
  FUN_00033e1b(unaff_EDX + 6,0);
  for (local_20 = 100000; (uVar1 = FUN_00033e30(unaff_EDX + 0xe), uVar1 < 0x80 && (local_20 != 0));
      local_20 = local_20 + -1) {
  }
  if ((local_20 != 0) && (iVar2 = FUN_00033e30(unaff_EDX + 10), iVar2 == 0xaa)) {
    DAT_000ecb24 = 1;
    return 1;
  }
  DAT_000ecb24 = 0;
  return 0;
}


/* ======== FUN_00030da4 @ 00030da4 ======== */

undefined8 FUN_00030da4(undefined4 param_1,undefined4 unaff_EDX)

{
  return CONCAT44(unaff_EDX,DAT_000ecb24);
}


/* ======== FUN_00030e7c @ 00030e7c ======== */

void FUN_00030e7c(undefined param_1)

{
  int iVar1;
  uint uVar2;
  int local_20;
  
  local_20 = 0;
  do {
    uVar2 = FUN_00033e30(DAT_000ecb20 + 0xc);
    if ((uVar2 & 0x80) == 0) {
      FUN_00033e1b(DAT_000ecb20 + 0xc,param_1);
      return;
    }
    iVar1 = local_20 + 1;
    local_20 = local_20 + 2;
  } while (iVar1 < 0xf4241);
  return;
}


/* ======== FUN_00030ed4 @ 00030ed4 ======== */

undefined8 FUN_00030ed4(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  uint uVar2;
  int local_24;
  undefined local_20;
  
  local_24 = 0;
  iVar1 = local_24;
  do {
    local_24 = iVar1;
    uVar2 = FUN_00033e30(DAT_000ecb20 + 0xe);
    if (0x7f < uVar2) {
      local_24 = FUN_00033e30(DAT_000ecb20 + 10);
      local_20 = (undefined)local_24;
      goto LAB_00030f25;
    }
    iVar1 = local_24 + 1;
  } while (local_24 < 0xf4241);
  local_20 = 0;
LAB_00030f25:
  return CONCAT44(unaff_EDX,CONCAT31((int3)((uint)local_24 >> 8),local_20));
}


/* ======== FUN_000310d0 @ 000310d0 ======== */

void FUN_000310d0(int param_1)

{
  if (*(int *)(param_1 + 0x8b) == 0) {
    g_bulletList = *(undefined4 *)(param_1 + 0x87);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x8b) + 0x87) = *(undefined4 *)(param_1 + 0x87);
  }
  if (*(int *)(param_1 + 0x87) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x87) + 0x8b) = *(undefined4 *)(param_1 + 0x8b);
  }
  if (*(int *)(param_1 + 0x7f) >> 1 == 5) {
    DAT_000889a0 = 0;
  }
  operator_delete(param_1);
  return;
}


/* ======== FUN_00031160 @ 00031160 ======== */

void FUN_00031160(int param_1)

{
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0x4d) < *(int *)(param_1 + 0x5d)) {
    local_2c = *(int *)(param_1 + 0x4d);
  }
  else {
    local_2c = *(int *)(param_1 + 0x5d);
  }
  if (*(int *)(param_1 + 0x51) < *(int *)(param_1 + 0x61)) {
    local_28 = *(int *)(param_1 + 0x51);
  }
  else {
    local_28 = *(int *)(param_1 + 0x61);
  }
  if (*(int *)(param_1 + 0x65) < *(int *)(param_1 + 0x55)) {
    local_24 = *(int *)(param_1 + 0x55);
  }
  else {
    local_24 = *(int *)(param_1 + 0x65);
  }
  if (*(int *)(param_1 + 0x69) < *(int *)(param_1 + 0x59)) {
    local_20 = *(int *)(param_1 + 0x59);
  }
  else {
    local_20 = *(int *)(param_1 + 0x69);
  }
  if ((*(int *)(param_1 + 0x30) <= local_2c) && (local_2c <= 0xe0 - *(int *)(param_1 + 0x38))) {
    FUN_000110c2(local_2c,local_28,(local_24 - local_2c) + 1,local_20 - local_28);
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_000310d0(param_1);
  }
  return;
}


/* ======== FUN_00031260 @ 00031260 ======== */

void FUN_00031260(int param_1)

{
  if ((*(int *)(param_1 + 0x30) <= *(int *)(param_1 + 0x41) >> 0x10) &&
     (*(int *)(param_1 + 0x41) >> 0x10 <= 0xe0 - *(int *)(param_1 + 0x38))) {
    FUN_00011145(*(int *)(param_1 + 0x41) >> 0x10,*(int *)(param_1 + 0x45) >> 0x10,
                 **(undefined **)(param_1 + 0x20),*(undefined *)(*(int *)(param_1 + 0x20) + 1));
  }
  *(int *)(param_1 + 0x4d) = *(int *)(param_1 + 0x41) >> 0x10;
  *(int *)(param_1 + 0x51) = *(int *)(param_1 + 0x45) >> 0x10;
  *(uint *)(param_1 + 0x55) = *(int *)(param_1 + 0x4d) + (uint)**(byte **)(param_1 + 0x20);
  *(uint *)(param_1 + 0x59) =
       *(int *)(param_1 + 0x51) + (uint)*(byte *)(*(int *)(param_1 + 0x20) + 1);
  return;
}


/* ======== FUN_0003131c @ 0003131c ======== */

void FUN_0003131c(int param_1)

{
  if (*(int *)(param_1 + 0x78) == 0) {
    if ((*(int *)(param_1 + 0x30) <= *(int *)(param_1 + 4) >> 0x10) &&
       (*(int *)(param_1 + 4) >> 0x10 <= 0xe0 - *(int *)(param_1 + 0x38))) {
      FUN_00010ba3(*(int *)(param_1 + 4) >> 0x10,*(int *)(param_1 + 8) >> 0x10,
                   *(undefined4 *)(param_1 + 0x1c));
    }
    *(int *)(param_1 + 0x5d) = *(int *)(param_1 + 4) >> 0x10;
    *(int *)(param_1 + 0x61) = *(int *)(param_1 + 8) >> 0x10;
    *(uint *)(param_1 + 0x65) = *(int *)(param_1 + 0x5d) + (uint)**(byte **)(param_1 + 0x1c);
    *(uint *)(param_1 + 0x69) =
         *(int *)(param_1 + 0x61) + (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1);
  }
  return;
}


/* ======== Bullet_Init @ 000313d8 ======== */

void Bullet_Init(undefined4 *param_1,int unaff_EDX)

{
  *param_1 = 0xffffffff;
  param_1[1] = (*(short *)(&DAT_0005427c + unaff_EDX * 0x24) + DAT_0007d45a) * 0x10000;
  param_1[2] = (*(short *)(&DAT_0005427e + unaff_EDX * 0x24) + DAT_0007d45e) * 0x10000;
  param_1[6] = *(undefined4 *)(&DAT_00054280 + unaff_EDX * 0x24);
  param_1[5] = *(undefined4 *)(&DAT_00054284 + unaff_EDX * 0x24);
  param_1[9] = *(undefined4 *)(&DAT_00054288 + unaff_EDX * 0x24);
  *(undefined4 *)((int)param_1 + 0x71) = *(undefined4 *)(&DAT_0005428c + unaff_EDX * 0x24);
  *(undefined2 *)((int)param_1 + 0x75) = *(undefined2 *)(&DAT_00054292 + unaff_EDX * 0x24);
  *(undefined *)((int)param_1 + 0x77) = (&DAT_00054294)[unaff_EDX * 0x24];
  *(undefined *)(param_1 + 0x1f) = (&DAT_00054295)[unaff_EDX * 0x24];
  *(undefined2 *)((int)param_1 + 0x7d) = *(undefined2 *)(&DAT_00054296 + unaff_EDX * 0x24);
  *(undefined4 *)((int)param_1 + 0x83) = *(undefined4 *)(&DAT_00054298 + unaff_EDX * 0x24);
  *(undefined4 *)((int)param_1 + 0x6d) = 0;
  param_1[7] = g_bobData + *(int *)(param_1[9] * 9 + g_bobDesc + 1);
  *(undefined *)(param_1 + 0x10) = *(undefined *)(param_1[9] * 9 + g_bobDesc);
  *(undefined4 *)((int)param_1 + 0x41) = param_1[1];
  param_1[8] = param_1[7];
  param_1[10] = param_1[9];
  param_1[0xc] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 5);
  param_1[0xd] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 6);
  param_1[0xe] = (uint)*(byte *)(g_bobDesc + param_1[9] * 9 + 7);
  param_1[0xf] = (uint)*(byte *)(g_bobDesc + param_1[9] * 9 + 8);
  *(undefined4 *)((int)param_1 + 0x49) = 0;
  param_1[0x1e] = 0;
  *(int *)((int)param_1 + 0x5d) = (int)param_1[1] >> 0x10;
  *(int *)((int)param_1 + 0x61) = (int)param_1[2] >> 0x10;
  *(uint *)((int)param_1 + 0x65) = *(int *)((int)param_1 + 0x5d) + (uint)*(byte *)param_1[7];
  *(uint *)((int)param_1 + 0x69) = *(int *)((int)param_1 + 0x61) + (uint)*(byte *)(param_1[7] + 1);
  *(undefined4 *)((int)param_1 + 0x4d) = *(undefined4 *)((int)param_1 + 0x5d);
  *(undefined4 *)((int)param_1 + 0x51) = *(undefined4 *)((int)param_1 + 0x61);
  *(undefined4 *)((int)param_1 + 0x55) = *(undefined4 *)((int)param_1 + 0x65);
  *(undefined4 *)((int)param_1 + 0x59) = *(undefined4 *)((int)param_1 + 0x69);
  return;
}


/* ======== Bullet_ctor @ 00031628 ======== */

int Bullet_ctor(int param_1,undefined4 unaff_EDX,int unaff_EBX)

{
  int local_24;
  
  *(undefined4 *)(param_1 + 0x87) = unaff_EDX;
  *(undefined4 *)(param_1 + 0x8b) = 0;
  Bullet_Init(param_1,unaff_EBX);
  DAT_000892e4 = (uint)*(byte *)(param_1 + 0x77);
  if (unaff_EBX >> 1 == 5) {
    DAT_000889a0 = 1;
  }
  *(int *)(param_1 + 0x7f) = unaff_EBX;
  local_24 = (int)*(short *)((&PTR_LAB_0005429c)[(g_curWeapon * 2 + g_heroDir) * 9] +
                            DAT_000892e8 * 2);
  if (local_24 == -1) {
    DAT_000892e8 = 0;
    local_24 = (int)*(short *)(&PTR_LAB_0005429c)[(g_curWeapon * 2 + g_heroDir) * 9];
  }
  DAT_000892e8 = DAT_000892e8 + 1;
  (**(code **)(*(int *)(g_sound + 0x158) + 0xc))(g_sound,local_24);
  return param_1;
}


/* ======== FUN_00031714 @ 00031714 ======== */

void FUN_00031714(int param_1)

{
  *(undefined4 *)(param_1 + 0x41) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x45) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x6d) == 0) {
    Bullet_Fly(param_1);
  }
  else if (*(int *)(param_1 + 0x6d) == 2) {
    Bullet_Impact(param_1);
  }
  return;
}


/* ======== Bullet_Fly @ 00031790 ======== */

void Bullet_Fly(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *local_44;
  uint local_40;
  int local_24;
  int local_20;
  
  *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + -1;
  if (*(char *)(param_1 + 0x10) == '\0') {
    param_1[9] = param_1[9] + 1;
    *(undefined *)(param_1 + 0x10) = *(undefined *)(param_1[9] * 9 + g_bobDesc);
    if (*(char *)(param_1 + 0x10) != -1) {
      param_1[0xc] = (uint)*(byte *)(g_bobDesc + param_1[9] * 9 + 5);
      param_1[0xd] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 6);
      param_1[0xe] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 7);
      param_1[0xf] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 8);
      param_1[7] = g_bobData + *(int *)(param_1[9] * 9 + g_bobDesc + 1);
    }
  }
  if (*(char *)(g_bobDesc + param_1[9] * 9) == -1) {
    local_40 = *(int *)(g_bobDesc + param_1[9] * 9 + 1) >> 0x10;
    param_1[9] = *(uint *)(g_bobDesc + param_1[9] * 9 + 1) & 0xffff;
    *(undefined *)(param_1 + 0x10) = *(undefined *)(param_1[9] * 9 + g_bobDesc);
    while (local_40 != 0) {
      if (local_40 < (uint)(int)*(char *)(g_bobDesc + param_1[9] * 9)) {
        *(char *)(param_1 + 0x10) = *(char *)(g_bobDesc + param_1[9] * 9) - (char)local_40;
        local_40 = 0;
      }
      else {
        local_40 = local_40 - (int)*(char *)(g_bobDesc + param_1[9] * 9);
        param_1[9] = param_1[9] + 1;
        *(undefined *)(param_1 + 0x10) = *(undefined *)(param_1[9] * 9 + g_bobDesc);
      }
    }
    param_1[0xc] = (uint)*(byte *)(g_bobDesc + param_1[9] * 9 + 5);
    param_1[0xd] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 6);
    param_1[0xe] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 7);
    param_1[0xf] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 8);
  }
  for (local_44 = g_objList; local_44 != (undefined4 *)0x0; local_44 = (undefined4 *)*local_44) {
    iVar6 = (**(code **)(local_44[1] + 0x28))
                      (local_44,0x78,((int)param_1[1] >> 0x10) + param_1[0xc],
                       ((int)param_1[2] >> 0x10) + param_1[0xd],
                       ((int)param_1[1] >> 0x10) + param_1[0xe],
                       ((int)param_1[2] >> 0x10) + param_1[0xf]);
    if ((iVar6 != 0) &&
       (iVar6 = (**(code **)(local_44[1] + 0x1c))(local_44,*(undefined *)(param_1 + 0x1f)),
       iVar6 != 0)) {
      *(undefined4 *)((int)param_1 + 0x49) = 1;
      *(undefined4 *)((int)param_1 + 0x6d) = 2;
      *param_1 = 0xffffffff;
    }
  }
  iVar7 = param_1[0xc] + ((int)(param_1[1] + param_1[6]) >> 0x10);
  iVar8 = param_1[0xd] + ((int)param_1[2] >> 0x10);
  iVar6 = param_1[1];
  iVar2 = param_1[6];
  iVar3 = param_1[0xe];
  iVar4 = param_1[2];
  iVar5 = param_1[0xf];
  iVar9 = iVar7 >> 4;
  iVar10 = iVar8 / 0x13;
  local_24 = iVar9;
  do {
    if ((iVar9 + 2 <= local_24) || (local_20 = iVar10, *(int *)((int)param_1 + 0x49) != 0)) {
      if (*(int *)((int)param_1 + 0x49) != 0) {
        *param_1 = 0xffffffff;
        *(undefined4 *)((int)param_1 + 0x6d) = 2;
      }
      param_1[6] = param_1[6] + param_1[5];
      param_1[1] = param_1[1] + param_1[6];
      if (((int)param_1[1] >> 0x10 < 0xe0 - param_1[0xe]) &&
         ((int)param_1[0xc] < (int)param_1[1] >> 0x10)) {
        if ((*(short *)((int)param_1 + 0x7d) != 0) &&
           (sVar1 = *(short *)((int)param_1 + 0x7d),
           *(short *)((int)param_1 + 0x7d) = *(short *)((int)param_1 + 0x7d) + -1, sVar1 == 1)) {
          param_1[0x1e] = 1;
        }
      }
      else {
        param_1[0x1e] = 1;
      }
      return;
    }
    while( true ) {
      if ((iVar10 + 2 <= local_20) || (*(int *)((int)param_1 + 0x49) != 0)) goto LAB_00031af4;
      iVar11 = TileCollide(iVar7,iVar8,iVar3 + (iVar6 + iVar2 >> 0x10),iVar5 + (iVar4 >> 0x10),
                           local_24,local_20);
      if (iVar11 == 2) break;
      local_20 = local_20 + 1;
    }
    *(undefined4 *)((int)param_1 + 0x49) = 1;
LAB_00031af4:
    local_24 = local_24 + 1;
  } while( true );
}


/* ======== Bullet_Impact @ 00031c00 ======== */

void Bullet_Impact(int *param_1)

{
  char cVar1;
  
  if (*param_1 == -1) {
    *param_1 = 0;
    param_1[9] = *(int *)((int)param_1 + 0x71);
    param_1[7] = g_bobData + *(int *)(param_1[9] * 9 + g_bobDesc + 1);
    *(undefined *)(param_1 + 0x10) = *(undefined *)(g_bobDesc + param_1[9] * 9);
    param_1[0xc] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 5);
    param_1[0xd] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 6);
    param_1[0xe] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 7);
    param_1[0xf] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 8);
    *(undefined4 *)((int)param_1 + 0x49) = 1;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x10);
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + -1;
    if (cVar1 == '\0') {
      param_1[9] = param_1[9] + 1;
      *(undefined *)(param_1 + 0x10) = *(undefined *)(param_1[9] * 9 + g_bobDesc);
      if (*(char *)(param_1 + 0x10) == -1) {
        param_1[0x1e] = 1;
      }
      else {
        param_1[0xc] = (uint)*(byte *)(g_bobDesc + param_1[9] * 9 + 5);
        param_1[0xd] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 6);
        param_1[0xe] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 7);
        param_1[0xf] = (uint)*(byte *)(param_1[9] * 9 + g_bobDesc + 8);
        param_1[7] = g_bobData + *(int *)(param_1[9] * 9 + g_bobDesc + 1);
      }
    }
  }
  return;
}


/* ======== FUN_00031ed0 @ 00031ed0 ======== */

undefined8 FUN_00031ed0(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  undefined uVar2;
  char cVar3;
  undefined uVar4;
  int iVar5;
  uint local_34;
  uint local_30;
  
  uVar1 = DAT_00057d08;
  uVar2 = FUN_0002d650(DAT_00057d08,0);
  FUN_0002d6ec(uVar1,0);
  cVar3 = FUN_0002d650(uVar1,0);
  if (cVar3 == -0x56) {
    uVar4 = 0;
    FUN_0002d6ec(uVar1,0,0);
    for (local_30 = 1; local_30 < 0x400; local_30 = local_30 + 1) {
      cVar3 = FUN_0002d650(uVar1,0,uVar4);
      if (cVar3 != '\0') break;
      iVar5 = local_30 << 10;
      uVar4 = FUN_0002d650(uVar1,iVar5,uVar4);
      FUN_0002d6ec(uVar1,iVar5,0xaa);
      cVar3 = FUN_0002d650(uVar1,iVar5);
      if (cVar3 != -0x56) break;
      FUN_0002d6ec(uVar1,iVar5);
    }
    FUN_0002d6ec(uVar1,0,uVar2);
    local_34 = local_30;
  }
  else {
    local_34 = 0;
  }
  return CONCAT44(unaff_EDX,local_34);
}


/* ======== FUN_000321b8 @ 000321b8 ======== */

void FUN_000321b8(void)

{
  DAT_00057d4c = DAT_00057d4c & 0xfd;
  FUN_00033e1b(DAT_00057d7d,DAT_00057d4c);
  return;
}


/* ======== FUN_000321e8 @ 000321e8 ======== */

void FUN_000321e8(void)

{
  DAT_00057d4c = DAT_00057d4c | 2;
  FUN_00033e1b(DAT_00057d7d,DAT_00057d4c);
  return;
}


/* ======== FUN_00032280 @ 00032280 ======== */

void FUN_00032280(void)

{
  DAT_00057d4c = DAT_00057d4c | 1;
  FUN_00033e1b(DAT_00057d7d,DAT_00057d4c);
  return;
}


/* ======== FUN_00032308 @ 00032308 ======== */

void FUN_00032308(void)

{
  DAT_00057d4c = DAT_00057d4c & 0xfb;
  FUN_00033e1b(DAT_00057d7d,DAT_00057d4c);
  return;
}


/* ======== FUN_00032560 @ 00032560 ======== */

void FUN_00032560(undefined4 param_1,int unaff_EDX)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)((uint)DAT_00057d4d * 4 + 0x57ef0);
  uVar2 = (uVar1 >> 1) + unaff_EDX * 0x200;
  uVar3 = uVar2 / uVar1;
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd(uVar3,uVar2 % uVar1);
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,1);
  FUN_00033e25(DAT_00057d6d,uVar3 << 1);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_000325f0 @ 000325f0 ======== */

void FUN_000325f0(undefined4 param_1,byte unaff_DL)

{
  byte bVar1;
  byte local_24;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0x8d);
  local_24 = FUN_00033e30(DAT_00057d71);
  if ((unaff_DL & 1) == 0) {
    local_24 = local_24 & 0xfb;
  }
  else {
    local_24 = local_24 | 4;
  }
  FUN_00033e1b(DAT_00057d69,0xd);
  FUN_00033e1b(DAT_00057d71,local_24);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,local_24);
  FUN_00033e1b(DAT_00057d69,0x80);
  bVar1 = FUN_00033e30(DAT_00057d71);
  bVar1 = bVar1 & 199 | unaff_DL & 0x38;
  FUN_00033e1b(DAT_00057d69,0);
  FUN_00033e1b(DAT_00057d71,bVar1);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d69,0);
  FUN_00033e1b(DAT_00057d71,bVar1);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00032890 @ 00032890 ======== */

byte FUN_00032890(undefined4 param_1,uint unaff_EDX,uint unaff_EBX,uint unaff_ECX,byte param_5)

{
  uint local_30;
  uint local_2c;
  uint local_28;
  byte local_20;
  
  local_2c = unaff_EBX;
  local_30 = unaff_ECX;
  if (unaff_ECX < unaff_EBX) {
    param_5 = param_5 | 0x40;
    local_2c = unaff_ECX;
    local_30 = unaff_EBX;
  }
  local_28 = unaff_EDX;
  if ((param_5 & 4) != 0) {
    local_28 = FUN_0002ec8c(unaff_EDX);
    local_2c = FUN_0002ec8c(local_2c);
    local_30 = FUN_0002ec8c(local_30);
  }
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0x8d);
  local_20 = FUN_00033e30(DAT_00057d71);
  if ((param_5 & 1) == 0) {
    local_20 = local_20 & 0xfb;
  }
  else {
    local_20 = local_20 | 4;
  }
  FUN_00033e1b(DAT_00057d69,0xd);
  FUN_00033e1b(DAT_00057d71,local_20);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,local_20);
  FUN_00033e1b(DAT_00057d69,0xb);
  FUN_00033e25(DAT_00057d6d,(local_28 & 0x7f) << 9);
  FUN_00033e1b(DAT_00057d69,10);
  FUN_00033e25(DAT_00057d6d,local_28 >> 7 & 0x1fff);
  FUN_00033e1b(DAT_00057d69,2);
  FUN_00033e25(DAT_00057d6d,local_2c >> 7 & 0x1fff);
  FUN_00033e1b(DAT_00057d69,3);
  FUN_00033e25(DAT_00057d6d,(local_2c & 0x7f) << 9);
  FUN_00033e1b(DAT_00057d69,4);
  FUN_00033e25(DAT_00057d6d,local_30 >> 7 & 0x1fff);
  FUN_00033e1b(DAT_00057d69,5);
  FUN_00033e25(DAT_00057d6d,(local_30 & 0x7f) << 9);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return param_5;
}


/* ======== FUN_00032a6c @ 00032a6c ======== */

void FUN_00032a6c(undefined4 param_1,byte unaff_DL)

{
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0);
  FUN_00033e1b(DAT_00057d71,unaff_DL & 0xfc);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,unaff_DL & 0xfc);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00032ae4 @ 00032ae4 ======== */

void FUN_00032ae4(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX,
                 undefined param_5)

{
  undefined uVar1;
  
  uVar1 = FUN_00032890(param_1,unaff_EDX,unaff_EBX,unaff_ECX,param_5);
  FUN_00032a6c(param_1,uVar1);
  return;
}


/* ======== FUN_00032b30 @ 00032b30 ======== */

void FUN_00032b30(undefined4 param_1)

{
  byte bVar1;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0x8d);
  bVar1 = FUN_00033e30(DAT_00057d71);
  FUN_00033e1b(DAT_00057d69,0xd);
  FUN_00033e1b(DAT_00057d71,bVar1 & 0xfb);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,bVar1 & 0xfb);
  FUN_00033e1b(DAT_00057d69,0x80);
  bVar1 = FUN_00033e30(DAT_00057d71);
  bVar1 = bVar1 & 0xdf | 3;
  FUN_00033e1b(DAT_00057d69,0);
  FUN_00033e1b(DAT_00057d71,bVar1);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,bVar1);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00032c90 @ 00032c90 ======== */

void FUN_00032c90(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX,
                 undefined param_5,undefined4 param_6)

{
  FUN_00032560(param_1,param_6);
  FUN_00032ae4(param_1,unaff_EDX,unaff_EBX,unaff_ECX,param_5);
  return;
}


/* ======== FUN_00032cd0 @ 00032cd0 ======== */

void FUN_00032cd0(undefined4 param_1,int unaff_EDX)

{
  if (unaff_EDX == 0) {
    FUN_00032b30(param_1);
  }
  else {
    FUN_000325f0(param_1,0);
  }
  return;
}


/* ======== FUN_00032d10 @ 00032d10 ======== */

void FUN_00032d10(undefined4 param_1,uint unaff_EDX,uint unaff_EBX,undefined param_4,byte param_5)

{
  byte bVar1;
  uint uVar2;
  
  if (unaff_EDX != unaff_EBX) {
    param_5 = param_5 & 0x78;
    uVar2 = unaff_EDX;
    if (unaff_EBX < unaff_EDX) {
      param_5 = param_5 | 0x40;
      uVar2 = unaff_EBX;
      unaff_EBX = unaff_EDX;
    }
    if (uVar2 < 0x40) {
      uVar2 = 0x40;
    }
    if (0xfc0 < unaff_EBX) {
      unaff_EBX = 0xfc0;
    }
    DAT_0008adbc = DAT_0008adbc + 1;
    FUN_000350bd();
    FUN_00033e1b(DAT_00057d65,param_1);
    FUN_00033e1b(DAT_00057d69,6);
    FUN_00033e1b(DAT_00057d71,param_4);
    FUN_00033e1b(DAT_00057d69,7);
    FUN_00033e1b(DAT_00057d71,uVar2 >> 4 & 0xff);
    FUN_00033e1b(DAT_00057d69,8);
    FUN_00033e1b(DAT_00057d71,unaff_EBX >> 4 & 0xff);
    FUN_00033100(param_1,unaff_EDX);
    FUN_00033e1b(DAT_00057d69,0x8d);
    bVar1 = FUN_00033e30(DAT_00057d71);
    if ((bVar1 & 4) != 0) {
      param_5 = param_5 | 4;
    }
    FUN_00033e1b(DAT_00057d69,0xd);
    FUN_00033e1b(DAT_00057d71,param_5);
    FUN_0002ebdc();
    FUN_00033e1b(DAT_00057d71,param_5);
    DAT_0008adbc = DAT_0008adbc + -1;
    if (DAT_0008adbc == 0) {
      FUN_000350bf();
    }
  }
  return;
}


/* ======== FUN_00032e70 @ 00032e70 ======== */

void FUN_00032e70(undefined4 param_1,int unaff_EDX)

{
  FUN_00033100(param_1,*(undefined4 *)(&DAT_00058418 + unaff_EDX * 4));
  return;
}


/* ======== FUN_00032f14 @ 00032f14 ======== */

void FUN_00032f14(undefined4 param_1,int unaff_EDX,undefined unaff_BL,undefined unaff_CL)

{
  undefined4 uVar1;
  
  FUN_00033170(param_1);
  uVar1 = FUN_00033040(param_1);
  FUN_00032d10(param_1,uVar1,*(undefined4 *)(&DAT_00058418 + unaff_EDX * 4),unaff_BL,unaff_CL);
  return;
}


/* ======== FUN_00032f70 @ 00032f70 ======== */

undefined4 FUN_00032f70(uint param_1,uint unaff_EDX,int unaff_EBX)

{
  uint uVar1;
  uint local_3c;
  uint local_38;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  if (unaff_EDX < param_1) {
    local_38 = param_1 - unaff_EDX;
  }
  else {
    local_38 = unaff_EDX - param_1;
  }
  local_38 = (uint)(unaff_EBX * 1000) / local_38;
  local_3c = 4;
  local_2c = *(uint *)((uint)DAT_00057d4d * 4 + 0x58c64);
  local_30 = 0;
  uVar1 = local_2c;
  do {
    if (2 < local_30) {
LAB_00032ff9:
      if (local_3c == 4) {
        local_3c = 3;
        local_28 = 1;
      }
      else {
        uVar1 = ((local_2c >> 1) + local_2c) / local_38;
        local_28 = uVar1;
      }
      uVar1 = CONCAT31((int3)(uVar1 >> 8),(undefined)local_28) & 0xffffff3f;
      return CONCAT31((int3)(uVar1 >> 8),(char)local_3c << 6 | (byte)uVar1);
    }
    uVar1 = local_30;
    if (local_38 < local_2c) {
      local_3c = local_30;
      goto LAB_00032ff9;
    }
    local_2c = local_2c << 3;
    local_30 = local_30 + 1;
  } while( true );
}


/* ======== FUN_00033040 @ 00033040 ======== */

undefined8 FUN_00033040(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0x89);
  uVar1 = FUN_00033e38(DAT_00057d6d);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return CONCAT44(unaff_EDX,uVar1 >> 4);
}


/* ======== FUN_00033100 @ 00033100 ======== */

void FUN_00033100(undefined4 param_1,int unaff_EDX)

{
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,9);
  FUN_00033e25(DAT_00057d6d,unaff_EDX << 4);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00033170 @ 00033170 ======== */

void FUN_00033170(undefined4 param_1)

{
  byte bVar1;
  
  DAT_0008adbc = DAT_0008adbc + 1;
  FUN_000350bd();
  FUN_00033e1b(DAT_00057d65,param_1);
  FUN_00033e1b(DAT_00057d69,0x8d);
  bVar1 = FUN_00033e30(DAT_00057d71);
  FUN_00033e1b(DAT_00057d69,0xd);
  FUN_00033e1b(DAT_00057d71,bVar1 | 3);
  FUN_0002ebdc();
  FUN_00033e1b(DAT_00057d71,bVar1 | 3);
  DAT_0008adbc = DAT_0008adbc + -1;
  if (DAT_0008adbc == 0) {
    FUN_000350bf();
  }
  return;
}


/* ======== FUN_00033280 @ 00033280 ======== */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined2 * FUN_00033280(undefined4 param_1,char unaff_DL)

{
  int iVar1;
  undefined2 *local_b8;
  undefined2 *local_b4;
  undefined4 local_a4;
  ushort local_a0;
  undefined2 uStack_9e;
  undefined2 local_9c;
  undefined2 uStack_9a;
  int local_94;
  undefined4 local_54;
  undefined2 *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  char local_18;
  
  local_1c = param_1;
  local_18 = unaff_DL;
  local_20 = FUN_000353e8();
  if ((short)local_20 == -1) {
    return (undefined2 *)0x0;
  }
  FUN_0003565a((int)(short)local_20,&local_a4);
  if (local_a0 < 0xaf11) {
LAB_00033302:
    FUN_00035798((int)(short)local_20);
    local_24 = (undefined2 *)0x0;
  }
  else {
    if (0xaf11 < local_a0) {
      if (local_a0 != 0xaf12) goto LAB_00033302;
      FUN_00035755((int)(short)local_20,local_54,0);
    }
    if (local_18 != '\x01') {
      local_b4 = (undefined2 *)malloc(local_a4);
      if (local_b4 == (undefined2 *)0x0) {
        if (local_18 == '\0') {
          FUN_00035798((int)(short)local_20);
          return (undefined2 *)0x0;
        }
        local_18 = '\x01';
      }
      else {
        local_18 = '\0';
      }
    }
    if ((local_18 == '\x01') &&
       (local_b4 = (undefined2 *)malloc(0x10), local_b4 == (undefined2 *)0x0)) {
      FUN_00035798((int)(short)local_20);
      local_24 = (undefined2 *)0x0;
    }
    else {
      if (local_a0 == 0xaf11) {
        *local_b4 = uStack_9e;
        local_b4[1] = local_9c;
        local_b4[2] = uStack_9a;
        local_b4[3] = (short)local_94;
      }
      else {
        *local_b4 = uStack_9e;
        local_b4[1] = local_9c;
        local_b4[2] = uStack_9a;
        local_b4[3] = (short)((ulonglong)(uint)(local_94 * 7) / 100);
        if (local_b4[3] == 0) {
          local_b4[3] = 1;
        }
      }
      local_b4[4] = 0;
      *(undefined4 *)(local_b4 + 5) = 0x10;
      if (local_18 == '\0') {
        local_b4[7] = 0;
        local_b8 = local_b4 + 8;
        while( true ) {
          iVar1 = FUN_0003565a((int)(short)local_20,local_b8,0x7fbc);
          if (iVar1 != 0x7fbc) break;
          local_b8 = local_b8 + 0x3fde;
        }
        FUN_00035798((int)(short)local_20);
      }
      else {
        local_b4[7] = (short)local_20;
      }
      local_24 = local_b4;
    }
  }
  return local_24;
}


/* ======== FUN_00033514 @ 00033514 ======== */

void FUN_00033514(byte *param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort local_24;
  byte local_20;
  byte *local_1c;
  
  local_20 = 0;
  bVar1 = *param_1;
  local_1c = param_1 + 2;
  if (DAT_00058ef8 == 0) {
    for (sVar2 = 0; sVar2 < (short)(ushort)bVar1; sVar2 = sVar2 + 1) {
      local_20 = local_20 + *local_1c;
      local_24 = (ushort)local_1c[1];
      if (local_1c[1] == 0) {
        local_24 = 0x100;
      }
      local_1c = local_1c + 2;
      for (sVar3 = 0; (int)sVar3 < (short)local_24 * 3; sVar3 = sVar3 + 1) {
        *(byte *)((int)sVar3 + (uint)local_20 * 3 + DAT_00115870) = *local_1c;
        local_1c = local_1c + 1;
      }
    }
  }
  else {
    for (sVar2 = 0; sVar2 < (short)(ushort)bVar1; sVar2 = sVar2 + 1) {
      local_20 = local_20 + *local_1c;
      uVar4 = (ushort)local_1c[1];
      if (uVar4 == 0) {
        uVar4 = 0x100;
      }
      FUN_00033e1b(0x3c8,local_20);
      local_1c = local_1c + 2;
      for (sVar3 = 0; (int)sVar3 < (short)uVar4 * 3; sVar3 = sVar3 + 1) {
        FUN_00033e1b(0x3c9,*local_1c);
        local_1c = local_1c + 1;
      }
    }
  }
  return;
}


/* ======== FUN_00033650 @ 00033650 ======== */

void FUN_00033650(byte *param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort local_2c;
  ushort local_20;
  byte *local_1c;
  
  bVar1 = *param_1;
  local_1c = param_1 + 2;
  for (sVar2 = 0; local_2c = (ushort)bVar1, sVar2 < (short)local_2c; sVar2 = sVar2 + 1) {
    local_20 = (ushort)local_1c[1];
    if (local_1c[1] == 0) {
      local_20 = 0x100;
    }
    local_1c = local_1c + 2;
    for (sVar3 = 0; (int)sVar3 < (short)local_20 * 3; sVar3 = sVar3 + 1) {
      *local_1c = (byte)((int)(uint)*local_1c >> 2);
      local_1c = local_1c + 1;
    }
  }
  return;
}


/* ======== FUN_000336ec @ 000336ec ======== */

void FUN_000336ec(byte *param_1,byte *unaff_EDX,short unaff_BX,short unaff_CX)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  byte *local_1c;
  byte *pbVar8;
  
  local_1c = param_1;
  for (sVar5 = 0; sVar5 < unaff_CX; sVar5 = sVar5 + 1) {
    bVar2 = *local_1c;
    local_1c = local_1c + 1;
    pbVar8 = unaff_EDX;
    for (sVar6 = 0; sVar6 < (short)(ushort)bVar2; sVar6 = sVar6 + 1) {
      pbVar1 = local_1c + 1;
      bVar3 = *local_1c;
      if ((char)bVar3 < '\0') {
        local_1c = pbVar1;
        for (sVar7 = 0; SBORROW4((int)sVar7,-(int)(char)bVar3) != (int)sVar7 + (int)(char)bVar3 < 0;
            sVar7 = sVar7 + 1) {
          *pbVar8 = *local_1c;
          local_1c = local_1c + 1;
          pbVar8 = pbVar8 + 1;
        }
      }
      else {
        local_1c = local_1c + 2;
        bVar4 = *pbVar1;
        for (sVar7 = 0; (int)sVar7 < (int)(char)bVar3; sVar7 = sVar7 + 1) {
          *pbVar8 = bVar4;
          pbVar8 = pbVar8 + 1;
        }
      }
    }
    unaff_EDX = unaff_EDX + unaff_BX;
  }
  return;
}


/* ======== FUN_000337e0 @ 000337e0 ======== */

void FUN_000337e0(short *param_1,byte *unaff_EDX,short unaff_BX,short *unaff_ECX)

{
  byte *pbVar1;
  short *psVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short *local_1c;
  byte *pbVar10;
  
  local_1c = param_1;
  do {
    unaff_EDX = unaff_EDX + (int)unaff_BX * (int)*local_1c;
    sVar6 = local_1c[1];
    local_1c = local_1c + 2;
    for (sVar7 = 0; sVar7 < sVar6; sVar7 = sVar7 + 1) {
      bVar3 = *(byte *)local_1c;
      local_1c = (short *)((int)local_1c + 1);
      pbVar10 = unaff_EDX;
      for (sVar8 = 0; sVar8 < (short)(ushort)bVar3; sVar8 = sVar8 + 1) {
        pbVar1 = (byte *)((int)local_1c + 1);
        pbVar10 = pbVar10 + *(byte *)local_1c;
        local_1c = local_1c + 1;
        bVar4 = *pbVar1;
        if ('\0' < (char)bVar4) {
          for (sVar9 = 0; (int)sVar9 < (int)(char)bVar4; sVar9 = sVar9 + 1) {
            *pbVar10 = *(byte *)local_1c;
            local_1c = (short *)((int)local_1c + 1);
            pbVar10 = pbVar10 + 1;
          }
        }
        if ((char)bVar4 < '\0') {
          psVar2 = (short *)((int)local_1c + 1);
          bVar5 = *(byte *)local_1c;
          for (sVar9 = 0; local_1c = psVar2,
              SBORROW4((int)sVar9,-(int)(char)bVar4) != (int)sVar9 + (int)(char)bVar4 < 0;
              sVar9 = sVar9 + 1) {
            *pbVar10 = bVar5;
            pbVar10 = pbVar10 + 1;
          }
        }
        if (unaff_ECX <= local_1c) {
          return;
        }
      }
      unaff_EDX = unaff_EDX + unaff_BX;
    }
    if (unaff_ECX <= local_1c) {
      return;
    }
  } while( true );
}


/* ======== FUN_00033924 @ 00033924 ======== */

void FUN_00033924(short *param_1,short *unaff_EDX,short unaff_BX)

{
  byte *pbVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  undefined local_30;
  short *local_1c;
  short *psVar10;
  
  sVar3 = *param_1;
  local_1c = param_1 + 1;
  for (sVar7 = 0; sVar7 < sVar3; sVar7 = sVar7 + 1) {
    sVar4 = *local_1c;
    psVar10 = local_1c;
    while (local_1c = psVar10 + 1, ((int)sVar4 & 0xc000U) == 0xc000) {
      unaff_EDX = (short *)((int)unaff_EDX - (int)sVar4 * (int)unaff_BX);
      psVar10 = local_1c;
      sVar4 = *local_1c;
    }
    sVar5 = sVar4;
    if (sVar4 < 0) {
      sVar5 = *local_1c;
      local_1c = psVar10 + 2;
    }
    psVar10 = unaff_EDX;
    for (sVar8 = 0; sVar8 < sVar5; sVar8 = sVar8 + 1) {
      pbVar1 = (byte *)((int)local_1c + 1);
      psVar10 = (short *)((int)psVar10 + (uint)*(byte *)local_1c);
      local_1c = local_1c + 1;
      bVar2 = *pbVar1;
      if ('\0' < (char)bVar2) {
        for (sVar9 = 0; (int)sVar9 < (int)(char)bVar2; sVar9 = sVar9 + 1) {
          *psVar10 = *local_1c;
          psVar10 = psVar10 + 1;
          local_1c = local_1c + 1;
        }
      }
      if ((char)bVar2 < '\0') {
        sVar6 = *local_1c;
        local_1c = local_1c + 1;
        for (sVar9 = 0; SBORROW4((int)sVar9,-(int)(char)bVar2) != (int)sVar9 + (int)(char)bVar2 < 0;
            sVar9 = sVar9 + 1) {
          *psVar10 = sVar6;
          psVar10 = psVar10 + 1;
        }
      }
    }
    if (sVar4 < 0) {
      local_30 = (undefined)sVar4;
      *(undefined *)psVar10 = local_30;
    }
    unaff_EDX = (short *)((int)unaff_EDX + (int)unaff_BX);
  }
  return;
}


/* ======== FUN_00033a98 @ 00033a98 ======== */

int FUN_00033a98(int param_1,int unaff_EDX,short unaff_BX)

{
  int local_20;
  int local_1c;
  
  local_1c = param_1;
  for (local_20 = 0; local_20 < 200; local_20 = local_20 + 1) {
    FUN_00034682(unaff_EDX,local_1c,0x140);
    unaff_EDX = unaff_EDX + unaff_BX;
    local_1c = local_1c + 0x140;
    param_1 = local_20;
  }
  return param_1;
}


/* ======== FUN_00033aec @ 00033aec ======== */

void FUN_00033aec(int param_1,short unaff_DX,short unaff_BX,short unaff_CX)

{
  int local_1c;
  
  local_1c = param_1;
  for (; 0 < unaff_CX; unaff_CX = unaff_CX + -1) {
    memset(local_1c,0,(int)unaff_BX);
    local_1c = local_1c + unaff_DX;
  }
  return;
}


/* ======== FUN_00033b2c @ 00033b2c ======== */

undefined4 FUN_00033b2c(ushort *param_1,undefined4 unaff_EDX,short unaff_BX)

{
  short sVar1;
  int iVar2;
  int *local_3c;
  int local_34;
  short local_2e;
  int *local_24;
  int *local_20;
  ushort *local_1c;
  
  local_1c = param_1;
  if (param_1[7] == 0) {
    local_20 = (int *)((int)param_1 + *(int *)(param_1 + 5));
    local_24 = local_20 + 4;
    param_1[4] = param_1[4] + 1;
  }
  else {
    FUN_0003565a(param_1[7],&local_34);
    local_20 = &local_34;
    if (local_2e != 0) {
      local_3c = (int *)malloc(local_34 + -0x10);
      if (local_3c == (int *)0x0) {
        return 1;
      }
      local_24 = local_3c;
      FUN_0003565a(local_1c[7],local_3c);
    }
    local_1c[4] = local_1c[4] + 1;
    if (local_1c[4] == *local_1c) {
      local_1c[4] = 0;
      iVar2 = FUN_00035755(local_1c[7],0x80,0);
      if (iVar2 == -1) {
        return 1;
      }
    }
  }
  if (*(short *)(local_20 + 1) == -0xe06) {
    for (sVar1 = 0; (int)sVar1 < (int)(uint)*(ushort *)((int)local_20 + 6); sVar1 = sVar1 + 1) {
      switch(*(undefined2 *)(local_24 + 1)) {
      case 4:
        FUN_00033650((int)local_24 + 6);
        *(undefined2 *)(local_24 + 1) = 0xb;
        FUN_00033514((int)local_24 + 6);
        break;
      case 7:
        FUN_00033924((int)local_24 + 6,unaff_EDX,(int)unaff_BX);
        break;
      case 0xb:
        FUN_00033514((int)local_24 + 6);
        break;
      case 0xc:
        FUN_000337e0((int)local_24 + 6,unaff_EDX,(int)unaff_BX,(int)local_24 + *local_24 + -1);
        break;
      case 0xd:
        FUN_00033aec(unaff_EDX,(int)unaff_BX,(int)(short)local_1c[1],(int)(short)local_1c[2]);
        break;
      case 0xf:
        FUN_000336ec((int)local_24 + 6,unaff_EDX,(int)unaff_BX,(int)(short)local_1c[2]);
        break;
      case 0x10:
        FUN_00033a98((int)local_24 + 6,unaff_EDX,(int)unaff_BX);
        break;
      case 0x12:
      }
      local_24 = (int *)((int)local_24 + *local_24);
    }
  }
  if (local_1c[7] == 0) {
    if (*local_1c < local_1c[4]) {
      local_1c[4] = 1;
      *(undefined4 *)(local_1c + 5) = 0x10;
      local_20 = (int *)((int)local_1c + *(int *)(local_1c + 5));
    }
    *(int *)(local_1c + 5) = *(int *)(local_1c + 5) + *local_20;
  }
  else if (local_2e != 0) {
    free(local_3c);
  }
  return 0;
}


/* ======== FUN_00033de4 @ 00033de4 ======== */

void FUN_00033de4(int param_1)

{
  if (*(short *)(param_1 + 0xe) != 0) {
    FUN_00035798(*(undefined2 *)(param_1 + 0xe));
  }
  free(param_1);
  return;
}


/* ======== FUN_00033e1b @ 00033e1b ======== */

undefined8 FUN_00033e1b(undefined4 param_1,undefined unaff_DL)

{
  out((short)param_1,unaff_DL);
  return CONCAT44(param_1,CONCAT31((int3)((uint)param_1 >> 8),unaff_DL));
}


/* ======== FUN_00033e25 @ 00033e25 ======== */

undefined8 FUN_00033e25(undefined4 param_1,undefined4 unaff_EDX)

{
  out((short)param_1,(short)unaff_EDX);
  return CONCAT44(param_1,unaff_EDX);
}


/* ======== FUN_00033e30 @ 00033e30 ======== */

undefined8 FUN_00033e30(undefined2 param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  
  bVar1 = in(param_1);
  return CONCAT44(unaff_EDX,(uint)bVar1);
}


/* ======== FUN_00033e38 @ 00033e38 ======== */

undefined8 FUN_00033e38(undefined2 param_1,undefined4 unaff_EDX)

{
  ushort uVar1;
  
  uVar1 = in(param_1);
  return CONCAT44(unaff_EDX,(uint)uVar1);
}


/* ======== FUN_00033e41 @ 00033e41 ======== */

undefined8 FUN_00033e41(char *param_1,undefined4 unaff_EDX)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  
  if ((DAT_00058fc4 != (int *)0x0) && (param_1 != (char *)0x0)) {
    uVar4 = 0xffffffff;
    pcVar7 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar5 = ~uVar4 - 1;
    for (piVar6 = DAT_00058fc4; iVar3 = *piVar6, iVar3 != 0; piVar6 = piVar6 + 1) {
      iVar2 = FUN_000357b8(iVar3,param_1,iVar5);
      if ((iVar2 == 0) && (*(char *)(iVar3 + iVar5) == '=')) {
        iVar3 = ~uVar4 + iVar3;
        goto LAB_00033e9b;
      }
    }
  }
  iVar3 = 0;
LAB_00033e9b:
  return CONCAT44(unaff_EDX,iVar3);
}


/* ======== FUN_00033ea2 @ 00033ea2 ======== */

undefined8 FUN_00033ea2(int param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  
  uVar1 = (uint)**(byte **)(param_1 + 8);
  if (uVar1 != 0) {
    *(byte **)(param_1 + 8) = *(byte **)(param_1 + 8) + 1;
    return CONCAT44(unaff_EDX,uVar1);
  }
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 2;
  return CONCAT44(unaff_EDX,0xffffffff);
}


/* ======== FUN_00033ecf @ 00033ecf ======== */

void FUN_00033ecf(undefined4 param_1)

{
  code *local_1c;
  undefined *local_18;
  undefined4 local_14;
  
  local_1c = FUN_00033ea2;
  local_18 = &LAB_00033ecb;
  local_14 = param_1;
  FUN_0003581a(&local_1c);
  return;
}


/* ======== FUN_00033ef6 @ 00033ef6 ======== */

void FUN_00033ef6(void)

{
  undefined4 param_5;
  undefined4 param_6;
  undefined *local_c;
  
  local_c = &stack0x0000000c;
  FUN_00033ecf(param_5,param_6,&local_c);
  return;
}


/* ======== thunk_FUN_00033f90 @ 00033f18 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 thunk_FUN_00033f90(void)

{
  char cVar1;
  code *pcVar2;
  short sVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  ushort extraout_DX;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined2 in_ES;
  undefined2 in_DS;
  short in_GS;
  bool bVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  code *in_stack_00000004;
  
  DAT_00058fdc._0_2_ = 0x24;
  pcVar2 = (code *)swi(0x21);
  DAT_00058fd0 = (undefined *)register0x00000010;
  DAT_00058fe4 = (undefined *)register0x00000010;
  uVar15 = (*pcVar2)(0x3000);
  iVar7 = (int)((ulonglong)uVar15 >> 0x20);
  DAT_00059007 = (undefined)uVar15;
  DAT_00059008 = (undefined)((ulonglong)uVar15 >> 8);
  puVar9 = (uint *)0x0;
  pcVar11 = (char *)0x81;
  sVar3 = (short)((ulonglong)uVar15 >> 0x10);
  if (sVar3 == 0x4458) {
    DAT_00058fd0 = (undefined *)(_DAT_0000005c + 0xfffU & 0xfffff000);
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)(CONCAT11(0x4a,(char)in_DS),iVar7,_DAT_0000005c + 0xfffU >> 0xc);
    uVar4 = SUB42(in_stack_00000004,0);
    DAT_00059005 = 0x2c;
  }
  else if (sVar3 == 0x4243) {
    pcVar2 = (code *)swi(0x21);
    _DAT_00058efc = iVar7;
    (*pcVar2)(CONCAT11(0x4a,(char)((ulonglong)uVar15 >> 0x10)),*(int *)(iVar7 + 0x1c),
              (int)&stack0x00000004 - *(int *)(iVar7 + 0x1c));
    pcVar11 = (char *)(*(int *)(iVar7 + 0x10) + 0x81);
    puVar9 = (uint *)((uint)*(ushort *)(*(int *)(iVar7 + 0x10) + 0x2c) << 4);
    uVar4 = 9;
    DAT_00058fdc._0_2_ = in_DS;
    DAT_00059005 = in_DS;
  }
  else {
    pcVar2 = (code *)swi(0x21);
    uVar16 = (*pcVar2)(0xff00,0x78);
    if ((char)uVar16 == '\0') {
      DAT_00059005 = 0x2c;
      uVar4 = 0;
    }
    else {
      if (in_GS != 0) {
        _DAT_00058f00 = in_GS;
      }
      pcVar2 = (code *)swi(0x31);
      (*pcVar2)(6,(int)((ulonglong)uVar16 >> 0x20),CONCAT22(0x5048,in_DS));
      uVar4 = 1;
      DAT_00058fdc._0_2_ = in_ES;
      DAT_00059005 = _DAT_0000002c;
      if ((ushort)(extraout_DX | (ushort)uVar15) != 0) {
        uVar4 = 0x101;
      }
    }
  }
  _DAT_00058fcc = &stack0x00000008;
  DAT_00058ffe = (char)uVar4;
  DAT_00058fff = (undefined)((ushort)uVar4 >> 8);
  pcVar8 = &DAT_00115ce0;
  bVar14 = true;
  uVar6 = (uint)(byte)pcVar11[-1];
  do {
    pcVar12 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar12 = pcVar11 + 1;
    bVar14 = *pcVar11 == ' ';
    pcVar11 = pcVar12;
  } while (bVar14);
  DAT_000341ed = in_DS;
  DAT_00059001 = puVar9;
  if (!bVar14) {
    pcVar11 = pcVar12 + -1;
    for (iVar7 = uVar6 + 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pcVar8 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  *pcVar8 = '\0';
  pcVar8[1] = '\0';
  DAT_00058fd8 = pcVar8 + 1;
  _DAT_00058ffc = 0;
  do {
    if (((*puVar9 | 0x20202020) == 0x37386f6e) && (*(char *)(puVar9 + 1) == '=')) {
      _DAT_00058ffc = _DAT_00058ffc + 1;
    }
    do {
      puVar10 = puVar9;
      puVar9 = (uint *)((int)puVar10 + 1);
    } while (*(char *)puVar10 != '\0');
  } while (*(char *)puVar9 != '\0');
  puVar9 = puVar10 + 1;
  pcVar11 = DAT_00058fd8;
  do {
    cVar1 = *(char *)puVar9;
    DAT_00058fe0 = pcVar11 + 1;
    *pcVar11 = *(char *)puVar9;
    puVar9 = (uint *)((int)puVar9 + 1);
    pcVar11 = DAT_00058fe0;
  } while (cVar1 != '\0');
  uVar6 = 0xaff24;
  if (DAT_00058ffe == '\x01') {
    uVar6 = 0x1000;
  }
  puVar13 = &DAT_00065dbc;
  for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined *)puVar13 = 0;
    puVar13 = (undefined4 *)((int)puVar13 + 1);
  }
  DAT_00058fd4 = &DAT_00115ce0;
  in_stack_00000004 = (code *)0x341a0;
  FUN_0003648c(0xff);
  in_stack_00000004 = thunk_FUN_000341cc;
  in_stack_00000004 = (code *)FUN_0003643c();
  FUN_000364d7(0,0xff);
  pcVar2 = (code *)swi(0x21);
  uVar5 = (*pcVar2)(CONCAT11(0x4c,(char)in_stack_00000004));
  return uVar5;
}


/* ======== FUN_00033f90 @ 00033f90 ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00033f90(void)

{
  char cVar1;
  code *pcVar2;
  short sVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  ushort extraout_DX;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined2 in_ES;
  undefined2 in_DS;
  short in_GS;
  bool bVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  code *in_stack_00000004;
  
  DAT_00058fdc._0_2_ = 0x24;
  pcVar2 = (code *)swi(0x21);
  DAT_00058fd0 = (undefined *)register0x00000010;
  DAT_00058fe4 = (undefined *)register0x00000010;
  uVar15 = (*pcVar2)(0x3000);
  iVar7 = (int)((ulonglong)uVar15 >> 0x20);
  DAT_00059007 = (undefined)uVar15;
  DAT_00059008 = (undefined)((ulonglong)uVar15 >> 8);
  puVar9 = (uint *)0x0;
  pcVar11 = (char *)0x81;
  sVar3 = (short)((ulonglong)uVar15 >> 0x10);
  if (sVar3 == 0x4458) {
    DAT_00058fd0 = (undefined *)(_DAT_0000005c + 0xfffU & 0xfffff000);
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)(CONCAT11(0x4a,(char)in_DS),iVar7,_DAT_0000005c + 0xfffU >> 0xc);
    uVar4 = SUB42(in_stack_00000004,0);
    DAT_00059005 = 0x2c;
  }
  else if (sVar3 == 0x4243) {
    pcVar2 = (code *)swi(0x21);
    _DAT_00058efc = iVar7;
    (*pcVar2)(CONCAT11(0x4a,(char)((ulonglong)uVar15 >> 0x10)),*(int *)(iVar7 + 0x1c),
              (int)&stack0x00000004 - *(int *)(iVar7 + 0x1c));
    pcVar11 = (char *)(*(int *)(iVar7 + 0x10) + 0x81);
    puVar9 = (uint *)((uint)*(ushort *)(*(int *)(iVar7 + 0x10) + 0x2c) << 4);
    uVar4 = 9;
    DAT_00058fdc._0_2_ = in_DS;
    DAT_00059005 = in_DS;
  }
  else {
    pcVar2 = (code *)swi(0x21);
    uVar16 = (*pcVar2)(0xff00,0x78);
    if ((char)uVar16 == '\0') {
      DAT_00059005 = 0x2c;
      uVar4 = 0;
    }
    else {
      if (in_GS != 0) {
        _DAT_00058f00 = in_GS;
      }
      pcVar2 = (code *)swi(0x31);
      (*pcVar2)(6,(int)((ulonglong)uVar16 >> 0x20),CONCAT22(0x5048,in_DS));
      uVar4 = 1;
      DAT_00058fdc._0_2_ = in_ES;
      DAT_00059005 = _DAT_0000002c;
      if ((ushort)(extraout_DX | (ushort)uVar15) != 0) {
        uVar4 = 0x101;
      }
    }
  }
  _DAT_00058fcc = &stack0x00000008;
  DAT_00058ffe = (char)uVar4;
  DAT_00058fff = (undefined)((ushort)uVar4 >> 8);
  pcVar8 = &DAT_00115ce0;
  bVar14 = true;
  uVar6 = (uint)(byte)pcVar11[-1];
  do {
    pcVar12 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar12 = pcVar11 + 1;
    bVar14 = *pcVar11 == ' ';
    pcVar11 = pcVar12;
  } while (bVar14);
  DAT_000341ed = in_DS;
  DAT_00059001 = puVar9;
  if (!bVar14) {
    pcVar11 = pcVar12 + -1;
    for (iVar7 = uVar6 + 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pcVar8 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  *pcVar8 = '\0';
  pcVar8[1] = '\0';
  DAT_00058fd8 = pcVar8 + 1;
  _DAT_00058ffc = 0;
  do {
    if (((*puVar9 | 0x20202020) == 0x37386f6e) && (*(char *)(puVar9 + 1) == '=')) {
      _DAT_00058ffc = _DAT_00058ffc + 1;
    }
    do {
      puVar10 = puVar9;
      puVar9 = (uint *)((int)puVar10 + 1);
    } while (*(char *)puVar10 != '\0');
  } while (*(char *)puVar9 != '\0');
  puVar9 = puVar10 + 1;
  pcVar11 = DAT_00058fd8;
  do {
    cVar1 = *(char *)puVar9;
    DAT_00058fe0 = pcVar11 + 1;
    *pcVar11 = *(char *)puVar9;
    puVar9 = (uint *)((int)puVar9 + 1);
    pcVar11 = DAT_00058fe0;
  } while (cVar1 != '\0');
  uVar6 = 0xaff24;
  if (DAT_00058ffe == '\x01') {
    uVar6 = 0x1000;
  }
  puVar13 = &DAT_00065dbc;
  for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined *)puVar13 = 0;
    puVar13 = (undefined4 *)((int)puVar13 + 1);
  }
  DAT_00058fd4 = &DAT_00115ce0;
  in_stack_00000004 = (code *)0x341a0;
  FUN_0003648c(0xff);
  in_stack_00000004 = thunk_FUN_000341cc;
  in_stack_00000004 = (code *)FUN_0003643c();
  FUN_000364d7(0,0xff);
  pcVar2 = (code *)swi(0x21);
  uVar5 = (*pcVar2)(CONCAT11(0x4c,(char)in_stack_00000004));
  return uVar5;
}


/* ======== thunk_FUN_000341cc @ 000341a7 ======== */

undefined4 thunk_FUN_000341cc(undefined param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_000364d7(0,0xff);
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)(CONCAT11(0x4c,param_1));
  return uVar2;
}


/* ======== FUN_000341a9 @ 000341a9 ======== */

undefined4
FUN_000341a9(undefined4 param_1,char *unaff_EDX,undefined4 param_3,undefined4 param_4,
            undefined param_5)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  pcVar3 = (code *)swi(0x21);
  uVar4 = (*pcVar3)(0x3d01,&DAT_00033f8c);
  pcVar6 = unaff_EDX;
  do {
    pcVar1 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar1;
  } while (cVar2 != '\0');
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)(0x4000,unaff_EDX,uVar4,pcVar1 + (-1 - (int)unaff_EDX));
  FUN_000364d7(0,0xff);
  pcVar3 = (code *)swi(0x21);
  uVar5 = (*pcVar3)(CONCAT11(0x4c,param_5));
  return uVar5;
}


/* ======== FUN_000341cc @ 000341cc ======== */

undefined4 FUN_000341cc(undefined param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_000364d7(0,0xff);
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)(CONCAT11(0x4c,param_1));
  return uVar2;
}


/* ======== FUN_000341e4 @ 000341e4 ======== */

void FUN_000341e4(void)

{
  return;
}


/* ======== FUN_000341ef @ 000341ef ======== */

uint FUN_000341ef(char *param_1,char **unaff_EDX,int unaff_EBX,int unaff_ECX)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  pcVar3 = param_1;
  if (unaff_EDX != (char **)0x0) {
    *unaff_EDX = param_1;
  }
  while (((&DAT_00065c3c)[(byte)(*pcVar3 + 1)] & 2) != 0) {
    pcVar3 = pcVar3 + 1;
  }
  cVar1 = *pcVar3;
  bVar2 = false;
  if ((cVar1 == '+') || (cVar1 == '-')) {
    pcVar3 = pcVar3 + 1;
  }
  if (unaff_EBX == 0) {
    if ((*pcVar3 == '0') && ((pcVar3[1] == 'x' || (pcVar3[1] == 'X')))) {
      unaff_EBX = 0x10;
    }
    else if (*pcVar3 == '0') {
      unaff_EBX = 8;
    }
    else {
      unaff_EBX = 10;
    }
  }
  if ((unaff_EBX < 2) || (0x24 < unaff_EBX)) {
    FUN_0003652c(0xd);
    uVar5 = 0;
  }
  else {
    if (((unaff_EBX == 0x10) && (*pcVar3 == '0')) && ((pcVar3[1] == 'x' || (pcVar3[1] == 'X')))) {
      pcVar3 = pcVar3 + 2;
    }
    pcVar4 = pcVar3;
    uVar5 = 0;
    while( true ) {
      uVar7 = FUN_00034364(*pcVar4);
      pcVar4 = (char *)((ulonglong)uVar7 >> 0x20);
      if (unaff_EBX <= (int)uVar7) break;
      if (*(uint *)(&DAT_00058efc + unaff_EBX * 4) < uVar5) {
        bVar2 = true;
      }
      uVar6 = uVar5 * unaff_EBX + (int)uVar7;
      if (uVar6 < uVar5) {
        bVar2 = true;
      }
      pcVar4 = pcVar4 + 1;
      uVar5 = uVar6;
    }
    if (pcVar4 == pcVar3) {
      pcVar4 = param_1;
    }
    if (unaff_EDX != (char **)0x0) {
      *unaff_EDX = pcVar4;
    }
    if (((unaff_ECX == 1) && (0x7fffffff < uVar5)) && ((uVar5 != 0x80000000 || (cVar1 != '-')))) {
      bVar2 = true;
    }
    if (bVar2) {
      FUN_0003652c(0xe);
      if (unaff_ECX == 0) {
        uVar5 = 0xffffffff;
      }
      else if (cVar1 == '-') {
        uVar5 = 0x80000000;
      }
      else {
        uVar5 = 0x7fffffff;
      }
    }
    else if (cVar1 == '-') {
      uVar5 = -uVar5;
    }
  }
  return uVar5;
}


/* ======== FUN_00034355 @ 00034355 ======== */

void FUN_00034355(void)

{
  FUN_000341ef();
  return;
}


/* ======== FUN_0003435c @ 0003435c ======== */

void FUN_0003435c(void)

{
  FUN_00034355();
  return;
}


/* ======== FUN_00034364 @ 00034364 ======== */

undefined8 FUN_00034364(byte param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  uint uVar2;
  
  if ((0x2f < param_1) && (param_1 < 0x3a)) {
    return CONCAT44(unaff_EDX,param_1 - 0x30);
  }
  bVar1 = FUN_0003655b(param_1);
  if (((bVar1 < 0x61) || (0x69 < bVar1)) && ((bVar1 < 0x6a || (0x72 < bVar1)))) {
    uVar2 = (uint)bVar1;
    if ((0x72 < uVar2) && (uVar2 < 0x7b)) {
      return CONCAT44(unaff_EDX,uVar2 - 0x57);
    }
    return CONCAT44(unaff_EDX,0x25);
  }
  return CONCAT44(unaff_EDX,bVar1 - 0x57);
}


/* ======== fread @ 000343c2 ======== */

/* WARNING: Type propagation algorithm not settling */

uint fread(undefined4 *param_1,uint unaff_EDX,int unaff_EBX,char **unaff_ECX)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 *local_18;
  char *local_14;
  char *local_10;
  
  if ((*(byte *)(unaff_ECX + 3) & 1) == 0) {
    FUN_0003652c(4);
    *(byte *)(unaff_ECX + 3) = *(byte *)(unaff_ECX + 3) | 0x20;
    return 0;
  }
  local_10 = (char *)(unaff_EBX * unaff_EDX);
  if (local_10 == (char *)0x0) {
    return 0;
  }
  if (unaff_ECX[2] == (char *)0x0) {
    FUN_00036569(unaff_ECX);
  }
  local_14 = (char *)0x0;
  local_18 = param_1;
  if ((*(byte *)(unaff_ECX + 3) & 0x40) == 0) {
    puVar5 = (undefined4 *)(local_10 + (int)param_1);
    do {
      if (unaff_ECX[1] == (char *)0x0) {
        uVar7 = FUN_00034f19(unaff_ECX);
        param_1 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
        if ((int)uVar7 == 0) break;
      }
      pcVar4 = *unaff_ECX;
      unaff_ECX[1] = unaff_ECX[1] + -1;
      *unaff_ECX = pcVar4 + 1;
      cVar1 = *pcVar4;
      if (cVar1 == '\r') {
        if (unaff_ECX[1] == (char *)0x0) {
          uVar7 = FUN_00034f19(unaff_ECX);
          param_1 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
          if ((int)uVar7 == 0) break;
        }
        pcVar4 = *unaff_ECX;
        unaff_ECX[1] = unaff_ECX[1] + -1;
        *unaff_ECX = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
      if (cVar1 == '\x1a') goto LAB_000344d7;
      *(char *)param_1 = cVar1;
      local_14 = local_14 + 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (param_1 != puVar5);
  }
  else {
    do {
      while( true ) {
        pcVar4 = unaff_ECX[1];
        if (pcVar4 != (char *)0x0) {
          if (local_10 < pcVar4) {
            pcVar4 = local_10;
          }
          puVar5 = (undefined4 *)*unaff_ECX;
          puVar6 = local_18;
          for (uVar3 = (uint)pcVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
          for (uVar3 = (uint)pcVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined *)puVar6 = *(undefined *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          local_18 = (undefined4 *)((int)local_18 + (int)pcVar4);
          local_14 = local_14 + (int)pcVar4;
          local_10 = local_10 + -(int)pcVar4;
          *unaff_ECX = *unaff_ECX + (int)pcVar4;
          unaff_ECX[1] = unaff_ECX[1] + -(int)pcVar4;
        }
        if (local_10 == (char *)0x0) goto LAB_0003458b;
        if ((local_10 < unaff_ECX[5]) && ((*(byte *)((int)unaff_ECX + 0xd) & 4) == 0)) break;
        unaff_ECX[1] = (char *)0x0;
        *unaff_ECX = unaff_ECX[2];
        iVar2 = FUN_000365e0(unaff_ECX[4],local_18);
        if (iVar2 == -1) {
          *(byte *)(unaff_ECX + 3) = *(byte *)(unaff_ECX + 3) | 0x20;
          goto LAB_0003458b;
        }
        if (iVar2 == 0) goto LAB_000344d7;
        local_18 = (undefined4 *)((int)local_18 + iVar2);
        local_10 = local_10 + -iVar2;
        local_14 = local_14 + iVar2;
      }
      iVar2 = FUN_00034f19(unaff_ECX);
    } while (iVar2 != 0);
  }
LAB_0003458b:
  return (uint)local_14 / unaff_EDX;
LAB_000344d7:
  *(byte *)(unaff_ECX + 3) = *(byte *)(unaff_ECX + 3) | 0x10;
  goto LAB_0003458b;
}


/* ======== FUN_0003459d @ 0003459d ======== */

int FUN_0003459d(byte *param_1,byte *unaff_EDX,int unaff_EBX)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  iVar1 = 0;
  bVar3 = true;
  do {
    if (unaff_EBX == 0) break;
    unaff_EBX = unaff_EBX + -1;
    bVar2 = *param_1 < *unaff_EDX;
    bVar3 = *param_1 == *unaff_EDX;
    param_1 = param_1 + 1;
    unaff_EDX = unaff_EDX + 1;
  } while (bVar3);
  if (!bVar3) {
    iVar1 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
  }
  return iVar1;
}


/* ======== free @ 000345bb ======== */

void free(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 in_DS;
  
  if (param_1 != 0) {
    uVar1 = DAT_00058f90;
    if (((DAT_001158b0 == 0) || (param_1 < DAT_001158b0)) ||
       (uVar2 = DAT_001158b0, *(uint *)(DAT_001158b0 + 8) <= param_1)) {
      for (; (uVar2 = uVar1, *(uint *)(uVar1 + 8) != 0 &&
             ((param_1 < uVar1 || (*(uint *)(uVar1 + 8) <= param_1)))); uVar1 = *(uint *)(uVar1 + 8)
          ) {
      }
    }
    FUN_000366a8(param_1,in_DS,uVar2);
    if ((uVar2 < DAT_00058f94) && (DAT_00058f98 < *(uint *)(uVar2 + 0x14))) {
      DAT_00058f98 = *(uint *)(uVar2 + 0x14);
    }
    DAT_001158b4 = 0;
    DAT_001158b0 = uVar2;
  }
  return;
}


/* ======== FUN_0003463d @ 0003463d ======== */

undefined8 FUN_0003463d(undefined4 *param_1,undefined4 unaff_EDX)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar3 = 0xffffffff;
  puVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *(char *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  puVar2 = (undefined4 *)malloc(uVar3);
  if (puVar2 != (undefined4 *)0x0) {
    puVar5 = puVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar5 = *param_1;
      param_1 = param_1 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined *)puVar5 = *(undefined *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  return CONCAT44(unaff_EDX,puVar2);
}


/* ======== FUN_00034682 @ 00034682 ======== */

undefined4 * FUN_00034682(undefined4 *param_1,undefined4 *unaff_EDX,uint unaff_EBX)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (uVar1 = unaff_EBX >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *unaff_EDX;
    unaff_EDX = unaff_EDX + 1;
    puVar2 = puVar2 + 1;
  }
  for (unaff_EBX = unaff_EBX & 3; unaff_EBX != 0; unaff_EBX = unaff_EBX - 1) {
    *(undefined *)puVar2 = *(undefined *)unaff_EDX;
    unaff_EDX = (undefined4 *)((int)unaff_EDX + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_1;
}


/* ======== malloc @ 000346a7 ======== */

undefined8 malloc(uint param_1,undefined4 unaff_EDX)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 in_DS;
  undefined8 uVar6;
  
  if ((param_1 != 0) && (param_1 < 0xffffffd5)) {
    iVar2 = 0;
    bVar1 = false;
    uVar5 = param_1 + 3 & 0xfffffffc;
LAB_000346da:
    do {
      uVar3 = uVar5;
      if (uVar5 < 0xc) {
        uVar3 = 0xc;
      }
      if (DAT_00058f98 < uVar3) {
        uVar4 = DAT_00058f94;
        uVar3 = DAT_00058f94;
        if (DAT_00058f94 == 0) goto LAB_000346f8;
      }
      else {
        uVar3 = 0;
LAB_000346f8:
        uVar4 = DAT_00058f90;
        DAT_00058f98 = uVar3;
      }
      for (; uVar4 != 0; uVar4 = *(uint *)(uVar4 + 8)) {
        DAT_00058f94 = uVar4;
        iVar2 = FUN_00036600(param_1,in_DS,uVar4);
        if (iVar2 != 0) goto LAB_00034771;
        if (DAT_00058f98 < *(uint *)(uVar4 + 0x14)) {
          DAT_00058f98 = *(uint *)(uVar4 + 0x14);
        }
        iVar2 = 0;
      }
      if (bVar1) {
LAB_00034753:
        uVar6 = FUN_00036d6d(param_1);
        iVar2 = (int)((ulonglong)uVar6 >> 0x20);
        if ((int)uVar6 == 0) goto LAB_00034771;
        bVar1 = false;
        goto LAB_000346da;
      }
      uVar6 = FUN_00036ba4(param_1,iVar2);
      iVar2 = (int)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) goto LAB_00034753;
      bVar1 = true;
    } while( true );
  }
  iVar2 = 0;
LAB_0003477b:
  return CONCAT44(unaff_EDX,iVar2);
LAB_00034771:
  DAT_001158b4 = 0;
  goto LAB_0003477b;
}


/* ======== FUN_0003478a @ 0003478a ======== */

void FUN_0003478a(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  undefined auStack_14 [12];
  
  FUN_00036d70(auStack_14,unaff_EDX,unaff_EBX,auStack_14);
  FUN_000352db(param_1);
  return;
}


/* ======== FUN_000347a7 @ 000347a7 ======== */

void FUN_000347a7(undefined *param_1,undefined *unaff_EDX,int unaff_EBX)

{
  undefined uVar1;
  
  for (unaff_EBX = unaff_EBX >> 1; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    uVar1 = *param_1;
    *unaff_EDX = param_1[1];
    param_1 = param_1 + 2;
    unaff_EDX[1] = uVar1;
    unaff_EDX = unaff_EDX + 2;
  }
  return;
}


/* ======== printf @ 000347c3 ======== */

void printf(void)

{
  undefined4 param_5;
  undefined *local_c;
  
  local_c = &stack0x00000008;
  FUN_00036da9(&DAT_0005902a,param_5,&local_c);
  return;
}


/* ======== FUN_000347e5 @ 000347e5 ======== */

undefined8
FUN_000347e5(undefined param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined uVar3;
  undefined2 extraout_var;
  undefined2 in_ES;
  
  if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
    uVar3 = 0;
    uVar2 = CONCAT11(0x35,param_1);
  }
  else {
    uVar2 = 0x2502;
    uVar3 = param_1;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(uVar2,DAT_00058ffe,unaff_EBX,uVar3,unaff_ECX,unaff_EBX);
  return CONCAT44(CONCAT22(extraout_var,in_ES),unaff_EBX);
}


/* ======== FUN_00034817 @ 00034817 ======== */

void FUN_00034817(undefined param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined2 unaff_CX)

{
  code *pcVar1;
  
  if ((1 < DAT_00058ffe) && (DAT_00058ffe < 9)) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(4,unaff_EBX,DAT_00058ffe,param_1);
    return;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(param_1,unaff_EBX,DAT_00058ffe,unaff_CX,unaff_EDX);
  return;
}


/* ======== FUN_00034844 @ 00034844 ======== */

void FUN_00034844(int param_1,int unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  int iVar1;
  
  iVar1 = malloc(param_1 * unaff_EDX,unaff_EDX,param_1 * unaff_EDX,unaff_ECX,unaff_EBX);
  if (iVar1 != 0) {
    memset(iVar1,0);
  }
  return;
}


/* ======== memset @ 00034860 ======== */

undefined4 memset(undefined4 param_1,undefined unaff_DL,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00036e30(param_1,CONCAT31(CONCAT21(CONCAT11(unaff_DL,unaff_DL),unaff_DL),unaff_DL),unaff_EBX,
               unaff_EBX,unaff_ECX);
  return param_1;
}


/* ======== FUN_00034878 @ 00034878 ======== */

undefined8 FUN_00034878(undefined *param_1,undefined4 unaff_EDX)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_0003655b(*param_1,0);
  uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
  uVar2 = (uint)uVar6 & 0xff;
  if (((uVar2 != 0x72) && (uVar2 != 0x77)) && (uVar2 != 0x61)) {
    FUN_0003652c(9);
    uVar3 = 0;
    goto LAB_00034941;
  }
  cVar1 = param_1[1];
  uVar2 = uVar3 | 3;
  if (cVar1 == '+') {
    uVar4 = CONCAT22((short)((ulonglong)uVar6 >> 0x30),(short)uVar2) | 0x40;
    if (param_1[2] == 'b') {
LAB_000348e5:
      uVar3 = uVar4;
    }
    else {
      uVar3 = uVar2;
      if (param_1[2] != 't') {
        bVar5 = DAT_00059219 == 0x200;
LAB_000348e3:
        if (bVar5) goto LAB_000348e5;
      }
    }
  }
  else {
    uVar4 = uVar3 | 0x40;
    if (cVar1 == 'b') {
      uVar3 = uVar4;
      if (param_1[2] == '+') {
        uVar4 = CONCAT31((int3)((ulonglong)uVar6 >> 0x28),(char)uVar4) | 3;
LAB_00034921:
        uVar3 = uVar4;
      }
    }
    else {
      if (cVar1 == 't') {
        bVar5 = param_1[2] == '+';
        uVar4 = uVar2;
        goto LAB_000348e3;
      }
      if (DAT_00059219 == 0x200) goto LAB_00034921;
    }
  }
  uVar2 = (uint)uVar6 & 0xff;
  if (uVar2 == 0x77) {
    uVar3 = uVar3 | 2;
  }
  else if (uVar2 == 0x61) {
    uVar3 = uVar3 | 0x82;
  }
  else {
    uVar3 = uVar3 | 1;
  }
LAB_00034941:
  return CONCAT44(unaff_EDX,uVar3);
}


/* ======== FUN_00034949 @ 00034949 ======== */

int FUN_00034949(undefined4 param_1,undefined param_2,uint unaff_EBX,undefined4 unaff_ECX,
                int param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(byte *)(param_5 + 0xc) = *(byte *)(param_5 + 0xc) & 0xfc;
  *(uint *)(param_5 + 0xc) = *(uint *)(param_5 + 0xc) | unaff_EBX;
  cVar1 = FUN_0003655b(param_2,unaff_ECX);
  if (cVar1 == 'r') {
    iVar2 = FUN_000349b7();
    return iVar2;
  }
  uVar3 = FUN_0003540c();
  *(undefined4 *)(param_5 + 0x10) = uVar3;
  if (*(int *)(param_5 + 0x10) == -1) {
    FUN_00036f79(param_5);
    return 0;
  }
  *(undefined4 *)(param_5 + 4) = 0;
  *(undefined4 *)(param_5 + 8) = 0;
  *(undefined4 *)(param_5 + 0x14) = 0;
  if ((unaff_EBX & 0x80) != 0) {
    FUN_00034c7f(param_5,0,2);
  }
  FUN_00036fd0(param_5);
  return param_5;
}


/* ======== FUN_000349b7 @ 000349b7 ======== */

int FUN_000349b7(undefined4 param_1,undefined4 param_2,uint unaff_EBX,int unaff_ECX)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0003540c();
  *(undefined4 *)(unaff_ECX + 0x10) = uVar1;
  if (*(int *)(unaff_ECX + 0x10) == -1) {
    FUN_00036f79(unaff_ECX);
    return 0;
  }
  *(undefined4 *)(unaff_ECX + 4) = 0;
  *(undefined4 *)(unaff_ECX + 8) = 0;
  *(undefined4 *)(unaff_ECX + 0x14) = 0;
  if ((unaff_EBX & 0x80) != 0) {
    FUN_00034c7f(unaff_ECX,0,2);
  }
  FUN_00036fd0(unaff_ECX);
  return unaff_ECX;
}


/* ======== FUN_00034a0d @ 00034a0d ======== */

int FUN_00034a0d(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_00034878(unaff_EDX,unaff_EDX,unaff_EBX,unaff_EBX);
  iVar1 = (int)uVar3;
  iVar2 = iVar1;
  if (iVar1 != 0) {
    uVar3 = FUN_00036ed3(0,(int)((ulonglong)uVar3 >> 0x20),iVar1);
    iVar2 = (int)uVar3;
    if (iVar2 != 0) {
      iVar2 = FUN_00034949(param_1,*(undefined *)((ulonglong)uVar3 >> 0x20),iVar1,unaff_EBX,iVar2);
    }
  }
  return iVar2;
}


/* ======== fopen @ 00034a46 ======== */

void fopen(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00034a0d(param_1,unaff_EDX,0,unaff_ECX,unaff_EBX);
  return;
}


/* ======== FUN_00034a50 @ 00034a50 ======== */

longlong FUN_00034a50(int param_1,uint unaff_EDX)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_001158bc;
  do {
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = &DAT_001158b8;
      do {
        puVar2 = puVar1;
        puVar1 = (undefined4 *)*puVar2;
        if (puVar1 == (undefined4 *)0x0) {
          FUN_0003652c(4);
          return (ulonglong)unaff_EDX << 0x20;
        }
      } while (param_1 != puVar1[1]);
      *puVar2 = *puVar1;
      *puVar1 = DAT_001158bc;
      DAT_001158bc = puVar1;
LAB_00034a77:
      return CONCAT44(unaff_EDX,param_1);
    }
    if (param_1 == puVar1[1]) {
      if ((*(byte *)(puVar1[1] + 0xc) & 3) != 0) {
        FUN_00034bad(param_1,1);
      }
      goto LAB_00034a77;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


/* ======== fclose @ 00034afa ======== */

undefined8 fclose(int param_1,undefined4 unaff_EDX)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_001158bc;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return CONCAT44(unaff_EDX,0xffffffff);
    }
    if (param_1 == puVar1[1]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  uVar2 = FUN_00034b27(param_1,1);
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_00034b27 @ 00034b27 ======== */

undefined4
FUN_00034b27(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  
  uVar1 = FUN_00034bad();
  FUN_00036f79(param_1,uVar1,param_1,unaff_ECX,unaff_EBX);
  return extraout_EDX;
}


/* ======== FUN_00034b3c @ 00034b3c ======== */

int FUN_00034b3c(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + 0x30;
  if (0x39 < iVar1) {
    iVar1 = param_1 + 0x57;
  }
  return iVar1;
}


/* ======== FUN_00034b48 @ 00034b48 ======== */

void FUN_00034b48(undefined *param_1,uint unaff_EDX)

{
  undefined uVar1;
  uint uVar2;
  undefined *extraout_EDX;
  undefined *puVar3;
  
  uVar2 = FUN_00037001();
  puVar3 = param_1 + 4;
  *param_1 = 0x74;
  do {
    uVar1 = FUN_00034b3c(uVar2 & 0xf,puVar3);
    *extraout_EDX = uVar1;
    puVar3 = extraout_EDX + -1;
    uVar2 = uVar2 >> 4;
  } while (puVar3 != param_1);
  param_1[5] = 0x5f;
  uVar1 = FUN_00034b3c((int)unaff_EDX >> 4 & 0xf);
  param_1[6] = uVar1;
  uVar1 = FUN_00034b3c(unaff_EDX & 0xf);
  param_1[8] = 0x2e;
  param_1[9] = 0x74;
  param_1[10] = 0x6d;
  param_1[0xb] = 0x70;
  param_1[0xc] = 0;
  param_1[7] = uVar1;
  return;
}


/* ======== FUN_00034bad @ 00034bad ======== */

uint FUN_00034bad(int param_1,int unaff_EDX)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined auStack_24 [16];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if ((*(byte *)(param_1 + 0xd) & 0x10) != 0) {
      uVar1 = FUN_00037007(param_1);
    }
    iVar2 = FUN_00034d7b(param_1);
    if (iVar2 != -1) {
      FUN_00035755(*(undefined4 *)(param_1 + 0x10),iVar2,0);
    }
    if (unaff_EDX != 0) {
      uVar3 = FUN_000370e0(*(undefined4 *)(param_1 + 0x10));
      uVar1 = uVar1 | uVar3;
    }
    if ((*(byte *)(param_1 + 0xc) & 8) != 0) {
      free(*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(param_1 + 8) = 0;
    }
    if ((*(byte *)(param_1 + 0xd) & 8) != 0) {
      FUN_00034b48(auStack_24,*(undefined *)(param_1 + 0x19));
      thunk_FUN_00038c71(auStack_24);
    }
  }
  return uVar1;
}


/* ======== FUN_00034c3d @ 00034c3d ======== */

undefined4 FUN_00034c3d(int param_1,int *unaff_EDX)

{
  *(byte *)(unaff_EDX + 3) = *(byte *)(unaff_EDX + 3) & 0xef;
  if ((param_1 <= unaff_EDX[1]) && (unaff_EDX[2] - *unaff_EDX <= param_1)) {
    *unaff_EDX = *unaff_EDX + param_1;
    unaff_EDX[1] = unaff_EDX[1] - param_1;
    return 0;
  }
  unaff_EDX[1] = 0;
  *unaff_EDX = unaff_EDX[2];
  return 1;
}


/* ======== FUN_00034c7f @ 00034c7f ======== */

/* WARNING: Removing unreachable block (ram,0x00034cf9) */

undefined4 FUN_00034c7f(undefined4 *param_1,int unaff_EDX,uint unaff_EBX)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 3) & 6) == 0) {
    if (unaff_EBX == 0) {
      iVar1 = FUN_0003711a(param_1[4]);
      iVar1 = FUN_00034c3d(unaff_EDX - (iVar1 - param_1[1]),param_1);
      if ((iVar1 != 0) && (iVar1 = FUN_00035755(param_1[4],unaff_EDX), iVar1 == -1)) {
        return 0xffffffff;
      }
    }
    else if (unaff_EBX < 2) {
      iVar1 = param_1[1];
      iVar2 = FUN_00034c3d(unaff_EDX,param_1);
      if ((iVar2 != 0) && (iVar1 = FUN_00035755(param_1[4],unaff_EDX - iVar1), iVar1 == -1)) {
        return 0xffffffff;
      }
    }
    else {
      if (unaff_EBX != 2) goto LAB_00034ca5;
      *param_1 = param_1[2];
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef;
      param_1[1] = 0;
      iVar1 = FUN_00035755(param_1[4],unaff_EDX);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
    }
  }
  else {
    if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
      if (unaff_EBX == 1) {
        unaff_EDX = unaff_EDX - param_1[1];
      }
      param_1[1] = 0;
      *param_1 = param_1[2];
    }
    else {
      iVar1 = FUN_00037007(param_1);
      if (iVar1 != 0) {
        if (unaff_EBX != 0) {
          return 0xffffffff;
        }
        if (-1 < unaff_EDX) {
          return 0xffffffff;
        }
LAB_00034ca5:
        FUN_0003652c(9);
        return 0xffffffff;
      }
    }
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xeb;
    iVar1 = FUN_00035755(param_1[4],unaff_EDX);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  return 0;
}


/* ======== FUN_00034d7b @ 00034d7b ======== */

undefined8 FUN_00034d7b(int param_1,undefined4 unaff_EDX)

{
  int extraout_EDX;
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0003711a(*(undefined4 *)(param_1 + 0x10),param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  iVar2 = (int)uVar3;
  if (iVar2 != -1) {
    if (((*(byte *)(iVar1 + 0xc) & 0x80) != 0) && ((*(byte *)(iVar1 + 0xd) & 0x10) != 0)) {
      FUN_0003712b(iVar1);
      iVar1 = extraout_EDX;
    }
    if (*(int *)(iVar1 + 4) != 0) {
      if ((*(byte *)(iVar1 + 0xd) & 0x10) != 0) {
        return CONCAT44(unaff_EDX,iVar2 + *(int *)(iVar1 + 4));
      }
      iVar2 = iVar2 - *(int *)(iVar1 + 4);
    }
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_00034dbd @ 00034dbd ======== */

uint FUN_00034dbd(uint param_1,int *unaff_EDX)

{
  int iVar1;
  uint uVar2;
  int extraout_EDX;
  int *extraout_EDX_00;
  undefined8 uVar3;
  
  if ((*(byte *)(unaff_EDX + 3) & 2) == 0) {
    FUN_0003652c(4);
    *(byte *)(extraout_EDX + 0xc) = *(byte *)(extraout_EDX + 0xc) | 0x20;
LAB_00034dd8:
    param_1 = 0xffffffff;
  }
  else {
    if (unaff_EDX[2] == 0) {
      FUN_00036569(unaff_EDX);
      unaff_EDX = extraout_EDX_00;
    }
    uVar2 = 0x400;
    if ((param_1 == 10) && (uVar2 = 0x600, (*(byte *)(unaff_EDX + 3) & 0x40) == 0)) {
      *(byte *)((int)unaff_EDX + 0xd) = *(byte *)((int)unaff_EDX + 0xd) | 0x10;
      *(undefined *)*unaff_EDX = 0xd;
      iVar1 = unaff_EDX[1];
      *unaff_EDX = *unaff_EDX + 1;
      unaff_EDX[1] = iVar1 + 1;
      if (iVar1 + 1 == unaff_EDX[5]) {
        uVar3 = FUN_00037007(unaff_EDX);
        unaff_EDX = (int *)((ulonglong)uVar3 >> 0x20);
        if ((int)uVar3 != 0) goto LAB_00034dd8;
      }
    }
    *(byte *)((int)unaff_EDX + 0xd) = *(byte *)((int)unaff_EDX + 0xd) | 0x10;
    *(char *)*unaff_EDX = (char)param_1;
    iVar1 = unaff_EDX[1];
    *unaff_EDX = *unaff_EDX + 1;
    unaff_EDX[1] = iVar1 + 1;
    if (((uVar2 & unaff_EDX[3]) != 0) || (iVar1 + 1 == unaff_EDX[5])) {
      iVar1 = FUN_00037007(unaff_EDX);
      if (iVar1 != 0) goto LAB_00034dd8;
    }
    param_1 = param_1 & 0xff;
  }
  return param_1;
}


/* ======== FUN_00034e61 @ 00034e61 ======== */

undefined8 FUN_00034e61(byte **param_1,undefined4 unaff_EDX)

{
  byte *pbVar1;
  uint uVar2;
  byte **extraout_EDX;
  int iVar3;
  undefined8 uVar4;
  
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    FUN_0003652c(4);
    uVar2 = 0xffffffff;
    *(byte *)(extraout_EDX + 3) = *(byte *)(extraout_EDX + 3) | 0x20;
    param_1 = extraout_EDX;
  }
  else {
    pbVar1 = param_1[1];
    param_1[1] = pbVar1 + -1;
    if ((int)(pbVar1 + -1) < 0) {
      uVar4 = FUN_00034eea(param_1);
      param_1 = (byte **)((ulonglong)uVar4 >> 0x20);
      uVar2 = (uint)uVar4;
    }
    else {
      uVar2 = (uint)**param_1;
      *param_1 = *param_1 + 1;
    }
  }
  uVar4 = CONCAT44(param_1,uVar2);
  if ((*(byte *)(param_1 + 3) & 0x40) == 0) {
    if (uVar2 == 0xd) {
      pbVar1 = param_1[1];
      param_1[1] = pbVar1 + -1;
      if ((int)(pbVar1 + -1) < 0) {
        uVar4 = FUN_00034eea(param_1);
      }
      else {
        uVar4 = CONCAT44(param_1,(uint)**param_1);
        *param_1 = *param_1 + 1;
      }
    }
    iVar3 = (int)((ulonglong)uVar4 >> 0x20);
    uVar2 = (uint)uVar4;
    if (uVar2 == 0x1a) {
      uVar2 = 0xffffffff;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x10;
    }
  }
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_00034eea @ 00034eea ======== */

undefined8 FUN_00034eea(undefined4 param_1,undefined4 unaff_EDX)

{
  byte *pbVar1;
  byte **ppbVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_00034f19(param_1,param_1);
  ppbVar2 = (byte **)((ulonglong)uVar3 >> 0x20);
  if ((int)uVar3 == 0) {
    return CONCAT44(unaff_EDX,0xffffffff);
  }
  pbVar1 = *ppbVar2;
  ppbVar2[1] = ppbVar2[1] + -1;
  *ppbVar2 = pbVar1 + 1;
  return CONCAT44(unaff_EDX,(uint)*pbVar1);
}


/* ======== FUN_00034f19 @ 00034f19 ======== */

undefined8 FUN_00034f19(undefined4 *param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[2] == 0) {
    FUN_00036569();
  }
  if (((*(byte *)((int)param_1 + 0xd) & 0x20) != 0) && ((*(byte *)((int)param_1 + 0xd) & 6) != 0)) {
    FUN_00037140(0x2000);
  }
  *param_1 = param_1[2];
  uVar1 = param_1[3];
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfb;
  if (((uVar1 & 0x2400) == 0x2400) && (param_1[4] == 0)) {
    param_1[1] = 0;
    iVar2 = FUN_0003716f();
    if (iVar2 != -1) {
      *(char *)*param_1 = (char)iVar2;
      param_1[1] = 1;
    }
  }
  else {
    uVar3 = FUN_000365e0(param_1[4],*param_1);
    param_1[1] = uVar3;
  }
  if ((int)param_1[1] < 1) {
    if (param_1[1] == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x10;
    }
    else {
      param_1[1] = 0;
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
    }
  }
  return CONCAT44(unaff_EDX,param_1[1]);
}


/* ======== FUN_00034fc5 @ 00034fc5 ======== */

int FUN_00034fc5(int param_1)

{
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ======== FUN_00034fcc @ 00034fcc ======== */

undefined4 * FUN_00034fcc(undefined4 *param_1,int unaff_EDX)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)malloc(unaff_EDX);
  }
  else if (unaff_EDX == 0) {
    free();
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = FUN_0003718c();
    puVar1 = (undefined4 *)FUN_00037195(param_1);
    if (puVar1 == (undefined4 *)0x0) {
      if ((DAT_00058ffe == '\x01') && (iVar3 = FUN_00036860(param_1 + -1,unaff_EDX + 4), iVar3 != 0)
         ) {
        puVar1 = (undefined4 *)(iVar3 + 4);
      }
      else {
        puVar1 = (undefined4 *)malloc(unaff_EDX);
        if (puVar1 == (undefined4 *)0x0) {
          FUN_00037195(param_1,uVar2);
        }
        else {
          puVar5 = param_1;
          puVar6 = puVar1;
          for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
          for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined *)puVar6 = *(undefined *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          free(param_1);
        }
      }
    }
  }
  return puVar1;
}


/* ======== FUN_00035092 @ 00035092 ======== */

void FUN_00035092(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  if (DAT_00059224 == 0) {
    DAT_00059224 = 1;
    FUN_000373c8(s_pure_virtual_function_called__0006581c,1,unaff_EBX,unaff_ECX,unaff_EDX);
  }
  return;
}


/* ======== thunk_FUN_00037417 @ 000350b8 ======== */

void thunk_FUN_00037417(int param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  if (param_1 != 0) {
    uVar2 = param_1 * DAT_001158c0 + 500;
    uVar3 = uVar2 / 1000;
    if (uVar3 == 0) {
      uVar3 = 1;
    }
    lVar4 = (ulonglong)(uVar2 % 1000) << 0x20;
    uVar5 = unaff_ECX;
    do {
      pcVar1 = (code *)swi(0x21);
      lVar4 = (*pcVar1)(CONCAT11(0x2c,(char)lVar4),(int)((ulonglong)lVar4 >> 0x20),0x300,unaff_ECX,
                        unaff_EDX,uVar5,unaff_EBX);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}


/* ======== FUN_000350bd @ 000350bd ======== */

void FUN_000350bd(void)

{
  return;
}


/* ======== FUN_000350bf @ 000350bf ======== */

void FUN_000350bf(void)

{
  return;
}


/* ======== FUN_000350c1 @ 000350c1 ======== */

void FUN_000350c1(void)

{
  return;
}


/* ======== exit @ 000350c2 ======== */

void exit(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_00058f9c)(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX);
  (*(code *)PTR_FUN_00058fa0)();
  FUN_000350da(extraout_EDX);
  return;
}


/* ======== FUN_000350da @ 000350da ======== */

void FUN_000350da(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_00058fa0)(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX);
  (*(code *)PTR_FUN_00058fa4)();
  thunk_FUN_000341cc(extraout_EDX);
  return;
}


/* ======== FUN_00035115 @ 00035115 ======== */

char * FUN_00035115(uint param_1,char *unaff_EDX,uint unaff_EBX)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char local_37 [35];
  
  pcVar3 = local_37;
  do {
    uVar2 = param_1 / unaff_EBX;
    *pcVar3 = s_0123456789abcdefghijklmnopqrstuv_000350f0[param_1 % unaff_EBX];
    pcVar3 = pcVar3 + 1;
    param_1 = uVar2;
    pcVar4 = unaff_EDX;
  } while (uVar2 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return unaff_EDX;
}


/* ======== FUN_0003515f @ 0003515f ======== */

undefined * FUN_0003515f(int param_1,undefined *unaff_EDX,int unaff_EBX)

{
  if ((unaff_EBX == 10) && (param_1 < 0)) {
    param_1 = -param_1;
    *unaff_EDX = 0x2d;
  }
  FUN_00035115(param_1);
  return unaff_EDX;
}


/* ======== FUN_0003517a @ 0003517a ======== */

undefined8 FUN_0003517a(char *param_1,undefined4 unaff_EDX)

{
  char cVar1;
  char *pcVar2;
  
  for (pcVar2 = param_1; cVar1 = *pcVar2, cVar1 != '\0'; pcVar2 = pcVar2 + 1) {
    if ((byte)(cVar1 + 0x9fU) < 0x1a) {
      *pcVar2 = cVar1 + -0x20;
    }
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_000351a0 @ 000351a0 ======== */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined8 FUN_000351a0(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  LOCK();
  *(undefined4 *)(unaff_EBP + 0x28) = param_1;
  UNLOCK();
  LOCK();
  uVar1 = *(undefined4 *)(unaff_EBP + 0x2c);
  *(undefined4 *)(unaff_EBP + 0x2c) = unaff_EDX;
  UNLOCK();
  return CONCAT44(*(undefined4 *)(unaff_EBP + 0x24),uVar1);
}


/* ======== FUN_000351b9 @ 000351b9 ======== */

undefined4 *
FUN_000351b9(undefined4 *param_1,undefined4 param_2,undefined4 *unaff_EBX,undefined4 param_4,
            uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (uVar1 = param_5 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *unaff_EBX;
    unaff_EBX = unaff_EBX + 1;
    puVar2 = puVar2 + 1;
  }
  for (param_5 = param_5 & 3; param_5 != 0; param_5 = param_5 - 1) {
    *(undefined *)puVar2 = *(undefined *)unaff_EBX;
    unaff_EBX = (undefined4 *)((int)unaff_EBX + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_1;
}


/* ======== operator_delete @ 000351e4 ======== */

void operator_delete(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 in_DS;
  
  if (param_1 != 0) {
    if (param_1 != 0) {
      uVar1 = DAT_00058f90;
      if (((DAT_001158b0 == 0) || (param_1 < DAT_001158b0)) ||
         (uVar2 = DAT_001158b0, *(uint *)(DAT_001158b0 + 8) <= param_1)) {
        for (; (uVar2 = uVar1, *(uint *)(uVar1 + 8) != 0 &&
               ((param_1 < uVar1 || (*(uint *)(uVar1 + 8) <= param_1))));
            uVar1 = *(uint *)(uVar1 + 8)) {
        }
      }
      FUN_000366a8(param_1,in_DS,uVar2);
      if ((uVar2 < DAT_00058f94) && (DAT_00058f98 < *(uint *)(uVar2 + 0x14))) {
        DAT_00058f98 = *(uint *)(uVar2 + 0x14);
      }
      DAT_001158b4 = 0;
      DAT_001158b0 = uVar2;
    }
    return;
  }
  return;
}


/* ======== operator_new @ 000351f0 ======== */

undefined8 operator_new(int param_1,undefined4 unaff_EDX)

{
  int extraout_EDX;
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
LAB_000351fe:
  uVar1 = malloc(param_1);
  if ((int)uVar1 == 0) {
    if (DAT_00115890 != (code *)0x0) goto code_r0x00035217;
    goto LAB_00035220;
  }
LAB_00035233:
  return CONCAT44(unaff_EDX,(int)uVar1);
code_r0x00035217:
  uVar2 = (*DAT_00115890)((int)((ulonglong)uVar1 >> 0x20));
  param_1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((int)uVar2 == 0) {
LAB_00035220:
    if (DAT_0011588c == (code *)0x0) goto LAB_00035233;
    (*DAT_0011588c)();
    param_1 = extraout_EDX;
  }
  goto LAB_000351fe;
}


/* ======== FUN_0003523b @ 0003523b ======== */

undefined8 FUN_0003523b(byte *param_1,undefined4 unaff_EDX)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  while (((&DAT_00065c3c)[(byte)(*param_1 + 1)] & 2) != 0) {
    param_1 = param_1 + 1;
  }
  bVar1 = *param_1;
  if ((bVar1 == 0x2b) || (bVar1 == 0x2d)) {
    param_1 = param_1 + 1;
  }
  iVar3 = 0;
  while (((&DAT_00065c3c)[(byte)(*param_1 + 1)] & 0x20) != 0) {
    bVar2 = *param_1;
    param_1 = param_1 + 1;
    iVar3 = iVar3 * 10 + (uint)bVar2 + -0x30;
  }
  if (bVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return CONCAT44(unaff_EDX,iVar3);
}


/* ======== clock_ticks @ 000352a8 ======== */

undefined8 clock_ticks(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  
  uVar1 = FUN_0003744d();
  if (uVar1 < DAT_001158c4) {
    uVar1 = uVar1 + 0x83d600;
  }
  return CONCAT44(unaff_EDX,uVar1 - DAT_001158c4);
}


/* ======== FUN_000352b0 @ 000352b0 ======== */

int FUN_000352b0(int param_1)

{
  return param_1 + 4;
}


/* ======== FUN_000352b4 @ 000352b4 ======== */

int FUN_000352b4(int param_1,int unaff_EDX)

{
  return param_1 + *(int *)(unaff_EDX * 8 + *(int *)(param_1 + 4));
}


/* ======== FUN_000352c1 @ 000352c1 ======== */

void FUN_000352c1(int param_1)

{
  *(undefined *)(param_1 + 8) = 0;
  return;
}


/* ======== FUN_000352db @ 000352db ======== */

undefined4
FUN_000352db(undefined4 param_1,undefined4 param_2,undefined4 *unaff_EBX,undefined4 unaff_ECX)

{
  FUN_000376d2(param_1,unaff_EBX,unaff_ECX);
  return *unaff_EBX;
}


/* ======== FUN_000352f4 @ 000352f4 ======== */

undefined * FUN_000352f4(void)

{
  return &DAT_00058fbc;
}


/* ======== FUN_000352fa @ 000352fa ======== */

undefined8 FUN_000352fa(undefined4 param_1,undefined4 unaff_EDX)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_000352f4();
  if (puVar1 != (uint *)0x0) {
    uVar2 = *puVar1 * 0x41c64e6d + 0x3039;
    *puVar1 = uVar2;
    puVar1 = (uint *)(uVar2 >> 0x10 & 0x7fff);
  }
  return CONCAT44(unaff_EDX,puVar1);
}


/* ======== FUN_0003531e @ 0003531e ======== */

void FUN_0003531e(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000352f4(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX);
  if ((undefined4 *)uVar1 != (undefined4 *)0x0) {
    *(undefined4 *)uVar1 = (int)((ulonglong)uVar1 >> 0x20);
  }
  return;
}


/* ======== FUN_0003532e @ 0003532e ======== */

char * FUN_0003532e(char *param_1,char *unaff_EDX,int unaff_EBX)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  for (; (unaff_EBX != 0 && (*unaff_EDX != '\0')); unaff_EDX = unaff_EDX + 1) {
    unaff_EBX = unaff_EBX + -1;
    *pcVar1 = *unaff_EDX;
    pcVar1 = pcVar1 + 1;
  }
  for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    *pcVar1 = '\0';
    pcVar1 = pcVar1 + 1;
  }
  return param_1;
}


/* ======== FUN_00035353 @ 00035353 ======== */

byte * FUN_00035353(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte abStack_28 [32];
  
  if ((param_1 != (byte *)0x0) ||
     (pbVar2 = param_1, param_1 = DAT_00058fc0, DAT_00058fc0 != (byte *)0x0)) {
    FUN_00037ab0(abStack_28);
    while( true ) {
      bVar1 = *param_1;
      pbVar2 = (byte *)(uint)bVar1;
      if ((pbVar2 == (byte *)0x0) || ((abStack_28[bVar1 >> 3] & (&DAT_00065d40)[bVar1 & 7]) == 0))
      break;
      param_1 = param_1 + 1;
    }
    pbVar3 = param_1;
    if (pbVar2 != (byte *)0x0) {
      for (; bVar1 = *pbVar3, bVar1 != 0; pbVar3 = pbVar3 + 1) {
        if ((abStack_28[bVar1 >> 3] & (&DAT_00065d40)[bVar1 & 7]) != 0) {
          *pbVar3 = 0;
          DAT_00058fc0 = pbVar3 + 1;
          return param_1;
        }
      }
      DAT_00058fc0 = (byte *)0x0;
      pbVar2 = param_1;
    }
  }
  return pbVar2;
}


/* ======== FUN_000353e8 @ 000353e8 ======== */

void FUN_000353e8(void)

{
  FUN_0003540c();
  return;
}


/* ======== FUN_0003540c @ 0003540c ======== */

undefined8 FUN_0003540c(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_ECX;
  uint uVar4;
  byte bVar5;
  bool bVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char *param_5;
  byte param_6;
  byte param_7;
  byte bStack00000010;
  uint in_stack_00000014;
  uint local_1c;
  uint uStack_18;
  
  for (; *param_5 == ' '; param_5 = param_5 + 1) {
  }
  local_1c._0_1_ = param_6 & 0x83;
  bVar5 = 0;
  uVar4 = 0xffffffff;
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x3d,(byte)local_1c | param_7),param_5);
  local_1c = (iVar2 << 1 | (uint)bVar5) >> 1;
  if ((bVar5 & 1) == 0) {
    uVar4 = local_1c & 0xffff;
  }
  if (((_param_7 & 3) == 0) || (uVar4 == 0xffffffff)) {
LAB_000354d9:
    if (uVar4 != 0xffffffff) goto LAB_0003557b;
    if (((_param_7 & 0x20) != 0) && ((short)local_1c == 2)) {
      if (in_stack_00000014 == 0) {
        in_stack_00000014 = 0x180;
      }
      bVar5 = 0;
      pcVar1 = (code *)swi(0x21);
      iVar2 = (*pcVar1)(CONCAT22((short)((in_stack_00000014 & ~DAT_00059240) >> 0x10),
                                 CONCAT11(0x3c,(char)(in_stack_00000014 & ~DAT_00059240))),param_5);
      bVar6 = (bVar5 & 1) != 0;
      uVar3 = (iVar2 << 1 | (uint)bVar5) >> 1;
      local_1c = uVar3 | (uint)bVar6 << 0x1f;
      if (!bVar6) {
        uVar4 = uVar3 & 0xffff;
        bVar5 = 0;
        if (_bStack00000010 == 0) {
LAB_0003557b:
          uVar3 = FUN_00037b91(uVar4);
          uVar8 = FUN_00037aee(uVar4,uVar3 & 0xffffff3c);
          uVar3 = (uint)((ulonglong)uVar8 >> 0x20);
          if ((int)uVar8 != 0) {
            uVar3 = uVar3 | 0x2000;
          }
          uStack_18 = uStack_18 & 0xffffff7f;
          if (uStack_18 == 2) {
            uVar3 = uVar3 | 3;
          }
          if (uStack_18 == 0) {
            uVar3 = uVar3 | 1;
          }
          if (uStack_18 == 1) {
            uVar3 = uVar3 | 2;
          }
          if ((_param_7 & 0x10) != 0) {
            uVar3 = uVar3 | 0x80;
          }
          if ((_param_7 & 0x300) == 0) {
            if (DAT_00059219 == 0x200) goto LAB_000355e1;
          }
          else if ((_param_7 & 0x200) != 0) {
LAB_000355e1:
            uVar3 = uVar3 | 0x40;
          }
          FUN_00037be6(uVar4,uVar3);
          goto LAB_000355ec;
        }
        pcVar1 = (code *)swi(0x21);
        iVar2 = (*pcVar1)(CONCAT22((short)(local_1c >> 0x10),CONCAT11(0x3e,(char)uVar3)),
                          _bStack00000010,uVar4);
        bVar6 = (bVar5 & 1) != 0;
        local_1c = (iVar2 << 1 | (uint)bVar5) >> 1 | (uint)bVar6 << 0x1f;
        if (!bVar6) {
          bVar5 = 0;
          pcVar1 = (code *)swi(0x21);
          iVar2 = (*pcVar1)(CONCAT22((short)(local_1c >> 0x10),
                                     CONCAT11(0x3d,(byte)uStack_18 | bStack00000010)),param_5);
          local_1c = (iVar2 << 1 | (uint)bVar5) >> 1;
          if ((bVar5 & 1) == 0) {
            uVar4 = local_1c & 0xffff;
            goto LAB_0003557b;
          }
        }
      }
    }
  }
  else {
    uVar7 = FUN_00037aee(uVar4);
    if ((int)uVar7 != 0) goto LAB_000354d9;
    if (((_param_7 & 0x400) != 0) && ((uVar7 & 0x2000000000) != 0)) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x3e00,(int)(uVar7 >> 0x20),uVar4);
      FUN_0003652c(7);
      uVar4 = 0xffffffff;
      goto LAB_000355ec;
    }
    if ((_param_7 & 0x40) == 0) goto LAB_000354d9;
    bVar5 = 0;
    pcVar1 = (code *)swi(0x21);
    uVar8 = (*pcVar1)(0x4000,&stack0xffffffec,uVar4);
    bVar6 = (bVar5 & 1) != 0;
    uVar3 = ((int)uVar8 << 1 | (uint)bVar5) >> 1;
    local_1c = uVar3 | (uint)bVar6 << 0x1f;
    if (!bVar6) goto LAB_000354d9;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT22((short)(local_1c >> 0x10),CONCAT11(0x3e,(char)uVar3)),
              (int)((ulonglong)uVar8 >> 0x20),uVar4);
  }
  uVar4 = FUN_00037b20(local_1c & 0xffff);
LAB_000355ec:
  return CONCAT44(unaff_ECX,uVar4);
}


/* ======== FUN_0003565a @ 0003565a ======== */

uint FUN_0003565a(undefined4 param_1,char *unaff_EDX,int unaff_EBX)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  bool bVar11;
  ulonglong uVar12;
  
  uVar12 = FUN_00037b91();
  iVar4 = (int)uVar12;
  if (iVar4 == 0) {
    uVar3 = 4;
  }
  else {
    if ((uVar12 & 1) != 0) {
      bVar10 = 0;
      if ((uVar12 & 0x40) == 0) {
        uVar5 = 0;
        while( true ) {
          bVar10 = 0;
          pcVar1 = (code *)swi(0x21);
          iVar4 = (*pcVar1)(CONCAT22((short)((uint)iVar4 >> 0x10),CONCAT11(0x3f,(char)iVar4)),
                            unaff_EDX,param_1,unaff_EBX);
          bVar11 = (bVar10 & 1) != 0;
          uVar2 = (iVar4 << 1 | (uint)bVar10) >> 1;
          uVar6 = uVar2 | (uint)bVar11 << 0x1f;
          if (bVar11) break;
          if (uVar6 == 0) {
            return uVar5;
          }
          iVar4 = 0;
          iVar9 = 0;
          for (pcVar7 = unaff_EDX; pcVar7 < unaff_EDX + uVar6; pcVar7 = pcVar7 + 1) {
            if (*pcVar7 == '\x1a') {
              FUN_00035755(param_1,(iVar4 - uVar6) + 1,1);
              return uVar5;
            }
            iVar8 = iVar9;
            if (*pcVar7 != '\r') {
              uVar5 = uVar5 + 1;
              iVar8 = iVar9 + 1;
              unaff_EDX[iVar9] = *pcVar7;
            }
            iVar4 = iVar4 + 1;
            iVar9 = iVar8;
          }
          iVar4 = CONCAT22((short)((uint)pcVar7 >> 0x10),(ushort)(byte)pcVar7);
          unaff_EBX = unaff_EBX - iVar9;
          unaff_EDX = unaff_EDX + iVar9;
          if ((uVar12 & 0x2000) != 0) {
            return uVar5;
          }
          if (unaff_EBX == 0) {
            return uVar5;
          }
        }
      }
      else {
        pcVar1 = (code *)swi(0x21);
        iVar4 = (*pcVar1)(CONCAT11(0x3f,(char)uVar12),(int)(uVar12 >> 0x20),param_1,unaff_EBX);
        bVar11 = (bVar10 & 1) != 0;
        uVar2 = (iVar4 << 1 | (uint)bVar10) >> 1;
        if (!bVar11) {
          return uVar2 | (uint)bVar11 << 0x1f;
        }
      }
      uVar5 = FUN_00037b20(uVar2 & 0xffff);
      return uVar5;
    }
    uVar3 = 6;
  }
  FUN_0003652c(uVar3);
  return 0xffffffff;
}


/* ======== FUN_00035755 @ 00035755 ======== */

undefined4 FUN_00035755(undefined4 param_1,uint unaff_EDX,undefined unaff_BL)

{
  code *pcVar1;
  int iVar2;
  undefined4 unaff_EDI;
  byte bVar3;
  
  bVar3 = (unaff_EDX >> 0xf & 1) != 0;
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x42,unaff_BL),unaff_EDX,param_1,unaff_EDX >> 0x10);
  if ((bVar3 & 1) != 0) {
    FUN_00037b20((iVar2 << 1 | (uint)bVar3) >> 1 & 0xffff);
    unaff_EDI = 0xffffffff;
  }
  return unaff_EDI;
}


/* ======== FUN_00035798 @ 00035798 ======== */

undefined4 FUN_00035798(uint param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  byte bVar2;
  
  if ((-1 < (int)param_1) && (bVar2 = param_1 < DAT_00059244, param_1 <= DAT_00059244)) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT11(0x3e,(char)param_1),unaff_EDX,param_1,param_1,unaff_ECX,unaff_EBX);
    if ((bVar2 & 1) == 0) {
      FUN_00037be6(param_1,0);
      return 0;
    }
    FUN_0003652c(4);
    return 0xffffffff;
  }
  FUN_0003652c(4);
  return 0xffffffff;
}


/* ======== FUN_000357b8 @ 000357b8 ======== */

int FUN_000357b8(byte *param_1,undefined *unaff_EDX,int unaff_EBX)

{
  byte bVar2;
  uint uVar1;
  
  while( true ) {
    if (unaff_EBX == 0) {
      return 0;
    }
    bVar2 = *param_1;
    uVar1 = (uint)CONCAT11(*unaff_EDX,bVar2);
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      uVar1 = (uint)CONCAT11(*unaff_EDX,bVar2 + 0x20);
    }
    bVar2 = (byte)(uVar1 >> 8);
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      uVar1 = (uint)CONCAT11(bVar2 + 0x20,(char)uVar1);
    }
    bVar2 = (byte)(uVar1 >> 8);
    if ((byte)uVar1 != bVar2) break;
    if (bVar2 == 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    unaff_EDX = unaff_EDX + 1;
    unaff_EBX = unaff_EBX + -1;
  }
  return (uVar1 & 0xff) - (uint)bVar2;
}


/* ======== FUN_0003580b @ 0003580b ======== */

void FUN_0003580b(code **param_1)

{
  (**param_1)();
  return;
}


/* ======== FUN_00035812 @ 00035812 ======== */

void FUN_00035812(undefined4 param_1,int unaff_EDX)

{
  (**(code **)(unaff_EDX + 4))();
  return;
}


/* ======== FUN_0003581a @ 0003581a ======== */

int FUN_0003581a(int param_1,byte *unaff_EDX,undefined4 unaff_EBX)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int local_14;
  
  iVar9 = 0;
  local_14 = 0;
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0xfd;
  do {
    pbVar4 = unaff_EDX + 1;
    uVar7 = (uint)*unaff_EDX;
    if (uVar7 == 0) goto LAB_00035a41;
    if (((&DAT_00065c3c)[(byte)(*unaff_EDX + 1)] & 2) != 0) {
      iVar2 = FUN_00035b56(param_1);
      iVar9 = iVar9 + iVar2;
      goto LAB_00035a01;
    }
    if (uVar7 == 0x25) {
      pbVar4 = (byte *)FUN_00035a61(pbVar4,param_1);
      bVar1 = *pbVar4;
      if (bVar1 != 0) {
        pbVar4 = pbVar4 + 1;
      }
      if (bVar1 < 0x65) {
        if (0x57 < bVar1) {
          if (bVar1 < 0x59) goto LAB_00035992;
          if (bVar1 < 99) {
            if (bVar1 != 0x5b) goto LAB_00035a01;
            iVar2 = FUN_00035dee(param_1,unaff_EBX,&stack0xffffffe8);
          }
          else {
            if (99 < bVar1) {
              uVar8 = 10;
              goto LAB_00035961;
            }
            iVar2 = FUN_00035b95(param_1,unaff_EBX);
          }
          goto LAB_000359ca;
        }
        if (bVar1 < 0x45) {
          if (bVar1 == 0x25) {
            uVar3 = FUN_0003580b(param_1);
            if (uVar3 != 0x25) goto LAB_0003588a;
            goto LAB_00035a00;
          }
        }
        else if ((bVar1 < 0x46) || (bVar1 == 0x47)) goto LAB_0003599e;
      }
      else if (bVar1 < 0x68) {
LAB_0003599e:
        iVar2 = FUN_00035ee8(param_1,unaff_EBX);
LAB_000359ca:
        if (iVar2 < 1) goto LAB_00035a41;
        iVar9 = iVar9 + iVar2;
        if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
          local_14 = local_14 + 1;
        }
      }
      else if (bVar1 < 0x70) {
        if (bVar1 < 0x6e) {
          if (bVar1 == 0x69) {
            uVar6 = 1;
            uVar8 = 0;
            goto LAB_00035965;
          }
        }
        else {
          if (0x6e < bVar1) {
            uVar8 = 8;
            goto LAB_00035961;
          }
          FUN_00035d4d(param_1,unaff_EBX,iVar9);
        }
      }
      else {
        if (bVar1 < 0x71) {
LAB_00035992:
          uVar8 = 0x10;
LAB_00035961:
          uVar6 = 1;
LAB_00035965:
          iVar2 = FUN_000361ff(param_1,unaff_EBX,uVar8,uVar6);
          goto LAB_000359ca;
        }
        if (bVar1 < 0x75) {
          if (bVar1 == 0x73) {
            iVar2 = FUN_00035c2a(param_1,unaff_EBX);
            goto LAB_000359ca;
          }
        }
        else {
          if (bVar1 < 0x76) {
            uVar8 = 10;
            uVar6 = 0;
            goto LAB_00035965;
          }
          if (bVar1 == 0x78) goto LAB_00035992;
        }
      }
    }
    else {
      uVar3 = FUN_0003580b(param_1);
      if (uVar3 != uVar7) {
LAB_0003588a:
        if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
          FUN_00035812(uVar3,param_1);
        }
        goto LAB_00035a41;
      }
LAB_00035a00:
      iVar9 = iVar9 + 1;
    }
LAB_00035a01:
    unaff_EDX = pbVar4;
  } while ((*(byte *)(param_1 + 0x10) & 2) == 0);
  if ((*pbVar4 == 0x25) && (pcVar5 = (char *)FUN_00035a61(pbVar4 + 1,param_1), *pcVar5 == 'n')) {
    FUN_00035d4d(param_1,unaff_EBX,iVar9);
  }
LAB_00035a41:
  if ((local_14 == 0) && ((*(byte *)(param_1 + 0x10) & 2) != 0)) {
    local_14 = -1;
  }
  return local_14;
}


/* ======== FUN_00035a61 @ 00035a61 ======== */

byte * FUN_00035a61(byte *param_1,int unaff_EDX)

{
  byte bVar1;
  int iVar2;
  uint local_10;
  
  bVar1 = *(byte *)(unaff_EDX + 0x10);
  *(byte *)(unaff_EDX + 0x10) = bVar1 | 1;
  *(undefined4 *)(unaff_EDX + 0xc) = 0xffffffff;
  *(byte *)(unaff_EDX + 0x10) = bVar1 & 3 | 1;
  if (*param_1 == 0x2a) {
    param_1 = param_1 + 1;
    *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) & 0xfe;
  }
  bVar1 = *param_1;
  if (((&DAT_00065c3c)[(byte)(bVar1 + 1)] & 0x20) != 0) {
    iVar2 = 0;
    do {
      local_10 = (uint)bVar1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 * 10 + (local_10 - 0x30);
      bVar1 = *param_1;
    } while (((&DAT_00065c3c)[(byte)(bVar1 + 1)] & 0x20) != 0);
    *(int *)(unaff_EDX + 0xc) = iVar2;
  }
  if (*param_1 == 0x4e) {
    *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) | 8;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x46) {
    *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) | 4;
    param_1 = param_1 + 1;
  }
  bVar1 = *param_1;
  if (bVar1 < 0x68) {
    if (bVar1 == 0x4c) {
      *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) | 0x40;
      param_1 = param_1 + 1;
    }
  }
  else if (bVar1 < 0x69) {
    *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) | 0x10;
    param_1 = param_1 + 1;
  }
  else if ((0x6b < bVar1) && ((bVar1 < 0x6d || (bVar1 == 0x77)))) {
    *(byte *)(unaff_EDX + 0x10) = *(byte *)(unaff_EDX + 0x10) | 0x20;
    param_1 = param_1 + 1;
  }
  return param_1;
}


/* ======== FUN_00035b56 @ 00035b56 ======== */

undefined8 FUN_00035b56(int param_1,undefined4 unaff_EDX)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = FUN_0003580b(param_1);
    if (((&DAT_00065c3c)[(byte)((char)uVar1 + 1)] & 2) == 0) break;
    iVar2 = iVar2 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    FUN_00035812(uVar1,param_1);
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_00035b95 @ 00035b95 ======== */

int FUN_00035b95(int param_1,int *unaff_EDX,undefined4 param_3,undefined2 *unaff_ECX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  int iVar5;
  int extraout_EDX;
  int iVar6;
  undefined local_18;
  
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if ((*(byte *)(param_1 + 0x10) & 8) == 0) {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ECX = (undefined2 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ECX = (undefined2 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*unaff_EDX;
      *unaff_EDX = (int)(puVar2 + 1);
      unaff_ECX = (undefined2 *)*puVar2;
    }
  }
  iVar5 = *(int *)(param_1 + 0xc);
  iVar6 = 0;
  if (iVar5 == -1) {
    iVar5 = 1;
  }
  while( true ) {
    if (iVar5 < 1) {
      return iVar6;
    }
    uVar4 = FUN_0003580b(param_1);
    bVar1 = *(byte *)(param_1 + 0x10);
    if ((bVar1 & 2) != 0) break;
    iVar6 = iVar6 + 1;
    iVar5 = extraout_EDX + -1;
    if ((bVar1 & 1) != 0) {
      if ((bVar1 & 0x20) == 0) {
        local_18 = (undefined)uVar4;
        *(undefined *)unaff_ECX = local_18;
        unaff_ECX = (undefined2 *)((int)unaff_ECX + 1);
      }
      else {
        *unaff_ECX = uVar4;
        unaff_ECX = unaff_ECX + 1;
      }
    }
  }
  return iVar6;
}


/* ======== FUN_00035c2a @ 00035c2a ======== */

int FUN_00035c2a(int param_1,int *unaff_EDX,undefined4 param_3,undefined2 *unaff_ECX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  byte local_18;
  
  if ((*(byte *)(param_1 + 0x10) & 0x20) == 0) {
    local_18 = 1;
  }
  else {
    local_18 = 2;
  }
  bVar1 = *(byte *)(param_1 + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ECX = (undefined2 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ECX = (undefined2 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*unaff_EDX;
      *unaff_EDX = (int)(puVar2 + 1);
      unaff_ECX = (undefined2 *)*puVar2;
    }
  }
  iVar5 = 0;
  while( true ) {
    local_1c = FUN_0003580b(param_1);
    if (((&DAT_00065c3c)[(byte)((char)local_1c + 1)] & 2) == 0) break;
    iVar5 = iVar5 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    iVar4 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar4 + -1;
    if (iVar4 != 0) {
      do {
        iVar5 = iVar5 + 1;
        if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
          if (local_18 == 1) {
            *(char *)unaff_ECX = (char)local_1c;
          }
          else {
            *unaff_ECX = (short)local_1c;
          }
          unaff_ECX = (undefined2 *)((int)unaff_ECX + (uint)local_18);
        }
        local_1c = FUN_00036416(param_1);
        if (local_1c == -1) goto LAB_00035d22;
      } while (((&DAT_00065c3c)[(byte)((char)local_1c + 1)] & 2) == 0);
    }
    FUN_00035812(local_1c,param_1);
  }
  else {
    iVar5 = 0;
  }
LAB_00035d22:
  if (((*(byte *)(param_1 + 0x10) & 1) != 0) && (0 < iVar5)) {
    if (local_18 == 1) {
      *(undefined *)unaff_ECX = 0;
    }
    else {
      *unaff_ECX = 0;
    }
  }
  return iVar5;
}


/* ======== FUN_00035d4d @ 00035d4d ======== */

void FUN_00035d4d(int param_1,int *unaff_EDX,undefined4 unaff_EBX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        puVar3 = (undefined4 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*unaff_EDX;
      *unaff_EDX = (int)(puVar2 + 1);
      puVar3 = (undefined4 *)*puVar2;
    }
    if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
      *(short *)puVar3 = (short)unaff_EBX;
      return;
    }
    *puVar3 = unaff_EBX;
  }
  return;
}


/* ======== FUN_00035dab @ 00035dab ======== */

byte * FUN_00035dab(byte *param_1,int unaff_EDX)

{
  byte *pbVar1;
  uint uVar2;
  
  memset(unaff_EDX,0,0x20);
  uVar2 = (uint)*param_1;
  param_1 = param_1 + 1;
  if (uVar2 != 0) {
    do {
      pbVar1 = (byte *)(((int)uVar2 >> 3) + unaff_EDX);
      *pbVar1 = *pbVar1 | (&DAT_00065c34)[uVar2 & 7];
      uVar2 = (uint)*param_1;
      if (uVar2 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
    } while (uVar2 != 0x5d);
  }
  return param_1;
}


/* ======== FUN_00035dee @ 00035dee ======== */

int FUN_00035dee(int param_1,int *unaff_EDX,char **unaff_EBX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined *unaff_ESI;
  int iVar6;
  undefined8 uVar7;
  byte abStack_40 [32];
  uint local_20;
  uint local_1c;
  uint local_18;
  
  local_1c = (uint)(**unaff_EBX == '^');
  if (local_1c != 0) {
    *unaff_EBX = *unaff_EBX + 1;
  }
  pcVar4 = (char *)FUN_00035dab(*unaff_EBX,abStack_40);
  *unaff_EBX = pcVar4;
  bVar1 = *(byte *)(param_1 + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ESI = (undefined *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar3 + 1);
        unaff_ESI = (undefined *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*unaff_EDX;
      *unaff_EDX = (int)(puVar2 + 1);
      unaff_ESI = (undefined *)*puVar2;
    }
  }
  iVar5 = *(int *)(param_1 + 0xc);
  iVar6 = 0;
  do {
    if (iVar5 == 0) {
LAB_00035ecf:
      if (((*(byte *)(param_1 + 0x10) & 1) != 0) && (0 < iVar6)) {
        *unaff_ESI = 0;
      }
      return iVar6;
    }
    uVar7 = FUN_0003580b(param_1);
    local_18 = (uint)uVar7;
    if ((*(byte *)(param_1 + 0x10) & 2) != 0) goto LAB_00035ecf;
    local_20 = (uint)abStack_40[(int)local_18 >> 3];
    if ((((&DAT_00065c34)[local_18 & 7] & abStack_40[(int)local_18 >> 3]) == 0) != local_1c) {
      FUN_00035812(local_18,param_1);
      goto LAB_00035ecf;
    }
    iVar6 = iVar6 + 1;
    iVar5 = (int)((ulonglong)uVar7 >> 0x20) + -1;
    if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
      local_18._0_1_ = (undefined)uVar7;
      *unaff_ESI = (undefined)local_18;
      unaff_ESI = unaff_ESI + 1;
    }
  } while( true );
}


/* ======== FUN_00035ee8 @ 00035ee8 ======== */

int FUN_00035ee8(int param_1,int *unaff_EDX)

{
  byte bVar1;
  undefined6 *puVar2;
  int **ppiVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char local_84;
  char local_83 [79];
  int local_34;
  int local_30;
  uint local_2c;
  int local_24;
  undefined2 local_1c;
  short sStack_1a;
  
  pcVar6 = &local_84;
  iVar9 = 0;
  local_24 = 0;
  while( true ) {
    iVar5 = FUN_0003580b(param_1);
    if (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 2) == 0) break;
    local_24 = local_24 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) goto LAB_00036139;
  iVar10 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar10 + -1;
  pcVar6 = &local_84;
  if (iVar10 != 0) {
    if ((iVar5 == 0x2b) || (pcVar6 = &local_84, iVar5 == 0x2d)) {
      local_84 = (char)iVar5;
      iVar5 = FUN_00036416(param_1);
      pcVar6 = local_83;
      local_24 = local_24 + 1;
      if (iVar5 == -1) goto LAB_00036139;
    }
    if ((((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) != 0) || (iVar5 == 0x2e)) {
      local_1c = 0;
      sStack_1a = 0;
      bVar4 = false;
      if (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) != 0) {
        bVar4 = true;
        do {
          *pcVar6 = (char)iVar5;
          pcVar6 = pcVar6 + 1;
          if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
            sStack_1a = (short)iVar5 + sStack_1a * 10 + -0x30;
          }
          iVar9 = iVar9 + 1;
          iVar5 = FUN_00036416(param_1);
          if (iVar5 == -1) goto LAB_00036139;
        } while (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) != 0);
      }
      pcVar8 = pcVar6;
      iVar10 = iVar9;
      if (iVar5 == 0x2e) {
        *pcVar6 = '.';
        iVar5 = FUN_00036416(param_1);
        pcVar6 = pcVar6 + 1;
        if (iVar5 == -1) goto LAB_00036139;
        if ((!bVar4) && (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) == 0)) goto LAB_00036130;
        iVar9 = iVar9 + 1;
        do {
          if (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) == 0) break;
          iVar9 = iVar9 + 1;
          *pcVar6 = (char)iVar5;
          iVar5 = FUN_00036416(param_1);
          pcVar6 = pcVar6 + 1;
        } while (iVar5 != -1);
        if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
          local_2c = 0;
          pcVar8 = pcVar6;
          while( true ) {
            pcVar8 = pcVar8 + -1;
            local_1c = (undefined2)local_2c;
            if (*pcVar8 == '.') break;
            local_2c = (uint)CONCAT12(*pcVar8 + -0x30,(undefined2)local_2c);
            local_2c = local_2c / 10;
          }
        }
        pcVar8 = pcVar6;
        iVar10 = iVar9;
        if (iVar5 == -1) goto LAB_00036139;
      }
      pcVar6 = pcVar8;
      iVar9 = iVar10;
      if (((*(byte *)(param_1 + 0x10) & 0x10) == 0) && ((iVar5 == 0x65 || (iVar5 == 0x45)))) {
        iVar9 = iVar10 + 1;
        *pcVar8 = (char)iVar5;
        iVar5 = FUN_00036416(param_1);
        pcVar6 = pcVar8 + 1;
        if (iVar5 == -1) goto LAB_00036139;
        if ((iVar5 == 0x2b) || (iVar5 == 0x2d)) {
          iVar9 = iVar10 + 2;
          *pcVar6 = (char)iVar5;
          iVar5 = FUN_00036416(param_1);
          pcVar6 = pcVar8 + 2;
          if (iVar5 == -1) goto LAB_00036139;
        }
        if (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) == 0) {
          iVar9 = 0;
        }
        else {
          do {
            iVar9 = iVar9 + 1;
            *pcVar6 = (char)iVar5;
            iVar5 = FUN_00036416(param_1);
            pcVar6 = pcVar6 + 1;
            if (iVar5 == -1) goto LAB_00036139;
          } while (((&DAT_00065c3c)[(byte)((char)iVar5 + 1)] & 0x20) != 0);
        }
      }
    }
  }
LAB_00036130:
  FUN_00035812(iVar5,param_1);
LAB_00036139:
  iVar5 = CONCAT22(sStack_1a,local_1c);
  if ((0 < iVar9) && (iVar9 = iVar9 + local_24, (*(byte *)(param_1 + 0x10) & 1) != 0)) {
    *pcVar6 = '\0';
    if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
      (*(code *)PTR_FUN_000592a0)(&local_84,&local_34);
    }
    else {
      iVar5 = CONCAT22(sStack_1a,local_1c);
      if (local_84 == '-') {
        iVar5 = -CONCAT22(sStack_1a,local_1c);
      }
    }
    if ((*(byte *)(param_1 + 0x10) & 4) == 0) {
      if ((*(byte *)(param_1 + 0x10) & 8) == 0) {
        ppiVar3 = (int **)*unaff_EDX;
        *unaff_EDX = (int)(ppiVar3 + 1);
        piVar7 = *ppiVar3;
      }
      else {
        ppiVar3 = (int **)*unaff_EDX;
        *unaff_EDX = (int)(ppiVar3 + 1);
        piVar7 = *ppiVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*unaff_EDX;
      *unaff_EDX = (int)(puVar2 + 1);
      piVar7 = (int *)*puVar2;
    }
    bVar1 = *(byte *)(param_1 + 0x10);
    if ((bVar1 & 0x10) == 0) {
      if (((bVar1 & 0x20) != 0) || ((bVar1 & 0x40) != 0)) {
        *piVar7 = local_34;
        piVar7[1] = local_30;
        return iVar9;
      }
      iVar5 = FUN_00037ce2(local_34,local_30);
    }
    *piVar7 = iVar5;
  }
  return iVar9;
}


/* ======== FUN_000361ff @ 000361ff ======== */

int FUN_000361ff(int param_1,int *unaff_EDX,undefined4 unaff_EBX,int unaff_ECX)

{
  byte bVar1;
  undefined6 *puVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_20;
  int local_18;
  
  iVar8 = 0;
  iVar6 = 0;
  local_20 = 0;
  while( true ) {
    lVar9 = FUN_0003580b(param_1,unaff_EBX);
    unaff_EBX = (undefined4)((ulonglong)lVar9 >> 0x20);
    iVar4 = (int)lVar9;
    if (((&DAT_00065c3c)[(byte)((char)lVar9 + 1)] & 2) == 0) break;
    local_20 = local_20 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    iVar7 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar7 + -1;
    if (iVar7 == 0) {
LAB_0003636e:
      FUN_00035812(iVar4,param_1);
    }
    else {
      local_18 = 0x2b;
      if ((unaff_ECX != 0) && ((iVar4 == 0x2b || (iVar4 == 0x2d)))) {
        local_20 = local_20 + 1;
        lVar9 = FUN_00036416(param_1);
        local_18 = iVar4;
        if ((int)lVar9 == -1) goto LAB_00036377;
      }
      if ((int)((ulonglong)lVar9 >> 0x20) == 0) {
        if ((int)lVar9 == 0x30) {
          iVar6 = 1;
          iVar4 = FUN_00036416(param_1);
          if (iVar4 == -1) goto LAB_00036377;
          if ((iVar4 == 0x78) || (iVar4 == 0x58)) {
            iVar4 = FUN_00036416(param_1);
            iVar6 = 0;
            local_20 = local_20 + 2;
            if (iVar4 == -1) goto LAB_00036377;
            lVar9 = CONCAT44(0x10,iVar4);
          }
          else {
            lVar9 = CONCAT44(8,iVar4);
          }
        }
        else {
          lVar9 = CONCAT44(10,(int)lVar9);
        }
      }
      else if (lVar9 == 0x1000000030) {
        iVar6 = 1;
        lVar9 = FUN_00036416(param_1);
        iVar4 = (int)lVar9;
        if (iVar4 == -1) goto LAB_00036377;
        if ((iVar4 == 0x78) || (iVar4 == 0x58)) {
          lVar9 = FUN_00036416(param_1);
          local_20 = local_20 + 2;
          iVar6 = 0;
          goto LAB_00036323;
        }
      }
      do {
        iVar4 = (int)lVar9;
        uVar10 = FUN_000363ef(iVar4,(int)((ulonglong)lVar9 >> 0x20));
        iVar7 = (int)((ulonglong)uVar10 >> 0x20);
        if (iVar7 <= (int)uVar10) {
          if ((iVar4 != 0x3a) || ((*(byte *)(param_1 + 0x10) & 0x80) == 0)) goto LAB_0003636e;
          goto LAB_0003634f;
        }
        iVar8 = iVar8 * iVar7 + (int)uVar10;
        iVar6 = iVar6 + 1;
        lVar9 = FUN_00036416(param_1);
LAB_00036323:
      } while ((int)lVar9 != -1);
    }
  }
LAB_00036377:
  if (local_18 == 0x2d) {
    iVar8 = -iVar8;
  }
  if (0 < iVar6) {
    bVar1 = *(byte *)(param_1 + 0x10);
    iVar6 = iVar6 + local_20;
    if ((bVar1 & 1) != 0) {
      if ((bVar1 & 4) == 0) {
        if ((bVar1 & 8) == 0) {
          ppiVar3 = (int **)*unaff_EDX;
          *unaff_EDX = (int)(ppiVar3 + 1);
          piVar5 = *ppiVar3;
        }
        else {
          ppiVar3 = (int **)*unaff_EDX;
          *unaff_EDX = (int)(ppiVar3 + 1);
          piVar5 = *ppiVar3;
        }
      }
      else {
        puVar2 = (undefined6 *)*unaff_EDX;
        *unaff_EDX = (int)(puVar2 + 1);
        piVar5 = (int *)*puVar2;
      }
      if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
        *piVar5 = iVar8;
      }
      else {
        *(short *)piVar5 = (short)iVar8;
      }
    }
  }
  return iVar6;
LAB_0003634f:
  iVar6 = iVar6 + 1;
  iVar4 = FUN_00036416(param_1);
  if (iVar4 == -1) goto LAB_00036377;
  uVar10 = FUN_000363ef();
  iVar7 = (int)((ulonglong)uVar10 >> 0x20);
  if (iVar7 <= (int)uVar10) goto LAB_0003636e;
  iVar8 = iVar8 * iVar7 + (int)uVar10;
  goto LAB_0003634f;
}


/* ======== FUN_000363ef @ 000363ef ======== */

int FUN_000363ef(int param_1)

{
  int iVar1;
  
  if ((0x2f < param_1) && (param_1 < 0x3a)) {
    return param_1 + -0x30;
  }
  iVar1 = FUN_0003655b();
  if ((0x60 < iVar1) && (iVar1 < 0x67)) {
    return iVar1 + -0x57;
  }
  return 0x10;
}


/* ======== FUN_00036416 @ 00036416 ======== */

undefined8 FUN_00036416(int param_1,undefined4 unaff_EDX)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  if (iVar1 != 0) {
    uVar3 = FUN_0003580b(param_1);
    uVar2 = (undefined4)uVar3;
    if ((*(byte *)((int)((ulonglong)uVar3 >> 0x20) + 0x10) & 2) == 0) goto LAB_00036439;
  }
  uVar2 = 0xffffffff;
LAB_00036439:
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_0003643c @ 0003643c ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003643c(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00037d2e(param_1,DAT_00058fe8 + 3U & 0xfffffffc);
  if ((uint)((ulonglong)uVar1 >> 0x20) < (uint)uVar1) {
    _DAT_00058fec = &stack0xfffffff8;
  }
  else {
    _DAT_00058fec = (undefined *)0x0;
  }
  _DAT_00058fec = _DAT_00058fec + DAT_00058fe8;
  FUN_00037d37();
  main(DAT_001158c8,DAT_001158cc);
  exit();
  return;
}


/* ======== FUN_0003648c @ 0003648c ======== */

void FUN_0003648c(byte param_1)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_00065db4;
    bVar1 = param_1;
    for (pcVar3 = &DAT_00065d48; pcVar3 < &DAT_00065db4; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && ((byte)pcVar3[1] <= bVar1)) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_00065db4) break;
    if (*(code **)(pcVar2 + 2) != (code *)0x0) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


/* ======== FUN_000364d7 @ 000364d7 ======== */

void FUN_000364d7(byte param_1,byte unaff_DL)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  
  while( true ) {
    pcVar2 = &DAT_00065dba;
    bVar1 = param_1;
    for (pcVar3 = &DAT_00065db4; pcVar3 < &DAT_00065dba; pcVar3 = pcVar3 + 6) {
      if ((*pcVar3 != '\x02') && (bVar1 <= (byte)pcVar3[1])) {
        bVar1 = pcVar3[1];
        pcVar2 = pcVar3;
      }
    }
    if (pcVar2 == &DAT_00065dba) break;
    if ((bVar1 <= unaff_DL) && (*(code **)(pcVar2 + 2) != (code *)0x0)) {
      (**(code **)(pcVar2 + 2))();
    }
    *pcVar2 = '\x02';
  }
  return;
}


/* ======== FUN_00036526 @ 00036526 ======== */

void FUN_00036526(void)

{
  return;
}


/* ======== FUN_0003652c @ 0003652c ======== */

void FUN_0003652c(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00037da0(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX);
  *(undefined4 *)uVar1 = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


/* ======== FUN_0003654f @ 0003654f ======== */

void FUN_0003654f(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00037da6(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX);
  *(undefined4 *)uVar1 = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


/* ======== FUN_0003655b @ 0003655b ======== */

int FUN_0003655b(int param_1)

{
  if ((0x40 < param_1) && (param_1 < 0x5b)) {
    param_1 = param_1 + 0x20;
  }
  return param_1;
}


/* ======== FUN_00036569 @ 00036569 ======== */

void FUN_00036569(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  byte bVar1;
  int extraout_EDX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  FUN_00036fd0(param_1,param_1,unaff_EBX,unaff_ECX,unaff_EDX,unaff_ECX);
  if (*(int *)(extraout_EDX + 0x14) == 0) {
    if ((*(byte *)(extraout_EDX + 0xd) & 2) == 0) {
      if ((*(byte *)(extraout_EDX + 0xd) & 4) == 0) {
        *(undefined4 *)(extraout_EDX + 0x14) = 0x1000;
      }
      else {
        *(undefined4 *)(extraout_EDX + 0x14) = 1;
      }
    }
    else {
      *(undefined4 *)(extraout_EDX + 0x14) = 0x86;
    }
  }
  uVar3 = malloc(*(undefined4 *)(extraout_EDX + 0x14));
  puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  puVar2[2] = (int)uVar3;
  if ((int)uVar3 == 0) {
    puVar2[5] = 1;
    bVar1 = *(byte *)((int)puVar2 + 0xd) & 0xf8;
    *(byte *)((int)puVar2 + 0xd) = bVar1;
    puVar2[2] = puVar2 + 6;
    *(byte *)((int)puVar2 + 0xd) = bVar1 | 4;
  }
  else {
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 8;
  }
  puVar2[1] = 0;
  *puVar2 = puVar2[2];
  return;
}


/* ======== FUN_000365e0 @ 000365e0 ======== */

void FUN_000365e0(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  code *pcVar1;
  int iVar2;
  byte in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x3f,(char)param_1),unaff_EDX,param_1,unaff_EBX);
  if ((in_CF & 1) != 0) {
    FUN_00037b20((iVar2 << 1 | (uint)in_CF) >> 1 & 0xffff);
  }
  return;
}


/* ======== FUN_00036600 @ 00036600 ======== */

uint * FUN_00036600(uint param_1,undefined4 param_2,int unaff_EBX)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  if (((param_1 != 0) && (param_1 < 0xfffffff5)) &&
     (uVar2 = param_1 + 0xb & 0xfffffff8, uVar2 = (uVar2 - 0x10 & -(uint)(0xf < uVar2)) + 0x10,
     uVar2 <= *(uint *)(unaff_EBX + 0x14))) {
    puVar3 = *(uint **)(unaff_EBX + 0xc);
    uVar4 = *(uint *)(unaff_EBX + 0x10);
    if (uVar2 <= uVar4) {
      puVar3 = *(uint **)(unaff_EBX + 0x28);
      uVar4 = 0;
    }
    do {
      uVar1 = *puVar3;
      if (uVar2 <= uVar1) {
        *(uint *)(unaff_EBX + 0x10) = uVar4;
        *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + 1;
        uVar4 = puVar3[2];
        if (uVar1 - uVar2 < 0x10) {
          *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
          uVar2 = puVar3[1];
          *(uint *)(uVar2 + 8) = uVar4;
          *(uint *)(uVar4 + 4) = uVar2;
          *(uint *)(unaff_EBX + 0xc) = uVar2;
        }
        else {
          puVar5 = (uint *)((int)puVar3 + uVar2);
          *(uint **)(unaff_EBX + 0xc) = puVar5;
          *puVar5 = uVar1 - uVar2;
          *puVar3 = uVar2;
          uVar2 = puVar3[1];
          puVar5[1] = uVar2;
          puVar5[2] = uVar4;
          *(uint **)(uVar2 + 8) = puVar5;
          *(uint **)(uVar4 + 4) = puVar5;
        }
        *puVar3 = *puVar3 | 1;
        return puVar3 + 1;
      }
      uVar4 = (uVar4 - uVar1 & -(uint)(uVar1 <= uVar4)) + uVar1;
      puVar3 = (uint *)puVar3[2];
    } while (puVar3 != (uint *)(unaff_EBX + 0x20U));
    *(uint *)(unaff_EBX + 0x14) = uVar4;
  }
  return (uint *)0x0;
}


/* ======== FUN_000366a8 @ 000366a8 ======== */

void FUN_000366a8(uint **param_1,undefined4 param_2,int unaff_EBX)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint **ppuVar5;
  uint **ppuVar6;
  uint *puVar7;
  uint **ppuVar8;
  
  if (param_1 == (uint **)0x0) {
    return;
  }
  ppuVar5 = param_1 + -1;
  if (((uint)*ppuVar5 & 1) == 0) {
    return;
  }
  puVar4 = (uint *)((uint)*ppuVar5 & 0xfffffffe);
  puVar7 = (uint *)((int)ppuVar5 + (int)puVar4);
  if ((*puVar7 & 1) == 0) {
    if (puVar7 == *(uint **)(unaff_EBX + 0xc)) {
      *(uint ***)(unaff_EBX + 0xc) = ppuVar5;
    }
    *ppuVar5 = (uint *)((int)puVar4 + *puVar7);
    puVar4 = (uint *)puVar7[1];
    ppuVar8 = (uint **)puVar7[2];
    puVar4[2] = (uint)ppuVar8;
    ppuVar8[1] = puVar4;
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
  }
  else {
    *ppuVar5 = puVar4;
    ppuVar8 = *(uint ***)(unaff_EBX + 0xc);
    if (ppuVar5 < ppuVar8) {
      if ((ppuVar8[1] < ppuVar5) || (ppuVar8 = *(uint ***)(unaff_EBX + 0x28), ppuVar5 < ppuVar8))
      goto LAB_00036766;
    }
    else {
      ppuVar8 = (uint **)ppuVar8[2];
      if ((ppuVar5 < ppuVar8) ||
         (ppuVar8 = (uint **)(unaff_EBX + 0x20), *(uint ***)(unaff_EBX + 0x24) < ppuVar5))
      goto LAB_00036766;
    }
    uVar1 = *(uint *)(unaff_EBX + 0x1c);
    uVar2 = *(uint *)(unaff_EBX + 0x18) / (uVar1 + 1);
    if (uVar2 < uVar1) {
      iVar3 = uVar2 * 2;
      if (*(int *)(unaff_EBX + 0x18) - uVar1 <= uVar1) {
        iVar3 = 0;
      }
      ppuVar8 = (uint **)((int)ppuVar5 + (int)*ppuVar5);
      do {
        puVar4 = *ppuVar8;
        if (((uint)puVar4 & 1) == 0) goto LAB_00036766;
        if (puVar4 == (uint *)0xffffffff) break;
        ppuVar8 = (uint **)((int)ppuVar8 + ((uint)puVar4 & 0xfffffffe));
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    ppuVar8 = *(uint ***)(unaff_EBX + 0xc);
    if (ppuVar5 < ppuVar8) {
      ppuVar8 = *(uint ***)(unaff_EBX + 0x28);
    }
    while (((ppuVar8 <= ppuVar5 && (ppuVar8 = (uint **)ppuVar8[2], ppuVar8 <= ppuVar5)) &&
           (ppuVar8 = (uint **)ppuVar8[2], ppuVar8 <= ppuVar5))) {
      ppuVar8 = (uint **)ppuVar8[2];
    }
  }
LAB_00036766:
  ppuVar6 = (uint **)ppuVar8[1];
  puVar4 = *ppuVar5;
  if ((uint **)((int)ppuVar6 + (int)*ppuVar6) == ppuVar5) {
    puVar4 = (uint *)((int)puVar4 + (int)*ppuVar6);
    *ppuVar6 = puVar4;
    if (ppuVar5 == *(uint ***)(unaff_EBX + 0xc)) {
      *(uint ***)(unaff_EBX + 0xc) = ppuVar6;
    }
  }
  else {
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + 1;
    param_1[1] = (uint *)ppuVar8;
    *param_1 = (uint *)ppuVar6;
    ppuVar6[2] = (uint *)ppuVar5;
    ppuVar8[1] = (uint *)ppuVar5;
    ppuVar6 = ppuVar5;
  }
  *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + -1;
  if ((ppuVar6 < *(uint ***)(unaff_EBX + 0xc)) && (*(uint **)(unaff_EBX + 0x10) < puVar4)) {
    *(uint **)(unaff_EBX + 0x10) = puVar4;
  }
  if (*(uint **)(unaff_EBX + 0x14) < puVar4) {
    *(uint **)(unaff_EBX + 0x14) = puVar4;
  }
  return;
}


/* ======== FUN_000367b3 @ 000367b3 ======== */

void FUN_000367b3(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == DAT_00058f94) {
    DAT_00058f94 = *(int *)(DAT_00058f94 + 8);
  }
  if (param_1 == DAT_001158b0) {
    DAT_001158b0 = 0;
  }
  if (param_1 == DAT_00058f90) {
    DAT_00058f90 = *(int *)(DAT_00058f90 + 8);
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = iVar2;
  }
  if (iVar2 != 0) {
    *(int *)(iVar2 + 4) = iVar1;
  }
  return;
}


/* ======== FUN_00036804 @ 00036804 ======== */

undefined8 FUN_00036804(undefined4 param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined2 extraout_var;
  int *piVar4;
  byte bVar5;
  undefined8 uVar6;
  
  uVar6 = CONCAT44(DAT_00058f90,param_1);
  while (piVar4 = (int *)((ulonglong)uVar6 >> 0x20), piVar4 != (int *)0x0) {
    if (*(int *)piVar4[9] + 0x2c == *piVar4) {
      iVar1 = piVar4[2];
      FUN_000367b3(piVar4);
      iVar2 = piVar4[-1];
      bVar5 = 0;
      if (iVar2 == 0) {
        pcVar3 = (code *)swi(0x31);
        uVar6 = (*pcVar3)(CONCAT31((int3)(CONCAT22(extraout_var,0x500) >> 8),2));
      }
      else {
        pcVar3 = (code *)swi(0x21);
        uVar6 = (*pcVar3)(CONCAT22((short)((uint)iVar2 >> 0x10),CONCAT11(0x49,(char)iVar2)),iVar1);
        uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),
                         ((int)uVar6 << 1 | (uint)bVar5) >> 1 | (uint)((bVar5 & 1) != 0) << 0x1f);
      }
    }
    else {
      uVar6 = CONCAT44(piVar4[2],*(int *)piVar4[9] + 0x2c);
    }
  }
  return CONCAT44(unaff_EDX,(int)uVar6);
}


/* ======== FUN_00036860 @ 00036860 ======== */

uint * FUN_00036860(int *param_1,int unaff_EDX)

{
  undefined2 uVar1;
  undefined2 uVar2;
  code *pcVar3;
  undefined2 *puVar4;
  uint *puVar5;
  int *extraout_EDX;
  uint uVar6;
  undefined2 *puVar7;
  int extraout_EDX_00;
  int *piVar8;
  uint uVar9;
  byte bVar10;
  
  FUN_00036804();
  piVar8 = DAT_00058f90;
  while( true ) {
    if (piVar8 == (int *)0x0) {
      return (uint *)0x0;
    }
    if (param_1 < piVar8) {
      return (uint *)0x0;
    }
    if ((piVar8 + 0xb == param_1) && (piVar8[6] == 1)) break;
    piVar8 = (int *)piVar8[2];
  }
  FUN_000367b3(piVar8);
  if (extraout_EDX[-1] != 0) {
    return (uint *)0x0;
  }
  uVar6 = *extraout_EDX + (unaff_EDX - (*param_1 + -4)) + 0x100b;
  puVar7 = (undefined2 *)((uVar6 >> 8 & 0xfffff0) * 0x100);
  bVar10 = (uVar6 >> 8 & 0xff) != 0;
  uVar1 = *(undefined2 *)(extraout_EDX + -2);
  uVar2 = *(undefined2 *)((int)extraout_EDX + -6);
  pcVar3 = (code *)swi(0x31);
  (*pcVar3)(CONCAT31((int3)(CONCAT22((short)((uint)(extraout_EDX + -2) >> 0x10),0x500) >> 8),3),
            puVar7,uVar6 >> 0x10);
  puVar4 = (undefined2 *)(1 - (uint)bVar10);
  if ((undefined2 *)(1 - (uint)bVar10) != (undefined2 *)0x0) {
    *puVar7 = uVar1;
    puVar7[1] = uVar2;
    puVar4 = puVar7;
  }
  if (puVar4 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar4 + 2) = 0;
    *(int *)(puVar4 + 4) = extraout_EDX_00 + -0xc;
    puVar5 = (uint *)FUN_0003695f(puVar4 + 4);
    *(undefined4 *)(puVar4 + 0x10) = 1;
    uVar9 = unaff_EDX + 1U & 0xfffffffe;
    uVar6 = *puVar5;
    if (uVar6 - uVar9 < 0xc) {
      *(byte *)puVar5 = *(byte *)puVar5 | 1;
      return puVar5;
    }
    *puVar5 = uVar9 | 1;
    *(uint *)((int)puVar5 + uVar9) = uVar6 - uVar9 | 1;
    *(undefined4 *)(puVar4 + 0xe) = 0xffffffff;
    *(int *)(puVar4 + 0x10) = *(int *)(puVar4 + 0x10) + 1;
    free((uint *)((int)puVar5 + uVar9) + 1);
    return puVar5;
  }
  return (uint *)0x0;
}


/* ======== FUN_0003695f @ 0003695f ======== */

undefined8 FUN_0003695f(int *param_1,undefined4 unaff_EDX)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = DAT_00058f90;
  piVar3 = (int *)0x0;
  while ((piVar2 = piVar1, piVar2 != (int *)0x0 && (piVar2 <= param_1))) {
    piVar3 = piVar2;
    piVar1 = (int *)piVar2[2];
  }
  param_1[1] = (int)piVar3;
  param_1[2] = (int)piVar2;
  piVar1 = param_1;
  if (piVar3 != (int *)0x0) {
    piVar3[2] = (int)param_1;
    piVar1 = DAT_00058f90;
  }
  DAT_00058f90 = piVar1;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = (int)param_1;
  }
  piVar1 = param_1 + 8;
  piVar3 = param_1 + 0xb;
  param_1[8] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = (int)piVar1;
  param_1[10] = (int)piVar1;
  param_1[3] = (int)piVar1;
  *piVar3 = *param_1 + -0x2c;
  *(undefined4 *)((int)piVar3 + *param_1 + -0x2c) = 0xffffffff;
  return CONCAT44(unaff_EDX,piVar3);
}


/* ======== FUN_000369d3 @ 000369d3 ======== */

longlong FUN_000369d3(undefined4 param_1,uint unaff_EDX)

{
  int *piVar1;
  undefined3 uVar2;
  ushort in_DS;
  
  if (DAT_00058f90 != 0) {
    piVar1 = *(int **)(DAT_00058f90 + 0x24);
    if (((1 < DAT_00058ffe) && (DAT_00058ffe < 9)) && (DAT_00059000 == '\0')) {
      uVar2 = SegmentLimit((uint)in_DS);
      DAT_00058fd0 = (ushort)uVar2 + 1;
    }
    if ((int)piVar1 + *piVar1 + 4 == DAT_00058fd0) {
      return CONCAT44(unaff_EDX,*piVar1);
    }
  }
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_00036a23 @ 00036a23 ======== */

undefined8
FUN_00036a23(undefined2 *param_1,undefined4 unaff_EDX,undefined4 param_3,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined2 extraout_var;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  code **ppcVar6;
  undefined2 extraout_DX;
  undefined4 extraout_EDX;
  undefined2 unaff_SI;
  code *unaff_EDI;
  undefined2 in_ES;
  byte bVar7;
  bool bVar8;
  undefined8 uVar9;
  
  bVar7 = ((uint)param_1 >> 0xf & 1) != 0;
  FUN_00036804(param_1,unaff_EDX,(uint)param_1 >> 0x10);
  pcVar1 = (code *)swi(0x31);
  (*pcVar1)(CONCAT31((int3)(CONCAT22(extraout_var,0x500) >> 8),1));
  puVar2 = (undefined2 *)(1 - bVar7);
  if ((undefined2 *)(1 - bVar7) != (undefined2 *)0x0) {
    *param_1 = (short)unaff_EDI;
    param_1[1] = unaff_SI;
    puVar2 = param_1;
  }
  if (puVar2 == (undefined2 *)0x0) {
    if ((DAT_001158d8 & 0xfff00000) != 0) {
      DAT_001158d8 = 0xfffff;
    }
    if (unaff_EDI < __break) {
      bVar7 = 0;
      pcVar1 = (code *)swi(0x21);
      iVar3 = (*pcVar1)(0x4800,extraout_EDX,
                        CONCAT31((uint3)(DAT_001158d8 >> 0xc),(char)(DAT_001158d8 >> 4)) | 1);
      bVar8 = (bVar7 & 1) != 0;
      uVar5 = (iVar3 << 1 | (uint)bVar7) >> 1;
      uVar4 = uVar5 | (uint)bVar8 << 0x1f;
      if (!bVar8) {
        bVar7 = ((uint)unaff_EDI >> 3 & 1) != 0;
        pcVar1 = (code *)swi(0x21);
        uVar9 = (*pcVar1)(CONCAT22((short)(uVar4 >> 0x10),CONCAT11(0x48,(char)uVar5)),uVar4,
                          (uint)unaff_EDI >> 4);
        bVar8 = (bVar7 & 1) != 0;
        uVar5 = ((int)uVar9 << 1 | (uint)bVar7) >> 1 | (uint)bVar8 << 0x1f;
        pcVar1 = (code *)swi(0x21);
        bVar7 = bVar8;
        iVar3 = (*pcVar1)(CONCAT11(0x49,(char)((ulonglong)uVar9 >> 0x20)),
                          (int)((ulonglong)uVar9 >> 0x20),uVar5);
        if (!bVar8) {
          pcVar1 = (code *)swi(0x31);
          (*pcVar1)(CONCAT31((int3)(((uint)(ushort)((ushort)((uint)(iVar3 << 1) >> 0x11) |
                                                   (ushort)(((uint)((bVar7 & 1) != 0) << 0x1f) >>
                                                           0x10)) << 0x10) >> 8),6));
          iVar3 = CONCAT22((short)param_1,extraout_DX);
          ppcVar6 = (code **)(iVar3 + 8);
          *(uint *)(iVar3 + 4) = uVar5;
          *ppcVar6 = (code *)(CONCAT22((short)((uint)unaff_EDI >> 0x10),in_ES) + -8);
          goto LAB_00036aeb;
        }
      }
    }
    ppcVar6 = (code **)0x0;
  }
  else {
    ppcVar6 = (code **)(puVar2 + 4);
    *ppcVar6 = unaff_EDI + -8;
    *(undefined4 *)(puVar2 + 2) = 0;
  }
LAB_00036aeb:
  return CONCAT44(unaff_ECX,ppcVar6);
}


/* ======== FUN_00036af4 @ 00036af4 ======== */

undefined8 FUN_00036af4(uint param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  undefined8 uVar6;
  uint local_18;
  
  if ((DAT_000592a4 != 0) && (DAT_00058fd0 != -2)) {
    local_18 = param_1;
    iVar2 = FUN_00036cf0(&local_18);
    if (iVar2 == 0) goto LAB_00036aeb;
    bVar5 = DAT_00058ffe == '\0';
    if (DAT_00058ffe == '\x01') {
      puVar3 = (uint *)FUN_00036a23(local_18);
      if (puVar3 != (uint *)0x0) {
        local_18 = *puVar3;
      }
    }
    else {
      pcVar1 = (code *)swi(0x21);
      uVar4 = (*pcVar1)(0x80004800);
      puVar3 = (uint *)(uVar4 & ~-(uint)bVar5);
      local_18 = local_18 - 4;
    }
    if (((puVar3 != (uint *)0x0) && (uVar4 = local_18 - 4, uVar4 <= local_18)) && (0x37 < uVar4)) {
      *puVar3 = uVar4;
      local_18 = uVar4;
      uVar6 = FUN_0003695f(puVar3);
      iVar2 = (int)((ulonglong)uVar6 >> 0x20);
      puVar3 = (uint *)uVar6;
      local_18 = *puVar3;
      *puVar3 = local_18 | 1;
      *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
      *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
      free(puVar3 + 1);
      iVar2 = 1;
      goto LAB_00036aeb;
    }
  }
  iVar2 = 0;
LAB_00036aeb:
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_00036ba4 @ 00036ba4 ======== */

undefined8 FUN_00036ba4(uint param_1,undefined4 unaff_EDX)

{
  int *piVar1;
  undefined3 uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  ushort in_DS;
  undefined8 uVar8;
  uint local_18;
  
  local_18 = param_1;
  if (((DAT_00058ffe == 1) && (DAT_00058fff == '\0')) || (DAT_00058ffe == 9)) {
    iVar3 = FUN_00036af4(param_1);
    goto LAB_00036ce7;
  }
  if ((DAT_000592a4 == 0) || (DAT_00058fd0 == 0xfffffffe)) goto LAB_00036be1;
  iVar3 = FUN_00036cf0(&local_18);
  if (iVar3 == 0) goto LAB_00036ce7;
  if (((1 < DAT_00058ffe) && (DAT_00058ffe < 9)) && (DAT_00059000 == '\0')) {
    uVar2 = SegmentLimit((uint)in_DS);
    DAT_00058fd0 = (ushort)uVar2 + 1;
  }
  uVar6 = local_18 + DAT_00058fd0;
  if (uVar6 < DAT_00058fd0) {
    uVar6 = 0xfffffffe;
  }
  uVar8 = FUN_00037e74(uVar6);
  puVar7 = (uint *)((ulonglong)uVar8 >> 0x20);
  puVar4 = (uint *)uVar8;
  if (((puVar4 != (uint *)0xffffffff) && (puVar4 < (uint *)0xfffffff9)) && (puVar4 < puVar7)) {
    uVar6 = (int)puVar7 - (int)puVar4;
    local_18 = uVar6 - 4;
    puVar7 = DAT_00058f90;
    if (local_18 <= uVar6) {
      for (; ((puVar7 != (uint *)0x0 && ((uint *)puVar7[2] != (uint *)0x0)) &&
             ((puVar4 < puVar7 || ((uint *)puVar7[2] <= puVar4)))); puVar7 = (uint *)puVar7[2]) {
      }
      if (puVar7 == (uint *)0x0) {
LAB_00036caa:
        if (local_18 < 0x38) goto LAB_00036be1;
        *puVar4 = local_18;
        uVar8 = FUN_0003695f(puVar4,puVar4);
        local_18 = *(uint *)uVar8;
      }
      else {
        puVar5 = (uint *)(*puVar7 + (int)puVar7);
        uVar8 = CONCAT44(puVar7,puVar5);
        if (puVar4 + -1 != puVar5) goto LAB_00036caa;
        *puVar7 = *puVar7 + uVar6;
        *(undefined4 *)((int)puVar5 + uVar6) = 0xffffffff;
        local_18 = uVar6;
      }
      iVar3 = (int)((ulonglong)uVar8 >> 0x20);
      *(uint *)uVar8 = local_18 | 1;
      piVar1 = (int *)(iVar3 + 0x18);
      *piVar1 = *piVar1 + 1;
      *(undefined4 *)(iVar3 + 0x14) = 0xffffffff;
      free((uint *)uVar8 + 1);
      iVar3 = 1;
      goto LAB_00036ce7;
    }
  }
LAB_00036be1:
  iVar3 = 0;
LAB_00036ce7:
  return CONCAT44(unaff_EDX,iVar3);
}


/* ======== FUN_00036cf0 @ 00036cf0 ======== */

longlong FUN_00036cf0(uint *param_1,uint unaff_EDX)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_1 + 0xb & 0xfffffff8;
  if (uVar1 != 0) {
    if (((DAT_00058ffe == '\x01') && (DAT_00058fff == '\0')) || (DAT_00058ffe == '\t')) {
      uVar1 = uVar1 + 8;
    }
    else {
      uVar2 = FUN_000369d3();
      uVar1 = (int)((ulonglong)uVar2 >> 0x20) - (int)uVar2;
    }
    *param_1 = uVar1;
    uVar1 = uVar1 + 0x3c;
    if (*param_1 <= uVar1) {
      if (uVar1 < DAT_000592a8) {
        uVar1 = DAT_000592a8 & 0xfffffffe;
      }
      *param_1 = uVar1;
      if (*param_1 <= uVar1 + 0xfff) {
        uVar1 = uVar1 + 0xfff >> 8 & 0xfffff0;
        *param_1 = uVar1 << 8;
        return CONCAT44(unaff_EDX,(uint)(uVar1 != 0));
      }
    }
  }
  return (ulonglong)unaff_EDX << 0x20;
}


/* ======== FUN_00036d6d @ 00036d6d ======== */

undefined4 FUN_00036d6d(void)

{
  return 0;
}


/* ======== FUN_00036d70 @ 00036d70 ======== */

void FUN_00036d70(undefined2 *param_1)

{
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  
  param_1[1] = in_CS;
  param_1[3] = in_DS;
  *param_1 = in_ES;
  param_1[2] = in_SS;
  param_1[4] = in_FS;
  param_1[5] = in_GS;
  return;
}


/* ======== FUN_00036d98 @ 00036d98 ======== */

void FUN_00036d98(undefined4 *param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX
                 )

{
  FUN_00034dbd(unaff_EDX,*param_1,param_1,unaff_ECX,unaff_EBX);
  param_1[4] = param_1[4] + 1;
  return;
}


/* ======== FUN_00036da9 @ 00036da9 ======== */

undefined4 FUN_00036da9(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  bool bVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xcf;
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00036569(param_1);
  }
  bVar3 = (*(byte *)(param_1 + 0xd) & 4) != 0;
  if (bVar3) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfa | 1;
  }
  uVar2 = FUN_00037f3f(param_1);
  if (bVar3) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfa | 4;
    FUN_00037007(param_1);
    uVar2 = extraout_EDX;
  }
  if ((*(byte *)(param_1 + 0xc) & 0x20) != 0) {
    uVar2 = 0xffffffff;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | uVar1 & 0x30;
  return uVar2;
}


/* ======== FUN_00036e30 @ 00036e30 ======== */

void FUN_00036e30(undefined *param_1,uint unaff_EDX,undefined4 param_3,uint unaff_ECX)

{
  undefined *puVar1;
  undefined uVar2;
  undefined6 uVar3;
  
  if (unaff_ECX != 0) {
    do {
      if (((uint)param_1 & 3) == 0) break;
      *param_1 = (char)unaff_EDX;
      param_1 = param_1 + 1;
      unaff_EDX = unaff_EDX >> 8 | unaff_EDX << 0x18;
      unaff_ECX = unaff_ECX - 1;
    } while (unaff_ECX != 0);
    uVar3 = FUN_00036e67();
    puVar1 = (undefined *)uVar3;
    unaff_ECX = unaff_ECX & 3;
    if (unaff_ECX != 0) {
      uVar2 = (undefined)((uint6)uVar3 >> 0x20);
      *puVar1 = uVar2;
      if ((unaff_ECX != 1) && (puVar1[1] = (char)((uint6)uVar3 >> 0x28), unaff_ECX != 2)) {
        puVar1[2] = uVar2;
      }
    }
  }
  return;
}


/* ======== FUN_00036e67 @ 00036e67 ======== */

undefined4 *
FUN_00036e67(undefined4 *param_1,undefined4 unaff_EDX,undefined4 param_3,uint unaff_ECX)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (unaff_ECX != 0) {
    do {
      if (((uint)param_1 & 0x1f) == 0) break;
      *param_1 = unaff_EDX;
      param_1 = param_1 + 1;
      unaff_ECX = unaff_ECX - 1;
    } while (unaff_ECX != 0);
    if (unaff_ECX >> 2 != 0) {
      iVar2 = (unaff_ECX >> 2) - 1;
      if (iVar2 != 0) {
        do {
          puVar1 = param_1;
          *puVar1 = unaff_EDX;
          puVar1[1] = unaff_EDX;
          puVar1[2] = unaff_EDX;
          puVar1[3] = unaff_EDX;
          if (iVar2 == 1) goto LAB_00036ea6;
          puVar1[4] = unaff_EDX;
          puVar1[5] = unaff_EDX;
          iVar2 = iVar2 + -2;
          puVar1[6] = unaff_EDX;
          puVar1[7] = unaff_EDX;
          param_1 = puVar1 + 8;
        } while (iVar2 != 0);
        puVar1 = puVar1 + 4;
LAB_00036ea6:
        param_1 = puVar1 + 4;
      }
      *param_1 = unaff_EDX;
      param_1[1] = unaff_EDX;
      param_1[2] = unaff_EDX;
      param_1[3] = unaff_EDX;
      param_1 = param_1 + 4;
    }
    unaff_ECX = unaff_ECX & 3;
    puVar1 = param_1;
    if (unaff_ECX != 0) {
      *param_1 = unaff_EDX;
      puVar1 = param_1 + 1;
      if (unaff_ECX != 1) {
        *puVar1 = unaff_EDX;
        puVar1 = param_1 + 2;
        if (unaff_ECX != 2) {
          *puVar1 = unaff_EDX;
          puVar1 = param_1 + 3;
        }
      }
    }
  }
  return puVar1;
}


/* ======== FUN_00036ed3 @ 00036ed3 ======== */

undefined8 FUN_00036ed3(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (DAT_001158b8 == (undefined4 *)0x0) {
    for (puVar2 = (undefined4 *)&DAT_00059010; puVar2 < &DAT_00059218;
        puVar2 = (undefined4 *)((int)puVar2 + 0x1a)) {
      if ((*(byte *)(puVar2 + 3) & 3) == 0) {
        puVar1 = (undefined4 *)malloc(8);
        if (puVar1 == (undefined4 *)0x0) goto LAB_00036f67;
        uVar3 = 3;
        goto LAB_00036f42;
      }
    }
    uVar3 = 0x4003;
    puVar1 = (undefined4 *)malloc(0x22);
    if (puVar1 == (undefined4 *)0x0) {
LAB_00036f67:
      FUN_0003652c(5);
      puVar2 = (undefined4 *)0x0;
      goto LAB_00036f73;
    }
    puVar2 = puVar1 + 2;
  }
  else {
    puVar2 = (undefined4 *)DAT_001158b8[1];
    uVar3 = (uint)((ushort)puVar2[3] & 0x4003 | 3);
    puVar1 = DAT_001158b8;
    DAT_001158b8 = (undefined4 *)*DAT_001158b8;
  }
LAB_00036f42:
  memset(puVar2,0,0x1a);
  puVar2[3] = uVar3;
  puVar1[1] = puVar2;
  *puVar1 = DAT_001158bc;
  DAT_001158bc = puVar1;
LAB_00036f73:
  return CONCAT44(unaff_EDX,puVar2);
}


/* ======== FUN_00036f79 @ 00036f79 ======== */

void FUN_00036f79(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &DAT_001158bc;
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
  } while (param_1 != puVar1[1]);
  *(byte *)(param_1 + 0xc) = *(byte *)(puVar1[1] + 0xc) | 3;
  *puVar2 = *puVar1;
  *puVar1 = DAT_001158b8;
  DAT_001158b8 = puVar1;
  return;
}


/* ======== FUN_00036fb2 @ 00036fb2 ======== */

void FUN_00036fb2(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  undefined4 *extraout_EDX;
  
  while (DAT_001158b8 != (undefined4 *)0x0) {
    free(DAT_001158b8,*DAT_001158b8,unaff_EBX,unaff_ECX,unaff_EDX);
    DAT_001158b8 = extraout_EDX;
  }
  return;
}


/* ======== FUN_00036fd0 @ 00036fd0 ======== */

void FUN_00036fd0(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(byte *)(param_1 + 0xd) & 0x20) == 0) {
    uVar3 = FUN_00037aee(*(undefined4 *)(param_1 + 0x10));
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 != 0) {
      bVar1 = *(byte *)(iVar2 + 0xd);
      *(byte *)(iVar2 + 0xd) = bVar1 | 0x20;
      if ((bVar1 & 7) == 0) {
        *(byte *)(iVar2 + 0xd) = bVar1 | 0x22;
      }
    }
  }
  return;
}


/* ======== FUN_00037001 @ 00037001 ======== */

undefined4 FUN_00037001(void)

{
  return DAT_00058fdc;
}


/* ======== FUN_00037007 @ 00037007 ======== */

undefined8 FUN_00037007(undefined4 *param_1,undefined4 unaff_EDX)

{
  int iVar1;
  int extraout_EDX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
    if ((param_1[2] != 0) &&
       (*(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef,
       (*(byte *)((int)param_1 + 0xd) & 0x20) == 0)) {
      iVar4 = param_1[1];
      if (iVar4 != 0) {
        iVar4 = FUN_00035755(param_1[4],-iVar4,1);
      }
      if (iVar4 == -1) {
        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
        iVar2 = -1;
      }
    }
  }
  else {
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xef;
    if (((*(byte *)(param_1 + 3) & 2) != 0) && (iVar4 = param_1[2], iVar4 != 0)) {
      iVar3 = param_1[1];
      while ((iVar3 != 0 && (iVar2 == 0))) {
        iVar1 = FUN_00038bfd(param_1[4],iVar4,iVar3);
        if (iVar1 == -1) {
          *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          iVar2 = -1;
        }
        else if (iVar1 == 0) {
          FUN_0003652c(0xc);
          iVar2 = -1;
          *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          iVar1 = extraout_EDX;
        }
        iVar4 = iVar4 + iVar1;
        iVar3 = iVar3 - iVar1;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_000370e0 @ 000370e0 ======== */

longlong FUN_000370e0(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,uint unaff_ECX)

{
  code *pcVar1;
  byte in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(0x3e,(char)param_1),unaff_EDX,param_1,param_1,unaff_ECX,unaff_EBX);
  if ((in_CF & 1) == 0) {
    FUN_00037be6(param_1,0);
    return (ulonglong)unaff_ECX << 0x20;
  }
  FUN_0003652c(4);
  return CONCAT44(unaff_ECX,0xffffffff);
}


/* ======== thunk_FUN_00038c71 @ 00037115 ======== */

longlong thunk_FUN_00038c71(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  byte in_CF;
  uint unaff_retaddr;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x41,(char)param_1),param_1);
  if ((in_CF & 1) != 0) {
    uVar3 = FUN_00037b20((iVar2 << 1 | (uint)in_CF) >> 1 & 0xffff);
    return CONCAT44(unaff_retaddr,uVar3);
  }
  return (ulonglong)unaff_retaddr << 0x20;
}


/* ======== FUN_0003711a @ 0003711a ======== */

void FUN_0003711a(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00035755(param_1,0,1,unaff_ECX,unaff_EDX,unaff_EBX);
  return;
}


/* ======== FUN_0003712b @ 0003712b ======== */

int FUN_0003712b(undefined4 *param_1)

{
  int iVar1;
  int extraout_EDX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_0003713b();
    return 0;
  }
  iVar2 = 0;
  if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
    if ((param_1[2] != 0) &&
       (*(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef,
       (*(byte *)((int)param_1 + 0xd) & 0x20) == 0)) {
      iVar4 = param_1[1];
      if (iVar4 != 0) {
        iVar4 = FUN_00035755(param_1[4],-iVar4,1);
      }
      if (iVar4 == -1) {
        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
        iVar2 = -1;
      }
    }
  }
  else {
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xef;
    if (((*(byte *)(param_1 + 3) & 2) != 0) && (iVar4 = param_1[2], iVar4 != 0)) {
      iVar3 = param_1[1];
      while ((iVar3 != 0 && (iVar2 == 0))) {
        iVar1 = FUN_00038bfd(param_1[4],iVar4,iVar3);
        if (iVar1 == -1) {
          *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          iVar2 = -1;
        }
        else if (iVar1 == 0) {
          FUN_0003652c(0xc);
          iVar2 = -1;
          *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          iVar1 = extraout_EDX;
        }
        iVar4 = iVar4 + iVar1;
        iVar3 = iVar3 - iVar1;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return iVar2;
}


/* ======== FUN_0003713b @ 0003713b ======== */

undefined8 FUN_0003713b(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined4 *extraout_EDX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = DAT_001158bc; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((*(int *)(puVar1[1] + 0xc) != 0) &&
       (iVar2 = iVar2 + 1, (*(byte *)(puVar1[1] + 0xd) & 0x10) != 0)) {
      FUN_00037007();
      puVar1 = extraout_EDX;
    }
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_00037140 @ 00037140 ======== */

undefined8 FUN_00037140(uint param_1,undefined4 unaff_EDX)

{
  undefined4 *extraout_EDX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = DAT_001158bc; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if (((*(uint *)(puVar1[1] + 0xc) & param_1) != 0) &&
       (iVar2 = iVar2 + 1, (*(byte *)(puVar1[1] + 0xd) & 0x10) != 0)) {
      FUN_00037007();
      puVar1 = extraout_EDX;
    }
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_0003716f @ 0003716f ======== */

undefined8 FUN_0003716f(undefined4 param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  uint uVar2;
  
  uVar2 = DAT_00058ff0;
  DAT_00058ff0 = 0;
  if (uVar2 == 0) {
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    uVar2 = uVar2 & 0xff;
  }
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_0003718c @ 0003718c ======== */

int FUN_0003718c(int param_1)

{
  return (*(uint *)(param_1 + -4) & 0xfffffffe) - 4;
}


/* ======== FUN_00037195 @ 00037195 ======== */

undefined4 FUN_00037195(undefined4 param_1,undefined4 unaff_EDX)

{
  bool bVar1;
  int iVar2;
  byte extraout_DH;
  undefined2 in_DS;
  undefined4 local_18;
  byte local_14;
  
  local_14 = local_14 & 0xfe;
  while( true ) {
    iVar2 = FUN_000371cd(in_DS,param_1,unaff_EDX,&local_18);
    if (iVar2 == 0) {
      return param_1;
    }
    if (iVar2 == 1) break;
    if (((DAT_00058ffe == '\x01') && (DAT_00058fff == '\0')) || (DAT_00058ffe == '\t')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
    if (iVar2 == 2) {
      if (((local_14 & 1) != 0) || (iVar2 = FUN_00036ba4(local_18), iVar2 == 0)) {
        return 0;
      }
      local_14 = extraout_DH | 1;
    }
  }
  return 0;
}


/* ======== FUN_000371cd @ 000371cd ======== */

undefined4 FUN_000371cd(short param_1,uint unaff_EDX,uint unaff_EBX,uint *unaff_ECX)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint unaff_ESI;
  short in_DS;
  
  uVar3 = unaff_EBX + 7 & 0xfffffffc;
  if (uVar3 < unaff_EBX) {
    uVar3 = 0xffffffff;
  }
  if (uVar3 < 0xc) {
    uVar3 = 0xc;
  }
  puVar1 = (uint *)(unaff_EDX - 4);
  uVar5 = *puVar1 & 0xfffffffe;
  if (uVar5 < uVar3) {
    uVar3 = uVar3 - uVar5;
    puVar6 = (uint *)((int)puVar1 + uVar5);
    while( true ) {
      *unaff_ECX = uVar3;
      uVar5 = *puVar6;
      if (uVar5 == 0xffffffff) break;
      if ((uVar5 & 1) != 0) {
        return 1;
      }
      uVar3 = puVar6[2];
      uVar2 = puVar6[1];
      uVar4 = DAT_00058f90;
      if (in_DS == param_1) {
        for (; (unaff_ESI = uVar4, *(uint *)(uVar4 + 8) != 0 &&
               ((unaff_EDX < uVar4 || (*(uint *)(uVar4 + 8) <= unaff_EDX))));
            uVar4 = *(uint *)(uVar4 + 8)) {
        }
      }
      if (puVar6 == *(uint **)(unaff_ESI + 0xc)) {
        *(uint *)(unaff_ESI + 0xc) = (*(uint **)(unaff_ESI + 0xc))[1];
      }
      if (*unaff_ECX <= uVar5) {
        uVar4 = uVar5 - *unaff_ECX;
        if (0xb < uVar4) {
          puVar6 = (uint *)((int)puVar6 + *unaff_ECX);
          *puVar6 = uVar4;
          puVar6[1] = uVar2;
          puVar6[2] = uVar3;
          *(uint **)(uVar2 + 8) = puVar6;
          *(uint **)(uVar3 + 4) = puVar6;
          *puVar1 = *puVar1 + *unaff_ECX;
          DAT_001158b5 = 0;
          return 0;
        }
      }
      *(uint *)(uVar2 + 8) = uVar3;
      *(uint *)(uVar3 + 4) = uVar2;
      *puVar1 = *puVar1 + uVar5;
      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
      DAT_001158b5 = 0;
      if (*unaff_ECX <= uVar5) goto LAB_00037351;
      uVar3 = *unaff_ECX - uVar5;
      puVar6 = (uint *)((int)puVar6 + uVar5);
    }
    uVar7 = 2;
  }
  else {
    if (0xb < uVar5 - uVar3) {
      *puVar1 = uVar3 | 1;
      *(uint *)((int)puVar1 + uVar3) = uVar5 - uVar3 | 1;
      uVar5 = DAT_00058f90;
      if (in_DS == param_1) {
        for (; (unaff_ESI = uVar5, *(uint *)(uVar5 + 8) != 0 &&
               ((unaff_EDX < uVar5 || (*(uint *)(uVar5 + 8) <= unaff_EDX))));
            uVar5 = *(uint *)(uVar5 + 8)) {
        }
      }
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + 1;
      free((uint *)((int)puVar1 + uVar3) + 1);
    }
LAB_00037351:
    uVar7 = 0;
  }
  return uVar7;
}


/* ======== FUN_000373c8 @ 000373c8 ======== */

void FUN_000373c8(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  int iVar1;
  undefined2 in_DS;
  
  iVar1 = FUN_00038c92(param_1,in_DS,param_1,unaff_EDX,unaff_ECX,unaff_EBX);
  if (iVar1 == 0) {
    thunk_FUN_000341a9(param_1,unaff_EDX);
  }
  return;
}


/* ======== FUN_000373e5 @ 000373e5 ======== */

void FUN_000373e5(void)

{
  code *pcVar1;
  byte extraout_DH;
  byte extraout_DH_00;
  uint extraout_EDX;
  int iVar2;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  do {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  } while ((extraout_EDX >> 8 & 0xff) == (uint)extraout_DH);
  iVar2 = 0;
  do {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    iVar2 = iVar2 + 1;
  } while (extraout_DH == extraout_DH_00);
  DAT_001158c0 = iVar2;
  return;
}


/* ======== FUN_00037417 @ 00037417 ======== */

void FUN_00037417(int param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  if (param_1 != 0) {
    uVar2 = param_1 * DAT_001158c0 + 500;
    uVar3 = uVar2 / 1000;
    if (uVar3 == 0) {
      uVar3 = 1;
    }
    lVar4 = (ulonglong)(uVar2 % 1000) << 0x20;
    uVar5 = unaff_ECX;
    do {
      pcVar1 = (code *)swi(0x21);
      lVar4 = (*pcVar1)(CONCAT11(0x2c,(char)lVar4),(int)((ulonglong)lVar4 >> 0x20),0x300,unaff_ECX,
                        unaff_EDX,uVar5,unaff_EBX);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}


/* ======== FUN_0003744d @ 0003744d ======== */

undefined8 FUN_0003744d(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined uStack_20;
  undefined local_1f;
  byte local_18;
  byte local_17;
  byte local_14;
  byte local_13;
  
  local_1f = 0x2c;
  FUN_00038cda(&uStack_20,&uStack_20);
  return CONCAT44(unaff_EDX,
                  (uint)local_14 +
                  (((uint)local_18 + (uint)local_17 * 0x3c) * 0x3c + (uint)local_13) * 100);
}


/* ======== FUN_000374b3 @ 000374b3 ======== */

undefined8 FUN_000374b3(undefined4 param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  
  uVar1 = FUN_0003744d();
  if (uVar1 < DAT_001158c4) {
    uVar1 = uVar1 + 0x83d600;
  }
  return CONCAT44(unaff_EDX,uVar1 - DAT_001158c4);
}


/* ======== FUN_000374db @ 000374db ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000374db(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = FUN_0003759c(DAT_00058fd4,0,&local_24);
  local_1c = local_1c + 1;
  local_20 = local_1c * 4;
  uVar3 = (local_24 - (int)DAT_00058fd4) + 1;
  puVar2 = (undefined4 *)malloc(local_20 + 4 + uVar3);
  iVar1 = local_20;
  if (puVar2 == (undefined4 *)0x0) {
    _DAT_00058fa8 = 0;
    DAT_00058fac = (undefined4 *)0x0;
  }
  else {
    DAT_00058fac = (undefined4 *)((int)puVar2 + uVar3);
    puVar5 = DAT_00058fd4;
    puVar6 = puVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined *)puVar6 = *(undefined *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    puVar5 = DAT_00058fac + 1;
    *DAT_00058fac = DAT_00058fd8;
    FUN_0003759c(puVar2,puVar5,&local_24);
    _DAT_00058fa8 = local_1c;
    *(undefined4 *)((int)DAT_00058fac + iVar1) = 0;
  }
  DAT_001158c8 = local_1c;
  DAT_001158cc = DAT_00058fac;
  return;
}


/* ======== FUN_0003759c @ 0003759c ======== */

int FUN_0003759c(char *param_1,int unaff_EDX,char **unaff_EBX)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  bool bVar5;
  int local_14;
  
  local_14 = 0;
LAB_000375b3:
  cVar4 = *param_1;
  if ((cVar4 == ' ') || (cVar4 == '\t')) goto LAB_000375c1;
  if (cVar4 != '\0') {
    cVar4 = cVar4 == '\"';
    pcVar3 = param_1;
    pcVar2 = param_1;
    if ((bool)cVar4) {
      param_1 = param_1 + 1;
      pcVar3 = param_1;
      pcVar2 = param_1;
    }
    do {
      while (*param_1 != '\"') {
LAB_00037604:
        if ((((*param_1 == ' ') || (*param_1 == '\t')) && (cVar4 == '\0')) || (*param_1 == '\0'))
        goto LAB_00037663;
        if (*param_1 == '\\') {
          if (DAT_001158dc == 0) {
            bVar5 = param_1[1] == '\"';
LAB_00037631:
            if (!bVar5) goto LAB_00037654;
          }
          else if (cVar4 == '\x01') {
            if (param_1[1] != '\"') {
              bVar5 = param_1[1] == '\\';
              goto LAB_00037631;
            }
          }
          else if (param_1[1] != '\"') goto LAB_00037654;
          param_1 = param_1 + 1;
        }
LAB_00037654:
        if (unaff_EDX == 0) {
LAB_000375f7:
          param_1 = param_1 + 1;
        }
        else {
          cVar1 = *param_1;
          param_1 = param_1 + 1;
          *pcVar3 = cVar1;
          pcVar3 = pcVar3 + 1;
        }
      }
      if (cVar4 == '\x01') goto LAB_00037663;
      if (DAT_001158dc != 0) goto LAB_00037604;
      if (cVar4 == '\0') {
        cVar4 = '\x02';
        goto LAB_000375f7;
      }
      if (cVar4 != '\x02') goto LAB_00037604;
      param_1 = param_1 + 1;
      cVar4 = '\0';
    } while( true );
  }
  goto LAB_00037696;
LAB_00037663:
  if (unaff_EDX == 0) {
    local_14 = local_14 + 1;
    if (*param_1 == '\0') goto LAB_00037696;
LAB_000375c1:
    param_1 = param_1 + 1;
  }
  else {
    *(char **)(unaff_EDX + local_14 * 4) = pcVar2;
    local_14 = local_14 + 1;
    if (*param_1 == '\0') {
      *pcVar3 = '\0';
LAB_00037696:
      *unaff_EBX = param_1;
      return local_14;
    }
    param_1 = param_1 + 1;
    *pcVar3 = '\0';
  }
  goto LAB_000375b3;
}


/* ======== FUN_000376ac @ 000376ac ======== */

undefined4 * FUN_000376ac(undefined4 *param_1,undefined4 unaff_EDX,undefined4 unaff_EBX)

{
  param_1[1] = unaff_EDX;
  param_1[2] = unaff_EBX;
  *param_1 = DAT_00115874;
  DAT_00115874 = param_1;
  return &DAT_00115874;
}


/* ======== FUN_000376d2 @ 000376d2 ======== */

void FUN_000376d2(undefined4 param_1,undefined4 *unaff_EDX,undefined2 *unaff_EBX,
                 undefined4 unaff_ECX)

{
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_DS;
  byte in_CF;
  undefined8 uVar1;
  
  uVar1 = FUN_0003770a();
  *unaff_EDX = (int)uVar1;
  unaff_EDX[1] = unaff_EBX;
  unaff_EDX[2] = unaff_ECX;
  unaff_EDX[3] = (int)((ulonglong)uVar1 >> 0x20);
  unaff_EDX[4] = unaff_ESI;
  unaff_EDX[5] = unaff_EDI;
  unaff_EDX[6] = -(uint)in_CF;
  unaff_EBX[3] = in_DS;
  *unaff_EBX = in_ES;
  return;
}


/* ======== FUN_0003770a @ 0003770a ======== */

undefined8 FUN_0003770a(void)

{
  undefined4 *unaff_EDI;
  
  return CONCAT44(unaff_EDI[3],*unaff_EDI);
}


/* ======== FUN_0003777c @ 0003777c ======== */

undefined8 FUN_0003777c(undefined4 param_1,undefined4 *unaff_EDX)

{
  return CONCAT44(unaff_EDX[3],*unaff_EDX);
}


/* ======== FUN_00037ab0 @ 00037ab0 ======== */

void FUN_00037ab0(int param_1,byte *unaff_EDX)

{
  byte bVar1;
  
  memset(param_1,0,0x20);
  for (; bVar1 = *unaff_EDX, bVar1 != 0; unaff_EDX = unaff_EDX + 1) {
    *(byte *)(param_1 + ((int)(uint)bVar1 >> 3)) =
         *(byte *)(param_1 + ((int)(uint)bVar1 >> 3)) | (&DAT_00065d40)[bVar1 & 7];
  }
  return;
}


/* ======== FUN_00037aee @ 00037aee ======== */

undefined8
FUN_00037aee(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  uint extraout_EDX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x4400,unaff_EDX,param_1,unaff_ECX,unaff_ECX,unaff_EBX);
  return CONCAT44(unaff_ECX,(uint)((extraout_EDX & 0x80) != 0));
}


/* ======== FUN_00037b1c @ 00037b1c ======== */

ulonglong FUN_00037b1c(uint param_1,int unaff_EDX)

{
  uint uVar1;
  uint extraout_EDX;
  uint uVar2;
  
  if (unaff_EDX != 0) {
    FUN_0003654f(param_1 & 0xff,param_1 & 0xff);
    if (param_1 < 0x100) {
      uVar1 = extraout_EDX;
      if (2 < DAT_00059007) {
        uVar2 = extraout_EDX & 0xff;
        if (uVar2 == 0x50) {
          uVar1 = 0xe;
        }
        else if (uVar2 < 0x22) {
          if (0x1f < uVar2) {
            uVar1 = 5;
          }
        }
        else {
          uVar1 = 0x13;
        }
      }
      if (0x13 < (uVar1 & 0xff)) {
        uVar1 = 0x13;
      }
      uVar1 = *(int *)((uVar1 & 0xff) + 0x59229) >> 0x18;
    }
    else {
      uVar1 = param_1 >> 8 & 0xff;
    }
    FUN_0003652c(uVar1);
    return CONCAT44(unaff_EDX,0xffffffff);
  }
  return (ulonglong)param_1;
}


/* ======== FUN_00037b20 @ 00037b20 ======== */

undefined8 FUN_00037b20(uint param_1,undefined4 unaff_EDX)

{
  uint uVar1;
  uint extraout_EDX;
  uint uVar2;
  
  FUN_0003654f(param_1 & 0xff,param_1 & 0xff);
  if (param_1 < 0x100) {
    uVar1 = extraout_EDX;
    if (2 < DAT_00059007) {
      uVar2 = extraout_EDX & 0xff;
      if (uVar2 == 0x50) {
        uVar1 = 0xe;
      }
      else if (uVar2 < 0x22) {
        if (0x1f < uVar2) {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 0x13;
      }
    }
    if (0x13 < (uVar1 & 0xff)) {
      uVar1 = 0x13;
    }
    uVar1 = *(int *)((uVar1 & 0xff) + 0x59229) >> 0x18;
  }
  else {
    uVar1 = param_1 >> 8 & 0xff;
  }
  FUN_0003652c(uVar1);
  return CONCAT44(unaff_EDX,0xffffffff);
}


/* ======== FUN_00037b91 @ 00037b91 ======== */

longlong FUN_00037b91(uint param_1,uint unaff_EDX)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_00059244 <= param_1) {
    return (ulonglong)unaff_EDX << 0x20;
  }
  if ((int)param_1 < 6) {
    iVar1 = param_1 * 4;
    if ((PTR_DAT_00059298[iVar1 + 1] & 0x40) == 0) {
      PTR_DAT_00059298[iVar1 + 1] = PTR_DAT_00059298[iVar1 + 1] | 0x40;
      uVar2 = FUN_00037aee(param_1);
      param_1 = (uint)((ulonglong)uVar2 >> 0x20);
      if ((int)uVar2 != 0) {
        PTR_DAT_00059298[iVar1 + 1] = PTR_DAT_00059298[iVar1 + 1] | 0x20;
      }
    }
  }
  return CONCAT44(unaff_EDX,*(undefined4 *)(PTR_DAT_00059298 + param_1 * 4));
}


/* ======== FUN_00037be6 @ 00037be6 ======== */

void FUN_00037be6(int param_1,uint unaff_EDX)

{
  *(uint *)(PTR_DAT_00059298 + param_1 * 4) = unaff_EDX | 0x4000;
  return;
}


/* ======== FUN_00037bfb @ 00037bfb ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00037bfb(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  pcVar4 = DAT_00059001;
  if (DAT_00058fc4 == 0) {
    iVar5 = 0;
    pcVar3 = DAT_00059001;
    while (*pcVar3 != '\0') {
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      iVar5 = iVar5 + 1;
    }
    iVar2 = (int)pcVar3 - (int)DAT_00059001;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    pcVar3 = (char *)malloc(iVar2);
    if (pcVar3 != (char *)0x0) {
      uVar6 = malloc(iVar5 * 5 + 4,pcVar3);
      if ((int)uVar6 == 0) {
        free((int)((ulonglong)uVar6 >> 0x20));
      }
      else {
        iVar2 = 0;
        iVar5 = 0;
        DAT_00058fc4 = (int)uVar6;
        while (_DAT_00058fc8 = DAT_00058fc4, *pcVar4 != '\0') {
          *(char **)(iVar5 + DAT_00058fc4) = pcVar3;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            *pcVar3 = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          iVar5 = iVar5 + 4;
          iVar2 = iVar2 + 1;
        }
        *(undefined4 *)(iVar5 + DAT_00058fc4) = 0;
        _DAT_00058fc8 = _DAT_00058fc8 + iVar5 + 4;
        memset(_DAT_00058fc8,0,iVar2);
      }
    }
  }
  return;
}


/* ======== FUN_00037ccf @ 00037ccf ======== */

void FUN_00037ccf(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00038cbd(s_Floating_point_support_not_loade_0006583c,1,unaff_EBX,unaff_ECX,unaff_EDX);
  return;
}


/* ======== FUN_00037ce2 @ 00037ce2 ======== */

uint FUN_00037ce2(uint param_1,uint unaff_EDX)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((unaff_EDX & 0x7ff00000) != 0) {
    uVar1 = (uint)(CARRY4(unaff_EDX,unaff_EDX) ||
                  CARRY4(unaff_EDX * 2,(uint)CARRY4(param_1,param_1))) << 0x1f;
    uVar2 = param_1 * 2 + 0x20000000;
    uVar3 = unaff_EDX * 2 + (uint)CARRY4(param_1,param_1) + (uint)(0xdfffffff < param_1 * 2);
    if ((uVar3 == 0) || (0x8fdfffff < uVar3)) {
      return uVar1 | 0x7f800000;
    }
    if (0x701fffff < uVar3) {
      return ((uVar3 + 0x90000000) * 2 + (uint)CARRY4(uVar2,uVar2)) * 2 +
             (uint)CARRY4(uVar2 * 2,uVar2 * 2) | uVar1;
    }
  }
  return 0;
}


/* ======== FUN_00037d2e @ 00037d2e ======== */

int FUN_00037d2e(void)

{
  return (int)&stack0x00000000 - DAT_00058fe0;
}


/* ======== FUN_00037d37 @ 00037d37 ======== */

undefined8 FUN_00037d37(undefined4 param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  int iVar2;
  undefined2 extraout_var;
  byte bVar3;
  
  DAT_000592a8 = 0x8000;
  if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    iVar2 = FUN_00038e35();
    if (iVar2 == 1) {
      bVar3 = 0;
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(0x600,0,0x41e4,3);
      iVar2 = CONCAT22(extraout_var,-(ushort)bVar3);
    }
  }
  return CONCAT44(unaff_EDX,iVar2);
}


/* ======== FUN_00037da0 @ 00037da0 ======== */

undefined * FUN_00037da0(void)

{
  return &DAT_001158d0;
}


/* ======== FUN_00037da6 @ 00037da6 ======== */

undefined * FUN_00037da6(void)

{
  return &DAT_001158d4;
}


/* ======== FUN_00037e74 @ 00037e74 ======== */

undefined8 FUN_00037e74(uint param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined unaff_DI;
  undefined2 in_DS;
  byte bVar6;
  undefined8 uVar7;
  
  if (DAT_00058fe4 <= param_1) {
    if (DAT_00058ffe == '\0') {
      uVar5 = param_1 + 0xf >> 4;
      if (uVar5 == 0) {
        uVar5 = 0xfffffff;
      }
      pcVar1 = (code *)swi(0x21);
      uVar7 = (*pcVar1)(CONCAT11(0xed,(char)in_DS),unaff_EDX,in_DS);
      iVar3 = (int)uVar7 << 0x1f;
      bVar6 = 0;
      if (iVar3 != 0) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)(CONCAT22((short)((uint)iVar3 >> 0x10),CONCAT11(0x4a,unaff_DI)),
                  (int)((ulonglong)uVar7 >> 0x20),uVar5);
        if ((bVar6 & 1) != 0) goto LAB_00037edf;
      }
      bVar6 = false;
    }
    else {
      bVar6 = DAT_00058ffe == '\0';
      if ((DAT_00058ffe == '\x01') && (bVar6 = DAT_00058fff == '\0', DAT_00058fff == '\x01')) {
        bVar6 = false;
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    uVar5 = DAT_00058fd0;
    uVar2 = param_1;
    if ((bVar6 & 1) == 0) goto LAB_00037f34;
  }
LAB_00037edf:
  puVar4 = (undefined4 *)FUN_00037da0();
  *puVar4 = 5;
  uVar5 = 0xffffffff;
  uVar2 = DAT_00058fd0;
LAB_00037f34:
  DAT_00058fd0 = uVar2;
  return CONCAT44(unaff_EDX,uVar5);
}


/* ======== FUN_00037f3f @ 00037f3f ======== */

undefined4 FUN_00037f3f(undefined4 param_1,char *unaff_EDX,int *unaff_EBX,code *unaff_ECX)

{
  int iVar1;
  char cVar2;
  undefined6 *puVar3;
  byte bVar5;
  undefined *puVar4;
  char *pcVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  bool bVar9;
  undefined auStack_134 [256];
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  byte local_20;
  char local_1f;
  char local_1e;
  char local_1d [5];
  undefined local_14 [4];
  
  local_14[0] = 0;
  local_20 = 0;
  local_24 = 0;
  local_34 = param_1;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          cVar2 = *unaff_EDX;
          if (cVar2 == '\0') {
            return local_24;
          }
          unaff_EDX = unaff_EDX + 1;
          if (cVar2 == '%') break;
          (*unaff_ECX)(&local_34);
        }
        unaff_EDX = (char *)FUN_000382de(unaff_EDX,unaff_EBX,&local_34);
        local_1f = *unaff_EDX;
        unaff_EDX = unaff_EDX + 1;
        if (local_1f == '\0') {
          return local_24;
        }
        if (local_1f == 'n') break;
        puVar4 = (undefined *)FUN_0003861c(auStack_134,unaff_EBX,&local_34,local_14);
        if (((local_20 & 8) == 0) && (local_1e == ' ')) {
          while (local_30 = local_30 + -1, -1 < local_30) {
            (*unaff_ECX)(&local_34,local_1e);
          }
        }
        for (pcVar6 = local_1d; *pcVar6 != '\0'; pcVar6 = pcVar6 + 1) {
          (*unaff_ECX)(&local_34,*pcVar6);
        }
        while (iVar1 = local_28 + -1, local_28 != 0) {
          local_28 = iVar1;
          (*unaff_ECX)(&local_34,0x30);
        }
        local_28 = iVar1;
        if (((local_20 & 8) == 0) && (local_1e != ' ')) {
          while (local_30 = local_30 + -1, -1 < local_30) {
            (*unaff_ECX)(&local_34,local_1e);
          }
        }
        if ((local_1f == 's') || (local_1f == 'S')) {
          if ((local_20 & 0x20) == 0) {
            while (iVar1 = local_2c + -1, bVar9 = local_2c != 0, local_2c = iVar1, bVar9) {
              (*unaff_ECX)(&local_34,*puVar4);
              puVar4 = puVar4 + 1;
            }
          }
          else {
            while (iVar1 = local_2c + -1, bVar9 = local_2c != 0, local_2c = iVar1, bVar9) {
              (*unaff_ECX)(&local_34,*puVar4);
              puVar4 = puVar4 + 2;
            }
          }
        }
        else {
          while (iVar1 = local_2c + -1, bVar9 = local_2c != 0, local_2c = iVar1, bVar9) {
            (*unaff_ECX)(&local_34,*puVar4);
            puVar4 = puVar4 + 1;
          }
        }
        if (((local_20 & 8) != 0) && (0 < local_30)) {
          while (iVar1 = local_30 + -1, bVar9 = local_30 != 0, local_30 = iVar1, bVar9) {
            (*unaff_ECX)(&local_34,0x20);
          }
        }
      }
      bVar5 = local_20 & 0x80;
      if ((local_20 & 0x20) == 0) break;
      if (bVar5 == 0) {
        if ((local_20 & 0x40) == 0) {
          puVar7 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar7 + 1);
          puVar7 = (undefined4 *)*puVar7;
        }
        else {
          puVar7 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar7 + 1);
          puVar7 = (undefined4 *)*puVar7;
        }
LAB_00038008:
        *puVar7 = local_24;
      }
      else {
        puVar3 = (undefined6 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar3 + 1);
        puVar7 = (undefined4 *)*puVar3;
LAB_00037fec:
        *puVar7 = local_24;
      }
    }
    if ((local_20 & 0x10) == 0) {
      if (bVar5 == 0) {
        if ((local_20 & 0x40) == 0) {
          puVar7 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar7 + 1);
          puVar7 = (undefined4 *)*puVar7;
        }
        else {
          puVar7 = (undefined4 *)*unaff_EBX;
          *unaff_EBX = (int)(puVar7 + 1);
          puVar7 = (undefined4 *)*puVar7;
        }
        goto LAB_00038008;
      }
      puVar3 = (undefined6 *)*unaff_EBX;
      *unaff_EBX = (int)(puVar3 + 1);
      puVar7 = (undefined4 *)*puVar3;
      goto LAB_00037fec;
    }
    if (bVar5 == 0) {
      if ((local_20 & 0x40) == 0) {
        puVar7 = (undefined4 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar7 + 1);
        puVar8 = (undefined2 *)*puVar7;
      }
      else {
        puVar7 = (undefined4 *)*unaff_EBX;
        *unaff_EBX = (int)(puVar7 + 1);
        puVar8 = (undefined2 *)*puVar7;
      }
      *puVar8 = (short)local_24;
    }
    else {
      puVar3 = (undefined6 *)*unaff_EBX;
      *unaff_EBX = (int)(puVar3 + 1);
      *(undefined2 *)*puVar3 = (short)local_24;
    }
  } while( true );
}


/* ======== FUN_000382de @ 000382de ======== */

byte * FUN_000382de(undefined4 param_1,int **unaff_EDX,int unaff_EBX)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  
  *(undefined *)(unaff_EBX + 0x17) = 0;
  *(undefined *)(unaff_EBX + 0x16) = 0x20;
  pbVar3 = (byte *)FUN_0003841c(param_1,unaff_EBX);
  *(undefined4 *)(unaff_EBX + 4) = 0;
  if ((*pbVar3 < 0x30) || (0x39 < *pbVar3)) {
    if (*pbVar3 == 0x2a) {
      piVar1 = *unaff_EDX;
      *unaff_EDX = piVar1 + 1;
      iVar2 = *piVar1;
      *(int *)(unaff_EBX + 4) = iVar2;
      if (iVar2 < 0) {
        *(int *)(unaff_EBX + 4) = -iVar2;
        *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) | 8;
      }
      pbVar3 = pbVar3 + 1;
    }
  }
  else {
    do {
      bVar5 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      *(uint *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) * 10 + (bVar5 - 0x30);
      if (*pbVar3 < 0x30) break;
    } while (*pbVar3 < 0x3a);
  }
  *(undefined4 *)(unaff_EBX + 8) = 0xffffffff;
  pbVar4 = pbVar3;
  if (*pbVar3 == 0x2e) {
    pbVar4 = pbVar3 + 1;
    *(undefined4 *)(unaff_EBX + 8) = 0;
    if (*pbVar4 == 0x2a) {
      piVar1 = *unaff_EDX;
      *unaff_EDX = piVar1 + 1;
      iVar2 = *piVar1;
      *(int *)(unaff_EBX + 8) = iVar2;
      if (iVar2 < 0) {
        *(undefined4 *)(unaff_EBX + 8) = 0xffffffff;
      }
      pbVar4 = pbVar3 + 2;
    }
    else {
      while( true ) {
        bVar5 = *pbVar4;
        if ((bVar5 < 0x30) || (bVar5 != 0x39 && 0x38 < bVar5)) break;
        pbVar4 = pbVar4 + 1;
        *(uint *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) * 10 + (bVar5 - 0x30);
      }
    }
  }
  bVar5 = *pbVar4;
  pbVar3 = pbVar4 + 1;
  if (bVar5 < 0x4e) {
    if (0x45 < bVar5) {
      if (0x46 < bVar5) {
        if (bVar5 == 0x4c) {
          *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) | 0x40;
          return pbVar3;
        }
        return pbVar4;
      }
      bVar5 = *(byte *)(unaff_EBX + 0x14) | 0x80;
LAB_000383ec:
      *(byte *)(unaff_EBX + 0x14) = bVar5;
      return pbVar4 + 1;
    }
  }
  else if (bVar5 < 0x4f) {
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) | 0x40;
    pbVar4 = pbVar3;
  }
  else {
    if (0x6b < bVar5) {
      if ((0x6c < bVar5) && (bVar5 != 0x77)) {
        return pbVar4;
      }
      bVar5 = *(byte *)(unaff_EBX + 0x14) | 0x20;
      goto LAB_000383ec;
    }
    if (bVar5 != 0x68) {
      return pbVar4;
    }
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) | 0x10;
    pbVar4 = pbVar3;
  }
  return pbVar4;
}


/* ======== FUN_0003841c @ 0003841c ======== */

char * FUN_0003841c(char *param_1,int unaff_EDX)

{
  char cVar1;
  
  *(undefined *)(unaff_EDX + 0x14) = 0;
  do {
    cVar1 = *param_1;
    if (cVar1 == '-') {
      *(byte *)(unaff_EDX + 0x14) = *(byte *)(unaff_EDX + 0x14) | 8;
    }
    else if (cVar1 == '#') {
      *(byte *)(unaff_EDX + 0x14) = *(byte *)(unaff_EDX + 0x14) | 1;
    }
    else if (cVar1 == '+') {
      *(byte *)(unaff_EDX + 0x14) = *(byte *)(unaff_EDX + 0x14) & 0xfd | 4;
    }
    else if (cVar1 == ' ') {
      if ((*(byte *)(unaff_EDX + 0x14) & 4) == 0) {
        *(byte *)(unaff_EDX + 0x14) = *(byte *)(unaff_EDX + 0x14) | 2;
      }
    }
    else {
      if (cVar1 != '0') {
        return param_1;
      }
      *(undefined *)(unaff_EDX + 0x16) = 0x30;
    }
    param_1 = param_1 + 1;
  } while( true );
}


/* ======== FUN_0003847b @ 0003847b ======== */

void FUN_0003847b(char *param_1,undefined4 param_2,int unaff_EBX)

{
  char cVar1;
  int iVar2;
  
  for (iVar2 = 0; (cVar1 = *param_1, param_1 = param_1 + 1, cVar1 != '\0' && (iVar2 != unaff_EBX));
      iVar2 = iVar2 + 1) {
  }
  return;
}


/* ======== FUN_0003849f @ 0003849f ======== */

void FUN_0003849f(short *param_1,undefined4 param_2,int unaff_EBX)

{
  short sVar1;
  int iVar2;
  
  for (iVar2 = 0; (sVar1 = *param_1, param_1 = param_1 + 1, sVar1 != 0 && (iVar2 != unaff_EBX));
      iVar2 = iVar2 + 1) {
  }
  return;
}


/* ======== FUN_000384c2 @ 000384c2 ======== */

void FUN_000384c2(undefined4 param_1,char *unaff_EDX,int unaff_EBX)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  FUN_0003515f(param_1,unaff_EDX,0x10);
  uVar3 = 0xffffffff;
  pcVar4 = unaff_EDX;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = unaff_EBX + -1;
  pcVar4 = unaff_EDX + (~uVar3 - 1);
  pcVar5 = unaff_EDX + iVar2;
  while (pcVar4 != unaff_EDX) {
    pcVar4 = pcVar4 + -1;
    iVar2 = iVar2 + -1;
    *pcVar5 = *pcVar4;
    pcVar5 = pcVar5 + -1;
  }
  pcVar4 = unaff_EDX + iVar2;
  for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    *pcVar4 = '0';
    pcVar4 = pcVar4 + -1;
  }
  unaff_EDX[unaff_EBX] = '\0';
  return;
}


/* ======== FUN_00038520 @ 00038520 ======== */

void FUN_00038520(char *param_1,uint unaff_EDX,int unaff_EBX)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = param_1;
  if ((int)unaff_EDX < 0) {
    unaff_EDX = -unaff_EDX;
    pcVar2 = param_1 + 1;
    *param_1 = '-';
  }
  if (*(int *)(unaff_EBX + 8) == -1) {
    *(undefined4 *)(unaff_EBX + 8) = 4;
  }
  FUN_0003515f(unaff_EDX >> 0x10,pcVar2,10);
  pcVar4 = pcVar2;
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  if (*(int *)(unaff_EBX + 8) != 0) {
    *pcVar3 = '.';
    for (iVar1 = 0; iVar1 < *(int *)(unaff_EBX + 8); iVar1 = iVar1 + 1) {
      unaff_EDX = (unaff_EDX & 0xffff) * 10;
      *pcVar4 = (char)(unaff_EDX >> 0x10) + '0';
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = '\0';
    pcVar3 = pcVar4;
  }
  if ((unaff_EDX & 0x8000) != 0) {
    while (pcVar3 != pcVar2) {
      pcVar4 = pcVar3 + -1;
      if (*pcVar4 == '.') {
        pcVar4 = pcVar3 + -2;
      }
      if (*pcVar4 != '9') {
        *pcVar4 = *pcVar4 + '\x01';
        return;
      }
      *pcVar4 = '0';
      pcVar3 = pcVar4;
    }
    *pcVar2 = '1';
    pcVar2 = pcVar2 + 1;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (*pcVar4 == '0');
    if (*pcVar4 == '.') {
      *pcVar4 = '0';
      pcVar4[1] = '.';
      for (pcVar4 = pcVar4 + 2; *pcVar4 == '0'; pcVar4 = pcVar4 + 1) {
      }
    }
    *pcVar4 = '0';
    pcVar4[1] = '\0';
  }
  return;
}


/* ======== FUN_00038615 @ 00038615 ======== */

void FUN_00038615(void)

{
  (*(code *)PTR_FUN_0005929c)();
  return;
}


/* ======== FUN_0003861c @ 0003861c ======== */

undefined8 FUN_0003861c(ushort *param_1,uint **unaff_EDX,int unaff_EBX,ushort *unaff_ECX)

{
  byte bVar1;
  ushort **ppuVar2;
  uint *puVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar8;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined4 uVar9;
  uint unaff_EBP;
  ushort *puVar10;
  ushort in_DS;
  ushort uVar11;
  bool bVar12;
  undefined8 uVar13;
  
  bVar4 = true;
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  *(undefined4 *)(unaff_EBX + 0xc) = 0;
  if (bVar1 < 0x69) {
    if (0x57 < bVar1) {
      if (bVar1 < 0x59) goto LAB_00038673;
      if (bVar1 == 100) goto LAB_000386b6;
    }
  }
  else {
    if (0x69 < bVar1) {
      if (bVar1 < 0x75) {
        bVar12 = bVar1 == 0x6f;
      }
      else {
        if (bVar1 < 0x76) goto LAB_00038673;
        bVar12 = bVar1 == 0x78;
      }
      if (!bVar12) goto LAB_000386c0;
LAB_00038673:
      if ((*(byte *)(unaff_EBX + 0x14) & 0x20) == 0) {
        if ((*(byte *)(unaff_EBX + 0x14) & 0x10) == 0) {
          puVar3 = *unaff_EDX;
          *unaff_EDX = puVar3 + 1;
          unaff_EBP = *puVar3;
        }
        else {
          puVar3 = *unaff_EDX;
          *unaff_EDX = puVar3 + 1;
          unaff_EBP = (uint)*(ushort *)puVar3;
        }
      }
      else {
        puVar3 = *unaff_EDX;
        *unaff_EDX = puVar3 + 1;
        unaff_EBP = *puVar3;
      }
      *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    }
LAB_000386b6:
    if (*(int *)(unaff_EBX + 8) != -1) {
      *(undefined *)(unaff_EBX + 0x16) = 0x20;
    }
  }
LAB_000386c0:
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  uVar9 = 10;
  puVar10 = param_1;
  uVar7 = in_DS;
  uVar11 = in_DS;
  if (bVar1 < 0x65) {
    if (bVar1 < 0x50) {
      if (bVar1 < 0x46) {
        bVar12 = bVar1 == 0x45;
      }
      else {
        if (bVar1 < 0x47) goto LAB_0003877b;
        bVar12 = bVar1 == 0x47;
      }
      if (!bVar12) goto LAB_00038a2a;
      goto LAB_000387ad;
    }
    if (0x50 < bVar1) {
      if (bVar1 < 0x58) {
        if (bVar1 != 0x53) goto LAB_00038a2a;
LAB_00038858:
        param_1 = unaff_ECX;
        if ((*(byte *)(unaff_EBX + 0x14) & 0x80) == 0) {
          if ((*(byte *)(unaff_EBX + 0x14) & 0x40) == 0) {
            ppuVar2 = (ushort **)*unaff_EDX;
            *unaff_EDX = (uint *)(ppuVar2 + 1);
            puVar10 = *ppuVar2;
          }
          else {
            ppuVar2 = (ushort **)*unaff_EDX;
            *unaff_EDX = (uint *)(ppuVar2 + 1);
            puVar10 = *ppuVar2;
          }
          if (puVar10 != (ushort *)0x0) {
            param_1 = puVar10;
          }
        }
        else {
          ppuVar2 = (ushort **)*unaff_EDX;
          *unaff_EDX = (uint *)(ppuVar2 + 2);
          if ((*ppuVar2 != (ushort *)0x0) || (*(ushort *)(ppuVar2 + 1) != 0)) {
            param_1 = *ppuVar2;
            uVar7 = *(ushort *)(ppuVar2 + 1);
          }
        }
        bVar1 = *(byte *)(unaff_EBX + 0x14);
        bVar4 = false;
        *(byte *)(unaff_EBX + 0x14) = bVar1 & 0xf9;
        if (*(char *)(unaff_EBX + 0x15) == 'S') {
          if ((bVar1 & 0x20) == 0) {
            uVar5 = (uint)*(byte *)param_1;
            param_1 = (ushort *)((int)param_1 + 1);
          }
          else {
            uVar5 = (uint)*param_1;
            param_1 = param_1 + 1;
          }
        }
        else {
          if ((bVar1 & 0x20) == 0) {
            uVar5 = (uint)uVar7;
            uVar9 = *(undefined4 *)(unaff_EBX + 8);
            goto LAB_000387fd;
          }
          uVar5 = FUN_0003849f(param_1,uVar7,*(undefined4 *)(unaff_EBX + 8));
        }
      }
      else {
        if (bVar1 < 0x59) {
LAB_00038921:
          if (((*(byte *)(unaff_EBX + 0x14) & 1) != 0) && (unaff_EBP != 0)) {
            *(undefined *)(unaff_EBX + 0x17) = 0x30;
            *(undefined *)(unaff_EBX + 0x19) = 0;
            *(undefined *)(unaff_EBX + 0x18) = *(undefined *)(unaff_EBX + 0x15);
          }
          uVar9 = 0x10;
LAB_00038944:
          FUN_00039312(unaff_EBP,param_1,uVar9);
          uVar8 = extraout_var_03;
          if (*(char *)(unaff_EBX + 0x15) == 'X') {
            FUN_00038b05(param_1);
            uVar8 = extraout_var_04;
          }
          goto LAB_000387e1;
        }
        if (bVar1 < 99) goto LAB_00038a2a;
        if (99 < bVar1) goto LAB_00038807;
        puVar3 = *unaff_EDX;
        *unaff_EDX = puVar3 + 1;
        bVar1 = *(byte *)puVar3;
        *(byte *)((int)param_1 + 1) = 0;
        *(byte *)param_1 = bVar1;
        *(undefined4 *)(unaff_EBX + 8) = 1;
        bVar4 = false;
        uVar5 = 1;
        *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
      }
      goto LAB_00038a53;
    }
LAB_00038967:
    if (*(int *)(unaff_EBX + 4) == 0) {
      if ((*(byte *)(unaff_EBX + 0x14) & 0x80) == 0) {
        *(undefined4 *)(unaff_EBX + 4) = 8;
      }
      else {
        *(undefined4 *)(unaff_EBX + 4) = 0xd;
      }
    }
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    puVar3 = *unaff_EDX;
    *unaff_EDX = puVar3 + 1;
    uVar5 = *puVar3;
    if ((*(byte *)(unaff_EBX + 0x14) & 0x80) != 0) {
      *unaff_EDX = puVar3 + 2;
      FUN_000384c2(puVar3[1] & 0xffff,param_1,4);
      *(byte *)(param_1 + 2) = 0x3a;
      puVar10 = (ushort *)((int)param_1 + 5);
    }
    FUN_000384c2(uVar5,puVar10,8);
    uVar8 = extraout_var_05;
    if (*(char *)(unaff_EBX + 0x15) == 'P') {
      FUN_00038b05(param_1);
      uVar8 = extraout_var_06;
    }
LAB_000387f4:
    uVar9 = 0xffffffff;
    uVar5 = CONCAT22(uVar8,in_DS);
    uVar7 = in_DS;
    in_DS = uVar11;
LAB_000387fd:
    uVar5 = FUN_0003847b(param_1,uVar5,uVar9);
  }
  else {
    if (bVar1 < 0x66) {
LAB_000387ad:
      uVar13 = FUN_00038615(param_1,unaff_EDX,unaff_EBX);
      uVar5 = (uint)((ulonglong)uVar13 >> 0x20);
      param_1 = (ushort *)uVar13;
      uVar9 = 0xffffffff;
      uVar7 = (ushort)((ulonglong)uVar13 >> 0x20);
      goto LAB_000387fd;
    }
    if (bVar1 < 0x6f) {
      if (bVar1 < 0x67) {
LAB_0003877b:
        if ((*(byte *)(unaff_EBX + 0x14) & 0x10) != 0) {
          puVar3 = *unaff_EDX;
          *unaff_EDX = puVar3 + 1;
          FUN_00038520(param_1,*puVar3,unaff_EBX);
          uVar9 = 0xffffffff;
          uVar5 = CONCAT22(extraout_var,uVar7);
          in_DS = uVar7;
          goto LAB_000387fd;
        }
      }
      else if (0x67 < bVar1) {
        if (bVar1 == 0x69) {
LAB_00038807:
          if ((*(byte *)(unaff_EBX + 0x14) & 0x20) == 0) {
            if ((*(byte *)(unaff_EBX + 0x14) & 0x10) == 0) {
              puVar3 = *unaff_EDX;
              *unaff_EDX = puVar3 + 1;
              FUN_0003515f(*puVar3,param_1,10);
              uVar8 = extraout_var_02;
              goto LAB_000387e1;
            }
            puVar3 = *unaff_EDX;
            *unaff_EDX = puVar3 + 1;
            uVar5 = (uint)(short)*(ushort *)puVar3;
          }
          else {
            puVar3 = *unaff_EDX;
            *unaff_EDX = puVar3 + 1;
            uVar5 = *puVar3;
          }
          FUN_0003935c(uVar5,param_1);
          uVar8 = extraout_var_01;
          goto LAB_000387e1;
        }
        goto LAB_00038a2a;
      }
      goto LAB_000387ad;
    }
    if (bVar1 < 0x70) {
      if ((*(byte *)(unaff_EBX + 0x14) & 1) != 0) {
        *(byte *)param_1 = 0x30;
        puVar10 = (ushort *)((int)param_1 + 1);
      }
      FUN_0003935c(unaff_EBP,puVar10,8);
      uVar8 = extraout_var_00;
LAB_000387e1:
      if ((*(int *)(unaff_EBX + 8) == 0) && (*(byte *)puVar10 == 0x30)) {
        *(byte *)param_1 = 0;
      }
      goto LAB_000387f4;
    }
    if (bVar1 < 0x73) {
      if (bVar1 == 0x70) goto LAB_00038967;
    }
    else {
      if (bVar1 < 0x74) goto LAB_00038858;
      if (0x74 < bVar1) {
        if (bVar1 < 0x76) goto LAB_00038944;
        if (bVar1 == 0x78) goto LAB_00038921;
      }
    }
LAB_00038a2a:
    *(undefined4 *)(unaff_EBX + 4) = 0;
    bVar1 = *(byte *)(unaff_EBX + 0x15);
    *(byte *)((int)param_1 + 1) = 0;
    *(byte *)param_1 = bVar1;
    *(undefined4 *)(unaff_EBX + 8) = 1;
    bVar4 = false;
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    uVar5 = 1;
  }
LAB_00038a53:
  if (!bVar4) goto LAB_00038aa8;
  if (*(byte *)param_1 == 0x2d) {
    param_1 = (ushort *)((int)param_1 + 1);
    *(undefined *)(unaff_EBX + 0x17) = 0x2d;
    uVar5 = uVar5 - 1;
LAB_00038a91:
    *(undefined *)(unaff_EBX + 0x18) = 0;
  }
  else {
    if ((*(byte *)(unaff_EBX + 0x14) & 2) != 0) {
      *(undefined *)(unaff_EBX + 0x17) = 0x20;
      goto LAB_00038a91;
    }
    if ((*(byte *)(unaff_EBX + 0x14) & 4) != 0) {
      *(undefined *)(unaff_EBX + 0x17) = 0x2b;
      goto LAB_00038a91;
    }
  }
  if (*(int *)(unaff_EBX + 8) < (int)uVar5) {
    *(uint *)(unaff_EBX + 8) = uVar5;
  }
  else {
    *(uint *)(unaff_EBX + 0xc) = *(int *)(unaff_EBX + 8) - uVar5;
  }
LAB_00038aa8:
  if (*(char *)(unaff_EBX + 0x16) == '*') {
    *(undefined *)(unaff_EBX + 0x17) = 0;
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
  }
  if (((*(int *)(unaff_EBX + 8) == -1) || ((int)uVar5 < *(int *)(unaff_EBX + 8))) &&
     (*(char *)(unaff_EBX + 0x15) != 'c')) {
    *(uint *)(unaff_EBX + 8) = uVar5;
  }
  iVar6 = FUN_0003847b(unaff_EBX + 0x17,in_DS,0xffffffff);
  *(int *)(unaff_EBX + 4) =
       *(int *)(unaff_EBX + 4) - (iVar6 + *(int *)(unaff_EBX + 8) + *(int *)(unaff_EBX + 0xc));
  return CONCAT44(CONCAT22((short)((uint)*(int *)(unaff_EBX + 0xc) >> 0x10),uVar7),param_1);
}


/* ======== FUN_00038b05 @ 00038b05 ======== */

void FUN_00038b05(char *param_1)

{
  undefined uVar1;
  undefined *extraout_EDX;
  
  while (*param_1 != '\0') {
    uVar1 = FUN_00039377(*param_1);
    *extraout_EDX = uVar1;
    param_1 = extraout_EDX + 1;
  }
  return;
}


/* ======== FUN_00038b94 @ 00038b94 ======== */

void FUN_00038b94(void)

{
  FUN_00038ba5(0);
  FUN_00036fb2();
  return;
}


/* ======== FUN_00038ba5 @ 00038ba5 ======== */

undefined8 FUN_00038ba5(int param_1,undefined4 unaff_EDX)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar3 = DAT_001158bc;
LAB_00038bf2:
  if (puVar3 == (undefined4 *)0x0) {
    return CONCAT44(unaff_EDX,iVar5);
  }
  puVar1 = (undefined4 *)*puVar3;
  puVar2 = (undefined *)puVar3[1];
  uVar4 = 1;
  puVar3 = puVar1;
  if (((puVar2[0xd] & 0x40) == 0) && ((puVar2[0xd] & 8) == 0)) goto code_r0x00038bdd;
  goto LAB_00038bea;
code_r0x00038bdd:
  if (&DAT_00059010 + param_1 * 0x1a <= puVar2) {
    if (puVar2 < &DAT_00059092) {
      uVar4 = 0;
    }
LAB_00038bea:
    FUN_00034b27(puVar2,uVar4);
    iVar5 = iVar5 + 1;
  }
  goto LAB_00038bf2;
}


/* ======== FUN_00038bfd @ 00038bfd ======== */

uint FUN_00038bfd(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint extraout_EDX;
  byte bVar4;
  bool bVar5;
  uint uStack_14;
  
  uVar2 = FUN_00037b91();
  if ((uVar2 & 0x80) != 0) {
    bVar4 = 0;
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)(0x4202,0,param_1,0);
    uStack_14 = uVar2 & 0xffff;
    if ((bVar4 & 1) != 0) goto LAB_00038c35;
  }
  bVar4 = 0;
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)(CONCAT11(0x40,(char)uVar2),unaff_EDX,param_1,unaff_EBX);
  bVar5 = (bVar4 & 1) != 0;
  uStack_14 = (iVar3 << 1 | (uint)bVar4) >> 1 | (uint)bVar5 << 0x1f;
  if (!bVar5) {
    if (uStack_14 == unaff_EBX) {
      return uStack_14;
    }
    FUN_0003652c(0xc);
    return extraout_EDX;
  }
LAB_00038c35:
  uVar2 = FUN_00037b20(uStack_14 & 0xffff);
  return uVar2;
}


/* ======== FUN_00038c71 @ 00038c71 ======== */

longlong FUN_00038c71(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  byte in_CF;
  uint unaff_retaddr;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x41,(char)param_1),param_1);
  if ((in_CF & 1) != 0) {
    uVar3 = FUN_00037b20((iVar2 << 1 | (uint)in_CF) >> 1 & 0xffff);
    return CONCAT44(unaff_retaddr,uVar3);
  }
  return (ulonglong)unaff_retaddr << 0x20;
}


/* ======== FUN_00038c92 @ 00038c92 ======== */

undefined4 FUN_00038c92(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_000592ac != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  return 0;
}


/* ======== thunk_FUN_000341a9 @ 00038cb8 ======== */

undefined4
thunk_FUN_000341a9(undefined4 param_1,char *unaff_EDX,undefined4 param_3,undefined4 param_4,
                  undefined param_5)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  pcVar3 = (code *)swi(0x21);
  uVar4 = (*pcVar3)(0x3d01,&DAT_00033f8c);
  pcVar6 = unaff_EDX;
  do {
    pcVar1 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar1;
  } while (cVar2 != '\0');
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)(0x4000,unaff_EDX,uVar4,pcVar1 + (-1 - (int)unaff_EDX));
  FUN_000364d7(0,0xff);
  pcVar3 = (code *)swi(0x21);
  uVar5 = (*pcVar3)(CONCAT11(0x4c,param_5));
  return uVar5;
}


/* ======== FUN_00038cbd @ 00038cbd ======== */

void FUN_00038cbd(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  int iVar1;
  undefined2 in_DS;
  
  iVar1 = FUN_00038c92(param_1,in_DS,param_1,unaff_EDX,unaff_ECX,unaff_EBX);
  if (iVar1 == 0) {
    FUN_000341a9(param_1,unaff_EDX);
  }
  return;
}


/* ======== FUN_00038cda @ 00038cda ======== */

undefined4 FUN_00038cda(undefined4 *param_1,undefined4 *unaff_EDX)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined4 *unaff_EBP;
  byte bVar6;
  undefined8 uVar7;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[4];
  uVar4 = param_1[5];
  bVar6 = 0;
  pcVar5 = (code *)swi(0x21);
  uVar7 = (*pcVar5)(*param_1,param_1[3]);
  *unaff_EDX = (int)uVar7;
  unaff_EDX[1] = uVar1;
  unaff_EDX[2] = uVar2;
  unaff_EDX[3] = (int)((ulonglong)uVar7 >> 0x20);
  unaff_EDX[4] = uVar3;
  unaff_EDX[5] = uVar4;
  unaff_EBP[6] = -(uint)bVar6;
  FUN_00037b1c(*unaff_EBP,-(uint)bVar6);
  return *unaff_EBP;
}


/* ======== FUN_00038e35 @ 00038e35 ======== */

undefined8
FUN_00038e35(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 in_DS;
  
  if (DAT_000592c8 != 0) goto LAB_00038ebc;
  if (DAT_00058ffe == '\x01') {
LAB_00038e60:
    pcVar1 = (code *)swi(0x31);
    uVar3 = (*pcVar1)(0x400,in_DS,unaff_EBX,unaff_ECX,0,0);
    if ((uint)(byte)((ushort)uVar3 >> 8) + (uint)(byte)uVar3 != 0) {
      DAT_000592c8 = 1;
      goto LAB_00038ebc;
    }
  }
  else {
    pcVar1 = (code *)swi(0x2f);
    sVar2 = (*pcVar1)(0x1686);
    if (sVar2 == 0) goto LAB_00038e60;
  }
  DAT_000592c8 = -1;
LAB_00038ebc:
  return CONCAT44(unaff_EDX,DAT_000592c8);
}


/* ======== FUN_00038ec9 @ 00038ec9 ======== */

void FUN_00038ec9(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined *puVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  undefined3 uVar4;
  undefined8 uVar5;
  
  puVar2 = PTR_FUN_00058fa0;
  if ((DAT_000592b0 != 0) || (DAT_000592b4 != 0)) {
    if (PTR_FUN_00058fa0 == &DAT_0003907a) {
      PTR_FUN_00058fa0 = FUN_0003907f;
    }
    else if ((code *)PTR_FUN_00058fa0 == FUN_00038ec9) {
      PTR_FUN_00058fa0 = FUN_000350c1;
    }
    if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
      uVar5 = FUN_00038e35();
      if ((int)uVar5 == 1) {
        uVar4 = (undefined3)((uint)puVar2 >> 8);
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(0x201,DAT_000592b0,CONCAT31(uVar4,0x23),DAT_000592b4);
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(CONCAT22(extraout_var,0x205),DAT_000592bc,CONCAT31(uVar4,0x23),DAT_000592c0);
      }
      else {
        FUN_00034817(0x23,(int)((ulonglong)uVar5 >> 0x20),DAT_000592b0,DAT_000592b4);
      }
    }
    else {
      uVar3 = CONCAT22((short)DAT_000592b0,DAT_000592b4);
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22((short)((uint)DAT_000592b0 >> 0x10),0x2505),DAT_000592b4,uVar3,0x23,
                unaff_EDX,unaff_ECX,unaff_EBX);
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x2504,DAT_000592bc,uVar3,0x23);
    }
    DAT_000592b4 = 0;
    DAT_000592b0 = 0;
  }
  return;
}


/* ======== FUN_0003907f @ 0003907f ======== */

void FUN_0003907f(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined *puVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  undefined3 uVar4;
  undefined8 uVar5;
  
  puVar2 = PTR_FUN_00058fa0;
  if ((DAT_000592b6 != 0) || (DAT_000592ba != 0)) {
    if (PTR_FUN_00058fa0 == &DAT_0003907a) {
      PTR_FUN_00058fa0 = FUN_00038ec9;
    }
    else if ((code *)PTR_FUN_00058fa0 == FUN_0003907f) {
      PTR_FUN_00058fa0 = FUN_000350c1;
    }
    if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
      uVar5 = FUN_00038e35();
      if ((int)uVar5 == 1) {
        uVar4 = (undefined3)((uint)puVar2 >> 8);
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(0x201,DAT_000592b6,CONCAT31(uVar4,0x1b),DAT_000592ba);
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(CONCAT22(extraout_var,0x205),DAT_000592c2,CONCAT31(uVar4,0x1b),DAT_000592c6);
      }
      else {
        FUN_00034817(0x1b,(int)((ulonglong)uVar5 >> 0x20),DAT_000592b6,DAT_000592ba);
      }
    }
    else {
      uVar3 = CONCAT22((short)DAT_000592b6,DAT_000592ba);
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22((short)((uint)DAT_000592b6 >> 0x10),0x2505),DAT_000592ba,uVar3,0x1b,
                unaff_EDX,unaff_ECX,unaff_EBX);
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x2504,DAT_000592c2,uVar3,0x1b);
    }
    DAT_000592ba = 0;
    DAT_000592b6 = 0;
  }
  return;
}


/* ======== FUN_000390b7 @ 000390b7 ======== */

void FUN_000390b7(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 uVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  short in_ES;
  undefined2 in_CS;
  undefined8 uVar4;
  
  if ((DAT_000592b0 == 0) && (DAT_000592b4 == 0)) {
    uVar2 = (undefined2)((uint)unaff_ECX >> 0x10);
    if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
      uVar4 = FUN_00038e35();
      uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 == 1) {
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(0x200,uVar3,0x23);
        pcVar1 = (code *)swi(0x31);
        DAT_000592b0 = extraout_EDX_00;
        DAT_000592b4 = (short)unaff_ECX;
        (*pcVar1)(CONCAT22(extraout_var_01,0x204),extraout_EDX_00,0x23);
        pcVar1 = (code *)swi(0x31);
        DAT_000592bc = extraout_EDX_01;
        DAT_000592c0 = (short)unaff_ECX;
        (*pcVar1)(CONCAT22(extraout_var_02,0x205),&LAB_00038d28,0x23,CONCAT22(uVar2,in_CS));
      }
      else {
        uVar4 = FUN_000347e5(0x23,uVar3,&LAB_00038d28,unaff_ECX,unaff_EDX);
        DAT_000592b0 = (uint)uVar4;
        DAT_000592b4 = (short)((ulonglong)uVar4 >> 0x20);
        FUN_00034817(0x23,(int)((ulonglong)uVar4 >> 0x20),&LAB_00038d28,CONCAT22(uVar2,in_CS));
      }
    }
    else {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x2503,unaff_EDX,unaff_EBX,0x23,unaff_ECX,unaff_EBX);
      DAT_000592b4 = (short)unaff_EBX;
      unaff_EBX = unaff_EBX >> 0x10;
      pcVar1 = (code *)swi(0x21);
      DAT_000592b0 = unaff_EBX;
      (*pcVar1)(CONCAT22(extraout_var,0x2502),&LAB_00038d28,unaff_EBX,
                CONCAT31((int3)(CONCAT22(uVar2,DAT_000592b4) >> 8),0x23));
      pcVar1 = (code *)swi(0x21);
      DAT_000592bc = unaff_EBX;
      DAT_000592c0 = in_ES;
      (*pcVar1)(CONCAT22(extraout_var_00,0x2506),extraout_EDX,unaff_EBX,
                CONCAT31((int3)(CONCAT22(uVar2,in_CS) >> 8),0x23));
    }
    if ((code *)PTR_FUN_00058fa0 == FUN_000350c1) {
      PTR_FUN_00058fa0 = FUN_00038ec9;
      return;
    }
    if ((code *)PTR_FUN_00058fa0 == FUN_0003907f) {
      PTR_FUN_00058fa0 = &DAT_0003907a;
    }
  }
  return;
}


/* ======== FUN_000391d2 @ 000391d2 ======== */

void FUN_000391d2(undefined4 param_1,undefined4 unaff_EDX,uint unaff_EBX,undefined4 unaff_ECX)

{
  code *pcVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 uVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  short in_ES;
  undefined2 in_CS;
  undefined8 uVar4;
  
  if ((DAT_000592b6 == 0) && (DAT_000592ba == 0)) {
    uVar2 = (undefined2)((uint)unaff_ECX >> 0x10);
    if ((DAT_00058ffe < 2) || (8 < DAT_00058ffe)) {
      uVar4 = FUN_00038e35();
      uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 == 1) {
        pcVar1 = (code *)swi(0x31);
        (*pcVar1)(0x200,uVar3,0x1b);
        pcVar1 = (code *)swi(0x31);
        DAT_000592b6 = extraout_EDX_00;
        DAT_000592ba = (short)unaff_ECX;
        (*pcVar1)(CONCAT22(extraout_var_01,0x204),extraout_EDX_00,0x1b);
        pcVar1 = (code *)swi(0x31);
        DAT_000592c2 = extraout_EDX_01;
        DAT_000592c6 = (short)unaff_ECX;
        (*pcVar1)(CONCAT22(extraout_var_02,0x205),&LAB_00038dbd,0x1b,CONCAT22(uVar2,in_CS));
      }
      else {
        uVar4 = FUN_000347e5(0x1b,uVar3,&LAB_00038dbd,unaff_ECX,unaff_EDX);
        DAT_000592b6 = (uint)uVar4;
        DAT_000592ba = (short)((ulonglong)uVar4 >> 0x20);
        FUN_00034817(0x1b,(int)((ulonglong)uVar4 >> 0x20),&LAB_00038dbd,CONCAT22(uVar2,in_CS));
      }
    }
    else {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(0x2503,unaff_EDX,unaff_EBX,0x1b,unaff_ECX,unaff_EBX);
      DAT_000592ba = (short)unaff_EBX;
      unaff_EBX = unaff_EBX >> 0x10;
      pcVar1 = (code *)swi(0x21);
      DAT_000592b6 = unaff_EBX;
      (*pcVar1)(CONCAT22(extraout_var,0x2502),&LAB_00038dbd,unaff_EBX,
                CONCAT31((int3)(CONCAT22(uVar2,DAT_000592ba) >> 8),0x1b));
      pcVar1 = (code *)swi(0x21);
      DAT_000592c2 = unaff_EBX;
      DAT_000592c6 = in_ES;
      (*pcVar1)(CONCAT22(extraout_var_00,0x2506),extraout_EDX,unaff_EBX,
                CONCAT31((int3)(CONCAT22(uVar2,in_CS) >> 8),0x1b));
    }
    if ((code *)PTR_FUN_00058fa0 == FUN_000350c1) {
      PTR_FUN_00058fa0 = FUN_0003907f;
      return;
    }
    if ((code *)PTR_FUN_00058fa0 == FUN_00038ec9) {
      PTR_FUN_00058fa0 = &DAT_0003907a;
    }
  }
  return;
}


/* ======== FUN_00039312 @ 00039312 ======== */

char * FUN_00039312(uint param_1,char *unaff_EDX,uint unaff_EBX)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char local_37 [35];
  
  pcVar3 = local_37;
  do {
    uVar2 = param_1 / unaff_EBX;
    *pcVar3 = s_0123456789abcdefghijklmnopqrstuv_000392ed[param_1 % unaff_EBX];
    pcVar3 = pcVar3 + 1;
    param_1 = uVar2;
    pcVar4 = unaff_EDX;
  } while (uVar2 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return unaff_EDX;
}


/* ======== FUN_0003935c @ 0003935c ======== */

undefined * FUN_0003935c(int param_1,undefined *unaff_EDX,int unaff_EBX)

{
  if ((unaff_EBX == 10) && (param_1 < 0)) {
    param_1 = -param_1;
    *unaff_EDX = 0x2d;
  }
  FUN_00039312(param_1);
  return unaff_EDX;
}


/* ======== FUN_00039377 @ 00039377 ======== */

int FUN_00039377(int param_1)

{
  if ((0x60 < param_1) && (param_1 < 0x7b)) {
    param_1 = param_1 + -0x20;
  }
  return param_1;
}


/* ======== FUN_0003938f @ 0003938f ======== */

void FUN_0003938f(undefined4 param_1)

{
  code *pcVar1;
  
  pcVar1 = DAT_000592d4;
  if (((DAT_000592d4 != (code *)0x1) && (DAT_000592d4 != (code *)0x2)) &&
     (DAT_000592d4 != (code *)0x3)) {
    DAT_000592d4 = (code *)0x2;
    (*pcVar1)(2,param_1);
  }
  return;
}


/* ======== FUN_00039479 @ 00039479 ======== */

undefined8 FUN_00039479(int param_1,undefined4 unaff_EDX)

{
  code *pcVar1;
  undefined4 uVar2;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  
  pcVar1 = *(code **)(&DAT_000592cc + param_1 * 4);
  switch(param_1) {
  case 1:
    if (pcVar1 == (code *)0x2) {
      FUN_00039541();
      param_1 = extraout_EDX;
    }
  case 4:
    if (((pcVar1 != (code *)0x1) && (pcVar1 != (code *)0x2)) && (pcVar1 != (code *)0x3)) {
      *(undefined4 *)(&DAT_000592cc + param_1 * 4) = 2;
      FUN_00038ec9();
      param_1 = extraout_EDX_00;
LAB_000394e7:
      (*pcVar1)(param_1);
    }
    break;
  case 2:
    FUN_0003938f(0x8c);
    break;
  case 3:
  case 5:
  case 6:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    if (((pcVar1 == (code *)0x1) || (pcVar1 == (code *)0x2)) || (pcVar1 == (code *)0x3)) break;
    *(undefined4 *)(&DAT_000592cc + param_1 * 4) = 2;
    goto LAB_000394e7;
  case 7:
    if (((pcVar1 != (code *)0x1) && (pcVar1 != (code *)0x2)) && (pcVar1 != (code *)0x3)) {
      *(undefined4 *)(&DAT_000592cc + param_1 * 4) = 2;
      FUN_0003907f();
      param_1 = extraout_EDX_01;
      goto LAB_000394e7;
    }
    break;
  default:
    uVar2 = 0xffffffff;
    goto LAB_000394af;
  }
  uVar2 = 0;
LAB_000394af:
  return CONCAT44(unaff_EDX,uVar2);
}


/* ======== FUN_00039541 @ 00039541 ======== */

void FUN_00039541(undefined4 param_1,undefined4 unaff_EDX,undefined4 unaff_EBX,undefined4 unaff_ECX)

{
  FUN_00038cbd(s_ABNORMAL_TERMINATION_00065890,0xff,unaff_EBX,unaff_ECX,unaff_EDX);
  return;
}


/* ======== thunk_FUN_00039558 @ 00039553 ======== */

void thunk_FUN_00039558(void)

{
  if (PTR_FUN_00058fa4 != &DAT_000395e7) {
    PTR_FUN_00059009 = FUN_0003938f;
    FUN_0003958a();
    PTR_FUN_00058fa4 = &DAT_000395e7;
  }
  FUN_00039644();
  return;
}


/* ======== FUN_00039558 @ 00039558 ======== */

void FUN_00039558(void)

{
  if (PTR_FUN_00058fa4 != &DAT_000395e7) {
    PTR_FUN_00059009 = FUN_0003938f;
    FUN_0003958a();
    PTR_FUN_00058fa4 = &DAT_000395e7;
  }
  FUN_00039644();
  return;
}


/* ======== FUN_0003958a @ 0003958a ======== */

void FUN_0003958a(void)

{
  if ((DAT_00059304 == 0) && (DAT_0005952c != '\0')) {
    FUN_000395a0();
    return;
  }
  return;
}


/* ======== FUN_000395a0 @ 000395a0 ======== */

undefined8 FUN_000395a0(undefined4 param_1,undefined4 unaff_EDX)

{
  if (DAT_00058ffe == '\0') {
    FUN_000399da();
  }
  else if (DAT_00058ffe == '\x01') {
    FUN_00039994();
  }
  else if (DAT_00058ffe == '\t') {
    FUN_00039a32();
  }
  else {
    FUN_000398a4();
  }
  FUN_00039644();
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_000395f2 @ 000395f2 ======== */

undefined8 FUN_000395f2(undefined4 param_1,undefined4 unaff_EDX)

{
  if (DAT_00058ffe == '\0') {
    FUN_00039a18();
  }
  else if (DAT_00058ffe == '\x01') {
    FUN_000399c1();
  }
  else if (DAT_00058ffe == '\t') {
    FUN_00039a8a();
  }
  else {
    FUN_00039967();
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_00039644 @ 00039644 ======== */

void FUN_00039644(void)

{
  return;
}


/* ======== FUN_00039659 @ 00039659 ======== */

/* WARNING: This function may have set the stack pointer */

undefined8 FUN_00039659(undefined4 param_1,undefined4 unaff_EDX)

{
  undefined2 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  undefined2 in_FPUControlWord;
  undefined2 in_FPUStatusWord;
  undefined2 *in_FPUInstructionPointer;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 *local_34;
  
  out(0x20,0x20);
  out(0xa0,0x20);
  out(0xf0,0);
  local_40 = CONCAT22(local_40._2_2_,in_FPUControlWord);
  local_3c = CONCAT22(local_3c._2_2_,in_FPUStatusWord);
  uStack_44 = 0x39684;
  local_34 = in_FPUInstructionPointer;
  uVar2 = FUN_000341e4();
  uVar4 = CONCAT22((short)(~local_40 >> 0x10),CONCAT11(0xff,(char)~local_40)) & local_3c;
  do {
    do {
      uVar1 = *local_34;
      local_34 = (undefined2 *)((int)local_34 + 1);
      bVar5 = (byte)uVar1;
    } while (bVar5 < 0xd8);
  } while (0xdf < bVar5);
  cVar3 = '\0';
  if ((uVar4 & 0x20) == 0) {
    if ((uVar4 & 0x40) == 0) {
      if ((uVar4 & 1) == 0) {
        if ((uVar4 & 2) == 0) {
          if ((uVar4 & 8) == 0) {
            if ((uVar4 & 0x10) == 0) {
              if ((uVar4 & 4) != 0) {
                uStack_44 = 0x39700;
                FUN_0003984b(uVar2,uVar4,CONCAT11(bVar5,(char)((ushort)uVar1 >> 8)));
                cVar3 = -0x7d;
              }
            }
            else {
              cVar3 = -0x7b;
            }
          }
          else {
            uStack_44 = 0x396e9;
            FUN_000397f9();
            cVar3 = -0x7c;
          }
        }
        else {
          cVar3 = -0x7e;
        }
      }
      else {
        uStack_44 = 0x396d4;
        FUN_0003976c();
      }
    }
    else if ((uVar4 & 0x200) == 0) {
      cVar3 = -0x75;
    }
    else {
      cVar3 = -0x76;
    }
  }
  else {
    cVar3 = -0x7a;
  }
  if (cVar3 != '\0') {
    DAT_00059528 = &uStack_44;
    uStack_44 = DAT_00058fe0;
    DAT_00058fe0 = &DAT_00059326;
    DAT_00059522 = 0x39736;
    (*(code *)PTR_FUN_00059009)(cVar3);
    DAT_00058fe0 = (undefined *)uStack_44;
    DAT_00059526 = 0;
  }
  return CONCAT44(unaff_EDX,param_1);
}


/* ======== FUN_0003976c @ 0003976c ======== */

void FUN_0003976c(undefined4 param_1,undefined4 param_2,ushort unaff_BX)

{
  if (unaff_BX == 0xd9fa) {
    return;
  }
  if (unaff_BX == 0xd9f1) {
    return;
  }
  if ((((unaff_BX != 0xd9f8 && unaff_BX != 0xd9f5) && ((unaff_BX & 0x310) != 0x310)) &&
      ((unaff_BX & 0x110) == 0x110)) && (((byte)unaff_BX & 0xc0) != 0xc0)) {
    FUN_00039896();
  }
  return;
}


/* ======== FUN_000397f9 @ 000397f9 ======== */

void FUN_000397f9(undefined4 param_1,undefined4 param_2,ushort unaff_BX)

{
  if (unaff_BX != 0xd9fd) {
    if ((unaff_BX & 0x110) == 0x110) {
      FUN_0003984b();
      if (((byte)unaff_BX & 0xc0) != 0xc0) {
        FUN_00039896();
      }
    }
    else if (((byte)unaff_BX & 0xc0) == 0xc0) {
      FUN_00039871();
    }
    else {
      FUN_0003984b();
    }
  }
  return;
}


/* ======== FUN_0003984b @ 0003984b ======== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0003984b(undefined4 param_1,undefined4 param_2,uint unaff_EBX)

{
  int unaff_EBP;
  float10 in_ST0;
  float10 fVar1;
  
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + 0x14) =
       (ushort)(in_ST0 < fVar1) << 8 | (ushort)(NAN(in_ST0) || NAN(fVar1)) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  if ((unaff_EBX & 0x400) == 0) {
    fVar1 = (float10)_DAT_00059322;
  }
  else {
    fVar1 = (float10)_DAT_0005931a;
  }
  if ((*(ushort *)(unaff_EBP + 0x14) & 0x100) != 0) {
    fVar1 = -fVar1;
  }
  return fVar1;
}


/* ======== FUN_00039871 @ 00039871 ======== */

unkbyte10 FUN_00039871(undefined4 param_1,undefined4 param_2,uint unaff_EBX)

{
  bool bVar1;
  unkbyte10 Var2;
  byte bVar3;
  byte bVar4;
  unkbyte10 *unaff_ESI;
  unkbyte10 in_ST0;
  unkbyte10 Var5;
  unkbyte10 in_ST1;
  unkbyte10 Var6;
  unkbyte10 in_ST2;
  unkbyte10 Var7;
  unkbyte10 in_ST3;
  unkbyte10 Var8;
  unkbyte10 in_ST4;
  unkbyte10 Var9;
  unkbyte10 in_ST5;
  unkbyte10 Var10;
  unkbyte10 in_ST6;
  unkbyte10 Var11;
  unkbyte10 in_ST7;
  unkbyte10 Var12;
  
  if ((unaff_EBX & 0x400) == 0) {
    bVar3 = 0;
    bVar4 = bVar3;
  }
  else {
    bVar3 = (byte)unaff_EBX & 7;
    bVar4 = bVar3;
  }
  do {
    Var12 = in_ST7;
    Var10 = in_ST6;
    Var9 = in_ST5;
    Var8 = in_ST4;
    Var7 = in_ST3;
    Var6 = in_ST2;
    Var5 = in_ST1;
    in_ST7 = in_ST0;
    bVar1 = '\0' < (char)bVar4;
    in_ST0 = Var5;
    in_ST1 = Var6;
    in_ST2 = Var7;
    in_ST3 = Var8;
    in_ST4 = Var9;
    in_ST5 = Var10;
    in_ST6 = Var12;
    bVar4 = bVar4 - 1;
  } while (bVar1);
  Var2 = *unaff_ESI;
  do {
    Var11 = Var10;
    Var10 = Var9;
    Var9 = Var8;
    Var8 = Var7;
    Var7 = Var6;
    Var6 = Var5;
    Var5 = Var2;
    bVar1 = '\0' < (char)bVar3;
    Var2 = Var12;
    Var12 = Var11;
    bVar3 = bVar3 - 1;
  } while (bVar1);
  return Var5;
}


/* ======== FUN_00039896 @ 00039896 ======== */

void FUN_00039896(undefined4 param_1,undefined4 param_2,byte unaff_BL)

{
  double *unaff_EDI;
  float10 in_ST0;
  
  if ((unaff_BL & 4) == 0) {
    *(float *)unaff_EDI = (float)in_ST0;
  }
  else {
    *unaff_EDI = (double)in_ST0;
  }
  return;
}


/* ======== FUN_000398a4 @ 000398a4 ======== */

void FUN_000398a4(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined2 uVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined4 uVar4;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  char cVar6;
  int iVar7;
  code *pcVar8;
  undefined2 in_ES;
  
  uVar5 = (undefined2)((uint)param_1 >> 0x10);
  if (DAT_00059533 == ' ') {
    pcVar8 = FUN_00039659;
  }
  else {
    pcVar8 = (code *)0x39666;
  }
  if (DAT_00058ffe < 3) {
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)(CONCAT22(uVar5,0x2503),pcVar8,unaff_EBX,0x50);
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)(CONCAT22(extraout_var,0x2502));
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)(CONCAT22(extraout_var_00,0x2506));
    uVar5 = extraout_var_01;
  }
  pcVar8 = (code *)swi(0x21);
  uVar4 = (*pcVar8)(CONCAT22(uVar5,0x250c));
  cVar6 = (char)((uint)uVar4 >> 8) + DAT_00059531;
  pcVar8 = (code *)swi(0x21);
  (*pcVar8)(0x2502);
  pcVar8 = (code *)swi(0x21);
  DAT_00059304 = in_ES;
  DAT_00059306 = unaff_EBX;
  (*pcVar8)(CONCAT22(extraout_var_02,0x2503));
  DAT_0005930a = unaff_EBX;
  if (DAT_00058ffe < 3) {
    uVar4 = InterruptDescriptorTableRegister();
    iVar3 = CONCAT22(param_5,(short)((uint)uVar4 >> 0x10));
    uVar4 = *(undefined4 *)(iVar3 + 0x280);
    uVar1 = *(undefined4 *)(iVar3 + 0x284);
    iVar7 = (uint)(byte)(cVar6 - 8) * 8;
    *(undefined4 *)(iVar3 + iVar7) = uVar4;
    *(undefined4 *)(iVar3 + 4 + iVar7) = uVar1;
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)(CONCAT22((short)((uint)uVar4 >> 0x10),0x2507),param_7,param_8,
              CONCAT31((int3)((uint)iVar7 >> 8),0x50));
  }
  else {
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)(CONCAT22(extraout_var_03,0x2506));
  }
  return;
}


/* ======== FUN_00039967 @ 00039967 ======== */

void FUN_00039967(void)

{
  code *pcVar1;
  char extraout_AH;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x250c);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x2507,DAT_00059306,DAT_0005930a,extraout_AH + DAT_00059531 + -8);
  return;
}


/* ======== FUN_00039994 @ 00039994 ======== */

void FUN_00039994(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  code *pcVar1;
  undefined2 in_ES;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(DAT_00059530);
  pcVar1 = (code *)swi(0x21);
  DAT_00059304 = in_ES;
  DAT_00059306 = unaff_EBX;
  (*pcVar1)(DAT_00059530,0x39666);
  return;
}


/* ======== FUN_000399c1 @ 000399c1 ======== */

void FUN_000399c1(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(DAT_00059530,DAT_00059306);
  return;
}


/* ======== FUN_000399da @ 000399da ======== */

void FUN_000399da(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  code *pcVar1;
  code *pcVar2;
  undefined2 in_ES;
  undefined2 in_CS;
  
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)(DAT_00059532);
  if (DAT_00059533 == ' ') {
    pcVar2 = FUN_00039659;
  }
  else {
    pcVar2 = (code *)0x39666;
  }
  pcVar1 = (code *)swi(0x21);
  DAT_00059304 = in_ES;
  DAT_00059306 = unaff_EBX;
  (*pcVar1)(DAT_00059532,pcVar2,in_CS);
  return;
}


/* ======== FUN_00039a18 @ 00039a18 ======== */

void FUN_00039a18(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(DAT_00059532,DAT_00059306);
  return;
}


/* ======== FUN_00039a32 @ 00039a32 ======== */

void FUN_00039a32(undefined4 param_1,undefined4 unaff_EDX,undefined4 param_3,undefined2 unaff_CX)

{
  code *pcVar1;
  undefined2 extraout_DX;
  undefined4 extraout_EDX;
  code *pcVar2;
  undefined2 in_CS;
  
  pcVar2 = (code *)swi(0x31);
  (*pcVar2)(0x204,unaff_EDX,DAT_00059530);
  pcVar2 = (code *)swi(0x31);
  DAT_00059304 = unaff_CX;
  DAT_00059306 = extraout_EDX;
  (*pcVar2)(0x200,extraout_EDX,DAT_00059530);
  DAT_0005930a = CONCAT22(unaff_CX,extraout_DX);
  if (DAT_00059533 == ' ') {
    pcVar2 = FUN_00039659;
  }
  else {
    pcVar2 = (code *)0x39666;
  }
  pcVar1 = (code *)swi(0x31);
  (*pcVar1)(0x205,pcVar2,DAT_00059530,CONCAT22(unaff_CX,in_CS));
  return;
}


/* ======== FUN_00039a8a @ 00039a8a ======== */

void FUN_00039a8a(void)

{
  return;
}


/* ======== FUN_00039a94 @ 00039a94 ======== */

void FUN_00039a94(void)

{
  if (DAT_0005952d != '\0') {
    PTR_FUN_00059538 = &LAB_00039a8b;
    PTR_FUN_0005953c = &LAB_00039a90;
  }
  FUN_00039b1a(DAT_00059540);
  return;
}


/* ======== FUN_00039acf @ 00039acf ======== */

void FUN_00039acf(void)

{
  char cVar1;
  
  if (DAT_0005952c == '\0') {
    DAT_0005952d = DAT_0005952c;
    cVar1 = FUN_00039a94();
    if (DAT_00058ffc == '\0') {
      DAT_0005952c = cVar1;
      DAT_0005952d = cVar1;
    }
  }
  return;
}


/* ======== FUN_00039b19 @ 00039b19 ======== */

void FUN_00039b19(void)

{
  return;
}


/* ======== FUN_00039b1a @ 00039b1a ======== */

undefined2 FUN_00039b1a(void)

{
  undefined2 *puVar1;
  undefined2 in_SS;
  undefined local_2 [2];
  
  LOCK();
  UNLOCK();
  puVar1 = (undefined2 *)segment(in_SS,(short)local_2);
  return *puVar1;
}

