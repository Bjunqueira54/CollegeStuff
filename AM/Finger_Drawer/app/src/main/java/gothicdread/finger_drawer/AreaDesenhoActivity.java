package gothicdread.finger_drawer;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.FrameLayout;

public class AreaDesenhoActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_area_desenho);

        Intent intent = getIntent();

        String titulo = intent.getStringExtra("titulo");
        if(titulo == null)
            titulo = "Sem Nome";

        int r = intent.getIntExtra("red", 255);
        int g = intent.getIntExtra("green", 255);
        int b = intent.getIntExtra("blue", 255);

        FrameLayout fr = findViewById(R.id.frameDesenho);

        AreaDesenho ad = new AreaDesenho(this, r, g, b);
        fr.addView(ad);
    }
}
