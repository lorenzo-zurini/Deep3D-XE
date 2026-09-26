import java.io.InputStream;
import javax.microedition.lcdui.AlertType;
import javax.microedition.media.Manager;
import javax.microedition.media.Player;
import javax.microedition.media.PlayerListener;
import javax.microedition.media.control.VolumeControl;

// $VF: renamed from: ak
public final class class_43 implements PlayerListener {
   // $VF: renamed from: a java.lang.String[]
   private static final String[] field_552 = new String[]{"/data/sound/station.mid", "/data/sound/station.mid"};
   // $VF: renamed from: b java.lang.String[]
   private static final String[] field_553 = new String[]{
      "/data/sound/echolot.amr",
      "/data/sound/traktor.amr",
      "/data/sound/message.amr",
      "/data/sound/gate.amr",
      "/data/sound/alert.amr",
      "/data/sound/harpoon.amr",
      "/data/sound/explosion.amr",
      "/data/sound/turbo.amr",
      "/data/sound/water.amr",
      "/data/sound/tiertot.amr",
      "/data/sound/signal.amr",
      "/data/sound/mine.amr",
      "/data/sound/amb02.amr",
      "/data/sound/amb03.amr",
      "/data/sound/harpoon_hit.amr",
      "/data/sound/beep.amr"
   };
   // $VF: renamed from: a int[]
   public static final int[] field_554 = new int[]{0, 8, 12, 13};
   // $VF: renamed from: b int
   private static int field_555;
   // $VF: renamed from: a long
   private static long field_556;
   // $VF: renamed from: a long[]
   private static final long[] field_557 = new long[]{
      1300L, 2500L, 1100L, 3000L, 1400L, 900L, 2800L, 3200L, 2800L, 1000L, 1000L, 300L, 1500L, 1500L, 150L, 90L
   };
   // $VF: renamed from: a short[]
   private static short[] field_558 = new short[]{0, 95, 100, 100, 100, 90, 100, 100, 0, 100, 100, 80, 80, 80, 90, 80};
   // $VF: renamed from: a javax.microedition.media.Player
   private static Player field_559;
   // $VF: renamed from: a javax.microedition.media.Player[]
   private Player[] field_560;
   // $VF: renamed from: a javax.microedition.media.control.VolumeControl
   private VolumeControl field_561;
   // $VF: renamed from: a int
   public int field_562;
   // $VF: renamed from: a boolean
   private boolean field_563 = false;
   // $VF: renamed from: c int
   private int field_564;

   public class_43() {
      this.field_562 = 100;
      this.field_560 = new Player[field_553.length];
   }

   // $VF: renamed from: a (int) void
   public final void method_422(int var1) {
      if (field_559 != null && field_559.getState() != 0) {
         this.field_561 = (VolumeControl)field_559.getControl("VolumeControl");
         this.field_561.setLevel(var1);
      }

      if (this.field_560 != null) {
         for (int var2 = 0; var2 < this.field_560.length; var2++) {
            if (this.field_560[var2] != null && this.field_560[var2].getState() != 0) {
               this.field_561 = (VolumeControl)this.field_560[var2].getControl("VolumeControl");
               this.field_561.setLevel(var1);
            }
         }
      }

      this.field_562 = var1;
   }

   // $VF: renamed from: a () void
   public final void method_423() {
      if (field_559 != null) {
         if (field_559.getState() != 0) {
            field_559.deallocate();
         }

         field_559.close();
         field_559 = null;
      }

      this.field_561 = null;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_424() {
      if (!class_41.field_497) {
         return false;
      } else {
         return field_559 == null ? false : field_559.getState() == 400;
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_425(int var1) {
      if (class_41.field_497) {
         this.method_430();

         try {
            field_559 = Manager.createPlayer(this.getClass().getResourceAsStream(field_552[var1]), "audio/midi");
            field_559.addPlayerListener(this);
            field_559.setLoopCount(-1);
            field_559.start();
            class_41.field_532 = var1;
            VolumeControl var3 = (VolumeControl)field_559.getControl("VolumeControl");

            try {
               var3.setMute(false);
            } catch (Exception var5) {
            }

            class_41.field_531 = false;
         } catch (Exception var6) {
            class_41.field_531 = true;
            if (field_559 != null) {
               field_559.deallocate();
               field_559.close();
            }

            field_559 = null;
         }
      }
   }

   // $VF: renamed from: a (int, int) void
   public final void method_426(int var1, int var2) {
      if (class_41.field_497) {
         if (System.currentTimeMillis() > field_556 + field_557[field_555] || field_558[var1] >= field_558[field_555]) {
            try {
               if (this.field_560[var1] == null) {
                  try {
                     InputStream var3 = this.getClass().getResourceAsStream(field_553[var1]);
                     this.field_560[var1] = Manager.createPlayer(var3, "audio/amr");
                     this.field_560[var1].setLoopCount(1);
                     this.field_560[var1].prefetch();
                  } catch (Exception var4) {
                     var4.printStackTrace();
                  }
               }

               ((VolumeControl)this.field_560[var1].getControl("VolumeControl")).setLevel(var2);
               this.field_560[var1].stop();
               this.field_560[var1].setMediaTime(0L);
               this.field_560[var1].start();
               field_555 = var1;
               field_556 = System.currentTimeMillis();
               return;
            } catch (Exception var5) {
               var5.printStackTrace();
            }
         }
      }
   }

   // $VF: renamed from: c (int) void
   public final void method_427(int var1) {
      this.method_426(var1, this.field_562);
   }

   // $VF: renamed from: b () void
   public final void method_428() {
      try {
         try {
            VolumeControl var1 = (VolumeControl)field_559.getControl("VolumeControl");
            this.field_564 = var1.getLevel();
            var1.setMute(true);
         } catch (Exception var2) {
         }

         field_559.stop();

         for (int var4 = 0; var4 < this.field_560.length; var4++) {
            if (this.field_560[var4] != null) {
               this.field_560[var4].stop();
            }
         }
      } catch (Exception var3) {
      }
   }

   // $VF: renamed from: c () void
   public final void method_429() {
      try {
         if (class_41.field_497) {
            try {
               VolumeControl var1;
               (var1 = (VolumeControl)field_559.getControl("VolumeControl")).setMute(false);
               AlertType.ERROR.playSound(class_41.field_529);
               var1.setLevel(this.field_564);
            } catch (Exception var4) {
            }

            field_559.start();
         }

         class_41.field_531 = false;
      } catch (Exception var5) {
         class_41.field_531 = true;
         if (field_559 != null) {
            try {
               field_559.deallocate();
               field_559.close();
            } catch (Exception var3) {
            }
         }

         field_559 = null;
      }
   }

   // $VF: renamed from: d () void
   public final void method_430() {
      try {
         if (field_559.getState() == 400) {
            field_559.stop();
            field_559.deallocate();
            field_559.close();
         }
      } catch (Exception var2) {
      }
   }

   public final void playerUpdate(Player var1, String var2, Object var3) {
      if (var2.compareTo("deviceUnavailable") == 0 && field_559 != null && field_559.getState() != 0) {
         this.field_563 = true;
      }

      if (var2.compareTo("deviceAvailable") == 0 && this.field_563) {
         this.field_563 = false;
         class_41.field_531 = true;
      }
   }
}
