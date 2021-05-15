# 按照文件名查找文件的指令
find /-name httpd.conf #根目录下查找
find /etc -name httpd.conf  #在/etc目录下找文件
find /etc -name '*srm*'  #在/etc目录下按照通配符查找文件名包含srm的文件
find . -name '*srm*'  #当前目录下模糊查询
# 按照文件特征查找
find / -amin -10
find / -empty
find / -size +10000c #查找系统中大于10000字节的文件

# 按照文件内容查询
grep 'test' d*      #显示所有以d为开头的文件中包含test的行
grep 'test' aa bb cc    #显示在aa,bb,cc中