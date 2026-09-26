import javax.microedition.lcdui.Image;

// $VF: renamed from: bh
public final class class_59 {
   // $VF: renamed from: a bd
   public class_68 field_709;
   // $VF: renamed from: a dn
   public class_19 field_710;
   // $VF: renamed from: a ac
   public class_120 field_711;
   // $VF: renamed from: a am
   public class_87 field_712;
   // $VF: renamed from: a boolean
   public boolean field_713;
   // $VF: renamed from: a java.lang.String
   public String field_714;
   // $VF: renamed from: a int
   public int field_715 = -1;
   // $VF: renamed from: b int
   public int field_716 = 0;
   // $VF: renamed from: a javax.microedition.lcdui.Image
   public Image field_717;

   public class_59(Image var1, int var2, String var3) {
      this.field_717 = var1;
      this.field_714 = var3;
      this.field_715 = var2;
      this.field_713 = true;
   }

   public class_59(class_68 var1) {
      this.field_709 = var1;
      this.field_713 = true;
   }

   public class_59(class_19 var1) {
      this.field_710 = var1;
      this.field_713 = true;
   }

   public class_59(class_120 var1) {
      this.field_711 = var1;
      this.field_713 = true;
   }

   public class_59(String var1) {
      this.field_714 = var1;
      this.field_713 = false;
   }

   public class_59(int var1) {
      this.field_715 = var1;
      this.field_713 = true;
   }

   public class_59(int var1, int var2) {
      this.field_716 = var1;
      this.field_715 = var2;
      this.field_713 = true;
   }

   public class_59(class_87 var1) {
      this.field_712 = var1;
      this.field_713 = true;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_534() {
      return this.field_717 != null;
   }

   // $VF: renamed from: b () boolean
   public final boolean method_535() {
      return this.field_709 != null;
   }

   // $VF: renamed from: c () boolean
   public final boolean method_536() {
      return this.field_710 != null;
   }

   // $VF: renamed from: d () boolean
   public final boolean method_537() {
      return this.field_711 != null;
   }

   // $VF: renamed from: e () boolean
   public final boolean method_538() {
      return !this.field_713;
   }

   // $VF: renamed from: f () boolean
   public final boolean method_539() {
      return this.field_712 != null;
   }

   // $VF: renamed from: g () boolean
   public final boolean method_540() {
      return this.field_715 >= 0;
   }

   // $VF: renamed from: h () boolean
   public final boolean method_541() {
      if (this.method_535()) {
         return this.field_709.method_603() <= class_21.method_182();
      } else if (this.method_536()) {
         return this.field_710.field_167 <= class_21.method_182();
      } else {
         return this.method_537() ? this.field_711.field_1484 <= class_21.method_182() : false;
      }
   }

   // $VF: renamed from: i () boolean
   public final boolean method_542() {
      return this.method_536() ? class_21.method_178().method_626() : false;
   }

   // $VF: renamed from: j () boolean
   public final boolean method_543() {
      return this.method_536() ? class_21.method_178().method_625(this.field_710.field_165) : false;
   }

   // $VF: renamed from: a () int
   public final int method_544() {
      if (this.method_535()) {
         return this.field_709.method_603();
      } else if (this.method_536()) {
         return this.field_710.field_167;
      } else {
         return this.method_537() ? this.field_711.field_1484 : 0;
      }
   }

   // $VF: renamed from: b () int
   public final int method_545() {
      if (this.method_535()) {
         return this.field_709.field_863;
      } else if (this.method_536()) {
         return this.field_710.field_166;
      } else {
         return this.method_537() ? this.field_711.field_1480 : 999999;
      }
   }
}
