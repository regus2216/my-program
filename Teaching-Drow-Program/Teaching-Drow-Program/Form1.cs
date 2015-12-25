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
        Color _selecredColor = Color.Black;//選択された色

        Bitmap _bitmap = null;//bitmapのインスタンス変数

        bool drawFlg = false;//true：描画中 

        Point oldLocation = new Point();//線の始点を保存

        public Form1()
        {
            InitializeComponent();
        }
        
        
        private void Form1_Load(object sender, EventArgs e)
        {
            _bitmap = new Bitmap(picNote.Width, picNote.Height);//bitmapの初期化


            cmbWidth.SelectedIndex = 0;//太さのコンボボックスのデフォルト値の設定

            btn1.BackColor = Color.Black;
            btn2.BackColor = Color.White;
            btn3.BackColor = Color.Blue ;
            btn4.BackColor = Color.Red;
            btn5.BackColor = Color.Green;
            btn6.BackColor = Color.Yellow;
            btn7.BackColor = Color.Pink;
            btn8.BackColor = Color.SkyBlue;
        }      

        
        private void picNote_MouseDown(object sender, MouseEventArgs e)
        {
            oldLocation = e.Location;//ペンの始点を更新

            //描画中にする
            drawFlg = true;
        }

        private void picNote_MouseUp(object sender, MouseEventArgs e)
        {
            //描画中を解除
            drawFlg = false;
        }

        private void picNote_MouseMove(object sender, MouseEventArgs e)
        {

            //描画中でなければ　処理を抜ける
            if (drawFlg == false) return;

            int penWidth = Int32.Parse(cmbWidth.SelectedItem.ToString());//コンボボックスから値を持ってくる

            Pen pen = new Pen(_selecredColor, penWidth);//ペンの作成

            using (Graphics g = Graphics.FromImage(_bitmap))
            {

                //g.DrawLine(pen, oldLocation, e.Location);//線の描画
                // g.FillEllipse(Brushes.Red,e.Location.X,e.Location.Y,20,20);//丸線の描画

                draw(g, oldLocation, e.Location,penWidth);


            };
            picNote.Image = _bitmap;//自動的に再描画 これないとfromが画面外にでると消える

            oldLocation = e.Location;//新しい始点を保存
        }


        //すべてのボタンクリックイベント
        private void btn_Click(object sender, EventArgs e)
        {
            _selecredColor = ((Button)sender).BackColor;
        }

        private void button1_Click(object sender, EventArgs e){}

        private void draw(Graphics g ,Point xy1 ,Point xy2,int penWidth)
        {
                //int penWidth = 20;//線の太さ
                Brush brush = new SolidBrush(_selecredColor);
                bool drawX = true;//true:x軸軸基準で描画　false:y軸基準で描画   

                if (Math.Abs(xy2.X - xy1.X) > Math.Abs(xy2.Y - xy1.Y))
                {
                    //幅の方が多きい場合　x軸でループ

                    //ぺんの向きが左向きならswap
                    //xy2.Xが多きなるように入れ替える
                    if (xy1.X > xy2.X)
                    {
                        Point p = xy1;
                        xy1 = xy2;
                        xy2 = p;
                    }
                    drawX = true;
                }
                else
                {
                    //高さの方が大きい場合　ｙ軸でループ
                    //xy2.Yが多きくなるように入れ替える
                    if (xy1.Y > xy2.Y)
                    {
                        Point p = xy1;
                        xy1 = xy2;
                        xy2 = p;
                    }
                    drawX = false;
                }
                if (drawX == true)
                {
                    float y = (float)xy1.Y;
                    float a = ((float)xy2.Y - xy1.Y) / ((float)xy2.X - xy1.X);//傾きの計算

                    for (int x = xy1.X; x <= xy2.X; x++)
                    {
                        RectangleF rect = new RectangleF(x, y, penWidth, penWidth);
                        g.FillEllipse(brush, rect);
                        y = y + a;
                    }
                }
                else
                {
                    float x = (float)xy1.X;
                    float a = ((float)xy2.X - xy1.X) / ((float)xy2.Y - xy1.Y);//傾きの計算

                    for (int y = xy1.Y; y <= xy2.Y; y++)
                    {
                        RectangleF rect = new RectangleF(x, y, penWidth, penWidth);
                        g.FillEllipse(brush, rect);
                        x = x + a;
                    }
                }
            
        }
    }
}
