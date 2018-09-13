using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ardunoid_level_generator
{
    public partial class Form1 : Form
    {
        int[] level = new int[189];
        

        public Form1()
        {
            for (int i = 0; i < 189; i++)
                level[i] = 0;
            InitializeComponent();
            updateLevel();
        }

        private void updateLevel()
        {
            String levelString = "const uint8_t level" + levelName.Text + " [] PROGMEM = {";

            for (int i = 0; i < 189; i++)
            {
                if (i != 188)
                    levelString += level[i].ToString() + ",";
                else
                    levelString += level[i].ToString();
            }

            levelString+="};";
            levelOut.Text = levelString;
        }

        private void levelName_TextChanged(object sender, EventArgs e)
        {
            updateLevel();
        }

        private void buttonClick(System.Windows.Forms.Button thing, int index)
        {
            if (level[index] == 0)
            {
                level[index] = 1;
                thing.BackColor = Color.Black;
            }
            else
            {
                level[index] = 0;
                thing.BackColor = Color.White;
            }
            updateLevel();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 0);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 1);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 2);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 3);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 4);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 5);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 6);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 7);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 8);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 9);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 10);
        }

        private void button12_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 11);
        }

        private void button13_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 12);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 13);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 14);
        }

        private void button16_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 15);
        }

        private void button17_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 16);
        }

        private void button18_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 17);
        }

        private void button19_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 18);
        }

        private void button20_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 19);
        }

        private void button21_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 20);
        }

        private void button22_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 21);
        }

        private void button23_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 22);
        }

        private void button24_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 23);
        }

        private void button25_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 24);
        }

        private void button26_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 25);
        }

        private void button27_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 26);
        }

        private void button28_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 27);
        }

        private void button29_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 28);
        }

        private void button30_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 29);
        }

        private void button31_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 30);
        }

        private void button32_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 31);
        }

        private void button33_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 32);
        }

        private void button34_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 33);
        }

        private void button35_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 34);
        }

        private void button36_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 35);
        }

        private void button37_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 36);
        }

        private void button38_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 37);
        }

        private void button39_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 38);
        }

        private void button40_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 39);
        }

        private void button41_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 40);
        }

        private void button42_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 41);
        }

        private void button43_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 42);
        }

        private void button44_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 43);
        }

        private void button45_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 44);
        }

        private void button46_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 45);
        }

        private void button47_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 46);
        }

        private void button48_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 47);
        }

        private void button49_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 48);
        }

        private void button50_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 49);
        }

        private void button51_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 50);
        }

        private void button52_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 51);
        }

        private void button53_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 52);
        }

        private void button54_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 53);
        }

        private void button55_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 54);
        }

        private void button56_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 55);
        }

        private void button57_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 56);
        }

        private void button58_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 57);
        }

        private void button59_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 58);
        }

        private void button60_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 59);
        }

        private void button61_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 60);
        }

        private void button62_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 61);
        }

        private void button63_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 62);
        }

        private void button126_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 63);
        }

        private void button125_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 64);
        }

        private void button124_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 65);
        }

        private void button123_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 66);
        }

        private void button122_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 67);
        }

        private void button121_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 68);
        }

        private void button120_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 69);
        }

        private void button119_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 70);
        }

        private void button118_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 71);
        }

        private void button117_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 72);
        }

        private void button116_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 73);
        }

        private void button115_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 74);
        }

        private void button114_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 75);
        }

        private void button113_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 76);
        }

        private void button112_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 77);
        }

        private void button111_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 78);
        }

        private void button110_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 79);
        }

        private void button109_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 80);
        }

        private void button108_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 81);
        }

        private void button107_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 82);
        }

        private void button106_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 83);
        }

        private void button105_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 84);
        }

        private void button104_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 85);
        }

        private void button103_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 86);
        }

        private void button102_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 87);
        }

        private void button101_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 88);
        }

        private void button100_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 89);
        }

        private void button99_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 90);
        }

        private void button98_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 91);
        }

        private void button97_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 92);
        }

        private void button96_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 93);
        }

        private void button95_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 94);
        }

        private void button94_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 95);
        }

        private void button93_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 96);
        }

        private void button92_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 97);
        }

        private void button91_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 98);
        }

        private void button90_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 99);
        }

        private void button89_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 100);
        }

        private void button88_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 101);
        }

        private void button87_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 102);
        }

        private void button86_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 103);
        }

        private void button85_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 104);
        }

        private void button84_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 105);
        }

        private void button83_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 106);
        }

        private void button82_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 107);
        }

        private void button81_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 108);
        }

        private void button80_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 109);
        }

        private void button79_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 110);
        }

        private void button78_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 111);
        }

        private void button77_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 112);
        }

        private void button76_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 113);
        }

        private void button75_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 114);
        }

        private void button74_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 115);
        }

        private void button73_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 116);
        }

        private void button72_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 117);
        }

        private void button71_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 118);
        }

        private void button70_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 119);
        }

        private void button69_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 120);
        }

        private void button68_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 121);
        }

        private void button67_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 122);
        }

        private void button66_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 123);
        }

        private void button65_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 124);
        }

        private void button64_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 125);
        }

        private void button189_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 126);
        }

        private void button188_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 127);
        }

        private void button187_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 128);
        }

        private void button186_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 129);
        }

        private void button185_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 130);
        }

        private void button184_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 131);
        }

        private void button183_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 132);
        }

        private void button182_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 133);
        }

        private void button181_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 134);
        }

        private void button180_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 135);
        }

        private void button179_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 136);
        }

        private void button178_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 137);
        }

        private void button177_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 138);
        }

        private void button176_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 139);
        }

        private void button175_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 140);
        }

        private void button174_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 141);
        }

        private void button173_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 142);
        }

        private void button172_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 143);
        }

        private void button171_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 144);
        }

        private void button170_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 145);
        }

        private void button169_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 146);
        }

        private void button168_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 147);
        }

        private void button167_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 148);
        }

        private void button166_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 149);
        }

        private void button165_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 150);
        }

        private void button164_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 151);
        }

        private void button163_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 152);
        }

        private void button162_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 153);
        }

        private void button161_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 154);
        }

        private void button160_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 155);
        }

        private void button159_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 156);
        }

        private void button158_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 157);
        }

        private void button157_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 158);
        }

        private void button156_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 159);
        }

        private void button155_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 160);
        }

        private void button154_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 161);
        }

        private void button153_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 162);
        }

        private void button152_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 163);
        }

        private void button151_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 164);
        }

        private void button150_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 165);
        }

        private void button149_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 166);
        }

        private void button148_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 167);
        }

        private void button147_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 168);
        }

        private void button146_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 169);
        }

        private void button145_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 170);
        }

        private void button144_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 171);
        }

        private void button143_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 172);
        }

        private void button142_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 173);
        }

        private void button141_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 174);
        }

        private void button140_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 175);
        }

        private void button139_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 176);
        }

        private void button138_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 177);
        }

        private void button137_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 178);
        }

        private void button136_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 179);
        }

        private void button135_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 180);
        }

        private void button134_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 181);
        }

        private void button133_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 182);
        }

        private void button132_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 183);
        }

        private void button131_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 184);
        }

        private void button130_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 185);
        }

        private void button129_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 186);
        }

        private void button128_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 187);
        }

        private void button127_Click(object sender, EventArgs e)
        {
            var button = sender as Button;
            buttonClick(button, 188);
        }

        private void copyButton_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(levelOut.Text);
        }
    }

}
