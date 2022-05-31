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
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 329
    Top = 12
    Width = 104
    Height = 15
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1060#1057
    Color = clBtnFace
    ParentColor = False
  end
  object Label3: TLabel
    Left = 412
    Top = 103
    Width = 62
    Height = 15
    Caption = #1057#1095#1080#1090#1072#1090#1100' '#1086#1090':'
  end
  object Label4: TLabel
    Left = 25
    Top = 39
    Width = 146
    Height = 15
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1073#1091#1082#1074#1091' '#1090#1086#1084#1072'/'#1076#1080#1089#1082#1072
  end
  object Label5: TLabel
    Left = 489
    Top = 123
    Width = 99
    Height = 15
    Caption = ' ('#1085#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072')'
  end
  object Label6: TLabel
    Left = 412
    Top = 147
    Width = 63
    Height = 15
    Caption = #1057#1095#1080#1090#1072#1090#1100' '#1076#1086':'
  end
  object Label7: TLabel
    Left = 489
    Top = 167
    Width = 99
    Height = 15
    Caption = ' ('#1085#1086#1084#1077#1088' '#1082#1083#1072#1089#1090#1077#1088#1072')'
  end
  object Label2: TLabel
    Left = 456
    Top = 291
    Width = 111
    Height = 15
    Caption = #1042#1099#1073#1077#1088#1077#1090#1077' '#1089#1080#1075#1085#1072#1090#1091#1088#1091
  end
  object Button1: TButton
    Left = 469
    Top = 392
    Width = 98
    Height = 25
    Caption = #1053#1072#1081#1090#1080' '#1089#1080#1075#1085#1072#1090#1091#1088#1091
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 480
    Top = 100
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 1
    OnExit = Edit1Exit
  end
  object Button3: TButton
    Left = 25
    Top = 8
    Width = 98
    Height = 25
    Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100' '#1060#1057
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 177
    Top = 36
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 480
    Top = 144
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 4
    OnExit = Edit3Exit
  end
  object RadioGroup1: TRadioGroup
    Left = 412
    Top = 188
    Width = 185
    Height = 89
    Caption = #1057#1095#1080#1090#1099#1074#1072#1085#1080#1077' '#1082#1083#1072#1089#1090#1077#1088#1086#1074' '#1076#1080#1089#1082#1072
    ItemIndex = 0
    Items.Strings = (
      #1057#1095#1080#1090#1072#1090#1100' '#1074#1089#1077
      #1055#1088#1086#1087#1091#1089#1090#1080#1090#1100' '#1087#1091#1089#1090#1099#1077)
    TabOrder = 5
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 124
    Width = 398
    Height = 309
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 6
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'Nomer klaster'
        Width = 110
      end
      item
        Position = 1
        Text = 'Type file'
        Width = 125
      end>
  end
  object Button2: TButton
    Left = 8
    Top = 99
    Width = 97
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 111
    Top = 99
    Width = 82
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1041#1044
    TabOrder = 8
    OnClick = Button4Click
  end
  object CheckListBox1: TCheckListBox
    Left = 456
    Top = 305
    Width = 121
    Height = 81
    ItemHeight = 15
    Items.Strings = (
      'pdf'
      'doc'
      '7z'
      'vmdk'
      'png')
    TabOrder = 9
  end
end
