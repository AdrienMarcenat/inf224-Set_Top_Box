import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import javax.swing.*;


public class MainWindow extends JFrame 
{
	//======================== Attributes =================//
	
	private static final long serialVersionUID = 1L;
	private JScrollPane scrollPane;
	private JTextArea textArea;
	private JTextField mediaName;
	private JPanel buttons;
	private QuitAction quit;
	private FindAction find;
	private PlayAction play;
	private JMenuBar menuBar;
	private JToolBar toolBar;
	private JMenu menu;
	
	private Client client;
	
	//======================== Constructor =================//
	
	MainWindow()
	{
		textArea = new JTextArea(20, 20);
		scrollPane = new JScrollPane(textArea);
		mediaName = new JTextField("Media name", 15);
		buttons = new JPanel();
		quit = new QuitAction("Quit");
		find = new FindAction("Find");
		play = new PlayAction("Play");
		
		buttons.add(find.getButton());
		buttons.add(play.getButton());
		buttons.add(mediaName);
		buttons.add(quit.getButton());
		
		menu = new JMenu("Menu");
		menuBar = new JMenuBar();
		toolBar = new JToolBar();
		menu.add(quit);
		menu.add(find);
		menu.add(play);
		menuBar.add(menu);
		toolBar.add(quit);
		toolBar.add(find);
		toolBar.add(play);
		
		add(scrollPane, BorderLayout.CENTER);
		add(buttons, BorderLayout.SOUTH);
		add(toolBar, BorderLayout.NORTH);
	
		pack();
		setJMenuBar(menuBar);
		setTitle("Set-Top-Box");
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // We close the application when we quit
		
		//We create and try to launch a client:
		String host = Client.DEFAULT_HOST;
		int port = Client.DEFAULT_PORT;

		client = null;

		try 
		{
			client = new Client(host, port);
		}
		catch (Exception e) 
		{
			System.err.println("Client: Couldn't connect to "+host+":"+port);
			System.exit(1);
		}
		
		System.out.println("Client connected to "+host+":"+port);
	}
	
	//======================== ActionListeners =================//
	
	class QuitAction extends AbstractAction 
	{  
		private static final long serialVersionUID = 1L;
		private JButton button;
		
		QuitAction(String name)
		{
			super(name);
			button = new JButton(name);
			button.addActionListener(this);
		}
		
		public void actionPerformed(ActionEvent e) 
		{  
			System.exit(0);
		}  
		
		public JButton getButton()
		{
			return button;
		}
	}  

	class FindAction extends AbstractAction 
	{  
		private static final long serialVersionUID = 1L;
		private JButton button;
		
		FindAction(String name)
		{
			super(name);
			button = new JButton(name);
			button.addActionListener(this);
		}
		
		public void actionPerformed(ActionEvent e) 
		{  
			String response = client.send("display " + mediaName.getText());
			textArea.append('\n' + response);
		}
		
		public JButton getButton()
		{
			return button;
		}
	}
	
	class PlayAction extends AbstractAction 
	{  
		private static final long serialVersionUID = 1L;
		private JButton button;
		
		PlayAction(String name)
		{
			super(name);
			button = new JButton(name);
			button.addActionListener(this);
		}
		
		public void actionPerformed(ActionEvent e) 
		{  
			client.send("play " + mediaName.getText());
		}  
		
		public JButton getButton()
		{
			return button;
		}
	}
}
