import javax.microedition.lcdui.Image;

// $VF: renamed from: bi
public final class class_2 {
   // $VF: renamed from: a be
   public class_32 field_21;
   // $VF: renamed from: a dn
   public class_51 field_22;
   // $VF: renamed from: a aa
   public class_46 field_23;
   // $VF: renamed from: a al
   public class_95 field_24;
   // $VF: renamed from: a boolean
   public boolean field_25;
   // $VF: renamed from: a java.lang.String
   public String field_26;
   // $VF: renamed from: a int
   public int field_27 = -1;
   // $VF: renamed from: b int
   public int field_28 = 0;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_29;

   public class_2(Image var1, int var2, String var3) {
      this.field_29 = var1;
      this.field_26 = var3;
      this.field_27 = var2;
      this.field_25 = true;
   }

   public class_2(class_32 var1) {
      this.field_21 = var1;
      this.field_25 = true;
   }

   public class_2(class_51 var1) {
      this.field_22 = var1;
      this.field_25 = true;
   }

   public class_2(class_46 var1) {
      this.field_23 = var1;
      this.field_25 = true;
   }

   public class_2(String var1) {
      this.field_26 = var1;
      this.field_25 = false;
   }

   public class_2(int var1) {
      this.field_27 = var1;
      this.field_25 = true;
   }

   public class_2(int var1, int var2) {
      this.field_28 = var1;
      this.field_27 = var2;
      this.field_25 = true;
   }

   public class_2(class_95 var1) {
      this.field_24 = var1;
      this.field_25 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_45() {
      return this.field_29 != null;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_46() {
      return this.field_21 != null;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_47() {
      return this.field_22 != null;
   }

   // $VF: renamed from: d () boolean
   public final boolean method_48() {
      return this.field_23 != null;
   }

   // $VF: renamed from: e () boolean
   public final boolean method_49() {
      return !this.field_25;
   }

   // $VF: renamed from: f () boolean
   public final boolean method_50() {
      return this.field_24 != null;
   }

   // $VF: renamed from: g () boolean
   public final boolean method_51() {
      return this.field_27 >= 0;
   }

   // $VF: renamed from: h () boolean
   public final boolean method_52() {
      if (this.method_46()) {
         return this.field_21.method_363() <= class_3.method_112();
      } else if (this.method_47()) {
         return this.field_22.field_712 <= class_3.method_112();
      } else {
         return this.method_48() ? this.field_23.field_630 <= class_3.method_112() : false;
      }
   }

   // $VF: renamed from: i () boolean
   public final boolean method_53() {
      return this.method_47() ? class_3.method_108().method_386() : false;
   }

   // $VF: renamed from: j () boolean
   public final boolean method_54() {
      return this.method_47() ? class_3.method_108().method_385(this.field_22.field_710) : false;
   }

   // $VF: renamed from: a () int
   public final int method_55() {
      if (this.method_46()) {
         return this.field_21.method_363();
      } else if (this.method_47()) {
         return this.field_22.field_712;
      } else {
         return this.method_48() ? this.field_23.field_630 : 0;
      }
   }

   // $VF: renamed from: b () int
   public final int method_56() {
      if (this.method_46()) {
         return this.field_21.field_422;
      } else if (this.method_47()) {
         return this.field_22.field_711;
      } else {
         return this.method_48() ? this.field_23.field_626 : 999999;
      }
   }
}
