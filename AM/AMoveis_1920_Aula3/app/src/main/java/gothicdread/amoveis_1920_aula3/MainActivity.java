package gothicdread.amoveis_1920_aula3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener
{
    TextView mytv;
    Integer i = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mytv = findViewById(R.id.gdTextView1);

        mytv.setText("Wtf is this shit?");

        actualiza(": asd");

        Button b1 = findViewById(R.id.gdButton1);
        b1.setOnClickListener(this);

        Button b2 = findViewById(R.id.gdButton2);
        b2.setOnClickListener
        (
            new View.OnClickListener()
            {
                @Override
                public void onClick(View v)
                {
                    mytv.setText("You've reset the counter!");
                    i = 0;
                }
            }
        );
    }

    void actualiza(String str)
    {
        mytv.setText(mytv.getText().toString() + str);
    }

    @Override
    public void onClick(View v)
    {
        i++;
        mytv.setText(i.toString());
    }
}
