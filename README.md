# Jupiter

## 该项目致力于实现一个简单高效的hub server, 通过多tcp, udp通道 收取数据， 进行自定义编解码， 并转发

## 目标
+ ringbuffer 实现多线程无锁队列
+ 内存表处理用户空间数据缓存
+ 插件化加载编解码
+ 跨平台， windows/unix/os x
+ 持续集成测试， 规范开发，   gtest/gmock   
+ 对数据进行流式dump， 落地， 支持反演
