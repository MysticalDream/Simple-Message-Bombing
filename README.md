# Simple-Message-Bombing（初学尝试，没啥技术含量）
## 仅供学习交流，请勿用于骚扰他人
### [点击下载exe文件](https://github.com/myhonor123/Simple-Message-Bombing/blob/main/Bomb/Bomb.exe) 测试可以在Win10上正常运行
### [视频演示](https://www.bilibili.com/video/BV1aF411t7mG)
## 使用方法
  - 步骤一：使用该程序需要先复制一段你要发送的内容。
  - 步骤二：打开QQ或者微信（不要关闭）。
  - 步骤三：进入到你要发送复制内容的好友聊天对话框界面，然后打开此程。
  - 步骤四：在程序中输入要发送的次数后，按回车键（enter）即可。**(特别说明QQ还需要输入要轰炸对象的备注)"**
 ## 实现原理
   - 调用 win api 获取qq和微信聊天窗口句柄，将其设置到前台，通过模拟键盘将剪切板内容粘贴发送。
