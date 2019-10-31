package gothicdread.steelballrun;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.view.View;

public class Board extends View implements SensorEventListener
{
    public Board(Context context, int color)
    {
        super(context);

        setBackgroundColor(color);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {

    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
