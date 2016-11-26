git 常用的命令

1 echo "# hardwera" >> README.md
2 git init                       //在该目录下初始化git
3 git add README.md              //把文件添加到本地库
4 git commit -m "first commit"   //提交本次提交	
5 git remote add origin https://github.com/wohuazai/hardwera.git    //关联一个远程库
6 git push -u origin master      //(第一次要用-u 以后不需要)把当前master分支推送到远程库
 

git merge –-no-ff  -m “注释” dev （合并禁用”Fast forward）

git branch dev 创建分支(-d删除)
git checkout dev 切换分支
git checkout  –b dev origin/dev （远程创建dev分支）
git reflog    查看历史版本号id
git reset --hard id 调到某个版本
git rebase -i <版号>  合并comit
git reset --soft commit-id
git reset --hard HEAD^~1 （退

git clone
git push
git pull
git log
git status