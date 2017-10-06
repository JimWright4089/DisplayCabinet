//----------------------------------------------------------------------------
//
//  $Workfile: CabinetColors.cs$
//
//  $Revision: 126$
//
//  Project:    Icon Builder
//
//                            Copyright (c) 2017
//                               Jim Wright
//                            All Rights Reserved
//
//  Modification History:
//  $Log:
//  $
//
//----------------------------------------------------------------------------
using System;
using System.Drawing;
using System.Windows.Forms;

namespace CabinetColors
{
  //----------------------------------------------------------------------------
  //  Class Declarations
  //----------------------------------------------------------------------------
  //
  // Class Name: CabinetColors
  // 
  // Purpose:
  //      This is a helping tool for converting the images to C++ code.
  //
  //----------------------------------------------------------------------------
  public partial class CabinetColors : Form
  {
    //----------------------------------------------------------------------------
    //  Class Constants 
    //----------------------------------------------------------------------------
    const int MAX_PIXELS = 46;
    const int FROM_TOP = 10;
    const int FROM_SIDE = 10;
    const int REC_SIZE = 15;

    //----------------------------------------------------------------------------
    //  Class Atributes 
    //----------------------------------------------------------------------------
    Brush[] mArray = new Brush[MAX_PIXELS];
    int mCount = 0;
    Bitmap mFire = new Bitmap(10, 10);
    Bitmap mLava = new Bitmap(10, 10);
    Bitmap mOcean = new Bitmap(10, 10);
    Bitmap mSwamp = new Bitmap(10, 10);
    Bitmap mStars = new Bitmap(10, 10);
    Bitmap mAlien = new Bitmap(10, 10);
    Bitmap mCurrentBitmap = new Bitmap(10, 10);

    //--------------------------------------------------------------------
    // Purpose:
    //     Constructor
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    public CabinetColors()
    {
      mSwamp = Properties.Resources.Swamp;
      mFire = Properties.Resources.Fire;
      mLava = Properties.Resources.Lava;
      mOcean = Properties.Resources.Ocean;
      mStars = Properties.Resources.Space;
      mAlien = Properties.Resources.Alien;
      mCurrentBitmap = Properties.Resources.Swamp;

      FillArray();
      InitializeComponent();
      tDisplay.Enabled = true;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Fill the brush array for painting later
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void FillArray()
    {
      for (int i = 0; i < MAX_PIXELS; i++)
      {
        mArray[i] = new SolidBrush(mCurrentBitmap.GetPixel(i, mCount));
      }

      mCount++;
      if (mCount >= mCurrentBitmap.Height)
      {
        mCount = 0;
      }
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change the array 10 times a second
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void tDisplay_Tick(object sender, EventArgs e)
    {
      FillArray();
      this.Invalidate();
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Paint blocks on the screen
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void CabinetColors_Paint(object sender, PaintEventArgs e)
    {
      Graphics graph = e.Graphics;
      for (int i = 0; i < MAX_PIXELS; i++)
      {
        graph.FillRectangle(mArray[i], FROM_SIDE + (REC_SIZE * i), FROM_TOP, REC_SIZE, REC_SIZE);
      }
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Ocean
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbOcean_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mOcean;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Lava
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbLava_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mLava;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Fire
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbFire_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mFire;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Swamp
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbSwamp_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mSwamp;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Stars
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbStars_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mStars;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Change Current Bitmap to Alien
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void rbAlien_CheckedChanged(object sender, EventArgs e)
    {
      mCurrentBitmap = mAlien;
    }

    //--------------------------------------------------------------------
    // Purpose:
    //     Write out the C++ code for the bitmap
    //
    // Notes:
    //     None.
    //--------------------------------------------------------------------
    private void bSave_Click(object sender, EventArgs e)
    {
      SaveFileDialog saveFileDialog = new SaveFileDialog();

      saveFileDialog.Filter = "CPP Files (.cpp)|*.cpp|All Files (*.*)|*.*";
      saveFileDialog.FilterIndex = 1;
      saveFileDialog.RestoreDirectory = true;

      // The OK button was hit
      if (saveFileDialog.ShowDialog() == DialogResult.OK)
      {
        System.IO.StreamWriter file =
            new System.IO.StreamWriter(saveFileDialog.FileName);

        // Write the header for the code
        file.WriteLine("const uint32_t gFireData[62][46] =");
        file.WriteLine("{");

        // Save the pixels for R G B values
        for (int j = 0; j < mCurrentBitmap.Height; j++)
        {
          file.Write("  {");
          for (int i = 0; i < MAX_PIXELS; i++)
          {
            Color cur = mCurrentBitmap.GetPixel(i, j);
            file.Write("0X");
            file.Write(cur.R.ToString("X2"));
            file.Write(cur.G.ToString("X2"));
            file.Write(cur.B.ToString("X2"));
            file.Write(",");
          }
          file.WriteLine("},");
        }
        file.WriteLine("};");
        file.Close();
      }
    }
  }
}