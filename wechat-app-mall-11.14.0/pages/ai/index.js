Page({
  data: {
    inputValue: '',
    messages: [],
    loading: false,
    suggestions: [
      '不知道吃什么推荐一下',
      '推荐一些零食',
      '推荐一些饮料',
      '适合宿舍的零食'
    ]
  },

  onLoad() {
    // 页面加载时的初始化
    this.setData({
      messages: [
        {
          type: 'ai',
          content: '你好！我是智购的AI助手，有什么可以帮你的吗？例如：不知道吃什么推荐一下'
        }
      ]
    })
  },

  onInputChange(e) {
    this.setData({
      inputValue: e.detail
    })
  },

  onSend() {
    if (!this.data.inputValue.trim()) {
      return
    }

    // 添加用户消息
    const userMessage = {
      type: 'user',
      content: this.data.inputValue
    }

    this.setData({
      messages: [...this.data.messages, userMessage],
      inputValue: '',
      loading: true
    })

    // 模拟AI回复
    setTimeout(() => {
      this.getAIResponse(this.data.inputValue)
    }, 1000)
  },

  onSuggestionClick(e) {
    const suggestion = e.currentTarget.dataset.name
    this.setData({
      inputValue: suggestion
    })
    this.onSend()
  },

  // 模拟AI回复
  getAIResponse(question) {
    let response = ''

    // 根据问题生成回复
    if (question.includes('不知道吃什么')) {
      response = '推荐以下零食：\n1. 薯片 - 经典零食，口感酥脆\n2. 坚果 - 营养健康\n3. 巧克力 - 甜蜜享受\n4. 饼干 - 方便携带\n5. 果干 - 天然美味'
    } else if (question.includes('零食')) {
      response = '热门零食推荐：\n1. 薯片类：原味、烧烤味、番茄味\n2. 坚果类：杏仁、核桃、腰果\n3. 糖果类：巧克力、硬糖、软糖\n4. 果干类：葡萄干、芒果干、草莓干'
    } else if (question.includes('饮料')) {
      response = '推荐饮料：\n1. 碳酸饮料：可乐、雪碧、芬达\n2. 果汁：橙汁、苹果汁、芒果汁\n3. 茶类：绿茶、红茶、乌龙茶\n4. 功能性饮料：红牛、脉动、宝矿力'
    } else if (question.includes('宿舍')) {
      response = '适合宿舍的零食：\n1. 泡面 - 方便快捷\n2. 火腿肠 - 充饥必备\n3. 饼干 - 随时可以吃\n4. 坚果 - 营养健康\n5. 果干 - 天然美味'
    } else {
      response = '抱歉，我不太理解你的问题。你可以尝试问：\n- 不知道吃什么推荐一下\n- 推荐一些零食\n- 推荐一些饮料\n- 适合宿舍的零食'
    }

    // 添加AI回复
    const aiMessage = {
      type: 'ai',
      content: response
    }

    this.setData({
      messages: [...this.data.messages, aiMessage],
      loading: false
    })
  }
  
  // 实际接入大模型API的方法
  /*
  async getAIResponse(question) {
    try {
      // 这里替换为实际的大模型API调用
      const response = await wx.request({
        url: 'https://api.example.com/ai/chat',
        method: 'POST',
        data: {
          question: question,
          apiKey: 'YOUR_API_KEY'
        },
        success: (res) => {
          const aiMessage = {
            type: 'ai',
            content: res.data.answer
          }

          this.setData({
            messages: [...this.data.messages, aiMessage],
            loading: false
          })
        },
        fail: (err) => {
          console.error(err)
          const aiMessage = {
            type: 'ai',
            content: '抱歉，AI服务暂时不可用，请稍后再试'
          }

          this.setData({
            messages: [...this.data.messages, aiMessage],
            loading: false
          })
        }
      })
    } catch (error) {
      console.error(error)
      const aiMessage = {
        type: 'ai',
        content: '抱歉，AI服务暂时不可用，请稍后再试'
      }

      this.setData({
        messages: [...this.data.messages, aiMessage],
        loading: false
      })
    }
  }
  */
})