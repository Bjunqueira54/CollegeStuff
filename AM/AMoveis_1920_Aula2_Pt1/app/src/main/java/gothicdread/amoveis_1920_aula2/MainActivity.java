package gothicdread.amoveis_1920_aula2;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Application;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity
{
    private String TAG = "AMov1920";

    int i = 0;

    MyApp app;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        app = (MyApp) getApplication();

        Log.i(TAG, "OnCreate: "+(++i)+" "+(++app.j)+" "+(++app.j));
    }

    @Override
    protected void onStart()
    {
        super.onStart();
        Log.i(TAG, "onStart: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onRestart()
    {
        super.onRestart();
        Log.i(TAG, "onRestart: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        Log.i(TAG, "onResume: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onPause()
    {
        super.onPause();
        Log.i(TAG, "onPause: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onStop()
    {
        super.onStop();
        Log.i(TAG, "onStop: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onDestroy()
    {
        super.onDestroy();
        Log.i(TAG, "onDestroy: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState)
    {
        super.onRestoreInstanceState(savedInstanceState);

        i = savedInstanceState.getInt("i", i);

        Log.i(TAG, "onRestoreInstanceState: "+(++i)+" "+(++app.j));
    }

    @Override
    protected void onSaveInstanceState(Bundle outState)
    {
        super.onSaveInstanceState(outState);

        outState.putInt("i", i);

        Log.i(TAG, "onSaveInstanceState: "+(++i)+" "+(++app.j));
    }
}