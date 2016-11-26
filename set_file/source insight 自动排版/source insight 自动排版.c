1，下载astyle工具：http://download.csdn.net/detail/taixinlfx/4306730

2，打开你的SourceInsight, 选择菜单“Options-->Custom Commands-->Add”, 输入Artistic Style(可以随便输入一个名字)。
3，Run中输入: "C:\Program Files\astyle\astyle.exe" -n -t --style=ansi %f （注意路径不可以是中文的）
4，Dir留空，将Iconic Window, Pause when done, Wait until done, File,then Line 四项前打上勾。
5，然后点对话框中右侧的按钮“Menu”， Menu--->Menu-->View--><end of menu>, 右侧Insert, OK.
6，此时在SourceInsight中的View菜单下多了个Style的子菜单选项，可以用它来对单个C/C++文件进行格式化。