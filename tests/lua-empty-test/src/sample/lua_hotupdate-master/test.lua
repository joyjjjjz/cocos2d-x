local test = {}
test.count = 0
count = 0
local d_count = 0
function test.func()
    count = count + 1
    d_count = d_count + 2
    test.count = test.count * 10 + 3
    print("test1.4", count, d_count, test.count)
    return true
end
return test
--[[
]]
