package gothicdread.amoveis_1920_aula2;

import android.app.Application;
import android.content.res.Configuration;
import android.util.Log;

import androidx.annotation.NonNull;

public class MyApp extends Application
{
    private String TAG = "AMov1920App";
    public int j = 0;

    @Override
    public void onCreate()
    {
        super.onCreate();
        Log.i(TAG, "onCreate: ");
    }

    @Override
    public void onTrimMemory(int level)
    {
        super.onTrimMemory(level);
    }

    @Override
    public void onLowMemory()
    {
        super.onLowMemory();
    }

    @Override
    public void onConfigurationChanged(@NonNull Configuration newConfig)
    {
        super.onConfigurationChanged(newConfig);
    }

    @Override
    public void onTerminate()
    {
        super.onTerminate();
    }
}
