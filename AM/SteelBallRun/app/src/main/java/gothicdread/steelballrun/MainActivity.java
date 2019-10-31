package gothicdread.steelballrun;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

public class MainActivity extends AppCompatActivity implements SensorEventListener
{
    TextView tv;
    SensorManager sm;
    Sensor sensor;

    FrameLayout flBase;
    Board board;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        flBase = findViewById(R.id.flBase);
        board = new Board(this, Color.rgb(0xca, 0xca, 0x40));
        flBase.addView(board);

        sm = (SensorManager) getSystemService(SENSOR_SERVICE);
        sensor = sm.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        if(sensor == null)
        {
            finish();
        }

        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_FULLSCREEN |
                View.SYSTEM_UI_FLAG_HIDE_NAVIGATION |
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY |
                View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN |
                View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION |
                View.SYSTEM_UI_FLAG_LAYOUT_STABLE);

        tv = findViewById(R.id.sbrTextViewID);

        sm = (SensorManager) getSystemService(SENSOR_SERVICE);
        List<Sensor> lst = sm.getSensorList(Sensor.TYPE_ALL);

        if (lst == null || lst.size() == 0)
            Log.i("Sensores", "Não tem sensores");

        else
            for (Sensor s : lst)
            {
                Log.i("Sensores", "Sensor: " + s.getName() + ", 0-" + s.getMaximumRange() + ", "
                    + s.getPower() + "mA, " + s.getResolution() + ", " + s.getType() + ", " + s.getVendor() + ", " + s.getVersion());

                //sm.registerListener(this,s,SensorManager.SENSOR_DELAY_NORMAL);
            }
    }

    @Override
    protected void onResume()
    {
        super.onResume();

        sensor = sm.getDefaultSensor(Sensor.TYPE_LIGHT);
        //Dispositivo Real: sm.getDefaultSensor(Sensor.TYPE_STEP_DETECTOR);

        if(sensor != null)
        {
            sm.registerListener(this, sensor, SensorManager.SENSOR_DELAY_GAME);
        }
    }

    @Override
    protected void onPause()
    {
        super.onPause();

        if(sensor != null)
            sm.unregisterListener(this);
    }

    @Override
    public void onSensorChanged(SensorEvent event)
    {
        //TYPE_LIGHT
        tv.setText("Luxes: " + event.values[0]);
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy)
    {
    }
}
