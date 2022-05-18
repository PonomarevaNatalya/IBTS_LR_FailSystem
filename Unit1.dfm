object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 56
    Top = 8
    Width = 34
    Height = 15
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 8
    Top = 128
    Width = 34
    Height = 15
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 334
    Top = 77
    Width = 137
    Height = 15
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1085#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072
  end
  object Button1: TButton
    Left = 376
    Top = 24
    Width = 75
    Height = 25
    Caption = 'FAT32'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 480
    Top = 24
    Width = 75
    Height = 25
    Caption = #1042' '#1073#1091#1092#1077#1088
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 480
    Top = 74
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 2
  end
  object Button3: TButton
    Left = 272
    Top = 24
    Width = 75
    Height = 25
    Caption = 'exFAT'
    TabOrder = 3
    OnClick = Button3Click
  end
end
