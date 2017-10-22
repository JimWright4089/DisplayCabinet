namespace CabinetColors
{
  partial class CabinetColors
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.components = new System.ComponentModel.Container();
      System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CabinetColors));
      this.rbFire = new System.Windows.Forms.RadioButton();
      this.rbAlien = new System.Windows.Forms.RadioButton();
      this.rbStars = new System.Windows.Forms.RadioButton();
      this.rbLava = new System.Windows.Forms.RadioButton();
      this.rbOcean = new System.Windows.Forms.RadioButton();
      this.rbSwamp = new System.Windows.Forms.RadioButton();
      this.tDisplay = new System.Windows.Forms.Timer(this.components);
      this.bSave = new System.Windows.Forms.Button();
      this.SuspendLayout();
      // 
      // rbFire
      // 
      this.rbFire.AutoSize = true;
      this.rbFire.Location = new System.Drawing.Point(12, 106);
      this.rbFire.Name = "rbFire";
      this.rbFire.Size = new System.Drawing.Size(42, 17);
      this.rbFire.TabIndex = 0;
      this.rbFire.TabStop = true;
      this.rbFire.Text = "Fire";
      this.rbFire.UseVisualStyleBackColor = true;
      this.rbFire.CheckedChanged += new System.EventHandler(this.rbFire_CheckedChanged);
      // 
      // rbAlien
      // 
      this.rbAlien.AutoSize = true;
      this.rbAlien.Location = new System.Drawing.Point(133, 106);
      this.rbAlien.Name = "rbAlien";
      this.rbAlien.Size = new System.Drawing.Size(48, 17);
      this.rbAlien.TabIndex = 1;
      this.rbAlien.TabStop = true;
      this.rbAlien.Text = "Alien";
      this.rbAlien.UseVisualStyleBackColor = true;
      this.rbAlien.CheckedChanged += new System.EventHandler(this.rbAlien_CheckedChanged);
      // 
      // rbStars
      // 
      this.rbStars.AutoSize = true;
      this.rbStars.Location = new System.Drawing.Point(133, 83);
      this.rbStars.Name = "rbStars";
      this.rbStars.Size = new System.Drawing.Size(49, 17);
      this.rbStars.TabIndex = 2;
      this.rbStars.TabStop = true;
      this.rbStars.Text = "Stars";
      this.rbStars.UseVisualStyleBackColor = true;
      this.rbStars.CheckedChanged += new System.EventHandler(this.rbStars_CheckedChanged);
      // 
      // rbLava
      // 
      this.rbLava.AutoSize = true;
      this.rbLava.Location = new System.Drawing.Point(12, 83);
      this.rbLava.Name = "rbLava";
      this.rbLava.Size = new System.Drawing.Size(49, 17);
      this.rbLava.TabIndex = 3;
      this.rbLava.TabStop = true;
      this.rbLava.Text = "Lava";
      this.rbLava.UseVisualStyleBackColor = true;
      this.rbLava.CheckedChanged += new System.EventHandler(this.rbLava_CheckedChanged);
      // 
      // rbOcean
      // 
      this.rbOcean.AutoSize = true;
      this.rbOcean.Location = new System.Drawing.Point(12, 60);
      this.rbOcean.Name = "rbOcean";
      this.rbOcean.Size = new System.Drawing.Size(57, 17);
      this.rbOcean.TabIndex = 4;
      this.rbOcean.TabStop = true;
      this.rbOcean.Text = "Ocean";
      this.rbOcean.UseVisualStyleBackColor = true;
      this.rbOcean.CheckedChanged += new System.EventHandler(this.rbOcean_CheckedChanged);
      // 
      // rbSwamp
      // 
      this.rbSwamp.AutoSize = true;
      this.rbSwamp.Location = new System.Drawing.Point(133, 60);
      this.rbSwamp.Name = "rbSwamp";
      this.rbSwamp.Size = new System.Drawing.Size(60, 17);
      this.rbSwamp.TabIndex = 5;
      this.rbSwamp.TabStop = true;
      this.rbSwamp.Text = "Swamp";
      this.rbSwamp.UseVisualStyleBackColor = true;
      this.rbSwamp.CheckedChanged += new System.EventHandler(this.rbSwamp_CheckedChanged);
      // 
      // tDisplay
      // 
      this.tDisplay.Tick += new System.EventHandler(this.tDisplay_Tick);
      // 
      // bSave
      // 
      this.bSave.Location = new System.Drawing.Point(262, 57);
      this.bSave.Name = "bSave";
      this.bSave.Size = new System.Drawing.Size(75, 23);
      this.bSave.TabIndex = 6;
      this.bSave.Text = "Save";
      this.bSave.UseVisualStyleBackColor = true;
      this.bSave.Click += new System.EventHandler(this.bSave_Click);
      // 
      // CabinetColors
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(779, 142);
      this.Controls.Add(this.bSave);
      this.Controls.Add(this.rbSwamp);
      this.Controls.Add(this.rbOcean);
      this.Controls.Add(this.rbLava);
      this.Controls.Add(this.rbStars);
      this.Controls.Add(this.rbAlien);
      this.Controls.Add(this.rbFire);
      this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
      this.Name = "CabinetColors";
      this.Text = "Cabinet Colors";
      this.Paint += new System.Windows.Forms.PaintEventHandler(this.CabinetColors_Paint);
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.RadioButton rbFire;
    private System.Windows.Forms.RadioButton rbAlien;
    private System.Windows.Forms.RadioButton rbStars;
    private System.Windows.Forms.RadioButton rbLava;
    private System.Windows.Forms.RadioButton rbOcean;
    private System.Windows.Forms.RadioButton rbSwamp;
    private System.Windows.Forms.Timer tDisplay;
    private System.Windows.Forms.Button bSave;
  }
}

