using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public Random random = new Random();

        public double expRaspr(double x, double coefficient)
        {
            if (x <= 0)
                return 0;
            else
                return coefficient * Math.Exp(-coefficient * (x));
        }

        public double[] getSelection(double coefficient, int interval, double n, int N)
        {
            double[] P = new double[interval],
                x = new double[interval];
            double PSum = 0;
            double step = n / interval;
            for (int i = 0; i < interval; i++)
            {
                x[i] = i * step + step / 2;
                P[i] = expRaspr(x[i], coefficient);
                PSum += P[i];
            }

            for (int i = 0; i < interval; i++)
                P[i] /= PSum;
                
            double[] xR = new double[N];
            for (int i = 0; i < N; i++)
                xR[i] = generator(P, x);

            return xR;
        }

        public double generator(double[] P, double[] x)
        {
            double r = random.NextDouble();
            int i = 0;
            for (; r > P[i]; i++)
                r -= P[i];
            double step = x[1] - x[0];
            return x[i] + step * random.NextDouble() - step / 2;
        }

        public double expRasprFunc(double x, double coefficient)
        {
            if (x <= 0)
                return 0;
            else
                return 1 - Math.Exp(-coefficient * (x));
        }

        public double kolmogorov(int[] h, double coefficient, int N, double step, int interval) // Проверка с помощью критерия согласия Колмогорова
        {
            double[] selectionF = new double[interval];
            selectionF[0] = 0;
            for (int i = 0; i < interval - 1; i++)
            {
                selectionF[i + 1] = selectionF[i] + h[i] / (double)N;
            }

            double D = 0;
            double t;
            for (int i = 0; i < interval; i++)
            {
                t = Math.Abs(selectionF[i] - expRasprFunc(step * (i + 0.5), coefficient));
                if (t > D)
                    D = t;
            }
            return D * Math.Sqrt(N);
        }

        private void button1_Click(object sender, EventArgs e) // Запуск программы по нажатию
        {
            chart1.Series[0].Points.Clear();
            double n = Convert.ToDouble(numericUpDown1.Value);
            double coefficient = Convert.ToDouble(numericUpDown3.Value);
            int interval = Convert.ToInt32(numericUpDown2.Value);
            int N = Convert.ToInt32(numericUpDown4.Value);
            int interval_N = Convert.ToInt32(numericUpDown5.Value);

            double[] xR = getSelection(coefficient, interval, n, N);

            int[] h = new int[interval_N];
            double step = n / interval_N;

            for (int i = 0; i < interval_N; i++)
                for (int j = 0; j < N; j++)
                    if (xR[j] > step * i && xR[j] <= step * (i + 1))
                        h[i]++;
                
            for (int i = 0; i < interval_N; i++)
                chart1.Series[0].Points.AddXY(step * (i + 0.5), h[i]);

            step = n / interval;
            h = new int[interval];

            for (int i = 0; i < interval; i++)
                for (int j = 0; j < N; j++)
                    if (xR[j] > step * i && xR[j] <= step * (i + 1))
                        h[i]++;

            richTextBox1.Text = Convert.ToString(kolmogorov(h, coefficient, N, step, interval));
        }

        
    }
}
