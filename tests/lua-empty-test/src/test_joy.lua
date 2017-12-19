
module("test_joy", package.seeall)

function hi()
    hi_detail()
end

function hi_detail( ... )
    local now_time = os.time()
    print("hi:9 in detail", now_time)
end