package pt.isec.ans.rockpaperscissors;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnCancelListener;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Enumeration;

public class GameActivity extends Activity
{
    public static final int SERVER = 0;
    public static final int CLIENT = 1;
    public static final int NONE = 0;
    public static final int ROCK = 1;
    public static final int PAPER = 2;
    public static final int SCISSORS = 3;
    public static final int ME = 0;
    public static final int OTHER = 1;
    private static final int PORT = 8899;
    private static final int PORTaux = 9988; // to test with emulators

    int mode = SERVER;

    ProgressDialog pd = null;

    ServerSocket serverSocket=null;
    Socket socketGame = null;
    BufferedReader input;
    PrintWriter output;
    Handler procMsg = null;

    int moves[] = { NONE, NONE };
    int wins[] = { 0, 0 };

    TextView tvme, tvother;
    ImageView imgrock, imgpaper, imgscissors;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);

        ConnectivityManager connMgr = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = connMgr.getActiveNetworkInfo();
        if (networkInfo == null || !networkInfo.isConnected()) {
            Toast.makeText(this, R.string.error_netconn, Toast.LENGTH_LONG).show();
            finish();
            return;
        }

        Intent intent = getIntent();
        if (intent != null)
            mode = intent.getIntExtra("mode", SERVER);

        procMsg = new Handler();

        tvme = (TextView) findViewById(R.id.tvme);
        tvother = (TextView) findViewById(R.id.tvother);
        imgrock = (ImageView) findViewById(R.id.imgrock);
        imgpaper = (ImageView) findViewById(R.id.imgpaper);
        imgscissors = (ImageView) findViewById(R.id.imgscissors);
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        if (mode == SERVER)
            server();
        else  // CLIENT
            clientDlg();
    }

    public void onRock(View v)
    {
        imgpaper.setVisibility(View.INVISIBLE);
        imgscissors.setVisibility(View.INVISIBLE);
        moveMyPlayer(ROCK);
    }

    public void onPaper(View v)
    {
        imgrock.setVisibility(View.INVISIBLE);
        imgscissors.setVisibility(View.INVISIBLE);
        moveMyPlayer(PAPER);
    }

    public void onScissors(View v)
    {
        imgpaper.setVisibility(View.INVISIBLE);
        imgrock.setVisibility(View.INVISIBLE);
        moveMyPlayer(SCISSORS);
    }

    void initgame()
    {
        imgrock.setVisibility(View.VISIBLE);
        imgpaper.setVisibility(View.VISIBLE);
        imgscissors.setVisibility(View.VISIBLE);
        moves[0] = moves[1] = NONE;
    }

    void moveOtherPlayer(int move)
    {
        if (move == ROCK || move == PAPER || move == SCISSORS)
        {
            moves[OTHER] = move;
            verifyGame();
        }
    }

    void moveMyPlayer(int move)
    {
        if (move == ROCK || move == PAPER || move == SCISSORS)
        {
            moves[ME] = move;
            Thread t = new Thread(new Runnable()
            {
                @Override
                public void run()
                {
                    try
                    {
                        Log.d("RPS", "Sending a move: " + moves[ME]);
                        output.println(moves[ME]);
                        output.flush();
                    }
                    catch (Exception e)
                    {
                        Log.d("RPS", "Error sending a move");
                    }
                }
            });

            t.start();
            verifyGame();
        }
    }

    int whowins[][] = { { ROCK, SCISSORS }, { SCISSORS, PAPER }, { PAPER, ROCK } };

    void verifyGame()
    {
        if (moves[ME] == NONE || moves[OTHER] == NONE)
            return;

        int winner = -1;

        for (int i = 0; i < whowins.length; i++)
            if (moves[ME] == whowins[i][0] && moves[OTHER] == whowins[i][1])
            {
                winner = ME;
                break;
            }
        else if(moves[OTHER] == whowins[i][0] && moves[ME] == whowins[i][1])
        {
                winner = OTHER;
                break;
        }

        if (winner != -1)
            wins[winner]++;

        tvme.setText(getString(R.string.me)+":\t" + wins[ME]);
        tvother.setText(getString(R.string.other)+":\t" + wins[OTHER]);
        procMsg.postDelayed(new Runnable() {
            @Override
            public void run() {
                initgame();
            }
        }, 5000);
    }

    void server()
    {
        // WifiManager wm = (WifiManager) getSystemService(WIFI_SERVICE);
        // String ip = Formatter.formatIpAddress(wm.getConnectionInfo()
        // .getIpAddress());
        String ip = getLocalIpAddress();
        pd = new ProgressDialog(this);
        pd.setMessage(getString(R.string.serverdlg_msg) + "\n(IP: " + ip + ")");
        pd.setTitle(R.string.serverdlg_title);
        pd.setOnCancelListener(new OnCancelListener() {
            @Override
            public void onCancel(DialogInterface dialog) {
                finish();

                if (serverSocket!=null)
                {
                    try
                    {
                        serverSocket.close();
                    }
                    catch (IOException e) {}

                    serverSocket=null;
                }
            }
        });

        pd.show();

        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                try
                {
                    serverSocket = new ServerSocket(PORTaux);
                    socketGame = serverSocket.accept();
                    serverSocket.close();
                    serverSocket=null;
                    commThread.start();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                    socketGame = null;
                }
                procMsg.post(new Runnable() {
                    @Override
                    public void run() {
                        pd.dismiss();

                        if (socketGame == null)
                            finish();
                    }
                });
            }
        });

        t.start();
    }

    void clientDlg()
    {
        final EditText edtIP = new EditText(this);
        final AlertDialog ad = new AlertDialog.Builder(this).setTitle("RPS Client")
                .setMessage("Server IP").setView(edtIP)
                .setPositiveButton("Confirm", new OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        client(edtIP.getText().toString(), PORTaux); // to test with emulators: PORTaux);
                    }
                }).setOnCancelListener(new OnCancelListener() {
                    @Override
                    public void onCancel(DialogInterface dialog) {
                        finish();
                    }
                }).create();

        edtIP.setMaxLines(1);
        edtIP.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {

                if (edtIP.getText().toString().isEmpty())
                    return false;

                client(edtIP.getText().toString(), PORTaux);
                ad.dismiss();
                return true;
            }
        });

        edtIP.setText("10.0.2.2");

        ad.show();
    }

    void client(final String strIP, final int Port)
    {
        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                try
                {
                    Log.d("RPS", "Connecting to the server  " + strIP);
                    socketGame = new Socket(strIP, Port);
                }
                catch (Exception e)
                {
                    socketGame = null;
                }

                if (socketGame == null)
                {
                    procMsg.post(new Runnable() {
                        @Override
                        public void run() {
                            finish();
                        }
                    });
                    return;
                }

                commThread.start();
            }
        });
        t.start();
    }

    Thread commThread = new Thread(new Runnable() {
        @Override
        public void run() {
            try
            {
                input = new BufferedReader(new InputStreamReader(socketGame.getInputStream()));
                output = new PrintWriter(socketGame.getOutputStream());

                while (!Thread.currentThread().isInterrupted())
                {
                    String read = input.readLine();
                    final int move = Integer.parseInt(read);
                    Log.d("RPS", "Received: " + move);
                    procMsg.post(new Runnable() {
                        @Override
                        public void run() {
                            moveOtherPlayer(move);
                        }
                    });
                }
            }
            catch (Exception e)
            {
                procMsg.post(new Runnable() {
                    @Override
                    public void run() {
                        finish();
                        Toast.makeText(getApplicationContext(), R.string.game_finished, Toast.LENGTH_LONG).show();
                    }
                });
            }
        }
    });

    protected void onPause()
    {
        super.onPause();
        try
        {
            commThread.interrupt();

            if (socketGame != null)
                socketGame.close();

            if (output != null)
                output.close();

            if (input != null)
                input.close();
        }
        catch (Exception e) {}

        input = null;
        output = null;
        socketGame = null;
    };

    public static String getLocalIpAddress()
    {
        try
        {
            for (Enumeration<NetworkInterface> en = NetworkInterface.getNetworkInterfaces(); en.hasMoreElements();)
            {
                NetworkInterface intf = en.nextElement();

                for (Enumeration<InetAddress> enumIpAddr = intf.getInetAddresses(); enumIpAddr.hasMoreElements();)
                {
                    InetAddress inetAddress = enumIpAddr.nextElement();

                    if (!inetAddress.isLoopbackAddress() && inetAddress instanceof Inet4Address)
                        return inetAddress.getHostAddress();
                }
            }
        }
        catch (SocketException ex)
        {
            ex.printStackTrace();
        }

        return null;
    }
}
