package pt.isec.ans.rockpaperscissors;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity
{
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

	}
	
	public void onServer(View v)
	{
		Intent intent=new Intent(this, GameActivity.class);
		intent.putExtra("mode", GameActivity.SERVER);
		startActivity(intent);
	}

	public void onClient(View v)
	{
		Intent intent=new Intent(this, GameActivity.class);
		intent.putExtra("mode", GameActivity.CLIENT);
		startActivity(intent);
	}
}
