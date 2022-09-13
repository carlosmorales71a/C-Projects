import java.awt.*;
import javax.swing.JFrame;

public class CharacterListTester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int x, y;  // used to center a frame
			// instantiate a frame
		JFrame frame = new JFrame("Character linked list");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
			// instantiate our 'primary' panel for our frame
		LinkedListGUI2 primary = new LinkedListGUI2();
		
			// add this panel to the frame
		frame.getContentPane().add(primary);
		frame.pack();
		frame.setVisible(true);
		
			// center the frame on the screen
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension size = frame.getSize();
		screenSize.height = screenSize.height/2;
		screenSize.width = screenSize.width/2;
		size.height = size.height/2;
		size.width = size.width/2;
		y = screenSize.height - size.height;
		x = screenSize.width - size.width;
		frame.setLocation(x, y);
	}   // end method main

}   // end class CharacterListTester

