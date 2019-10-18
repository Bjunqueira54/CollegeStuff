package gothicdread.finger_drawer;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;

import java.util.ArrayList;

class Ponto
{
    private float x, y;

    public Ponto(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public float getX() { return this.x; }
    public float getY() { return this.y; }
}

public class AreaDesenho extends View implements GestureDetector.OnGestureListener
{
    int cor = Color.BLACK;

    ArrayList<Ponto> linha;
    GestureDetector gd;

    public AreaDesenho(Context context, int r, int g, int b)
    {
        super(context);
        linha = new ArrayList<>();
        gd = new GestureDetector(context, this);
        setBackgroundColor(Color.rgb(r, g, b));
    }

    @Override
    protected void onDraw(Canvas canvas)
    {
        super.onDraw(canvas);

        Paint paint = new Paint(Paint.DITHER_FLAG);
        paint.setColor(cor);
        paint.setStrokeWidth(4.0f);
        paint.setStyle(Paint.Style.FILL);
        //canvas.drawLine(10, 90, 90, 10, paint);

        if(linha.size() < 2)
            return;

        float oldx = 0, oldy = 0;

        for(int i = 0; i < linha.size(); i++)
        {
            Ponto p = linha.get(i);

            if(p.getX() < 0 || p.getY() < 0)
            {
                oldx = -p.getX();
                oldy = -p.getY();
            }
            else
            {
                canvas.drawLine(oldx, oldy, p.getX(), p.getY(), paint);
                oldx = p.getX();
                oldy = p.getY();
            }
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event)
    {
        if(gd.onTouchEvent(event))
            return true;

        return super.onTouchEvent(event);
    }

    @Override
    public boolean onDown(MotionEvent e)
    {
        linha.add(new Ponto(-e.getX(), -e.getY()));
        invalidate();
        return true;
    }

    @Override
    public void onShowPress(MotionEvent e)
    {

    }

    @Override
    public boolean onSingleTapUp(MotionEvent e)
    {
        return false;
    }

    @Override
    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY)
    {
        linha.add(new Ponto(e2.getX(), e2.getY()));
        invalidate();
        return true;
    }

    @Override
    public void onLongPress(MotionEvent e)
    {

    }

    @Override
    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY)
    {
        return false;
    }
}
