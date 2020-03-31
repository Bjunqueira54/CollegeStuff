package gothicdread.finger_drawer;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity
{
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onFundoSolido(View view)
    {
        Intent intent = new Intent(this, FundoSolidoActivity.class);
        startActivity(intent);
    }

    public void onFundoImagem(View view)
    {
        Intent intent = new Intent(this, FundoImagemActivity.class);
        startActivity(intent);
    }
}
