package gothicdread.finger_drawer;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.SeekBar;
import android.widget.Toast;

public class FundoSolidoActivity extends AppCompatActivity implements SeekBar.OnSeekBarChangeListener
{
    EditText edTitulo;
    SeekBar r, g, b;
    FrameLayout fPreview;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fundo_solido);

        edTitulo = findViewById(R.id.edTitulo);
        fPreview = findViewById(R.id.fundoPreview);
        r = findViewById(R.id.rValue);
        g = findViewById(R.id.gValue);
        b = findViewById(R.id.bValue);

        r.setMax(255);
        g.setMax(255);
        b.setMax(255);

        r.setProgress(255);
        g.setProgress(255);
        b.setProgress(255);

        r.setOnSeekBarChangeListener(this);
        g.setOnSeekBarChangeListener(this);
        b.setOnSeekBarChangeListener(this);

        atualizaPreview();
    }

    void atualizaPreview()
    {
        fPreview.setBackgroundColor(Color.rgb(r.getProgress(), g.getProgress(), b.getProgress()));
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser)
    {
        atualizaPreview();
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {}

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {}

    @Override
    public boolean onCreateOptionsMenu(Menu menu)
    {
        MenuInflater mi = getMenuInflater();

        mi.inflate(R.menu.menu_escolhe_cor, menu);

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item)
    {
        if(item.getItemId() == R.id.menuCriar)
        {
            String strTitulo = edTitulo.getText().toString();

            if(strTitulo.length() < 1)
            {
                Toast.makeText(this, "Deve indicar um titulo", Toast.LENGTH_SHORT).show();
                return true;
            }

            int rValue = r.getProgress();
            int gValue = g.getProgress();
            int bValue = b.getProgress();

            Intent intent = new Intent(this, AreaDesenhoActivity.class);
            intent.putExtra("titulo", strTitulo);
            intent.putExtra("red", rValue);
            intent.putExtra("green", gValue);
            intent.putExtra("blue", bValue);

            startActivity(intent);

            finish();

            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
