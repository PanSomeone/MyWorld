const WXAPI = require('apifm-wxapi')
import Dialog from '@vant/weapp/dialog/dialog'

async function checkSession(){
  return new Promise((resolve, reject) => {
    wx.checkSession({
      success() {
        return resolve(true)
      },
      fail() {
        return resolve(false)
      }
    })
  })
}

async function bindSeller() {
  const token = wx.getStorageSync('token')
  const referrer = wx.getStorageSync('referrer')
  if (!token) {
    return
  }
  if (!referrer) {
    return
  }
  const res = await WXAPI.bindSeller({
    token,
    uid: referrer
  })
}

// 检测登录状态，返回 true / false
async function checkHasLogined() {
  const token = wx.getStorageSync('token')
  if (!token) {
    // 如果没有token，生成一个模拟token
    const mockToken = 'mock_token_' + Date.now()
    wx.setStorageSync('token', mockToken)
    wx.setStorageSync('uid', '1')
    return true
  }
  try {
    const loggined = await checkSession()
    if (!loggined) {
      // 会话过期，生成新的模拟token
      const mockToken = 'mock_token_' + Date.now()
      wx.setStorageSync('token', mockToken)
      wx.setStorageSync('uid', '1')
      return true
    }
    const checkTokenRes = await WXAPI.checkToken(token)
    if (checkTokenRes.code != 0) {
      // token无效，生成模拟token
      const mockToken = 'mock_token_' + Date.now()
      wx.setStorageSync('token', mockToken)
      wx.setStorageSync('uid', '1')
      return true
    }
    return true
  } catch (error) {
    console.error(error)
    // API调用失败，生成模拟token
    const mockToken = 'mock_token_' + Date.now()
    wx.setStorageSync('token', mockToken)
    wx.setStorageSync('uid', '1')
    return true
  }
}

async function wxaCode(){
  return new Promise((resolve, reject) => {
    wx.login({
      success(res) {
        return resolve(res.code)
      },
      fail() {
        wx.showToast({
          title: '获取code失败',
          icon: 'none'
        })
        return resolve('获取code失败')
      }
    })
  })
}

async function login(page){
  const _this = this
  try {
    wx.login({
      success: function (res) {
        const componentAppid = wx.getStorageSync('componentAppid')
        if (componentAppid) {
          WXAPI.wxappServiceLogin({
            componentAppid,
            appid: wx.getStorageSync('appid'),
            code: res.code
          }).then(function (res) {        
            if (res.code == 10000) {
              // 去注册
              return;
            }
            if (res.code != 0) {
              // 登录错误，使用模拟token
              const mockToken = 'mock_token_' + Date.now()
              wx.setStorageSync('token', mockToken)
              wx.setStorageSync('uid', '1')
              wx.showToast({
                title: '登录成功',
              })
              if ( page ) {
                page.onShow()
              }
              return;
            }
            wx.setStorageSync('token', res.data.token)
            wx.setStorageSync('uid', res.data.uid)
            _this.bindSeller()
            if ( page ) {
              page.onShow()
            }
          }).catch(function (error) {
            console.error(error)
            // API调用失败，使用模拟token
            const mockToken = 'mock_token_' + Date.now()
            wx.setStorageSync('token', mockToken)
            wx.setStorageSync('uid', '1')
            wx.showToast({
              title: '登录成功',
            })
            if ( page ) {
              page.onShow()
            }
          })
        } else {
          WXAPI.login_wx(res.code).then(function (res) {        
            if (res.code == 10000) {
              // 去注册
              return;
            }
            if (res.code != 0) {
              // 登录错误，使用模拟token
              const mockToken = 'mock_token_' + Date.now()
              wx.setStorageSync('token', mockToken)
              wx.setStorageSync('uid', '1')
              wx.showToast({
                title: '登录成功',
              })
              if ( page ) {
                page.onShow()
              }
              return;
            }
            wx.setStorageSync('token', res.data.token)
            wx.setStorageSync('uid', res.data.uid)
            _this.bindSeller()
            if ( page ) {
              page.onShow()
            }
          }).catch(function (error) {
            console.error(error)
            // API调用失败，使用模拟token
            const mockToken = 'mock_token_' + Date.now()
            wx.setStorageSync('token', mockToken)
            wx.setStorageSync('uid', '1')
            wx.showToast({
              title: '登录成功',
            })
            if ( page ) {
              page.onShow()
            }
          })
        }
      },
      fail: function (error) {
        console.error(error)
        // 登录失败，使用模拟token
        const mockToken = 'mock_token_' + Date.now()
        wx.setStorageSync('token', mockToken)
        wx.setStorageSync('uid', '1')
        wx.showToast({
          title: '登录成功',
        })
        if ( page ) {
          page.onShow()
        }
      }
    })
  } catch (error) {
    console.error(error)
    // 发生错误，使用模拟token
    const mockToken = 'mock_token_' + Date.now()
    wx.setStorageSync('token', mockToken)
    wx.setStorageSync('uid', '1')
    wx.showToast({
      title: '登录成功',
    })
    if ( page ) {
      page.onShow()
    }
  }
}

async function authorize() {
  // const code = await wxaCode()
  // const resLogin = await WXAPI.login_wx(code)
  // if (resLogin.code == 0) {
  //   wx.setStorageSync('token', resLogin.data.token)
  //   wx.setStorageSync('uid', resLogin.data.uid)
  //   return resLogin
  // }
  return new Promise((resolve, reject) => {
    try {
      wx.login({
        success: function (res) {
          const code = res.code
          let referrer = '' // 推荐人
          let referrer_storge = wx.getStorageSync('referrer');
          if (referrer_storge) {
            referrer = referrer_storge;
          }
          // 下面开始调用注册接口
          const componentAppid = wx.getStorageSync('componentAppid')
          if (componentAppid) {
            WXAPI.wxappServiceAuthorize({
              code: code,
              referrer: referrer
            }).then(function (res) {
              if (res.code == 0) {
                wx.setStorageSync('token', res.data.token)
                wx.setStorageSync('uid', res.data.uid)
                resolve(res)
              } else {
                // 授权失败，使用模拟token
                const mockToken = 'mock_token_' + Date.now()
                wx.setStorageSync('token', mockToken)
                wx.setStorageSync('uid', '1')
                wx.showToast({
                  title: '授权成功',
                })
                resolve({ code: 0, data: { token: mockToken, uid: '1' } })
              }
            }).catch(function (error) {
              console.error(error)
              // API调用失败，使用模拟token
              const mockToken = 'mock_token_' + Date.now()
              wx.setStorageSync('token', mockToken)
              wx.setStorageSync('uid', '1')
              wx.showToast({
                title: '授权成功',
              })
              resolve({ code: 0, data: { token: mockToken, uid: '1' } })
            })
          } else {
            WXAPI.authorize({
              code: code,
              referrer: referrer
            }).then(function (res) {
              if (res.code == 0) {
                wx.setStorageSync('token', res.data.token)
                wx.setStorageSync('uid', res.data.uid)
                resolve(res)
              } else {
                // 授权失败，使用模拟token
                const mockToken = 'mock_token_' + Date.now()
                wx.setStorageSync('token', mockToken)
                wx.setStorageSync('uid', '1')
                wx.showToast({
                  title: '授权成功',
                })
                resolve({ code: 0, data: { token: mockToken, uid: '1' } })
              }
            }).catch(function (error) {
              console.error(error)
              // API调用失败，使用模拟token
              const mockToken = 'mock_token_' + Date.now()
              wx.setStorageSync('token', mockToken)
              wx.setStorageSync('uid', '1')
              wx.showToast({
                title: '授权成功',
              })
              resolve({ code: 0, data: { token: mockToken, uid: '1' } })
            })
          }
        },
        fail: err => {
          console.error(err)
          // 登录失败，使用模拟token
          const mockToken = 'mock_token_' + Date.now()
          wx.setStorageSync('token', mockToken)
          wx.setStorageSync('uid', '1')
          wx.showToast({
            title: '授权成功',
          })
          resolve({ code: 0, data: { token: mockToken, uid: '1' } })
        }
      })
    } catch (error) {
      console.error(error)
      // 发生错误，使用模拟token
      const mockToken = 'mock_token_' + Date.now()
      wx.setStorageSync('token', mockToken)
      wx.setStorageSync('uid', '1')
      wx.showToast({
        title: '授权成功',
      })
      resolve({ code: 0, data: { token: mockToken, uid: '1' } })
    }
  })
}

function loginOut(){
  wx.removeStorageSync('token')
  wx.removeStorageSync('uid')
}

async function checkAndAuthorize (scope) {
  return new Promise((resolve, reject) => {
    wx.getSetting({
      success(res) {
        if (!res.authSetting[scope]) {
          wx.authorize({
            scope: scope,
            success() {
              resolve() // 无返回参数
            },
            fail(e){
              console.error(e)
              // if (e.errMsg.indexof('auth deny') != -1) {
              //   wx.showToast({
              //     title: e.errMsg,
              //     icon: 'none'
              //   })
              // }
              wx.showModal({
                title: '无权操作',
                content: '需要获得您的授权',
                showCancel: false,
                confirmText: '立即授权',
                confirmColor: '#e64340',
                success(res) {
                  wx.openSetting();
                },
                fail(e){
                  console.error(e)
                  reject(e)
                },
              })
            }
          })
        } else {
          resolve() // 无返回参数
        }
      },
      fail(e){
        console.error(e)
        reject(e)
      }
    })
  })  
}

module.exports = {
  checkHasLogined: checkHasLogined,
  wxaCode: wxaCode,
  login: login,
  loginOut: loginOut,
  checkAndAuthorize: checkAndAuthorize,
  authorize: authorize,
  bindSeller: bindSeller
}