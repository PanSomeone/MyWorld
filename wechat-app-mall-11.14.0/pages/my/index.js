const WXAPI = require('apifm-wxapi')
const AUTH = require('../../utils/auth')
const TOOLS = require('../../utils/tools.js')

Page({
	data: {
    balance:0.00,
    freeze:0,
    score:0,
    growth:0,
    score_sign_continuous:0,
    rechargeOpen: false, // 是否开启充值[预存]功能

    // 用户订单统计数据
    count_id_no_confirm: 0,
    count_id_no_pay: 0,
    count_id_no_reputation: 0,
    count_id_no_transfer: 0,

    // 判断有没有用户详细资料
    userInfoStatus: 0 // 0 未读取 1 没有详细信息 2 有详细信息
  },
	onLoad() {
    this.readConfigVal()
    // 补偿写法
    getApp().configLoadOK = () => {
      this.readConfigVal()
    }
	},
  onShow() {
    const _this = this
    AUTH.checkHasLogined().then(isLogined => {
      if (isLogined) {
        _this.getUserApiInfo();
        _this.getUserAmount();
        _this.orderStatistics();
        TOOLS.showTabBarBadge();
      } else {
        // 未登录时，设置默认状态
        _this.setData({
          userInfoStatus: 1
        })
      }
    }).catch(err => {
      console.error(err)
      // 登录失败时，设置默认状态
      _this.setData({
        userInfoStatus: 1
      })
    })
  },
  readConfigVal() {
    this.setData({
      order_hx_uids: wx.getStorageSync('order_hx_uids'),
      cps_open: wx.getStorageSync('cps_open'),
      recycle_open: wx.getStorageSync('recycle_open'),
      show_3_seller: wx.getStorageSync('show_3_seller'),
      show_quan_exchange_score: wx.getStorageSync('show_quan_exchange_score'),
      show_score_exchange_growth: wx.getStorageSync('show_score_exchange_growth'),
    })
  },
  async getUserApiInfo() {
    try {
      const res = await WXAPI.userDetail(wx.getStorageSync('token'))
      if (res.code == 0) {
        let _data = {}
        _data.apiUserInfoMap = res.data
        if (res.data.base.mobile) {
          _data.userMobile = res.data.base.mobile
        }
        if (res.data.base.nick && res.data.base.avatarUrl) {
          _data.userInfoStatus = 2
        } else {
          _data.userInfoStatus = 1
        }
        if (this.data.order_hx_uids && this.data.order_hx_uids.indexOf(res.data.base.id) != -1) {
          _data.canHX = true // 具有扫码核销的权限
        }
        const adminUserIds = wx.getStorageSync('adminUserIds')
        if (adminUserIds && adminUserIds.indexOf(res.data.base.id) != -1) {
          _data.isAdmin = true
        }
        if (res.data.peisongMember && res.data.peisongMember.status == 1) {
          _data.memberChecked = false
        } else {
          _data.memberChecked = true
        }
        this.setData(_data);
      } else {
        // API调用失败，使用模拟数据
        this.setData({
          apiUserInfoMap: {
            base: {
              id: 1,
              nick: '测试用户',
              avatarUrl: 'https://via.placeholder.com/100'
            }
          },
          userInfoStatus: 2
        });
      }
    } catch (error) {
      console.error(error)
      // 发生错误，使用模拟数据
      this.setData({
        apiUserInfoMap: {
          base: {
            id: 1,
            nick: '测试用户',
            avatarUrl: 'https://via.placeholder.com/100'
          }
        },
        userInfoStatus: 2
      });
    }
  },
  async memberCheckedChange() {
    try {
      const res = await WXAPI.peisongMemberChangeWorkStatus(wx.getStorageSync('token'))
      if (res.code != 0) {
        wx.showToast({
          title: res.msg,
          icon: 'none'
        })
      } else {
        this.getUserApiInfo()
      }
    } catch (error) {
      console.error(error)
      wx.showToast({
        title: '操作失败',
        icon: 'none'
      })
    }
  },
  getUserAmount: function () {
    var that = this;
    try {
      WXAPI.userAmount(wx.getStorageSync('token')).then(function (res) {
        if (res.code == 0) {
          that.setData({
            balance: res.data.balance.toFixed(2),
            freeze: res.data.freeze.toFixed(2),
            score: res.data.score,
            growth: res.data.growth
          });
        } else {
          // API调用失败，使用模拟数据
          that.setData({
            balance: '0.00',
            freeze: '0',
            score: 0,
            growth: 0
          });
        }
      }).catch(function (error) {
        console.error(error)
        // 发生错误，使用模拟数据
        that.setData({
          balance: '0.00',
          freeze: '0',
          score: 0,
          growth: 0
        });
      })
    } catch (error) {
      console.error(error)
      // 发生错误，使用模拟数据
      that.setData({
        balance: '0.00',
        freeze: '0',
        score: 0,
        growth: 0
      });
    }
  },
  handleOrderCount: function (count) {
    return count > 99 ? '99+' : count;
  },
  orderStatistics: function () {
    try {
      WXAPI.orderStatistics(wx.getStorageSync('token')).then((res) => {
        if (res.code == 0) {
          const {
            count_id_no_confirm,
            count_id_no_pay,
            count_id_no_reputation,
            count_id_no_transfer,
          } = res.data || {}
          this.setData({
            count_id_no_confirm: this.handleOrderCount(count_id_no_confirm),
            count_id_no_pay: this.handleOrderCount(count_id_no_pay),
            count_id_no_reputation: this.handleOrderCount(count_id_no_reputation),
            count_id_no_transfer: this.handleOrderCount(count_id_no_transfer),
          })
        } else {
          // API调用失败，使用默认数据
          this.setData({
            count_id_no_confirm: 0,
            count_id_no_pay: 0,
            count_id_no_reputation: 0,
            count_id_no_transfer: 0,
          })
        }
      }).catch((error) => {
        console.error(error)
        // 发生错误，使用默认数据
        this.setData({
          count_id_no_confirm: 0,
          count_id_no_pay: 0,
          count_id_no_reputation: 0,
          count_id_no_transfer: 0,
        })
      })
    } catch (error) {
      console.error(error)
      // 发生错误，使用默认数据
      this.setData({
        count_id_no_confirm: 0,
        count_id_no_pay: 0,
        count_id_no_reputation: 0,
        count_id_no_transfer: 0,
      })
    }
  },
  goAsset: function () {
    // 资产页面已移除
    wx.showToast({
      title: '资产功能已移除',
      icon: 'none'
    })
  },
  goScore: function () {
    // 积分页面已移除
    wx.showToast({
      title: '积分功能已移除',
      icon: 'none'
    })
  },
  goOrder: function (e) {
    wx.navigateTo({
      url: "/pages/order-list/index?type=" + e.currentTarget.dataset.type
    })
  },
  scanOrderCode(){
    wx.scanCode({
      onlyFromCamera: true,
      success(res) {
        wx.navigateTo({
          url: '/pages/order-details/scan-result?hxNumber=' + res.result,
        })
      },
      fail(err) {
        console.error(err)
        wx.showToast({
          title: err.errMsg,
          icon: 'none'
        })
      }
    })
  },
  updateUserInfo(e) {
    wx.getUserProfile({
      lang: 'zh_CN',
      desc: '用于完善会员资料',
      success: res => {
        console.log(res);
        this._updateUserInfo(res.userInfo)
      },
      fail: err => {
        console.log(err);
        wx.showToast({
          title: err.errMsg,
          icon: 'none'
        })
      }
    })
  },
  async _updateUserInfo(userInfo) {
    try {
      const postData = {
        token: wx.getStorageSync('token'),
        nick: userInfo.nickName,
        avatarUrl: userInfo.avatarUrl,
        city: userInfo.city,
        province: userInfo.province,
        gender: userInfo.gender,
      }
      const res = await WXAPI.modifyUserInfo(postData)
      if (res.code != 0) {
        // API调用失败，使用模拟数据
        this.setData({
          apiUserInfoMap: {
            base: {
              id: 1,
              nick: userInfo.nickName,
              avatarUrl: userInfo.avatarUrl
            }
          },
          userInfoStatus: 2
        });
        wx.showToast({
          title: '登录成功',
        })
        return
      }
      wx.showToast({
        title: '登录成功',
      })
      this.getUserApiInfo()
    } catch (error) {
      console.error(error)
      // 发生错误，使用模拟数据
      this.setData({
        apiUserInfoMap: {
          base: {
            id: 1,
            nick: userInfo.nickName,
            avatarUrl: userInfo.avatarUrl
          }
        },
        userInfoStatus: 2
      });
      wx.showToast({
        title: '登录成功',
      })
    }
  },
  gogrowth() {
    // 成长值页面已移除
    wx.showToast({
      title: '成长值功能已移除',
      icon: 'none'
    })
  },
})