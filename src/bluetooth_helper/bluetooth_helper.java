package bluetoothhelper;

import android.os.Build;
import androidx.annotation.Keep;
import android.util.Log;

public class BluethoothHelper {

    @Keep
    static public String getBuildVersion() {
        return Build.VERSION.RELEASE;
    }

    @Keep
    static public int getDevices() {
        return 0;
    }
}