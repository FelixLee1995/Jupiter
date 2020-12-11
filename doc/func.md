# 实现的功能
* 多tcp, udp 输入
* 多tcp, udp 输出
* 支持线程池拓展选项


## 第一步
+ 实现config服务， 采用配置文件读取， 或配置中心读取 两种方式     yaml    nacos
+ 实现log服务， 日志和std同时输出， 可配置的级别， 运行时控制
+ 插件化加载服务
+ 版本更新打包，  更新说明


## 预计集成的服务
+ redis
+ nacos
+ mysql/oracle
+ mongodb
+ mq 消息队列

