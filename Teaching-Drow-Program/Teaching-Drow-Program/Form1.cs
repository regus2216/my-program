using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Teaching_Drow_Program
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        
        private void Form1_Load(object sender, EventArgs e)
        {
            _bitmap = new Bitmap(picNote.Width, picNote.Height);//bitmapの初期化
        }
        

        Bitmap _bitmap = null;//bitmapのインスタンス変数
        private void button1_Click(object sender, EventArgs e)
        {
            /*
            using (Graphics g = picNote.CreateGraphics())//線とか色を描くのに必要
            { 
                g.DrawLine(Pens.Blue, 100, 100, 300, 300);
            };
             */
            using (Graphics g = Graphics.FromImage(_bitmap)) {
                g.DrawLine(Pens.Blue, 100, 100, 300, 300);
            };
            picNote.Image = _bitmap;//自動的に再描画
        }

        bool drawFlg = false;//true：描画中 

        Point oldLocation = new Point();//線の終点を保存

        private void picNote_MouseMove(object sender, MouseEventArgs e)
        {

            //描画中でなければ　処理を抜ける
            if (drawFlg == false) return;

            using (Graphics g = Graphics.FromImage(_bitmap))
            {
                g.DrawLine(Pens.Black, oldLocation, e.Location);
            };
            picNote.Image = _bitmap;//自動的に再描画

            oldLocation = e.Location;//新しい位置を保存
        }

        private void picNote_MouseUp(object sender, MouseEventArgs e)
        {
          //描画中を解除
            drawFlg = false;
        }

        private void picNote_MouseDown(object sender, MouseEventArgs e)
        {
            oldLocation = e.Location;

            //描画中にする
            drawFlg = true;
        }

        
    }
}
