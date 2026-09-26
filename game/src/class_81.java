import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import javax.microedition.lcdui.Image;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;

// $VF: renamed from: cw
public final class class_81 {
   // $VF: renamed from: a javax.microedition.rms.RecordStore
   public static RecordStore field_1093 = null;

   // $VF: renamed from: a () cg[]
   public static final class_45[] method_728() {
      class_45[] var0 = new class_45[4];

      for (int var1 = 0; var1 < var0.length; var1++) {
         var0[var1] = method_732(var1);
      }

      return var0;
   }

   // $VF: renamed from: a (int) cg
   public static final class_45 method_729(int var0) {
      new class_45();
      Object var1 = null;
      return method_732(var0);
   }

   // $VF: renamed from: a () void
   public static final void method_730() {
      try {
         field_1093 = RecordStore.openRecordStore("Deep_Options", false);
         field_1093.closeRecordStore();
      } catch (RecordStoreException var5) {
      }

      try {
         field_1093 = RecordStore.openRecordStore("Deep_Options", false);
         byte[] var0 = field_1093.getRecord(field_1093.getNextRecordID() - 1);
         ByteArrayInputStream var1 = new ByteArrayInputStream(var0);
         DataInputStream var2;
         class_41.field_497 = (var2 = new DataInputStream(var1)).readBoolean();
         class_41.field_498 = var2.readBoolean();
         class_41.field_499 = var2.readBoolean();
         class_41.field_500 = var2.readInt();
         var2.close();
         var1.close();
         field_1093.closeRecordStore();
         field_1093 = null;
      } catch (RecordStoreException var3) {
      } catch (IOException var4) {
      }
   }

   // $VF: renamed from: b () void
   public static final void method_731() {
      try {
         RecordStore.deleteRecordStore("Deep_Options");
      } catch (RecordStoreException var6) {
      }

      try {
         field_1093 = RecordStore.openRecordStore("Deep_Options", true);
      } catch (RecordStoreException var5) {
      }

      ByteArrayOutputStream var0 = null;
      DataOutputStream var1 = null;

      try {
         var0 = new ByteArrayOutputStream();
         (var1 = new DataOutputStream(var0)).writeBoolean(class_41.field_497);
         var1.writeBoolean(class_41.field_498);
         var1.writeBoolean(class_41.field_499);
         var1.writeInt(class_41.field_500);
         var1.close();
         var0.close();
         field_1093.addRecord(var0.toByteArray(), 0, var0.toByteArray().length);
         field_1093.closeRecordStore();
         field_1093 = null;
      } catch (IOException var3) {
      } catch (RecordStoreException var4) {
         var4.printStackTrace();
      }
   }

   // $VF: renamed from: b (int) cg
   public static final class_45 method_732(int var0) {
      class_45 var1 = null;

      try {
         field_1093 = RecordStore.openRecordStore("Deep_" + var0, false);
         field_1093.closeRecordStore();
      } catch (RecordStoreException var22) {
      }

      try {
         field_1093 = RecordStore.openRecordStore("Deep_" + var0, false);
         byte[] var2 = field_1093.getRecord(field_1093.getNextRecordID() - 1);
         ByteArrayInputStream var3 = new ByteArrayInputStream(var2);
         DataInputStream var4 = new DataInputStream(var3);
         var1 = new class_45();

         for (int var5 = 0; var5 < var1.field_568.length; var5++) {
            var1.field_568[var5] = var4.readBoolean();
         }

         var1.field_569 = var4.readInt();
         var1.field_570 = var4.readInt();
         var1.field_571 = var4.readLong();
         var1.field_572 = var4.readInt();
         var1.field_573 = var4.readInt();
         var1.field_584 = var4.readInt();
         var1.field_585 = var4.readInt();
         var1.field_574 = var4.readInt();
         var1.field_575 = var4.readInt();
         var1.field_576 = var4.readInt();
         var1.field_577 = var4.readInt();
         var1.field_583 = var4.readInt();
         var1.field_588 = var4.readInt();
         var1.field_589 = method_735(var4);
         var1.field_590 = method_735(var4);
         var1.field_591 = var4.readUTF();
         var1.field_579 = var4.readInt();
         var1.field_580 = var4.readInt();
         var1.field_581 = var4.readInt();
         var1.field_582 = var4.readInt();
         var1.field_578 = var4.readInt();
         var1.field_587 = var4.readInt();
         var1.field_586 = var4.readInt();
         var1.field_596 = new boolean[class_3.method_125().length];

         for (int var24 = 0; var24 < var1.field_596.length; var24++) {
            var1.field_596[var24] = var4.readBoolean();
         }

         var1.field_600 = new int[class_58.field_805.length];

         for (int var25 = 0; var25 < var1.field_600.length; var25++) {
            var1.field_600[var25] = var4.readInt();
         }

         if (var4.readBoolean()) {
            byte[] var27 = new byte[class_119.field_1503];

            for (int var29 = 0; var29 < class_119.field_1503; var29++) {
               var27[var29] = var4.readByte();
            }

            var1.field_592 = var27;
         } else {
            int[] var26 = new int[var4.readInt()];

            for (int var6 = 0; var6 < var26.length; var6++) {
               var26[var6] = var4.readInt();
            }

            var1.field_593 = Image.createRGBImage(var26, class_119.field_1504, class_119.field_1505, false);
         }

         boolean[] var28 = new boolean[200];

         for (int var30 = 0; var30 < var28.length; var30++) {
            var28[var30] = var4.readBoolean();
         }

         var1.field_594 = var28;
         boolean[] var31 = new boolean[class_3.method_98().length];

         for (int var7 = 0; var7 < var31.length; var7++) {
            var31[var7] = var4.readBoolean();
         }

         var1.field_595 = var31;
         var1.field_624 = class_24.method_313()[var4.readInt()].method_387();
         var1.field_624.field_443 = var4.readBoolean();
         var1.field_624.method_388();
         int var32 = var4.readInt();
         Object var8 = null;
         if (var32 > 0) {
            var8 = new class_51[var32];

            for (int var9 = 0; var9 < var32; var9++) {
               int var10;
               if ((var10 = var4.readInt()) == -1) {
                  ((Object[])var8)[var9] = null;
               } else {
                  ((Object[])var8)[var9] = class_24.method_311()[var10].method_504(1, class_24.method_311()[var10].field_715);
                  ((class_51)((Object[])var8)[var9]).method_509();
               }
            }

            var1.field_624.method_375((class_51[])var8);
         }

         int var35 = var4.readInt();
         Object var37 = null;
         if (var35 > 0) {
            var37 = new class_46[var35];

            for (int var11 = 0; var11 < var35; var11++) {
               int var12 = var4.readInt();
               int var13 = var4.readInt();
               int var14 = var4.readInt();
               ((Object[])var37)[var11] = class_24.method_315()[var12].method_448(var13, class_24.method_315()[var12].field_633);
               ((class_46)((Object[])var37)[var11]).field_630 = var14;
            }

            var1.field_624.method_368((class_46[])var37);
         }

         class_60[] var39 = new class_60[3];

         for (int var40 = 0; var40 < var39.length + 1; var40++) {
            class_60 var42 = null;
            short var45;
            if ((var45 = var4.readShort()) == -1) {
               var42 = null;
            } else {
               var42 = class_44.method_431(var45);
               var32 = var4.readInt();
               Object var15 = null;
               if (var32 > 0) {
                  var15 = new class_51[var32];

                  for (int var16 = 0; var16 < var32; var16++) {
                     int var17 = var4.readInt();
                     int var18 = var4.readInt();
                     boolean var19 = var4.readBoolean();
                     ((Object[])var15)[var16] = class_24.method_311()[var17].method_504(var18, class_24.method_311()[var17].field_715);
                     if (var19) {
                        ((class_51)((Object[])var15)[var16]).method_509();
                        ((class_51)((Object[])var15)[var16]).field_721 = true;
                     }
                  }

                  var42.field_835 = (class_51[])var15;
               }

               var35 = var4.readInt();
               Object var47 = null;
               if (var35 > 0) {
                  var47 = new class_46[var35];

                  for (int var49 = 0; var49 < var35; var49++) {
                     int var51 = var4.readInt();
                     int var54 = var4.readInt();
                     int var20 = var4.readInt();
                     ((Object[])var47)[var49] = class_24.method_315()[var51].method_448(var54, class_24.method_315()[var51].field_633);
                     ((class_46)((Object[])var47)[var49]).field_630 = var20;
                  }

                  var42.field_836 = (class_46[])var47;
               }

               int var50 = var4.readInt();
               Object var52 = null;
               if (var50 > 0) {
                  var52 = new class_32[var50];

                  for (int var55 = 0; var55 < var50; var55++) {
                     int var57 = var4.readInt();
                     ((Object[])var52)[var55] = class_24.method_313()[var57].method_387();
                     ((class_32)((Object[])var52)[var55]).field_443 = var4.readBoolean();
                  }

                  var42.field_837 = (class_32[])var52;
               }

               int var56 = var4.readInt();
               Object var58 = null;
               if (var56 > 0) {
                  var58 = new class_95[var56];

                  for (int var21 = 0; var21 < var56; var21++) {
                     ((Object[])var58)[var21] = method_735(var4);
                  }

                  var42.field_838 = (class_95[])var58;
               }
            }

            if (var40 == var39.length) {
               var1.field_625 = var42;
            } else {
               var39[var40] = var42;
            }
         }

         var1.field_597 = var39;
         int var41;
         if ((var41 = var4.readInt()) > 0) {
            var1.field_598 = new int[var41];

            for (int var44 = 0; var44 < var41; var44++) {
               var1.field_598[var44] = var4.readInt();
            }
         }

         var1.field_599 = var4.readInt();
         var1.field_601 = var4.readBoolean();
         var1.field_602 = var4.readBoolean();
         var1.field_603 = var4.readBoolean();
         var1.field_604 = var4.readBoolean();
         var1.field_605 = var4.readBoolean();
         var1.field_606 = var4.readBoolean();
         var1.field_607 = var4.readBoolean();
         var1.field_608 = var4.readBoolean();
         var1.field_609 = var4.readBoolean();
         var1.field_610 = var4.readBoolean();
         var1.field_611 = var4.readBoolean();
         var1.field_612 = var4.readBoolean();
         var1.field_613 = var4.readBoolean();
         var1.field_614 = var4.readBoolean();
         var1.field_615 = var4.readBoolean();
         var1.field_616 = var4.readBoolean();
         var1.field_617 = var4.readBoolean();
         var1.field_618 = var4.readBoolean();
         var1.field_619 = var4.readBoolean();
         var1.field_620 = var4.readBoolean();
         var1.field_621 = var4.readBoolean();
         var1.field_622 = var4.readBoolean();
         var1.field_623 = var4.readBoolean();
         var4.close();
         var3.close();
         field_1093.closeRecordStore();
         field_1093 = null;
      } catch (javax.microedition.rms.RecordStoreNotFoundException var24) {
         // empty slot
      } catch (Exception var23) {
         // Deep3D-PC: a failed read used to show the slot as BLANK silently.
         System.err.println("[save] slot " + var0 + " could not be read:");
         var23.printStackTrace();
         var1 = null;
      }

      return var1;
   }

   // $VF: renamed from: a (int) void
   public static final void method_733(int var0) {
      try {
         RecordStore.deleteRecordStore("Deep_" + var0);
      } catch (RecordStoreException var16) {
      }

      try {
         field_1093 = RecordStore.openRecordStore("Deep_" + var0, true);
      } catch (RecordStoreException var15) {
      }

      ByteArrayOutputStream var1 = null;
      DataOutputStream var2 = null;

      try {
         var1 = new ByteArrayOutputStream();
         var2 = new DataOutputStream(var1);
         boolean[] var3 = class_44.method_433();

         for (int var4 = 0; var4 < var3.length; var4++) {
            var2.writeBoolean(var3[var4]);
         }

         var2.writeInt(class_3.method_112());
         var2.writeInt(class_3.method_130());
         var2.writeLong(class_3.method_142());
         var2.writeInt(class_3.method_132());
         var2.writeInt(class_3.method_138());
         var2.writeInt(class_3.method_100());
         var2.writeInt(class_3.method_102());
         var2.writeInt(class_3.method_139());
         var2.writeInt(class_3.method_140());
         var2.writeInt(class_3.method_131());
         var2.writeInt(class_3.method_121());
         var2.writeInt(class_3.method_107());
         var2.writeInt(class_3.method_73());
         method_734(var2, class_3.method_65());
         method_734(var2, class_3.method_67());
         var2.writeUTF(class_3.method_143());
         var2.writeInt(class_3.method_86());
         var2.writeInt(class_3.method_81());
         var2.writeInt(class_3.method_84());
         var2.writeInt(class_3.method_88());
         var2.writeInt(class_3.method_135());
         var2.writeInt(class_3.method_90());
         var2.writeInt(class_3.method_89());
         boolean[] var21 = class_3.method_125();

         for (int var5 = 0; var5 < var21.length; var5++) {
            var2.writeBoolean(var21[var5]);
         }

         int[] var22 = class_58.method_566();

         for (int var6 = 0; var6 < var22.length; var6++) {
            var2.writeInt(var22[var6]);
         }

         var2.writeBoolean(class_3.method_145() != null);
         if (class_3.method_145() != null) {
            for (int var23 = 0; var23 < class_119.field_1503; var23++) {
               var2.writeByte(class_3.method_145()[var23]);
            }
         } else {
            int[] var24 = new int[class_3.method_147().getWidth() * class_3.method_147().getHeight()];
            class_3.method_147().getRGB(var24, 0, class_3.method_147().getWidth(), 0, 0, class_3.method_147().getWidth(), class_3.method_147().getHeight());
            var2.writeInt(var24.length);

            for (int var7 = 0; var7 < var24.length; var7++) {
               var2.writeInt(var24[var7]);
            }
         }

         boolean[] var25 = class_3.method_105();

         for (int var26 = 0; var26 < var25.length; var26++) {
            var2.writeBoolean(var25[var26]);
         }

         boolean[] var27 = class_3.method_98();

         for (int var8 = 0; var8 < var27.length; var8++) {
            var2.writeBoolean(var27[var8]);
         }

         var2.writeInt(class_3.method_108().field_422);
         var2.writeBoolean(class_3.method_108().field_443);
         class_51[] var28;
         if ((var28 = class_3.method_108().field_444) == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(var28.length);

            for (int var9 = 0; var9 < var28.length; var9++) {
               if (var28[var9] != null) {
                  var2.writeInt(var28[var9].field_711);
               } else {
                  var2.writeInt(-1);
               }
            }
         }

         class_46[] var30;
         if ((var30 = class_3.method_108().field_445) == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(var30.length);

            for (int var10 = 0; var10 < var30.length; var10++) {
               var2.writeInt(var30[var10].field_626);
               var2.writeInt(var30[var10].field_636);
               var2.writeInt(var30[var10].field_630);
            }
         }

         for (int var32 = 0; var32 < class_3.method_57().length + 1; var32++) {
            class_60 var11 = null;
            if (var32 == class_3.method_57().length) {
               var11 = class_3.method_110();
            } else {
               var11 = class_3.method_57()[var32];
            }

            if (var11 == null) {
               var2.writeShort(-1);
            } else {
               var2.writeShort(var11.field_828);
               var28 = var11.field_835;
               if (var11.field_835 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var28.length);

                  for (int var12 = 0; var12 < var28.length; var12++) {
                     var2.writeInt(var28[var12].field_711);
                     var2.writeInt(var28[var12].field_720);
                     var2.writeBoolean(var28[var12].field_721);
                  }
               }

               var30 = var11.field_836;
               if (var11.field_836 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var30.length);

                  for (int var35 = 0; var35 < var30.length; var35++) {
                     var2.writeInt(var30[var35].field_626);
                     var2.writeInt(var30[var35].field_636);
                     var2.writeInt(var30[var35].field_630);
                  }
               }

               class_32[] var36 = var11.field_837;
               if (var11.field_837 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var36.length);

                  for (int var13 = 0; var13 < var36.length; var13++) {
                     var2.writeInt(var36[var13].field_422);
                     var2.writeBoolean(var36[var13].field_443);
                  }
               }

               class_95[] var37 = var11.field_838;
               if (var11.field_838 == null) {
                  var2.writeInt(0);
               } else {
                  var2.writeInt(var37.length);

                  for (int var14 = 0; var14 < var37.length; var14++) {
                     method_734(var2, var37[var14]);
                  }
               }
            }
         }

         if (class_41.field_525 == null) {
            var2.writeInt(0);
         } else {
            var2.writeInt(class_41.field_525.length);

            for (int var33 = 0; var33 < class_41.field_525.length; var33++) {
               var2.writeInt(class_41.field_525[var33]);
            }
         }

         var2.writeInt(class_41.field_526);
         var2.writeBoolean(class_41.field_502);
         var2.writeBoolean(class_41.field_503);
         var2.writeBoolean(class_41.field_504);
         var2.writeBoolean(class_41.field_505);
         var2.writeBoolean(class_41.field_506);
         var2.writeBoolean(class_41.field_507);
         var2.writeBoolean(class_41.field_508);
         var2.writeBoolean(class_41.field_509);
         var2.writeBoolean(class_41.field_510);
         var2.writeBoolean(class_41.field_511);
         var2.writeBoolean(class_41.field_512);
         var2.writeBoolean(class_41.field_513);
         var2.writeBoolean(class_41.field_514);
         var2.writeBoolean(class_41.field_515);
         var2.writeBoolean(class_41.field_516);
         var2.writeBoolean(class_41.field_517);
         var2.writeBoolean(class_41.field_518);
         var2.writeBoolean(class_41.field_519);
         var2.writeBoolean(class_41.field_521);
         var2.writeBoolean(class_41.field_520);
         var2.writeBoolean(class_41.field_522);
         var2.writeBoolean(class_41.field_523);
         var2.writeBoolean(class_41.field_524);
         var2.close();
         var1.close();
         field_1093.addRecord(var1.toByteArray(), 0, var1.toByteArray().length);
         field_1093.closeRecordStore();
         field_1093 = null;
         System.out.println("[save] wrote slot " + var0 + " (" + var1.size() + " bytes)");
      } catch (IOException var17) {
         var17.printStackTrace();
      } catch (RecordStoreException var18) {
         var18.printStackTrace();
      }
   }

   // $VF: renamed from: a (java.io.DataOutputStream, al) void
   private static void method_734(DataOutputStream var0, class_95 var1) throws IOException {
      var0.writeInt(var1.field_1226);
      if (!var1.method_789()) {
         var0.writeBoolean(var1.field_1241);
         if (!var1.field_1241) {
            var0.writeUTF(var1.field_1227);

            for (int var2 = 0; var2 < class_119.field_1503; var2++) {
               var0.writeByte(var1.field_1228[var2]);
            }
         }

         var0.writeInt(var1.field_1229);
         var0.writeInt(var1.field_1231);
         var0.writeInt(var1.field_1230);
         var0.writeInt(var1.field_1232);
         var0.writeInt(var1.field_1234);
         var0.writeInt(var1.field_1236);
         var0.writeInt(var1.field_1235);
         var0.writeInt(var1.field_1247);
         var0.writeInt(var1.field_1246);
         var0.writeInt(var1.field_1248);
         var0.writeInt(var1.field_1245);
         var0.writeInt(var1.field_1244);
         var0.writeInt(var1.field_1250);
         var0.writeBoolean(var1.field_1251);
      }
   }

   // $VF: renamed from: a (java.io.DataInputStream) al
   private static class_95 method_735(DataInputStream var0) throws IOException {
      int var1;
      if ((var1 = var0.readInt()) == -1) {
         return class_95.field_1225;
      } else {
         boolean var2 = var0.readBoolean();
         String var3 = "";
         byte[] var4 = null;
         if (!var2) {
            var3 = var0.readUTF();
            var4 = new byte[class_119.field_1503];

            for (int var5 = 0; var5 < class_119.field_1503; var5++) {
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
         class_95 var19 = null;
         if (var2) {
            var19 = new class_95(var1, var7, var8);
         } else {
            var19 = new class_95(var1, var3, var4, var20, var7, var8, var9, var11);
         }

         var19.field_1231 = var6;
         var19.method_790(var13, var12, var14);
         var19.method_791(var16, var15);
         var19.field_1250 = var17;
         var19.field_1251 = var18;
         var19.method_796(var10);
         return var19;
      }
   }
}
