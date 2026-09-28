import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import javax.microedition.lcdui.Image;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;

// $VF: renamed from: cx
public final class class_27 {
   // $VF: renamed from: a javax.microedition.rms.RecordStore
   public static RecordStore field_303 = null;

   // $VF: renamed from: a () cg[]
   public static final class_41[] method_272() {
      class_41[] var0 = new class_41[4];

      for (int var1 = 0; var1 < var0.length; var1++) {
         var0[var1] = method_276(var1);
      }

      return var0;
   }

   // $VF: renamed from: a (int) cg
   public static final class_41 method_273(int var0) {
      new class_41();
      Object var1 = null;
      return method_276(var0);
   }

   // $VF: renamed from: a () void
   public static final void method_274() {
      try {
         field_303 = RecordStore.openRecordStore("Deep_Options", false);
         field_303.closeRecordStore();
      } catch (RecordStoreException var5) {
      }

      try {
         field_303 = RecordStore.openRecordStore("Deep_Options", false);
         byte[] var0 = field_303.getRecord(field_303.getNextRecordID() - 1);
         ByteArrayInputStream var1 = new ByteArrayInputStream(var0);
         DataInputStream var2;
         class_84.field_1080 = (var2 = new DataInputStream(var1)).readBoolean();
         class_84.field_1081 = var2.readBoolean();
         class_84.field_1082 = var2.readBoolean();
         class_84.field_1083 = var2.readInt();
         var2.close();
         var1.close();
         field_303.closeRecordStore();
         field_303 = null;
      } catch (RecordStoreException var3) {
      } catch (IOException var4) {
      }
   }

   // $VF: renamed from: b () void
   public static final void method_275() {
      try {
         RecordStore.deleteRecordStore("Deep_Options");
      } catch (RecordStoreException var6) {
      }

      try {
         field_303 = RecordStore.openRecordStore("Deep_Options", true);
      } catch (RecordStoreException var5) {
      }

      ByteArrayOutputStream var0 = null;
      DataOutputStream var1 = null;

      try {
         var0 = new ByteArrayOutputStream();
         (var1 = new DataOutputStream(var0)).writeBoolean(class_84.field_1080);
         var1.writeBoolean(class_84.field_1081);
         var1.writeBoolean(class_84.field_1082);
         var1.writeInt(class_84.field_1083);
         var1.close();
         var0.close();
         field_303.addRecord(var0.toByteArray(), 0, var0.toByteArray().length);
         field_303.closeRecordStore();
         field_303 = null;
      } catch (IOException var3) {
      } catch (RecordStoreException var4) {
         var4.printStackTrace();
      }
   }

   // $VF: renamed from: b (int) cg
   public static final class_41 method_276(int var0) {
      class_41 var1 = null;

      try {
         field_303 = RecordStore.openRecordStore("Deep_" + var0, false);
         field_303.closeRecordStore();
      } catch (RecordStoreException var22) {
      }

      try {
         field_303 = RecordStore.openRecordStore("Deep_" + var0, false);
         byte[] var2 = field_303.getRecord(field_303.getNextRecordID() - 1);
         ByteArrayInputStream var3 = new ByteArrayInputStream(var2);
         DataInputStream var4 = new DataInputStream(var3);
         var1 = new class_41();

         for (int var5 = 0; var5 < var1.field_394.length; var5++) {
            var1.field_394[var5] = var4.readBoolean();
         }

         var1.field_395 = var4.readInt();
         var1.field_396 = var4.readInt();
         var1.field_397 = var4.readLong();
         var1.field_398 = var4.readInt();
         var1.field_399 = var4.readInt();
         var1.field_410 = var4.readInt();
         var1.field_411 = var4.readInt();
         var1.field_400 = var4.readInt();
         var1.field_401 = var4.readInt();
         var1.field_402 = var4.readInt();
         var1.field_403 = var4.readInt();
         var1.field_409 = var4.readInt();
         var1.field_414 = var4.readInt();
         var1.field_415 = method_279(var4);
         var1.field_416 = method_279(var4);
         var1.field_417 = var4.readUTF();
         var1.field_405 = var4.readInt();
         var1.field_406 = var4.readInt();
         var1.field_407 = var4.readInt();
         var1.field_408 = var4.readInt();
         var1.field_404 = var4.readInt();
         var1.field_413 = var4.readInt();
         var1.field_412 = var4.readInt();
         var1.field_422 = new boolean[class_21.method_195().length];

         for (int var24 = 0; var24 < var1.field_422.length; var24++) {
            var1.field_422[var24] = var4.readBoolean();
         }

         var1.field_426 = new int[class_14.field_135.length];

         for (int var25 = 0; var25 < var1.field_426.length; var25++) {
            var1.field_426[var25] = var4.readInt();
         }

         if (var4.readBoolean()) {
            byte[] var27 = new byte[class_119.field_1457];

            for (int var29 = 0; var29 < class_119.field_1457; var29++) {
               var27[var29] = var4.readByte();
            }

            var1.field_418 = var27;
         } else {
            int[] var26 = new int[var4.readInt()];

            for (int var6 = 0; var6 < var26.length; var6++) {
               var26[var6] = var4.readInt();
            }

            var1.field_419 = Image.createRGBImage(var26, class_119.field_1458, class_119.field_1459, false);
         }

         boolean[] var28 = new boolean[200];

         for (int var30 = 0; var30 < var28.length; var30++) {
            var28[var30] = var4.readBoolean();
         }

         var1.field_420 = var28;
         boolean[] var31 = new boolean[class_21.method_168().length];

         for (int var7 = 0; var7 < var31.length; var7++) {
            var31[var7] = var4.readBoolean();
         }

         var1.field_421 = var31;
         var1.field_450 = class_90.method_783()[var4.readInt()].method_627();
         var1.field_450.field_884 = var4.readBoolean();
         var1.field_450.method_628();
         int var32 = var4.readInt();
         Object var8 = null;
         if (var32 > 0) {
            var8 = new class_19[var32];

            for (int var9 = 0; var9 < var32; var9++) {
               int var10;
               if ((var10 = var4.readInt()) == -1) {
                  ((Object[])var8)[var9] = null;
               } else {
                  ((Object[])var8)[var9] = class_90.method_781()[var10].method_119(1, class_90.method_781()[var10].field_170);
                  ((class_19)((Object[])var8)[var9]).method_124();
               }
            }

            var1.field_450.method_615((class_19[])var8);
         }

         int var35 = var4.readInt();
         Object var37 = null;
         if (var35 > 0) {
            var37 = new class_120[var35];

            for (int var11 = 0; var11 < var35; var11++) {
               int var12 = var4.readInt();
               int var13 = var4.readInt();
               int var14 = var4.readInt();
               ((Object[])var37)[var11] = class_90.method_785()[var12].method_930(var13, class_90.method_785()[var12].field_1487);
               ((class_120)((Object[])var37)[var11]).field_1484 = var14;
            }

            var1.field_450.method_608((class_120[])var37);
         }

         class_86[] var39 = new class_86[3];

         for (int var40 = 0; var40 < var39.length + 1; var40++) {
            class_86 var42 = null;
            short var45;
            if ((var45 = var4.readShort()) == -1) {
               var42 = null;
            } else {
               var42 = class_38.method_354(var45);
               var32 = var4.readInt();
               Object var15 = null;
               if (var32 > 0) {
                  var15 = new class_19[var32];

                  for (int var16 = 0; var16 < var32; var16++) {
                     int var17 = var4.readInt();
                     int var18 = var4.readInt();
                     boolean var19 = var4.readBoolean();
                     ((Object[])var15)[var16] = class_90.method_781()[var17].method_119(var18, class_90.method_781()[var17].field_170);
                     if (var19) {
                        ((class_19)((Object[])var15)[var16]).method_124();
                        ((class_19)((Object[])var15)[var16]).field_176 = true;
                     }
                  }

                  var42.field_1141 = (class_19[])var15;
               }

               var35 = var4.readInt();
               Object var47 = null;
               if (var35 > 0) {
                  var47 = new class_120[var35];

                  for (int var49 = 0; var49 < var35; var49++) {
                     int var51 = var4.readInt();
                     int var54 = var4.readInt();
                     int var20 = var4.readInt();
                     ((Object[])var47)[var49] = class_90.method_785()[var51].method_930(var54, class_90.method_785()[var51].field_1487);
                     ((class_120)((Object[])var47)[var49]).field_1484 = var20;
                  }

                  var42.field_1142 = (class_120[])var47;
               }

               int var50 = var4.readInt();
               Object var52 = null;
               if (var50 > 0) {
                  var52 = new class_68[var50];

                  for (int var55 = 0; var55 < var50; var55++) {
                     int var57 = var4.readInt();
                     ((Object[])var52)[var55] = class_90.method_783()[var57].method_627();
                     ((class_68)((Object[])var52)[var55]).field_884 = var4.readBoolean();
                  }

                  var42.field_1143 = (class_68[])var52;
               }

               int var56 = var4.readInt();
               Object var58 = null;
               if (var56 > 0) {
                  var58 = new class_87[var56];

                  for (int var21 = 0; var21 < var56; var21++) {
                     ((Object[])var58)[var21] = method_279(var4);
                  }

                  var42.field_1144 = (class_87[])var58;
               }
            }

            if (var40 == var39.length) {
               var1.field_451 = var42;
            } else {
               var39[var40] = var42;
            }
         }

         var1.field_423 = var39;
         int var41;
         if ((var41 = var4.readInt()) > 0) {
            var1.field_424 = new int[var41];

            for (int var44 = 0; var44 < var41; var44++) {
               var1.field_424[var44] = var4.readInt();
            }
         }

         var1.field_425 = var4.readInt();
         var1.field_427 = var4.readBoolean();
         var1.field_428 = var4.readBoolean();
         var1.field_429 = var4.readBoolean();
         var1.field_430 = var4.readBoolean();
         var1.field_431 = var4.readBoolean();
         var1.field_432 = var4.readBoolean();
         var1.field_433 = var4.readBoolean();
         var1.field_434 = var4.readBoolean();
         var1.field_435 = var4.readBoolean();
         var1.field_436 = var4.readBoolean();
         var1.field_437 = var4.readBoolean();
         var1.field_438 = var4.readBoolean();
         var1.field_439 = var4.readBoolean();
         var1.field_440 = var4.readBoolean();
         var1.field_441 = var4.readBoolean();
         var1.field_442 = var4.readBoolean();
         var1.field_443 = var4.readBoolean();
         var1.field_444 = var4.readBoolean();
         var1.field_445 = var4.readBoolean();
         var1.field_446 = var4.readBoolean();
         var1.field_447 = var4.readBoolean();
         var1.field_448 = var4.readBoolean();
         var1.field_449 = var4.readBoolean();
         var4.close();
         var3.close();
         field_303.closeRecordStore();
         field_303 = null;
      } catch (Exception var23) {
      }

      return var1;
   }

   // $VF: renamed from: a (int) void
   public static final void method_277(int var0) {
      try {
         RecordStore.deleteRecordStore("Deep_" + var0);
      } catch (RecordStoreException var16) {
      }

      try {
         field_303 = RecordStore.openRecordStore("Deep_" + var0, true);
      } catch (RecordStoreException var15) {
      }

      ByteArrayOutputStream var1 = null;
      DataOutputStream var2 = null;

      try {
         var1 = new ByteArrayOutputStream();
         var2 = new DataOutputStream(var1);
         boolean[] var3 = class_38.method_356();

         for (int var4 = 0; var4 < var3.length; var4++) {
            var2.writeBoolean(var3[var4]);
         }

         var2.writeInt(class_21.method_182());
         var2.writeInt(class_21.method_200());
         var2.writeLong(class_21.method_212());
         var2.writeInt(class_21.method_202());
         var2.writeInt(class_21.method_208());
         var2.writeInt(class_21.method_170());
         var2.writeInt(class_21.method_172());
         var2.writeInt(class_21.method_209());
         var2.writeInt(class_21.method_210());
         var2.writeInt(class_21.method_201());
         var2.writeInt(class_21.method_191());
         var2.writeInt(class_21.method_177());
         var2.writeInt(class_21.method_143());
         method_278(var2, class_21.method_135());
         method_278(var2, class_21.method_137());
         var2.writeUTF(class_21.method_213());
         var2.writeInt(class_21.method_156());
         var2.writeInt(class_21.method_151());
         var2.writeInt(class_21.method_154());
         var2.writeInt(class_21.method_158());
         var2.writeInt(class_21.method_205());
         var2.writeInt(class_21.method_160());
         var2.writeInt(class_21.method_159());
         boolean[] var21 = class_21.method_195();

         for (int var5 = 0; var5 < var21.length; var5++) {
            var2.writeBoolean(var21[var5]);
         }

         int[] var22 = class_14.method_71();

         for (int var6 = 0; var6 < var22.length; var6++) {
            var2.writeInt(var22[var6]);
         }

         var2.writeBoolean(class_21.method_215() != null);
         if (class_21.method_215() != null) {
            for (int var23 = 0; var23 < class_119.field_1457; var23++) {
               var2.writeByte(class_21.method_215()[var23]);
            }
         } else {
            int[] var24 = new int[class_21.method_217().getWidth() * class_21.method_217().getHeight()];
            class_21.method_217().getRGB(var24, 0, class_21.method_217().getWidth(), 0, 0, class_21.method_217().getWidth(), class_21.method_217().getHeight());
            var2.writeInt(var24.length);

            for (int var7 = 0; var7 < var24.length; var7++) {
               var2.writeInt(var24[var7]);
            }
         }

         boolean[] var25 = class_21.method_175();

         for (int var26 = 0; var26 < var25.length; var26++) {
            var2.writeBoolean(var25[var26]);
         }

         boolean[] var27 = class_21.method_168();

         for (int var8 = 0; var8 < var27.length; var8++) {
            var2.writeBoolean(var27[var8]);
         }

         var2.writeInt(class_21.method_178().field_863);
         var2.writeBoolean(class_21.method_178().field_884);
         class_19[] var28;
         if ((var28 = class_21.method_178().field_885) == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(var28.length);

            for (int var9 = 0; var9 < var28.length; var9++) {
               if (var28[var9] != null) {
                  var2.writeInt(var28[var9].field_166);
               } else {
                  var2.writeInt(-1);
               }
            }
         }

         class_120[] var30;
         if ((var30 = class_21.method_178().field_886) == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(var30.length);

            for (int var10 = 0; var10 < var30.length; var10++) {
               var2.writeInt(var30[var10].field_1480);
               var2.writeInt(var30[var10].field_1490);
               var2.writeInt(var30[var10].field_1484);
            }
         }

         for (int var32 = 0; var32 < class_21.method_127().length + 1; var32++) {
            class_86 var11 = null;
            if (var32 == class_21.method_127().length) {
               var11 = class_21.method_180();
            } else {
               var11 = class_21.method_127()[var32];
            }

            if (var11 == null) {
               var2.writeShort(-1);
            } else {
               var2.writeShort(var11.field_1134);
               var28 = var11.field_1141;
               if (var11.field_1141 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var28.length);

                  for (int var12 = 0; var12 < var28.length; var12++) {
                     var2.writeInt(var28[var12].field_166);
                     var2.writeInt(var28[var12].field_175);
                     var2.writeBoolean(var28[var12].field_176);
                  }
               }

               var30 = var11.field_1142;
               if (var11.field_1142 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var30.length);

                  for (int var35 = 0; var35 < var30.length; var35++) {
                     var2.writeInt(var30[var35].field_1480);
                     var2.writeInt(var30[var35].field_1490);
                     var2.writeInt(var30[var35].field_1484);
                  }
               }

               class_68[] var36 = var11.field_1143;
               if (var11.field_1143 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var36.length);

                  for (int var13 = 0; var13 < var36.length; var13++) {
                     var2.writeInt(var36[var13].field_863);
                     var2.writeBoolean(var36[var13].field_884);
                  }
               }

               class_87[] var37 = var11.field_1144;
               if (var11.field_1144 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var37.length);

                  for (int var14 = 0; var14 < var37.length; var14++) {
                     method_278(var2, var37[var14]);
                  }
               }
            }
         }

         if (class_84.field_1108 == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(class_84.field_1108.length);

            for (int var33 = 0; var33 < class_84.field_1108.length; var33++) {
               var2.writeInt(class_84.field_1108[var33]);
            }
         }

         var2.writeInt(class_84.field_1109);
         var2.writeBoolean(class_84.field_1085);
         var2.writeBoolean(class_84.field_1086);
         var2.writeBoolean(class_84.field_1087);
         var2.writeBoolean(class_84.field_1088);
         var2.writeBoolean(class_84.field_1089);
         var2.writeBoolean(class_84.field_1090);
         var2.writeBoolean(class_84.field_1091);
         var2.writeBoolean(class_84.field_1092);
         var2.writeBoolean(class_84.field_1093);
         var2.writeBoolean(class_84.field_1094);
         var2.writeBoolean(class_84.field_1095);
         var2.writeBoolean(class_84.field_1096);
         var2.writeBoolean(class_84.field_1097);
         var2.writeBoolean(class_84.field_1098);
         var2.writeBoolean(class_84.field_1099);
         var2.writeBoolean(class_84.field_1100);
         var2.writeBoolean(class_84.field_1101);
         var2.writeBoolean(class_84.field_1102);
         var2.writeBoolean(class_84.field_1104);
         var2.writeBoolean(class_84.field_1103);
         var2.writeBoolean(class_84.field_1105);
         var2.writeBoolean(class_84.field_1106);
         var2.writeBoolean(class_84.field_1107);
         var2.close();
         var1.close();
         field_303.addRecord(var1.toByteArray(), 0, var1.toByteArray().length);
         field_303.closeRecordStore();
         field_303 = null;
      } catch (IOException var17) {
      } catch (RecordStoreException var18) {
         var18.printStackTrace();
      }
   }

   // $VF: renamed from: a (java.io.DataOutputStream, am) void
   private static void method_278(DataOutputStream var0, class_87 var1) throws IOException {
      var0.writeInt(var1.field_1146);
      if (!var1.method_754()) {
         var0.writeBoolean(var1.field_1161);
         if (!var1.field_1161) {
            var0.writeUTF(var1.field_1147);

            for (int var2 = 0; var2 < class_119.field_1457; var2++) {
               var0.writeByte(var1.field_1148[var2]);
            }
         }

         var0.writeInt(var1.field_1149);
         var0.writeInt(var1.field_1151);
         var0.writeInt(var1.field_1150);
         var0.writeInt(var1.field_1152);
         var0.writeInt(var1.field_1154);
         var0.writeInt(var1.field_1156);
         var0.writeInt(var1.field_1155);
         var0.writeInt(var1.field_1167);
         var0.writeInt(var1.field_1166);
         var0.writeInt(var1.field_1168);
         var0.writeInt(var1.field_1165);
         var0.writeInt(var1.field_1164);
         var0.writeInt(var1.field_1170);
         var0.writeBoolean(var1.field_1171);
      }
   }

   // $VF: renamed from: a (java.io.DataInputStream) am
   private static class_87 method_279(DataInputStream var0) throws IOException {
      int var1;
      if ((var1 = var0.readInt()) == -1) {
         return class_87.field_1145;
      } else {
         boolean var2 = var0.readBoolean();
         String var3 = "";
         byte[] var4 = null;
         if (!var2) {
            var3 = var0.readUTF();
            var4 = new byte[class_119.field_1457];

            for (int var5 = 0; var5 < class_119.field_1457; var5++) {
               var4[var5] = var0.readByte();
            }
         }

         int var20 = var0.readInt();
         int var6 = var0.readInt();
         int var7 = var0.readInt();
         int var8 = var0.readInt();
         int var9 = var0.readInt();
         int var10 = var0.readInt();
         int var11 = var0.readInt();
         int var12 = var0.readInt();
         int var13 = var0.readInt();
         int var14 = var0.readInt();
         int var15 = var0.readInt();
         int var16 = var0.readInt();
         int var17 = var0.readInt();
         boolean var18 = var0.readBoolean();
         class_87 var19 = null;
         if (var2) {
            var19 = new class_87(var1, var7, var8);
         } else {
            var19 = new class_87(var1, var3, var4, var20, var7, var8, var9, var11);
         }

         var19.field_1151 = var6;
         var19.method_755(var13, var12, var14);
         var19.method_756(var16, var15);
         var19.field_1170 = var17;
         var19.field_1171 = var18;
         var19.method_761(var10);
         return var19;
      }
   }
}
