整体思路简单明了，基于AFNetWorking3.1的封装，Get、Post、Put、Delete网络请求方式的数据获取，文件的下载，视频的上传下载，单图多图上传，网络监测。

参照[BANetWorkManager](https://github.com/boai/BANetManager)的封装方式进行小小修改，为便于以后自己项目的使用。

* 1 建立工程 ZBNetWork
* 2 cd Desktop/Git/ZBNetWork/
* 3 vim Podfile cocoaPods导入AFNetWorking(pod 'AFNetworking', '~> 3.1')
* 4 在info.plist文件中双击 -> Open As -> SourceCode添加以下代码（在iOS 9中 苹果将原http协议改成了https协议 使用 TLS1.2 SSL加密请求数据，所以我们不能直接请求http协议下的数据了）