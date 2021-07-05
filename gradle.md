# 断点调试
1. [文章链接](https://fucknmb.com/2017/07/05/%E5%8F%88%E6%8E%8C%E6%8F%A1%E4%BA%86%E4%B8%80%E9%A1%B9%E6%96%B0%E6%8A%80%E8%83%BD-%E6%96%AD%E7%82%B9%E8%B0%83%E8%AF%95Gradle%E6%8F%92%E4%BB%B6/)
2. 方式1
    - gradle :app:clean -Dorg.gradle.debug=true  --no-daemon  开启debug，关闭daemon
    - 利用remote debug调试，端口为5005