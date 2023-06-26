using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace proxy
{
    class MyPictureBox : PictureBox
    {
        int lastX;
        int lastY;
        Picture imageContainer;
        //установить координаты для изображения
        public MyPictureBox(Picture imageContainer, int x, int y, int w, int h)
        {
            this.imageContainer = imageContainer;
            this.Height = h;
            this.Width = w;
            this.Top = y;
            this.Left = x;
            this.MouseMove += MoveBox;  //свободное перемещение бокса с помощью «мыши» по экрану
            this.MouseDoubleClick += RClick; //При двойном нажатии на правую клавишу «мыши» 
            BackColor = Color.White;
            SizeMode = PictureBoxSizeMode.AutoSize;
        }
        public void LoadPicture()
        {
            Image = imageContainer.GetImage();
        }
        public void MoveBox(Object Sender, MouseEventArgs args)
        {
            int dx = args.X - lastX;
            int dy = args.Y - lastY;
            lastX = args.X;
            lastY = args.Y;
            if (args.Button == MouseButtons.Left)
            {
                Top += dy;
                Left += dx;
                lastY -= dy;
                lastX -= dx;
            }
        }
        public void RClick(object Sender, MouseEventArgs args)
        {
            if (args.Button == MouseButtons.Right)
            {
                LoadPicture(); 
            }
        }
    }
}
