import javax.microedition.m3g.Appearance;
import javax.microedition.m3g.CompositingMode;
import javax.microedition.m3g.Group;
import javax.microedition.m3g.KeyframeSequence;
import javax.microedition.m3g.Loader;
import javax.microedition.m3g.Material;
import javax.microedition.m3g.Mesh;
import javax.microedition.m3g.Node;
import javax.microedition.m3g.Object3D;
import javax.microedition.m3g.PolygonMode;
import javax.microedition.m3g.Texture2D;
import javax.microedition.m3g.Transform;
import javax.microedition.m3g.World;

// $VF: renamed from: bk
public final class class_111 extends class_108 {
   // $VF: renamed from: c int
   private int field_1393;
   // $VF: renamed from: g int
   private int field_1394;
   // $VF: renamed from: h int
   private int field_1395;
   // $VF: renamed from: i int
   private int field_1396;
   // $VF: renamed from: a long
   private long field_1397;
   // $VF: renamed from: d boolean
   private boolean field_1398;
   // $VF: renamed from: a byte
   private byte field_1399;
   // $VF: renamed from: a javax.microedition.m3g.Transform
   private static Transform field_1400 = new Transform();
   // $VF: renamed from: a float[]
   private static float[] field_1401 = new float[16];
   // $VF: renamed from: a javax.microedition.m3g.Node[]
   private Node[] field_1402;
   // $VF: renamed from: b javax.microedition.m3g.Node[]
   private Node[] field_1403;
   // $VF: renamed from: a javax.microedition.m3g.PolygonMode
   private static PolygonMode field_1404;
   // $VF: renamed from: b javax.microedition.m3g.PolygonMode
   private static PolygonMode field_1405;
   // $VF: renamed from: a javax.microedition.m3g.CompositingMode
   private static CompositingMode field_1406;
   // $VF: renamed from: e boolean
   private boolean field_1407 = false;
   // $VF: renamed from: a javax.microedition.m3g.Texture2D
   private Texture2D field_1408 = null;

   public class_111(int var1, String var2, int var3) {
      super.field_1344 = var1;
      this.method_898();
      this.method_899(var2);
      super.field_1348 = var3;
   }

   public class_111(class_111 var1) {
      this.method_898();
      super.field_1348 = var1.field_1348;
      this.field_1402 = var1.field_1402;
      this.field_1403 = var1.field_1403;
      super.field_1367 = var1.field_1367;
      super.field_1338 = var1.field_1338;
      this.field_1393 = var1.field_1393;
      this.field_1394 = var1.field_1394;
      this.field_1395 = var1.field_1395;
      this.field_1396 = var1.field_1396;
      this.field_1397 = var1.field_1397;
      this.field_1398 = var1.field_1398;
      this.field_1399 = var1.field_1399;
      super.field_1344 = var1.field_1344;
   }

   // $VF: renamed from: f () void
   private void method_898() {
      if (field_1404 == null) {
         field_1404 = new PolygonMode();
         field_1404.setCulling(160);
         field_1404.setShading(165);
      }

      if (field_1405 == null) {
         field_1405 = new PolygonMode();
         field_1405.setCulling(162);
         field_1405.setShading(164);
      }

      if (field_1406 == null) {
         field_1406 = new CompositingMode();
         field_1406.setBlending(64);
         field_1406.setDepthTestEnable(true);
         field_1406.setDepthWriteEnable(false);
      }
   }

   // $VF: renamed from: a (java.lang.String) void
   private void method_899(String var1) {
      try {
         Object3D[] var3 = Loader.load(class_28.method_283(var1 + ".m3g"), 0);

         for (int var4 = 0; var4 < var3.length; var4++) {
            if (!(var3[var4] instanceof World)) {
               if (var3[var4] instanceof Group) {
                  int var12;
                  if ((var12 = this.method_902((Group)var3[var4], 0)) == 0) {
                     for (int var13 = 0; var13 < ((Group)var3[var4]).getChildCount(); var13++) {
                        Node var15;
                        if ((var15 = ((Group)var3[var4]).getChild(var13)) instanceof Mesh) {
                           Transform var16 = new Transform();
                           var15.getTransform(var16);
                           ((Group)var3[var4]).removeChild(var15);
                           var15.setTransform(var16);
                           this.method_900(var15);
                        }
                     }
                  } else {
                     this.method_900((Group)var3[var4]);
                     this.field_1393 = this.field_1393 < var12 ? var12 : this.field_1393;
                  }
               }
            } else {
               for (int var5 = 0; var5 < ((World)var3[var4]).getChildCount(); var5++) {
                  Node var6 = ((World)var3[var4]).getChild(var5);
                  int var7 = 0;
                  var7 = this.method_902(var6, 0);
                  if (var6 instanceof Group) {
                     if (var7 == 0) {
                        for (int var8 = 0; var8 < ((Group)var6).getChildCount(); var8++) {
                           Node var9;
                           if ((var9 = ((Group)var6).getChild(var8)) instanceof Mesh) {
                              Transform var10 = new Transform();
                              var9.getTransform(var10);
                              ((Group)var6).removeChild(var9);
                              var9.setTransform(var10);
                              this.method_900(var9);
                           }
                        }
                     } else {
                        this.method_900(var6);
                        this.field_1393 = this.field_1393 < var7 ? var7 : this.field_1393;
                     }
                  } else if (var6 instanceof Mesh) {
                     this.method_900(var6);
                     this.field_1393 = this.field_1393 < var7 ? var7 : this.field_1393;
                  }
               }
            }
         }

         if (this.field_1393 != 0) {
            this.field_1394 = 0;
            this.field_1395 = this.field_1393;
            this.field_1396 = 0;
            this.field_1397 = -1L;
            this.field_1398 = true;
            this.field_1399 = 2;
         }
      } catch (Exception var11) {
         this.field_1402 = null;
         this.field_1403 = null;
      }
   }

   // $VF: renamed from: a (javax.microedition.m3g.Node) void
   private void method_900(Node var1) {
      if (this.method_901(var1)) {
         if (this.field_1403 == null) {
            this.field_1403 = new Node[1];
            this.field_1403[0] = var1;
         } else {
            Node[] var3 = new Node[this.field_1403.length + 1];
            System.arraycopy(this.field_1403, 0, var3, 0, this.field_1403.length);
            var3[this.field_1403.length] = var1;
            this.field_1403 = var3;
         }
      } else if (this.field_1402 == null) {
         this.field_1402 = new Node[1];
         this.field_1402[0] = var1;
      } else {
         Node[] var2 = new Node[this.field_1402.length + 1];
         System.arraycopy(this.field_1402, 0, var2, 0, this.field_1402.length);
         var2[this.field_1402.length] = var1;
         this.field_1402 = var2;
      }
   }

   // $VF: renamed from: a (javax.microedition.m3g.Node) boolean
   private boolean method_901(Node var1) {
      if (var1 instanceof Group) {
         for (int var2 = 0; var2 < ((Group)var1).getChildCount(); var2++) {
            Node var3;
            if ((var3 = ((Group)var1).getChild(var2)) instanceof Mesh) {
               for (int var4 = 0; var4 < ((Mesh)var3).getSubmeshCount(); var4++) {
                  Material var6;
                  if ((var6 = ((Mesh)var3).getAppearance(var4).getMaterial()) != null && var6.getColor(8192) == 65280) {
                     return true;
                  }
               }
            }
         }
      } else if (var1 instanceof Mesh) {
         for (int var7 = 0; var7 < ((Mesh)var1).getSubmeshCount(); var7++) {
            Material var8;
            if ((var8 = ((Mesh)var1).getAppearance(var7).getMaterial()) != null && var8.getColor(8192) == 65280) {
               return true;
            }
         }
      }

      return false;
   }

   // $VF: renamed from: a (javax.microedition.m3g.Node, int) int
   private int method_902(Node var1, int var2) {
      for (int var3 = 0; var3 < var1.getAnimationTrackCount(); var3++) {
         KeyframeSequence var4;
         if ((var4 = var1.getAnimationTrack(var3).getKeyframeSequence()).getDuration() > var2) {
            var2 = var4.getDuration();
         }
      }

      if (var1 instanceof Group) {
         for (int var7 = 0; var7 < ((Group)var1).getChildCount(); var7++) {
            Node var8 = ((Group)var1).getChild(var7);

            for (int var5 = 0; var5 < var8.getAnimationTrackCount(); var5++) {
               KeyframeSequence var6;
               if ((var6 = var8.getAnimationTrack(var5).getKeyframeSequence()).getDuration() > var2) {
                  var2 = var6.getDuration();
               }
            }

            if (var8 instanceof Group) {
               var2 = this.method_902((Group)var8, var2);
            }
         }
      }

      return var2;
   }

   // $VF: renamed from: d () void
   public final void method_887() {
      if (this.field_1402 != null) {
         super.field_1368.method_505(field_1401);
         field_1400.set(field_1401);
         if (this.field_1393 > 0) {
            for (int var2 = 0; var2 < this.field_1402.length; var2++) {
               if (this.field_1399 == 3) {
                  this.field_1402[var2].animate(this.field_1395 - this.field_1396);
               } else {
                  this.field_1402[var2].animate(this.field_1396);
               }

               class_72.field_1016.render(this.field_1402[var2], field_1400);
            }

            return;
         }

         for (int var1 = 0; var1 < this.field_1402.length; var1++) {
            class_72.field_1016.render(this.field_1402[var1], field_1400);
         }
      }
   }

   // $VF: renamed from: e () void
   public final void method_888() {
      if (this.field_1403 != null) {
         super.field_1368.method_505(field_1401);
         field_1400.set(field_1401);
         if (this.field_1393 > 0) {
            for (int var2 = 0; var2 < this.field_1403.length; var2++) {
               if (this.field_1399 == 3) {
                  this.field_1403[var2].animate(this.field_1395 - this.field_1396);
               } else {
                  this.field_1403[var2].animate(this.field_1396);
               }

               class_72.field_1016.render(this.field_1403[var2], field_1400);
            }

            return;
         }

         for (int var1 = 0; var1 < this.field_1403.length; var1++) {
            class_72.field_1016.render(this.field_1403[var1], field_1400);
         }
      }
   }

   // $VF: renamed from: a (long) void
   public final void method_895(long var1) {
      if (this.field_1398) {
         if (this.field_1397 == -1L) {
            this.field_1397 = var1;
         }

         this.field_1396 = this.field_1394 + (int)((var1 - this.field_1397) / super.field_1335);
         if (this.field_1396 > this.field_1395) {
            if (this.field_1399 == 2) {
               this.field_1396 = this.field_1394;
               this.field_1397 = var1 - (this.field_1396 - this.field_1394) * super.field_1335;
               return;
            }

            this.field_1398 = false;
            this.field_1396 = this.field_1395;
            this.field_1397 = -1L;
         }
      }
   }

   // $VF: renamed from: e () int
   public final int method_875() {
      return this.field_1396;
   }

   // $VF: renamed from: f (int) void
   public final void method_874(int var1) {
      this.field_1396 = var1;
   }

   // $VF: renamed from: e (int) void
   public final void method_873(int var1) {
      super.field_1335 = var1 > 0 ? var1 : 1;
   }

   // $VF: renamed from: a (int, int) void
   public final void method_876(int var1, int var2) {
      this.field_1394 = var1 >= 0 && var1 <= this.field_1393 ? var1 : 0;
      this.field_1395 = var2 >= 0 && var2 <= this.field_1393 ? var2 : this.field_1393;
      this.field_1396 = this.field_1396 < var1 ? var1 : (this.field_1396 > var2 ? var2 : this.field_1396);
      this.field_1397 = -1L;
      if (this.field_1407) {
         if (var1 == 1 && var2 == 1
            || var1 == 3 && var2 == 5
            || var1 == 2 && var2 == 3
            || (super.field_1344 == 3305 || super.field_1344 == 3306 || super.field_1344 == 3309 || super.field_1344 == 3310) && var1 == 2 && var2 == 2) {
            this.field_1408.setTranslation(0.0F, 0.125F, 0.0F);
            return;
         }

         if (var1 == 2 && var2 == 2 || var1 == 6 && var2 == 8) {
            this.field_1408.setTranslation(0.0F, 0.25F, 0.0F);
         }
      }
   }

   // $VF: renamed from: a (byte) void
   public final void method_877(byte var1) {
      if (!this.field_1407 || super.field_1344 == 3300 || super.field_1344 == 3311 || super.field_1344 == 3308) {
         this.field_1399 = var1;
         this.field_1397 = -1L;
         this.field_1398 = this.field_1393 > 0;
      }
   }

   // $VF: renamed from: a () void
   public final void method_878() {
      this.field_1398 = false;
   }

   // $VF: renamed from: a () af
   public final class_102 method_840() {
      return new class_111(this);
   }

   // $VF: renamed from: a (cc) void
   public final void method_893(class_44 var1) {
      if (this.field_1402 != null) {
         for (int var2 = 0; var2 < this.field_1402.length; var2++) {
            this.method_903(this.field_1402[var2], ((class_45)var1).field_476, false);
         }
      }

      if (this.field_1403 != null) {
         for (int var3 = 0; var3 < this.field_1403.length; var3++) {
            this.method_903(this.field_1403[var3], ((class_45)var1).field_476, true);
         }
      }
   }

   // $VF: renamed from: a (javax.microedition.m3g.Node, javax.microedition.m3g.Texture2D[], boolean) void
   private void method_903(Node var1, Texture2D[] var2, boolean var3) {
      if (var1 instanceof Mesh) {
         int var8 = ((Mesh)var1).getUserID();

         for (int var9 = 0; var9 < ((Mesh)var1).getSubmeshCount(); var9++) {
            Appearance var6 = ((Mesh)var1).getAppearance(var9);
            if (var3) {
               var6.setCompositingMode(field_1406);
               var6.setPolygonMode(field_1405);
            } else {
               var6.setCompositingMode(null);
               var6.setPolygonMode(field_1404);
            }

            boolean var7 = false;
            if (var6.getMaterial() != null) {
               var7 = var6.getMaterial().getColor(8192) == 16711680;
            }

            var6.setMaterial(null);
            if (var6.getTexture(0) != null && var2 != null) {
               if (var8 < var2.length) {
                  if (var7) {
                     this.field_1408 = (Texture2D)var2[var8].duplicate();
                     var6.setTexture(0, this.field_1408);
                  } else {
                     var6.setTexture(0, var2[var8]);
                  }
               } else if (var7) {
                  this.field_1408 = (Texture2D)var2[0].duplicate();
                  var6.setTexture(0, this.field_1408);
               } else {
                  var6.setTexture(0, var2[0]);
               }
            }

            ((Mesh)var1).setAppearance(var9, var6);
            if (var7) {
               this.field_1407 = true;
            }
         }
      } else {
         if (var1 instanceof Group) {
            for (int var4 = 0; var4 < ((Group)var1).getChildCount(); var4++) {
               Node var5 = ((Group)var1).getChild(var4);
               this.method_903(var5, var2, var3);
            }
         }
      }
   }

   // $VF: renamed from: c () void
   public final void method_894() {
   }
}
