git ���õ�����

1 echo "# hardwera" >> README.md
2 git init                       //�ڸ�Ŀ¼�³�ʼ��git
3 git add README.md              //���ļ���ӵ����ؿ�
4 git commit -m "first commit"   //�ύ�����ύ	
5 git remote add origin https://github.com/wohuazai/hardwera.git    //����һ��Զ�̿�
6 git push -u origin master      //(��һ��Ҫ��-u �Ժ���Ҫ)�ѵ�ǰmaster��֧���͵�Զ�̿�
 

git merge �C-no-ff  -m ��ע�͡� dev ���ϲ����á�Fast forward��

git branch dev ������֧(-dɾ��)
git checkout dev �л���֧
git checkout  �Cb dev origin/dev ��Զ�̴���dev��֧��
git reflog    �鿴��ʷ�汾��id
git reset --hard id ����ĳ���汾
git rebase -i <���>  �ϲ�comit
git reset --soft commit-id
git reset --hard HEAD^~1 ����

git clone
git push
git pull
git log
git status