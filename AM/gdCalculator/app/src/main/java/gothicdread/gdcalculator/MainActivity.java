package gothicdread.gdcalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{
    TextView tvDisplay;
    String strValor = "0.0";
    boolean novoValor = true;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvDisplay = findViewById(R.id.gdTVDisplay);

        actualiza();
    }

    void actualiza()
    {
        tvDisplay.setText(strValor);
    }

    public void onDigito(View v)
    {
        if (novoValor || strValor.length() < 20)
        {
            Button bt = (Button) v;

            strValor = novoValor ? bt.getText().toString() : strValor + bt.getText().toString();
            novoValor = false;

            actualiza();
        }
    }
}
