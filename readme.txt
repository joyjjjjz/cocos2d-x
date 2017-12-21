EraserScene:	在cocos2d-x中实现橡皮擦功能
先将要被擦除的像素渲染到 FrameBuffer 中，然后使用 Alpha 为 0 的像素块与已有像素做混合，将已有的像素替换成 Alpha 为 0 的像素即可完成擦除。
https://blog.zengrong.net/post/2067.html

