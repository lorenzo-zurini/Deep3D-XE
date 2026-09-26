// $VF: renamed from: bx
public final class class_122 {
   // $VF: renamed from: a java.lang.String
   private static String field_1527;
   // $VF: renamed from: b java.lang.String
   private static String field_1528;
   // $VF: renamed from: c java.lang.String
   private static String field_1529;

   private class_122() {
   }

   // $VF: renamed from: a (long) java.lang.String
   public static final String method_931(long var0) {
      int var2 = (int)(var0 / 1000L % 60L);
      int var3 = (int)(var0 / 60000L % 60L);
      int var4 = (int)(var0 / 3600000L % 24L);
      field_1527 = (var2 < 10 ? "0" : "") + var2;
      field_1528 = (var3 < 10 ? "0" : "") + var3;
      if (var4 == 0) {
         return new String(field_1528 + ":" + field_1527);
      } else {
         int var5 = (int)(var0 / 3600000L / 24L);
         var4 += var5 * 24;
         field_1529 = (var4 < 10 ? "0" : "") + var4;
         return new String(field_1529 + ":" + field_1528 + ":" + field_1527);
      }
   }

   // $VF: renamed from: b (long) java.lang.String
   public static final String method_932(long var0) {
      int var2 = (int)(var0 / 60000L % 60L);
      int var3 = (int)(var0 / 3600000L % 24L);
      field_1528 = (var2 < 10 ? "0" : "") + var2;
      int var4 = (int)(var0 / 3600000L / 24L);
      var3 += var4 * 24;
      field_1529 = (var3 < 10 ? "0" : "") + var3;
      return new String(field_1529 + ":" + field_1528);
   }
}
