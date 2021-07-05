## 创建型
### 简单工厂模式: 一个工厂对应多个产品，一个工厂及多个产品 ★★★★
- abstractProduct：Product1、Product2...
- Factory：（para1->Product1),(para2->Product2)
- 不同参数返回不同实例
- 产品基类 -> 产品子类1、产品子类2、...
- 工厂类：输入为产品代号，输出为产品对象
- 新增产品时，需要修改源代码
- 缺点
    - 工厂类集中了所有的逻辑，一旦不能工作，整个系统将受到影响
    - 增加系统中类的个数
    - 扩展困难

### 工厂方法模式：一个工厂对应一个产品，多个工厂及多个产品  ★★★★★
- abstractProduct：Product1、Product2...
- abstractFactory：Factory1（Product1）、Factory2（Product2）...
- 抽象产品
- 具体产品
- 抽象工厂
- 具体工厂


### 抽象工厂模式  ★★★★★
- 一个工厂对应不同产品类型的产品
- abstractProductA -> ProductA1、ProductA2...
- abstractProductB -> ProductB1、ProductB2... 
- abstractFactory -> ConcreteFactory1（ProductA1、ProductB1）、ConcreteFactory2（ProductA2、ProductB2）...

### 单例模式 ★★★★
- 1. 只能有一个实例 2. 必须自行创建这个实例 3. 必须自行向整个系统提供这个实例
- 只有一个实例，定义一个全局变量可以确保对象随时被访问，但不能防止实例化多个对象
- 类自身负责保存它的唯一实例，保证没有其他实例被创建，并且提供一个访问该实例的方法


### 建造者模式 ★★
- 产品本身与产品创建过程解耦，使得相同创建过程可以创建不同的产品对象
- 复杂对象拥有多个组成部分，对用户而言，无须直到各个部分的装配细节，也几乎不会使用单独某个部件，而是作为整体使用
- 建造者模式将部件与其组装过程分开，一步一步创建一个复杂对象，用户只需指定复杂对象类型就可以得到该对象，无须直到内部的具体构造细节
- 通俗理解：设计一个建造者类，作用是组合另一个复杂对象的组件
- 复杂对象的构建与表示分离，使得同样的构建可以创建不同的表示
- Builder：抽象建造者
- ConcreteBuilder：具体建造者
- Director：指挥者，包含Builder*, Product*，setBuilder(Builder*)
- Product：产品角色



## 结构性

### 外观模式 ★★★★★
- 外部与一个子系统的通信必须通过一个统一的外观对象进行，为子系统中的一组接口提供一个一致的界面

                client
                  ||
                  \/
                Facade
                   |
                /  |  \
            
        systemA systemB systemC

### 适配器模式 ★★★★
- 将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的类可以一起工作，别名为包装器
- 类似于电源适配器的设计和编码技巧
- 提供新的接口或者包装类，实现对现有类的重用
- Target：目标抽象类
- Adapater：适配器类
- Adaptee：适配者类，被包装的对象
- Client：客户类


### 代理模式 ★★★★
- 某些情况下，一个客户不行或者不能直接引用一个对象，此时可以通过一个称为代理的第三者来实现间接引用，代理对象可以在客户端和目标对象直接起到中介的作用，并且可以通过代理对象去掉客户端不能看到的内容和服务或者添加客户需要的额外服务

### 组合模式 ★★★★

### 桥接模式 ★★★
- 将继承关系转换为关联关系，从而降低了类与类之间的耦合
- 将抽象部分与他的实现部分分离，使它们可以独立变化
- Abstraction：抽象类
- RefinedAbstraction：扩充抽象类
- Implementor：实现类接口
- ConcreteImplementor：具体实现类
- 抽象化：忽略一些信息，把不同的实体当做同样的实体对待，将对象的共同性质抽取出来形成类的过程为抽象化的过程

- 实例：如果要绘制矩形、圆形、正方形，至少需要4个形状类，但是如果绘制的图像需要具有不同的颜色，如红色、绿色、蓝色等，此时至少有如下两种设计方案：
    - 为每一种形状都提供一套各种颜色的版本
    - 根据实际需要对形状和颜色进行组合，***此方案就是桥接模式的应用***


### 装饰模式 ★★★
- 一般有两种方式可以给一个类或对象增加行为：
    - 继承
    - 关联机制，将一个类的对象嵌入另一个对象中，由另一个对象来决定是否调用嵌入对象的行为以便扩展自己的行为，这个嵌入的对象被称为装饰器
- 动态地给一个对象增加一些额外的职责，装饰模式比生成子类实现更为灵活


### 享元模式 ★
- 通过共享技术实现相同或相似对象的重用，有效地支持大量细粒度对象的重用
- 


## 行为型模式
- 对在不同对象之间划分责任和算法的抽象化
- 行为型模式不仅关注类和对象的结构，而且重点关注他们之间的相互作用
- 行为型模式分为类行为型模式和对象行为型模式：
    - 类行为型模式：使用继承关系在几个类之间分配行为，通过多态等方式类分配父类与子类的职责
    - 对象行为型模式：使用对象的聚合关联关系来分配行为

### 迭代器模式 ★★★★★

### 观察者模式 ★★★★★
- 建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将做出相应反应
- 发生改变的对象成为观察目标，被通知的对象成为观察者


### 命令模式 ★★★★
- 解除请求发送者和请求接受者之间的耦合，让对象之间的调用关系更加灵活
- 发生请求的对象只需要直到如何发生请求，不必直到如何完成请求
- 将一个请求封装为一个对象，从而使我们可用不同的请求对客户进行参数化，对请求排队或者记录请求日志，以及支持可撤销的操作
- 本质是对命令进行封装，将发出命令的责任和执行命令的责任分割开

### 策略模式 ★★★★

### 职责链模式 ★★★
