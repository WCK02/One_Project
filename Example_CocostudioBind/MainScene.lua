
local MainScene = class("MainScene", cc.load("mvc").ViewBase)
local Size  = cc.Director:getInstance():getWinSize()--960,640
local Center = cc.p(Size.width/2,Size.height/2)
-- testNode = cc.Node:create() -- cocos2d不允许使用全局变量赋值 除非使用允许的标准命名
local testNode

local bindSingle = function(name)
    printLog("bindSingle : ",name)
end

cc.CSLoader.createBindNode = function(self, csbnode, csbname)
    self.bindFunc(csbnode,csbnode.bindMainSceneUI)
    return cc.CSLoader:createNode("MainScene.csb")
end

function MainScene:bindMainSceneUI()
    print("running MainScene:bindMainSceneUI")
    self.spr = cc.CSLoader:bindSingle("Default")
    self.btn = cc.CSLoader:bindSingle("Button_2")
end


function MainScene:onCreate()
    local node = cc.CSLoader:createBindNode(self,"MainScene.csb")

    self:addChild(node,0,0)
end







function MainScene:onCreate1()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)
        
    -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
        :move(display.cx, display.cy + 200)
        :addTo(self)
        print("Type Conqure :")
        print(type(cc.Node))--table
        print(type(cc.Node:create()))--userdata ÓÃÀ´ÃèÊöÓ¦ÓÃ³ÌÐò»òÊ¹ÓÃCÊµÏÖµÄ¿â´´½¨µÄÐÂÀàÐÍ

    Size = cc.Director:getInstance():getWinSize()
    Center = cc.p(Size.width/2,Size.height/2)

    local label = cc.Label:create()
    label:setString("Hello,World")
    label:setSystemFontSize(64)
    label:addTo(self)
    label:setPosition(cc.p(300,300))

    print("This Class")
    print(type(my.MyClass))
    print(type(MyClass))
    print(type(cc.Node))
    print(type(cc.Sprite3DCache))
    --setmetatable(my.MyClass,{})

    local LuaTable = {function(num) print("I will print Num : ",num) end}

    local myclass = my.MyClass:create()
    myclass:print(function (a,b)
        print(a,b)
    end)
    myclass:getLuaFunc(LuaTable[1],"Yes I am")

    -- myclass:delete()
    myclass:print()

    -- myclass = nil
    -- collectgarbage("collect")

    testNode = cc.Node:create()
    -- self:performWithDelay(function()
    --     testNode:setVisible(false)
    -- end, 2)
    self:runAction(cc.Sequence:create(cc.DelayTime:create(1),
        cc.CallFunc:create(function()
            print("call func testNode visible")
            testNode:setVisible(true)
        end)))


    local spc = cc.Sprite3DCache:new()

    print("json : --------------------------------------")
    --[[
    json本身是个对象，由{}包裹
    {}代表一个对象
    []代表一个数组
    ,分隔多个数据
    ：键值对
    --]]
    local tb = json.decode('{"a":1,"b":"ss","c":{"c1":1,"c2":2},"d":[10,11],"1":100}')
    dump(tb)

    local str = json.encode({a=1,b="ss",c={c1=1,c2=2},d={10,11},100})
    print(str)

    print("crypto : --------------------------------------")
    -- local encryptStr = crypto.encryptAES256("Hello EncryptStr world!","this is a key")--crypto仅支持IOS和MAC,没有跑出来
    -- print(crypto.decryptAES256(encryptStr,"this is key"))

    -- local encryptStr = crypto.encryptXXTEA("hello world!","this is a key")
    -- print(crypto.decryptXXTEA(encryptStr,"this is a key"))
    self:downFunc()--先被require了 之后再被调用

    local layercolor = cc.LayerColor:create(cc.c4b(255,0,0,255),Size.width,Size.height)
    layercolor:setPosition(cc.p(0,0))
    self:addChild(layercolor,-1)

    local spr = display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self,1)
    spr:setOpacity(0)
    spr:setScale(0.5)
    -- spr:setBlendFunc(gl.ONE,gl.ONE)--sprite和Armature才有混合模式

    self.fbo = cc.RenderTexture:create(Size.width,Size.height)--create一张画布
    self.fbo:setPosition(Center)--
    self.fbo:clear(0,0,0,0.5)--清除 设置rgba

    self:addChild(self.fbo)

    self.eraser = cc.DrawNode:create()--画图节点
    self.eraser:drawDot(cc.p(0,0),20, cc.c4f(1,1,1,0))
    -- self.eraser:retain()
    self.eraser:setBlendFunc(gl.ONE, gl.ZERO)--这个也有
    --self:setTouchEnabled(true)--原生的coco2dLua没有把scene设置为可触摸 quick在cc.Node里重写了触摸方法
    -- self:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
    --     if event.name == "begin" then
    --         return true
    --     end
    --     if event.name == "moved" then
    --         self.eraser:pos(event.x,event.y)--位置按左下角为原点开始计算
    --         self.fbo:begin()--RenderTexture开始绘制
    --         self.eraser:visit()--画上eraser
    --         self.fbo:endToLua()--RenderTexture绘制结束
    --     end
    -- end)

    --self:NetWork()
    local camera = cc.Camera:createOrthographic(Size.width,Size.height,0,1)
    camera:setCameraFlag(cc.CameraFlag.USER1)
    --camera:setAnchorPoint(cc.p(0.5,0.5))没用
    --camera:ignoreAnchorPointForPosition(false)没用
    camera:setPosition(cc.p(480,320))-- 使用左下角 0,0 为锚点 不能改
    self:addChild(camera)

    --必须要在摄像机属性修改完成后再改这个 摄像机的CameraMask和渲染节点的CameraFlag与运算不为0时 才能被显示在屏幕上
    --第二个applyChildren 默认为true 自动更新所有节点的CameraFlag
    self:setCameraMask(2,true)



end

function MainScene:downFunc()
    print("This is downFunc")
end

function MainScene:NetWork()
    print("NetWork : -----------------")
    local workrun = network.isLocalWiFiAvailable()
end

return MainScene
