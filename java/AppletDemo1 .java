import java.applet.*;
import java.awt.*;
class AppletDemo1 extends Applet
{
	public void init()
	{
		setBackground(Color.blue);
	}
	public void paint(Graphics g)
	{
		g.drawString("Welcome to the world of applet",50,50);
		g.drawString("Hello friends",150,150);	
	}
}
/* 
<applet code="AppletDemo1.class"width="300"height="100">
</applet>
*/
