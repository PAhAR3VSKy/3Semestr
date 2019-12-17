using System;
using System.Windows.Forms;

namespace TerVerLab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void button1_Click(object sender, EventArgs e)
        {
            chart1.Series[0].Points.Clear();
            double sredSq = Convert.ToDouble(numericUpDown3.Value);
            double time = Convert.ToDouble(numericUpDown1.Value);
            double Mk = Convert.ToDouble(numericUpDown2.Value);

            double timer = 0;
            double T;
            Random rand = new Random();
            double r;
            int num = 0;

            double intensiv = 1 / Mk;
            double k = 1/Math.Pow(sredSq*intensiv, 2);

            double intensivPotok = intensiv * k;

            do
            {
                for (int n = 0; n < k; n++)
                {
                    r = rand.NextDouble();
                    T = -1 / (intensivPotok) * Math.Log(r);
                    timer += T;
                }
                this.chart1.Series[0].Points.AddXY(timer, k);
                num++;
            } while (timer < time);

            this.textBox1.Text = Convert.ToString(k);
            this.textBox2.Text = Convert.ToString(num);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }
    }
}
