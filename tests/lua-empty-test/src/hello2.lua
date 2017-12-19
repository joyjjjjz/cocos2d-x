print("1.1")
require "test_joy"
require "reload"
-- package.path = package.path  .. ";E:/git/cocos2d-x-3.6/tests/lua-empty-test/src/?.lua"
package.path = package.path  .. ";E:/git/cocos2d-x-3.6/tests/lua-empty-test/src/?.lua"
print(package.path)
print(package.preload)
for k, v in pairs(package.preload) do
    print("detail", k, v)
end
function myadd(x, y)
    return x + y
end

function sleep(n)
   if n > 0 then os.execute("ping -n " .. tonumber(n) .. " localhost > NUL") end
end

function hello_test()
    test_joy.hi()
end

function MyReload(t)
    local now_time = os.time()
    while true do
        if os.time() - now_time > t then
            -- reload.Reload("E:/git/cocos2d-x-3.6/tests/lua-empty-test/src/test.lua")
            reload.Reload("test_joy")
            return
        else
            sleep(1)
        end
    end
end

-- print("start runing")
-- sleep(1)
-- print(os.time())
-- -- MyReload(1)
-- while true do
--     print("current time:", os.time())
--     hello_test()
--     MyReload(1)
-- end
-- print("stop runing")
