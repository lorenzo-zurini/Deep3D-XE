import java.io.InputStream;
import javax.microedition.lcdui.AlertType;
import javax.microedition.media.Manager;
import javax.microedition.media.Player;
import javax.microedition.media.PlayerListener;
import javax.microedition.media.control.VolumeControl;

// $VF: renamed from: al
public final class class_88 implements PlayerListener {
   // $VF: renamed from: a java.lang.String[]
   private static final String[] field_1172 = new String[]{"/data/sound/station.mid", "/data/sound/station.mid"};
   // $VF: renamed from: b java.lang.String[]
   private static final String[] field_1173 = new String[]{
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
   public static final int[] field_1174 = new int[]{0, 8, 12, 13};
   // $VF: renamed from: b int
   private static int field_1175;
   // $VF: renamed from: a long
   private static long field_1176;
   // $VF: renamed from: a long[]
   private static final long[] field_1177 = new long[]{
      1300L, 2500L, 1100L, 3000L, 1400L, 900L, 2800L, 3200L, 2800L, 1000L, 1000L, 300L, 1500L, 1500L, 150L, 90L
   };
   // $VF: renamed from: a short[]
   private static short[] field_1178 = new short[]{0, 95, 100, 100, 100, 90, 100, 100, 0, 100, 100, 80, 80, 80, 90, 80};
   // $VF: renamed from: a javax.microedition.media.Player
   private static Player field_1179;
   // $VF: renamed from: a javax.microedition.media.Player[]
   private Player[] field_1180;
   // $VF: renamed from: a javax.microedition.media.control.VolumeControl
   private VolumeControl field_1181;
   // $VF: renamed from: a int
   public int field_1182;
   // $VF: renamed from: a boolean
   private boolean field_1183 = false;
   // $VF: renamed from: c int
   private int field_1184;

   public class_88() {
      this.field_1182 = 100;
      this.field_1180 = new Player[field_1173.length];
   }

   // $VF: renamed from: a (int) void
   public final void method_765(int var1) {
      if (field_1179 != null && field_1179.getState() != 0) {
         this.field_1181 = (VolumeControl)field_1179.getControl("VolumeControl");
         this.field_1181.setLevel(var1);
      }

      if (this.field_1180 != null) {
         for (int var2 = 0; var2 < this.field_1180.length; var2++) {
            if (this.field_1180[var2] != null && this.field_1180[var2].getState() != 0) {
               this.field_1181 = (VolumeControl)this.field_1180[var2].getControl("VolumeControl");
               this.field_1181.setLevel(var1);
            }
         }
      }

      this.field_1182 = var1;
   }

   // $VF: renamed from: a () void
   public final void method_766() {
      if (field_1179 != null) {
         if (field_1179.getState() != 0) {
            field_1179.deallocate();
         }

         field_1179.close();
         field_1179 = null;
      }

      this.field_1181 = null;
   }

   // $VF: renamed from: a () boolean
   public final boolean method_767() {
      if (!class_84.field_1080) {
         return false;
      } else {
         return field_1179 == null ? false : field_1179.getState() == 400;
      }
   }

   // $VF: renamed from: b (int) void
   public final void method_768(int var1) {
      if (class_84.field_1080) {
         this.method_773();

         try {
            field_1179 = Manager.createPlayer(this.getClass().getResourceAsStream(field_1172[var1]), "audio/midi");
            field_1179.addPlayerListener(this);
            field_1179.setLoopCount(-1);
            field_1179.start();
            class_84.field_1115 = var1;
            VolumeControl var3;
            (var3 = (VolumeControl)field_1179.getControl("VolumeControl")).setLevel(40);

            try {
               var3.setMute(false);
            } catch (Exception var5) {
            }

            class_84.field_1114 = false;
         } catch (Exception var6) {
            class_84.field_1114 = true;
            if (field_1179 != null) {
               field_1179.deallocate();
               field_1179.close();
            }

            field_1179 = null;
         }
      }
   }

   // $VF: renamed from: a (int, int) void
   public final void method_769(int var1, int var2) {
      if (class_84.field_1080) {
         if (System.currentTimeMillis() > field_1176 + field_1177[field_1175] || field_1178[var1] >= field_1178[field_1175]) {
            try {
               if (this.field_1180[var1] == null) {
                  try {
                     InputStream var3 = this.getClass().getResourceAsStream(field_1173[var1]);
                     this.field_1180[var1] = Manager.createPlayer(var3, "audio/amr");
                     this.field_1180[var1].setLoopCount(1);
                     this.field_1180[var1].prefetch();
                  } catch (Exception var4) {
                     var4.printStackTrace();
                  }
               }

               ((VolumeControl)this.field_1180[var1].getControl("VolumeControl")).setLevel(var2);
               this.field_1180[var1].stop();
               this.field_1180[var1].setMediaTime(0L);
               this.field_1180[var1].start();
               field_1175 = var1;
               field_1176 = System.currentTimeMillis();
               return;
            } catch (Exception var5) {
               var5.printStackTrace();
            }
         }
      }
   }

   // $VF: renamed from: c (int) void
   public final void method_770(int var1) {
      this.method_769(var1, this.field_1182);
   }

   // $VF: renamed from: b () void
   public final void method_771() {
      try {
         try {
            VolumeControl var1 = (VolumeControl)field_1179.getControl("VolumeControl");
            this.field_1184 = var1.getLevel();
            var1.setMute(true);
         } catch (Exception var2) {
         }

         field_1179.stop();

         for (int var4 = 0; var4 < this.field_1180.length; var4++) {
            if (this.field_1180[var4] != null) {
               this.field_1180[var4].stop();
            }
         }
      } catch (Exception var3) {
      }
   }

   // $VF: renamed from: c () void
   public final void method_772() {
      try {
         if (class_84.field_1080) {
            try {
               VolumeControl var1;
               (var1 = (VolumeControl)field_1179.getControl("VolumeControl")).setMute(false);
               AlertType.ERROR.playSound(class_84.field_1112);
               var1.setLevel(this.field_1184);
            } catch (Exception var4) {
            }

            field_1179.start();
         }

         class_84.field_1114 = false;
      } catch (Exception var5) {
         class_84.field_1114 = true;
         if (field_1179 != null) {
            try {
               field_1179.deallocate();
               field_1179.close();
            } catch (Exception var3) {
            }
         }

         field_1179 = null;
      }
   }

   // $VF: renamed from: d () void
   public final void method_773() {
      try {
         if (field_1179.getState() == 400) {
            field_1179.stop();
            field_1179.deallocate();
            field_1179.close();
         }
      } catch (Exception var2) {
      }
   }

   public final void playerUpdate(Player var1, String var2, Object var3) {
      if (var2.compareTo("deviceUnavailable") == 0 && field_1179 != null && field_1179.getState() != 0) {
         this.field_1183 = true;
      }

      if (var2.compareTo("deviceAvailable") == 0 && this.field_1183) {
         this.field_1183 = false;
         class_84.field_1114 = true;
      }
   }
}
