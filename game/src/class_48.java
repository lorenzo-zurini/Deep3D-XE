// $VF: renamed from: by
public final class class_48 {
   // $VF: renamed from: a java.lang.String
   private static String field_536;
   // $VF: renamed from: b java.lang.String
   private static String field_537;
   // $VF: renamed from: c java.lang.String
   private static String field_538;

   private class_48() {
   }

   // $VF: renamed from: a (long) java.lang.String
   public static final String method_397(long var0) {
      int var2 = (int)(var0 / 1000L % 60L);
      int var3 = (int)(var0 / 60000L % 60L);
      int var4 = (int)(var0 / 3600000L % 24L);
      field_536 = (var2 < 10 ? "0" : "") + var2;
      field_537 = (var3 < 10 ? "0" : "") + var3;
      if (var4 == 0) {
         return new String(field_537 + ":" + field_536);
      } else {
         int var5 = (int)(var0 / 3600000L / 24L);
         var4 += var5 * 24;
         field_538 = (var4 < 10 ? "0" : "") + var4;
         return new String(field_538 + ":" + field_537 + ":" + field_536);
      }
   }

   // $VF: renamed from: b (long) java.lang.String
   public static final String method_398(long var0) {
      int var2 = (int)(var0 / 60000L % 60L);
      int var3 = (int)(var0 / 3600000L % 24L);
      field_537 = (var2 < 10 ? "0" : "") + var2;
      int var4 = (int)(var0 / 3600000L / 24L);
      var3 += var4 * 24;
      field_538 = (var3 < 10 ? "0" : "") + var3;
      return new String(field_538 + ":" + field_537);
   }
}
