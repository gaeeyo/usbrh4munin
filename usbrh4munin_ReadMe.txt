
 usbrh4munin
 ===========

���T�v

 Strawberry Linux���甭������Ă���uUSB���x�E���x���胂�W���[���v��
munin-nodewin32 ���痘�p���邽�߂̊O���v���O�C���ł��B

���g����


1. �A�[�J�C�u�� Release �ȉ��ɂ���2�̃t�@�C�����A�K���ȏꏊ�ɔz�u���܂��B

  usbrh4munin.exe
  USBMeter.dll

2. munin-node.ini �� [Plugins] �� External=1 ��ݒ肵�܂��B

  [Plugins]
    :
  External=1

3. munin-node.ini �� [ExternalPlugin] ��ݒ肵�܂��B

  [ExternalPlugin]
  Plugin01=W:\share\usbrh4munin.exe

  usbrh4munin.exe��z�u�����ꏊ���v���p�X�ŋL�q���܂��B

4. �T�[�r�X���ċN�����܂�

  sc stop munin-node
  sc start munin-node

���A����

�z�z���̊m�F�Ȃǂ͂��̃����N����m�F���Ă��������B

http://d.hatena.ne.jp/gae/searchdiary?word=%2a%5b%c6%fc%b5%ad%5d


